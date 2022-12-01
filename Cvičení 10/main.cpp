#include "elements.cpp"
#include <iostream>

int main()
{
    Form *form = new Form();
    Input in1, in2, in3, in4;
    Select sel1, sel2, sel3;
    
    /*Form *form = new Form(); */
    form->addInput(&in1);

    std::cout << in1.getHTML() << sel1.getHTML() << std::endl;

    //std::cout << form -> getHTML() << std::endl;
}