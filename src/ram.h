#ifndef RAM_H_INCLUDED
#define RAM_H_INCLUDED

#include <vector>
#include <functional>

#include "cpu.h"

//TODO: should this be in RAM?
struct memhandler
{
    u32 start;
    u32 end;
    std::function<u8(u32)> rb;
    std::function<void(u32,u8)> wb;
};

namespace RAM
{
extern u8 RAM[0x100000];
extern u8 BIOS[0x20000];
extern std::vector<memhandler> handlers;
extern bool write;

extern memhandler bios_handler;

u32 getaddr(u16 seg, u16 offset);

u8 rb(u16 seg, u16 off); //read byte
void wb(u16 seg, u16 off, u8 value); //write byte

} //namespace RAM

#endif // RAM_H_INCLUDED
