#include "String.h"
#include <iostream>
#include <string.h>

int String::strlen(char *value)
{
    int i = 0;

    while (i < 100)
    {
        if (*(value + i) == '\0')
            return i;
        i++;
    }

    return -1;
}

int String::getLength()
{
    return this->length;
}

// Tohle může bejt unsafe af
void String::set(char *value)
{
    int len = String::strlen(value);

    if (len > this->length) {} //TODO: Přealokovat string
    
    for (int i = 0; i < (this->length - 1); i++)
    {
        *(this->pointer + i) = *(value + i);
    }

    *(this->pointer + this->length - 1) = '\0';
}

void String::print()
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << *(this->pointer + i);
    }

    std::cout << std::endl;
}

/*void Pumpkin::total_display() {
    std::cout << "Total weight of " << total_number << " pumkins is " << total_weight << std::endl;
}

//pretezovani operatoru

void Pumpkin::operator+(int _weight) {
    this->weight += _weight;
}

void Pumpkin::operator+(Pumpkin &pumpkin) {
    this->weight += pumpkin.weight;
}

int Pumpkin::operator()() {
    return this->weight;
}


bool Pumpkin::operator==(Pumpkin &pumpkin) {
    return this->weight == pumpkin.weight;
}*/