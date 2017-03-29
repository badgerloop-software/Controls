# Controls
We are the team responsible for the embedded programming side of badgerloop. We will work closely with the software and electrical teams to develop our mechatronic system. This will be your main resource to get things done.
<hr>



## Contributors
* [Nick Beckwith](mailto:nbeckwith2@wisc.edu) **Lead** 
(add your name here while you're at it)

## Important Links
* [System Architecture Design](https://drive.google.com/file/d/0B3JYQFEVstJTN0VSdUcyTlg0RlE/view?usp=sharing)
* [State Machine Diagram](https://drive.google.com/file/d/0B3JYQFEVstJTa3dqOElqY2ttcGc/view?usp=sharing)
* [Microcontroller](https://developer.mbed.org/platforms/ST-Nucleo-F429ZI/)
* [Final Design Package](https://docs.google.com/presentation/d/19tKkz2pZJ3SqOj3gx-DnCM2pNxR-0_Wi3x4bgSyD5tw/edit?usp=sharing)
<!---
# Code Example
-->

## So you want to make a commit
Does it compile?  
* yes -> Commit away!  
* no  -> Don't you dare  

## PlatformIO
In order to ditch the online ide, we will be using platformIO which has mbed support. PlatformIO allows you to work on the IDE and OS of your choice with well documented configurations. There is an official platformIO ide that is based off of the Atom editor which works nicely and has a built-in serial monitor. If you're more comfortable with other editors i.e. eclipse or visual studio, you can do that too, but it won't be covered.
* Install Atom and the platformIO package [here](http://platformio.org/platformio-ide)
* After platformIO is installed, go to Atom and follow [this](http://docs.platformio.org/en/latest/ide/atom.html#quick-start) to install Clang for code completion.
* Click `platformIO>Initialize` or Update PlatformIO Project, select the Nucleo-F429ZI board this repo directory. Click process. This step installs the STM platform and any toolchains needed.
* In the future, this will be all you'll need to compile and run on our environment. As of right now, (29 Mar 17), the toolchain platformIO uses for our microcontroller is out of date. So we have to install the [GNU ARM Embedded Toolchain](https://launchpad.net/gcc-arm-embedded/+download).
* Backup `toolchain-gccarmnoneeabi` and create a new `toolchain-gccarmnoneeabi` folder.
* Extract/install your toolchain in the new `toolchain-gccarmnoneeabi` folder.
* Copy `package.json` file from `z_toolchain-gccarmnoneeabi` to the new folder `toolchain-gccarmnoneeabi`
* Start programming!

