
# Controls: MBED Edition
We are the team responsible for the embedded programming side of badgerloop. We will work closely with the software and electrical teams to develop our mechatronic system. This will be your main resource to get things done.
<hr>

## Boards Supported
<hr>
* [Nucleo 144 F429ZI](https://developer.mbed.org/platforms/ST-Nucleo-F429ZI/)

## Environmenets Supported
* [Keil uVision 5 IDE](http://www2.keil.com/mdk5/uvision/)

## Dependencies
<hr>
* [MBED OS](https://www.mbed.com/en/platform/mbed-os/)
MBED OS includes further dependencies like ST's HAL and MBED. Keil's package manager will install further packages.

## Development Instructions
<hr>
1. [Install Keil](https://www.keil.com/demo/eval/arm.htm). You will need to fill out a form to be able to download it, and what you are downloading is a trial version of the software.
2. Follow the [instructions](https://kb.wisc.edu/cae/page.php?id=32730) to connect to UW-Madison's Engineering License VPN.
  + If you already have Cisco AnyConnect or another VPN app, connect to `dept-ra-cssc.vpn.wisc.edu` and use the group `ENGINEERING_LICENSING`.
3. Open *File -> License Management* and navigate to the FlexLM License tab. Edit the Flex Server field and enter `8224@license-2.cae.wisc.edu` (this isn't sensitive information as you must already have an active CAE account and authenticate through the VPN).
4. Check *Use Flex Server*, and close the window.
5. Clone this git repository.
6. Open `keil/badgerloop.uvprojx` (should be associated with Keil) and attempt to build. You won't know if authentication occurs until linkage. Building the first time takes about ten minutes, but if it links then you are authenticated.
7. Begin contributing!

## So you want to make a commit
<hr>
Does it compile?  
* yes -> Commit away!  
* no  -> Don't you dare  

## Important Links
<hr>
* [System Architecture Design](https://drive.google.com/file/d/0B3JYQFEVstJTN0VSdUcyTlg0RlE/view?usp=sharing)
* [State Machine Diagram](https://drive.google.com/file/d/0B3JYQFEVstJTa3dqOElqY2ttcGc/view?usp=sharing)
* [Microcontroller](https://developer.mbed.org/platforms/ST-Nucleo-F429ZI/)
* [Final Design Package](https://docs.google.com/presentation/d/19tKkz2pZJ3SqOj3gx-DnCM2pNxR-0_Wi3x4bgSyD5tw/edit?usp=sharing)
<!---
# Code Example
-->
