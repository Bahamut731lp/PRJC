#include <iostream>
#include "block.h"
#include "vyjimka.h"

using namespace std;

Block::Block(EXCEPTION_TYPE type, Block *next)
{
    this->exception_type = type;
    this->next = next;
};

void Block::process(Vyjimka *exception)
{
    if (this->next == NULL)
        throw exception->getDescription();

    if (exception->getType() != this->getExceptionType()) {
        this->next->process(exception);
        return;
    }
    
    cout << "Vyjimka " << exception->getType() << " zpracovana: " << exception->getDescription() << endl;
};

void Block::setNext(Block *next) {
    this->next = next;
};

EXCEPTION_TYPE Block::getExceptionType() {
    return this->exception_type;
};

Block::~Block() {}