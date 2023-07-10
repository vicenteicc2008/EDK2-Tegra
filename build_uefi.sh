#!/bin/bash

function _help(){
	echo "Usage: build_uefi.sh -d <Codename> [-r <Build Mode>]"
	echo
	echo "Build EDK2 UEFI for Tegra Platforms."
	echo
	echo "Options:"
	echo "	--device <Codename>, -d <Codename>:       Build a Device."
	echo "	--release <Build Mode>, -r <Build Mode>:  Release mode for building, 'RELEASE' is the default or use 'DEBUG' alternatively."
	echo "	--help, -h:                               Shows this Help."
	echo
	echo "MainPage: https://github.com/Robotix22/EDK2-Tegra"
	exit "${1}"
}

function _error(){ echo "${@}" >&2;exit 1; }

TARGET_DEVICE=""
TARGET_BUILD_MODE="RELEASE"
UPDATE_CHECK=""
OPTS="$(getopt -o d:hfabcACDO:r: -l device:,help,release: -n 'build_uefi.sh' -- "$@")"||exit 1
eval set -- "${OPTS}"
while true
do	case "${1}" in
		-d|--device) TARGET_DEVICE="${2}";shift 2;;
		-h|--help) _help 0;shift;;
		-r|--release) TARGET_BUILD_MODE="${2}";shift 2;;
		--) shift;break;;
		*) _help 1;;
	esac
done

case "${TARGET_BUILD_MODE}" in
	RELEASE) _TARGET_BUILD_MODE=RELEASE;;
	*) _TARGET_BUILD_MODE=DEBUG;;
esac

if [ -z ${TARGET_DEVICE} ]; then
	_help
fi

if [ -f "configs/devices/${TARGET_DEVICE}.conf" ]
then source "configs/devices/${TARGET_DEVICE}.conf"
else _error "Device configuration not found"
fi
if [ -f "configs/${SOC_PLATFORM}.conf" ]
then source "configs/${SOC_PLATFORM}.conf"
else _error "SoC configuration not found"
fi

git fetch &> /dev/null
UPDATE_CHECK=$(git status)
if [[ ${UPDATE_CHECK} == *"git pull"* ]]; then
	echo ""
	echo "===================[ INFO ]=================="
	echo "You are using an old Version of EDK2-Tegra."
	echo "Please Update to get the latest fixes and changes."
	echo "============================================="
	echo ""
fi

for i in "${EDK2}" ./Common/edk2
do
	if [ -n "${i}" ]&&[ -f "${i}/edksetup.sh" ]
	then
		_EDK2="$(realpath "${i}")"
		break
	fi
done

[ -n "${_EDK2}" ]||_error "EDK2 not Found!"
export CROSS_COMPILE="${CROSS_COMPILE:-arm-linux-gnueabihf-}"
export CLANG38_ARM_PREFIX="${CROSS_COMPILE}"
export PACKAGES_PATH="$_EDK2:$PWD:$PWD/Platforms"
export WORKSPACE="${PWD}/workspace"

#rm ./BootShim/BootShim.bin
#rm ./BootShim/BootShim.elf
rm edk2-${TARGET_DEVICE}.fd

#cd BootShim

#make UEFI_BASE=${FD_BASE} UEFI_SIZE=${FD_SIZE}||exit 1

#cd ..

source "${_EDK2}/edksetup.sh"
[ -d "${WORKSPACE}" ]||mkdir "${WORKSPACE}"
make -C "${_EDK2}/BaseTools"||exit "$?"

build \
	-s \
	-n 0 \
	-a ARM \
	-t CLANG38 \
	-p "./Platforms/${SOC_PLATFORM}Pkg/${SOC_PLATFORM}.dsc" \
	-b "${_TARGET_BUILD_MODE}" \
	-D TARGET_DEVICE="${TARGET_DEVICE}" \
	-D FD_BASE="${FD_BASE}" \
	-D FD_SIZE="${FD_SIZE}" \
	-D FD_BLOCKS="${FD_BLOCKS}" \
	||exit 1

#cat ./BootShim/BootShim.bin "./workspace/Build/Tegra30Pkg/${_TARGET_BUILD_MODE}_CLANG38/FV/TEGRA30PKG_UEFI.fd" > "./edk2-${TARGET_DEVICE}.fd" ||exit 1
cp "./workspace/Build/${SOC_PLATFORM}Pkg/${_TARGET_BUILD_MODE}_CLANG38/FV/NVIDIAPKG_UEFI.fd" "./edk2-${TARGET_DEVICE}.fd"
