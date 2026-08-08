# Orion
Orion is an emulator for a fictional computer i am making (which is called Orion).
# History i guess?
The reason i am making Orion is because i wanted to make an OS but didn't wanna deal with the x86-64 architecture
i tried reading the very first public release of the Linux kernel's source code (Linux v0.0.1 i think although i'm not too sure)
but to my dismay it was already a full kernel,
now why was this bad for me? i wanted to see how one would go about making a kernel step by step, from the first file to the releases, so i could actually understand what was happening.
Now could i have just read all the source code and the build scripts? yes, but nobody wants to waste their precious time in this world on that instead of actually writing the project.
And besides, i wasn't even gonna try to learn x86-64 assembly (i just don't like it), so i remembered that i know 6502 assembly already so it wouldn't be that much of a step, so i decided to make my own 6502 based computer to 
1-write my own OS on
2-help other people who were in my situation (probably nobody but maybe you're one of them if you're reading this?)
## Memory map

| Address range | Description |
|---|---|
| `0x0000 - 0x3FFF` | Fixed RAM (16KB) |
| `0x4000 - 0x7FFF` | Banked RAM (16KB per bank) |
| `0x8000 - 0xFFFF` | ROM |

The bank register is in fixed RAM at the last address, being 0x3FFF.
it's a 1 byte large register, meaning 256 banks of RAM, giving a total of 4MB of banked RAM.
