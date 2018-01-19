#ifndef _CODER_H_
#define _CODER_H_

#include "serverpch.h"

class ICoder
{
    virtual bool encode(const char* src,e_uint32 srclen,char* rst,e_uint32& rstlen) = 0;
    
    virtual bool decode(const char* src,e_uint32 srclen,char* rst,e_uint32& rstlen) = 0;

};

#endif
