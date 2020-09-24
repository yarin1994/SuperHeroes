#include "SuperHero.h"



SuperHero::SuperHero()
{
    _name = NULL;
    _age = 0.0;
    _radioactive = false;
}

SuperHero::SuperHero(const char* name, double age, bool radioactive)
{
    setName(name);
    setAge(age);
    setRadioactive(radioactive);

}


SuperHero::SuperHero(const SuperHero& superHero)
{
    setName(superHero.getName());

    setAge(superHero.getAge());

    setRadioactive(superHero.getRadioactive());

}


const char* SuperHero::getName() const
{
    return _name;
}

double SuperHero::getAge() const
{
    return _age;
}

bool SuperHero::getRadioactive() const
{
    return _radioactive;
}

void SuperHero::setName(const char* name)
{
    // need to make sure what is the meaning of I DIFFERENT FROM NULL


    if ( _name != name && name != NULL)
    {
        int size = strlen(name);
        _name = new char[strlen(name) + 1];
        for (int i = 0; i < size + 1; i++)
        {
            _name[i] = name[i];
        }
        _name[strlen(name)] = '\0';
    }

}

void SuperHero::setAge(double age)
{
    if (age >= 15 && age <= 40)
        _age = age;
}

void SuperHero::setRadioactive(bool radioactive)
{
    _radioactive = radioactive;
}

void SuperHero::load(ifstream& in_file)
{
    int n;
    in_file.read((char*)&n, sizeof(n));
    _name = new char[n + 1];
    in_file.read(_name, n);
    _name[n] = '\0';
    in_file.read((char*)&_age, sizeof(_age));
    in_file.read((char*)&_radioactive, sizeof(_radioactive));

}


void SuperHero::save(ofstream& out_file) const
{
    int n = strlen(_name);
    out_file.write((char*)&n, sizeof(n));
    out_file.write(_name, n);
    out_file.write((char*)&_age, sizeof(_age));
    out_file.write((char*)&_radioactive, sizeof(_radioactive));

}


SuperHero::~SuperHero()
{
    delete _name;
}
