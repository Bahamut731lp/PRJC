#pragma once
#include <string>
using namespace std;

/*
    const u návratovýho typu => Návratový typ bude konstantní, resp. nebude L-hodnota
    virtual const std::string getHTML() = 0; => Nikdy nebude mít tělo, je to čistě virtuální metoda
*/
class FormElement
{
private:
    const string name;

public:
    //Čistě virtuální metoda
    virtual const std::string getHTML() = 0;
};

class Input : public FormElement
{
private:
    const string name = "input";
public:
    const string getHTML();
};

class Select : public FormElement
{
private:
    const std::string name = "select";
public:
    virtual const std::string getHTML();
};

class Form
{
private:
    FormElement **inputs;

public:
    void addInput(FormElement *in1);
    const std::string getHTML();
};