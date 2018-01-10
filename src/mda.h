#ifndef MDA_H_INCLUDE
#define MDA_H_INCLUDE

#include "interface.h"

#include "misc.h"
#include "ram.h"


namespace MDA
{
#ifdef USE_SDL
extern SDL_Surface* mdscr;
#else
extern u8 mdscr[720*350*4];
#endif
extern u8 ROM[0x2000];
extern u8 crtcindex;
extern u8 htotal;
extern u8 hdisp;
extern u8 hsyncp;
extern u8 hsyncw;
extern u8 vtotal;
extern u8 vtotala;
extern u8 vdisp;
extern u8 vsyncp;
extern u8 maxscan;
extern u8 curstart;
extern u8 curend;
extern u16 startaddr;
extern u16 curaddr;

extern int framecount;

extern u8 dispmode; //Bit 1 must be set at all times, unless the processor wants to be halted.
extern u8 status;

u8 status_r(u16 addr);

void putpix(int x, int y, u8 r, u8 g, u8 b);

extern bool shouldblank;
void tick_frame();
void init();

void mda_w(u16 addr, u8 value);

extern iohandler mdacrtc;
}

#endif // MDA_H_INCLUDE
