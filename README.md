Orion is an emulator for a computer that uses the MOS-6502, 
It's currently still heavily in development and there are no builds ready yet (i'm not even done making the headers yet, the main file is basically non-existent)
Memory map:
0x0000-0x3fff fixed RAM, 16KB
0x4000-0x7fff banked RAM, each bank is 16KB, there are 256 banks meaning there's 4MB of RAM, bank register is in fixed RAM at 0x3fff
0x8000-0xffff ROM
