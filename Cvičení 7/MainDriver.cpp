#include "Pumpkin.h"
#include <iostream>
using namespace std;

int main() {
	//1. definice tridy, staticke metody a atributy
	Pumpkin p1(15), p2(20), p3(45);
	Pumpkin *ppointer = new Pumpkin(1);
	p1.display();
	p2.display();
	p3.display();
	ppointer->display();

	Pumpkin::total_display();
	p1.total_display();

	delete(ppointer);

	Pumpkin::total_display();
	p1.total_display();

	//2. pretezovani operatoru
	p1 + 10;
	p1.display();
	p1 + p2;
	p1.display();
    //pointer call
    (*ppointer)();
    (*ppointer) + p2;
    
	int weight = p1();
	cout << "weight: " << weight << endl;

	if (p1 == p3)
		cout << "equal " <<  endl;
	else
		cout << "not equal " << endl;
	cin.get();

}