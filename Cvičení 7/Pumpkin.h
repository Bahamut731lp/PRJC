#pragma once

class Pumpkin {
	int weight;
	static int total_weight;
	static int total_number;
public:
	Pumpkin(int _weight) : weight(_weight) {
		total_weight += _weight;
		total_number++;
	}

	~Pumpkin() {
		total_weight -= weight;
		total_number--;
	}
	void display();
	static void total_display();

	//pretezovani operatoru

	void operator+(int);
	void operator+(Pumpkin &);
	int operator()();
	bool operator==(Pumpkin &);
};

