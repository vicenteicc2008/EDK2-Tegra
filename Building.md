# Building

### Step 1:

First of you need the sourcecode to compile a UEFI Image. <br />
Clone the Repo by using:
```
git clone https://github.com/Robotix22/EDK2-Tegra.git --recursive
cd EDK2-Tegra
```

### Step 2:

After Cloning the repo we can now continue on Setting up the Environment. <br />
First we need to install the needed Packages:
```
./setup_env.sh -p <Package Manager>
```

### Step 3:

So now we are able to begin the real UEFI build:
```
./build_uefi.sh -d <Codename> [-r <Build Mode>]
```

When then Build is done you will find a `.fd` File in the root of the repo.
