#include "vyjimka.h"

Vyjimka::Vyjimka(EXCEPTION_TYPE type, int timestamp, string description)
{
    this->type = type;
    this->timestamp = timestamp;
    this->description = description;
};

Vyjimka::~Vyjimka(){};

EXCEPTION_TYPE Vyjimka::getType()
{
    return this->type;
};

int Vyjimka::getTimestamp()
{
    return this->timestamp;
};

string Vyjimka::getDescription()
{
    return this->description;
};