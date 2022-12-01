#pragma once
#include <stdlib.h>

class String {
	const int LIMIT = 100;
    int length;
    char* pointer;

private:
    int strlen(char* value);

public:
	String(int size) {
        this->length = size + 1;
        pointer = (char *) malloc(size * sizeof(char));
	}

    void set(char* value);
    char* substring();
    void join();
    void print();
    void dispose();
	
    int getLength();

	//pretezovani operatoru

	/*void operator+(int);
	void operator+(Pumpkin &);
	int operator()();
	bool operator==(Pumpkin &);*/
};

