#pragma once
#include "vyjimka.h"

class Block
{
private:
    Block *next;
    EXCEPTION_TYPE exception_type;
public:
    Block(EXCEPTION_TYPE type, Block *next);
    ~Block();

    void setNext(Block *next);
    void process(Vyjimka *exception);
    EXCEPTION_TYPE getExceptionType();
};