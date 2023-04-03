# QmlScrcpy

you can embedded scrcpy[https://github.com/Genymobile/scrcpy] inside your qml project

This application mirrors Android devices (video and audio) connected via USB or over TCP/IP, and allows to control the device with the keyboard and the mouse of the computer. It does not require any root access. It works on Linux, Windows and macOS.

It focuses on:

### lightness: native, displays only the device screen
* performance: 30~120fps, depending on the device
* quality: 1920×1080 or above
* low latency: 35~70ms
* low startup time: ~1 second to display the first image
* non-intrusiveness: nothing is left installed on the Android device
* user benefits: no account, no ads, no internet required
* freedom: free and open source software

## Qmlscrcpy Project:

This application mirrors Android devices (video) connected via USB or WiFi, and allows to control the device with the keyboard and the mouse of the computer. It does not require any root access. It works on Linux

Android Application

Qt Application

scsrcpy server

| key | Scrcpy | QmlScrcpy |
| :--- | :---: | :---: |
| ui |  SDL | QML |
| video encode | ffmpeg | ffmpeg |
| video render | SDL | OpenGL |
| language | C | C++ |
| build | meson + gradle | CMake |

### features:
* lightness: native, displays only the device screen
* performance: 30~120fps, depending on the device
* quality: 1920×1080 or above
* low latency: 35~70ms
* low startup time: ~1 second to display the first image
* non-intrusiveness: nothing is left installed on the Android device
* user benefits: no account, no ads, no internet required
* freedom: free and open source software

#### Qml Benefits
* Screen Buffers are render by native OpenGl, No requirement to external library similar GStreamer or LibVlc
* You Can Used Animation, Scale, Rotation



## Requirement
```
adb --version
Android Debug Bridge version 1.0.41
Version 31.0.3-7562133
Installed as /usr/lib/android-sdk/platform-tools/adb
```

```
ubuntu 20.04
```


### Download & Install Qt 5.10.1
```
cd ~/
wget https://download.qt.io/new_archive/qt/5.10/5.10.1/qt-opensource-linux-x64-5.10.1.run
sudo chmod 755 qt-opensource-linux-x64-5.10.1.run
./qt-opensource-linux-x64-5.10.1.run
```

### [Clion IDE](https://www.jetbrains.com/clion/)
* My Clion version is 2022.3.3


* Add qt path to cmake
```
 Clion --> File --> Settings --> Build, Execution, Deployment --> CMake
 
-DCMAKE_PREFIX_PATH=~/Qt5.10.1/5.10.1/gcc_64/lib/cmake
```


<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="./res/images/cmake.png"  width="1450" height="768" alt="">
  </a>
</div>





## Test
* Test