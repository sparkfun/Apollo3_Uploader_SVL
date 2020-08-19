![generate executables](https://github.com/sparkfun/Apollo3_Uploader_SVL/workflows/generate%20executables/badge.svg)

# Apollo3 Uploader - SparkFun Variable Loader (SVL)

The ```svl``` bootloader is the default bootloader on Artemis module--based boards. This repo contains both the Python programs that are used to send code to a board and the source code for the program that receives code on an Artemis module.

The bootloader for the Artemis can be upgraded via Arduino using [these instructions](https://learn.sparkfun.com/tutorials/designing-with-the-sparkfun-artemis/all#troubleshooting). It can also be upgraded using the [Artemis Firmware Upload GUI](https://github.com/sparkfun/Artemis-Firmware-Upload-GUI).

Artemis SVL Versions:

* v5 - Speed and reliability increases
* v4 - Added peripheral deinitialization to deliver the Apollo3 closer to the initial reset state.
* v3 - Initial version
