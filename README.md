# Orion

Orion is an emulator for a computer built around the MOS-6502 CPU.

It is currently heavily in development, and there are no builds available yet. The project is still in the early stages (the headers are not even finished yet, and the main file is mostly empty).

## Memory map

| Address range | Description |
|---|---|
| `0x0000 - 0x3FFF` | Fixed RAM (16KB) |
| `0x4000 - 0x7FFF` | Banked RAM (16KB per bank) |
| `0x8000 - 0xFFFF` | ROM |

The bank register is located in fixed RAM at `0x3FFF`.

The system has 256 RAM banks, giving a total of 4MB of banked RAM.
