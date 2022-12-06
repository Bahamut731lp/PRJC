#include <iostream>
#include "vyjimka.cpp"
#include "block.cpp"

using namespace std;

/*
Poznámky ze cvičení:
- Máme tolik tříd, kolik máme "různého" chování
- Jakmile se objekty liší akorát atributy, stačí jedna třída. Pokud se ale liší i chováním, je potřeba mít tříd více
*/

int main() {
    const auto exc1 = new Vyjimka(EXCEPTION_1, 1500, "Popis vyjimky 1");
    const auto exc2 = new Vyjimka(EXCEPTION_2, 7000, "Popis vyjimky 2");
    const auto exc3 = new Vyjimka(EXCEPTION_3, 9000, "Popis vyjimky 3");

    const auto t1 = new Block(EXCEPTION_1, NULL);
    const auto t2 = new Block(EXCEPTION_2, NULL);
    const auto t3 = new Block(EXCEPTION_5, NULL);

    t1->setNext(t2);
    t2->setNext(t3);

    try
    {
        t1->process(exc1);
        t1->process(exc2);
        t1->process(exc3);
    }
    catch(const string e)
    {
        cout << e << endl;
    }
}