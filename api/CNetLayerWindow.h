#ifndef _CNETLAYERWINDOW_H_
#define _CNETLAYERWINDOW_H_
#include "nwndef.h"

class CNetLayerWindow
{
public:
    int AddToHighOutgoingQueue(unsigned short);
    int AddToLowOutgoingQueue(unsigned short);
    void CutOutgoingBufferSize();
    int DoubleOutgoingBufferSize();
    int FauxNagle();
    int FrameNumberBetween(unsigned long, unsigned long, unsigned long);
    int FrameReceive(unsigned char *, unsigned long);
    void FrameSend(unsigned char, unsigned short, unsigned short);
    int FrameTimeout(unsigned long);
    void InitializeCompressionBuffers();
    void Initialize(CNetLayerInternal *);
    void LoadWindowWithFrames();
    int PlaceFrameInOutgoingBuffers(unsigned short);
    int SetAckTimer();
    int SetFauxNagleTimer();
    int SetInFrameTimer();
    int SetOutFrameTimer(unsigned long);
    void ShutDown();
    int TestAckTimer(unsigned long);
    int TestFauxNagleTimer(unsigned long);
    int TestInFrameTimer(unsigned long);
    int TestOutFrameTimer(unsigned long, unsigned long);
    int UnpacketizeFullMessages(int);
    ~CNetLayerWindow();
    CNetLayerWindow();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x918/2328 */ char rsvd1[2308];
    /* 0x918/2328 */ unsigned long field_918;
};
#endif
