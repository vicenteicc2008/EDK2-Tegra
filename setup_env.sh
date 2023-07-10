#!/bin/bash

function _help(){
        echo "Usage: setup_env.sh -p <Package Manager>"
        echo
        echo "Install all needed Packages."
        echo
        echo "Options:"
        echo "  --package-manager PAK, -p PAK:   Chose what Package Manager you use."
        echo "  --help, -h:                      Shows this Help."
        echo
        echo "MainPage: https://github.com/Robotix22/edk2-Tegra"
        exit 1
}

function _error(){ echo "${@}" >&2;exit 1; }

DISTRO=""
OPTS="$(getopt -o p:hfabcACDO: -l package-manager:,help -n 'setup_env.sh' -- "$@")"||exit 1
eval set -- "${OPTS}"
while true
do      case "${1}" in
                -p|--package-manager) PAK="${2}";shift 2;;
                -h|--help) _help 0;shift;;
                --) shift;break;;
                *) _help 1;;
        esac
done

if [ -z ${PAK} ]; then
    _help
fi

if [ ${PAK} = apt ]; then
    sudo apt update && sudo apt upgrade -y
    sudo apt install -y mono-devel build-essential nuget uuid-dev nasm gcc-arm-linux-gnueabihf gettext locales gnupg ca-certificates clang llvm
elif [ ${PAK} = dnf ]; then
    sudo dnf upgrade -y
    sudo dnf install -y mono-devel nuget nasm make gcc automake gcc-arm-linux-gnueabihf kernel-devel gettext gnupg ca-certificates clang llvm curl
elif [ ${PAK} = pacman ] || [ ${PAK} = yay ]; then
    if [ ${PAK} = pacman ]; then
        sudo pacman -Syu --needed git base-devel && git clone https://aur.archlinux.org/yay.git && cd yay && makepkg -si
    fi
    yay -Sy git mono base-devel nuget uuid nasm gcc-arm-linux-gnueabihf gettext gnupg ca-certificates clang llvm curl
else
    _error "Invaild Package Manager! Availbe Package Managers: apt, dnf, pacman and yay"
fi

export CLANG38_BIN=/usr/lib/llvm-38/bin/
export CLANG38_ARM_PREFIX=arm-linux-gnueabihf-
