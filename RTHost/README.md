# RTHost - interfacing to IMU chips from desktop systems

RTHost includes two RTIMULib-based apps - RTHostIMU and RTHostIMUGL. These apps provide a simple way of using IMU chips with a desktop computer running Ubuntu, Windows or Mac OS X. They will also run on a Raspberry Pi (although RTHostIMUGL will only work a low sample rates).

### Setting up the desktop

The desktop needs a version of Qt installed. This can be Qt4 or Qt5. The desktop must be set up so that Qt applications can be successfully built. On Ubuntu, this can be as simple as:

    sudo apt-get install libqt4-dev
    
or

    sudo apt-get install qt5-default
    
The Arduino must have the RTArduLinkIMU sketch from the richards-tech RTIMULib-Arduino repo installed. The Arduino must be connected to the desktop using a USB cable.
    
### Ubuntu/Mac OS X - Build using cmake with Qt4

Navigate to the RTHost directory. Then run:

    mkdir build
    cd build
    cmake ..
    make
    sudo make install
    sudo ldconfig
    
### Ubuntu/Mac OS X - Build using cmake with Qt5

Navigate to the RTHost directory. Then run:

    mkdir build
    cd build
    cmake -DQT5=1 ..
    make
    sudo make install
    sudo ldconfig
    
### Ubuntu/Mac OS X - Build using qmake

Qt's qmake can be used to build the apps. Navigate to the RTHostIMU or RTHostIMUGL directory and run:

    qmake
    make
    sudo make install

### Windows - Build using cmake

cmake can be run as above if installed on the Windows system. cmake creates .sln files that can then be used with Visual Studio.

### Windows - Build using Visual Studio

On Windows, Visual Studio (2010 or higher) can be used to build the apps. .sln file are included in the RTHostIMU and RTHostIMUGL directories.

### Running RTHostIMU or RTHostIMUGL

When the apps are started, the interface to the Arduino is not enabled. To enable the interface, use the drop-down to select the correct serial port/device. IMU data should be seen shortly after.



