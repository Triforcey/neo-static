# NEO-STATIC
## This is just the front end for Arduino! To get the front end for the RPI, go to https://github.com/Triforcey/neo-static-server.
## Original purpose
To generate random numbers. It worked as expected. The random numbers were generated on a RPI3 using floating GPIO pins.
## What actually happened
The numbers by all means are true random numbers. Why technically it could be possible to predict, it's not even close to realistic. At first I thought it would be impossible to predict due to quantum events, heat transfers, etc. However, once I got it running visualy on my 8x8 NeoPixel grid, it proved otherwise. It showed waves, not static. At first I thought it must be some illusion or just my tired brain, but the waves consited through the night, and over the next day up to as I write this. The wires must've been acting as sort of antenas. Inorder to confirm this I held my phone up to the wires, and as soon as it was within about 5cm it crashed. I repeated this a few times and it crashed every time. To prevent the interference a friend suggested I cover the wires with tinfoil. So I bundled them all up in a thin layer of tinfoil. After this there was nothing on the display. It was completly blank. Until I reached my hand over. As soon as my hand was within a foot it lit up. As I slowly put my hand closer, it got brighter and the wave pattern once again became evident.

Currently I'm running it on a 8x8 grid and the waves go diagnoaly, appearing to move from the bottom left to the top right. The colors definitely are random, and this method is still safe for encryption. It's fun to see what happens when using different electrical defices near it too.
## So is it random or not?
It is not random, but it does appear to be much more reliable then pseudo random. Also the colors on the grid itself do appear to be random. The brightness is relative to the strength of the signal, but the color appears to have no corolation other then the exact moment it's measured.
