#pragma once
#include <string>
using namespace std;

enum EXCEPTION_TYPE {
    EXCEPTION_1,
    EXCEPTION_2,
    EXCEPTION_3,
    EXCEPTION_4,
    EXCEPTION_5
};

class Vyjimka
{
private:
    /* data */
    int timestamp;
    EXCEPTION_TYPE type;
    string description;

public:
    Vyjimka(EXCEPTION_TYPE type, int timestamp, string description);
    ~Vyjimka();

    int getTimestamp();
    EXCEPTION_TYPE getType();
    string getDescription();
};
