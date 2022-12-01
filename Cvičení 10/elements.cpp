#include "elements.h"
#include <iostream>

const std::string Input::getHTML() {
    std::string str = "<" + Input::name + "/>";
    return str;
};

const std::string Select::getHTML() {
    std::string str = "<" + Select::name + "/>";
    return str;
};

void Form::addInput(FormElement *element) {
    //this->inputs

    
};