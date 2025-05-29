# RA6E1-Bare-Metal-Programming
This Repo consist of Bare metal Programs related to Renesas RA6E1, Using GNU ARM tool chain.

### Prerequisites: 

1. ***VS Code :***  For code editor and Intellisense.
Visual Studio Code required Plugins<br>
    a. C/C++ for Visual Studio Code (link)
    b. Cortex-Debug (link)
    c. C/C++ Intellisense(link) optional
2. ***GNU ARM Embedded Tool chain :*** (GCC ARM Embedded) for compiling ARM Cortex-M code.
3. ***Make :*** A build automation tool
4. ***Debugger Hardware :*** A hardware debugger (e.g., Segger J-Link, Renesas E2/E2 Lite)connected to your RA6E1 board.
5. ***SVD for Renesas FPB-RA6E1:*** Device-specific System View Description (SVD) files which provide a high-level, textual description of registers and the associated bits.
6. ***Renesas RA6E1 Development Board:*** Renesas FPB-RA6E1 Dev board.
7. ***Renesas RA6E1 Datasheet & User's Manual:*** Essential references for hardware details.

### Modify launch.json 

```
{
    "version": "0.2.0",
    "configurations": [

        {
            "name": "Cortex-Debug",
            "cwd": "${workspaceFolder}",
            "executable": "D:/C_C++_FILES/RA6E1/RA6E1-Bare-Metal-Programming/TEMPLATE/build/Template.elf",
            "request": "launch",
            "type": "cortex-debug",
            "runToEntryPoint": "main",
            "servertype": "jlink",
            "serverpath": "C:/Program Files (x86)/SEGGER/JLink_V722b/JLinkGDBServerCL.exe",
            "serverArgs": [],
            "device": "R7FA6E10F",
            "interface": "jtag",
            "svdFile": "D:/C_C++_FILES/RA6E1/RA6E1_TOOLS/R7FA6E10F.svd",
            "liveWatch": {
                "enabled": true,
                "samplesPerSecond": 4
            }
        }
    ]
}
```
1. name: Any name for your debug
2. cwd & executable: current working directory and path for the .elf executable file to Debug
3. request: type of request, launch or release
4. serverpath: path to the GDB server
5. svdfile: locate your SVD file path

### Building the Project: 

1. Navigate to the Project:
``` 
    cd TEMPLATE
```
2. Build and Clean commands
```
    make all
```
```
    make clean
```