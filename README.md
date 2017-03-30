# Controls
We are the team responsible for the embedded programming side of badgerloop. We will work closely with the software and electrical teams to develop our mechatronic system. This will be your main resource to get things done.
<hr>



## Contributors
* [Nick Beckwith](mailto:nbeckwith2@wisc.edu) **Lead** 
* [Doug Dresser](mailto:dwdresser@wisc.edu) **Not-Lead**
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
* After platformIO is installed, go to Atom and follow [this](http://docs.platformio.org/en/latest/ide/atom.html#quick-start) to install Clang for code completion. The platformIO installer might prompt you to install Clang, but this will most likely not work so you should still follow this link for the installer. If you have already installed Clang but platformIO says you have not, restarting your computer should work.
* Click `platformIO>Initialize` or Update PlatformIO Project, select the Nucleo-F429ZI board as the board we will use. For the directory, you will need to set that as this repository. To get this repository on your computer, you must install github for desktop. You can then login(or make a github account) and have Nick add you to this repo. On the desktop program, you can clone a copy of this repo onto your local computer. This local copy is where you choose the directory path to be.
* In the future, this will be all you'll need to compile and run on our environment. As of right now, (29 Mar 17), the toolchain platformIO uses for our microcontroller is out of date. So we have to install the [GNU ARM Embedded Toolchain](https://launchpad.net/gcc-arm-embedded/+download). DO NOT INSTALL THIS YET, JUST DOWNLOAD THE INSTALLER.
* Now, find your .platformio folder(for windows it should be under your home directory), and find a folder called 'toolchain-gccarmnoneeabi' in the 'packages' folder. Backup `toolchain-gccarmnoneeabi` by renaming it as something else you will remember like 'toolchain-gccarmoneeabi_backup'.  Now create a new folder with the original name `toolchain-gccarmoneeabi`.
* Now you can run the installer from 2 steps ago and extract/install your toolchain in the new `toolchain-gccarmnoneeabi` folder. If the extracted toolchain is inside another file, just remove it so that you can see everything once you are inside `toolchain-gccarmoneeabi`. You should not have to click on another single folder to view everthing.
* Copy the `package.json` file from  your backup`toolchain-g ccarmnoneeabi_backup` to the new folder `toolchain-gccarmnoneeabi`
* You should now be ready to program! 

## Troublehshooting 
As we encounter problems attempting to install, compile, and upload our code, we will try to post solutions here.
* When uploading code, if you get an error saying that you must specify the upload port, a few solutions might work.
  * First try to install the Nucleo-F429ZI drivers you can find online. 
  * If this doesn't work, open the `platformio.ini` file and you can specify the upload port here. You can add the line of code 'upload_port = YOUR_PATH' where YOUR_PATH is the path you can find the microcontroller plugged in via usb. For windows users, look in the file explorer and see what letter drive this is. It could be the 'D:/' drive for example, so you would type 'upload_file = D:/". After adding this line of code it should upload correctly.

