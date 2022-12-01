#include "Pumpkin.h"
#include <iostream>


int Pumpkin::total_number = 0;
int Pumpkin::total_weight = 0;

void Pumpkin::display() {
	std::cout << "This one weights " << weight << std::endl;
}

void Pumpkin::total_display() {
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
}