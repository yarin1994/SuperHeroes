#include "Spiderman.h"
#include "SuperHero.h"


Spiderman::Spiderman()
{
    _webSize = 0;
}

Spiderman::Spiderman(const char* name, double age, bool radioactive, const char* animal, double webSize) : SuperHero(name , age, radioactive) ,AnimalBasedSuperHero(animal)
{
    setWebSize(webSize);

}

Spiderman::Spiderman(const char* animal, double webSize) : SuperHero() , AnimalBasedSuperHero(animal)
{
    setWebSize(webSize);

}

double Spiderman::getWebSize() const
{
    return _webSize;
}


Spiderman::Spiderman(double webSize) : SuperHero() ,AnimalBasedSuperHero()
{
    setWebSize(webSize);
}


void Spiderman::setWebSize(double webSize)
{
    if (webSize >= 0)
        _webSize = webSize;
}

Spiderman::Spiderman(const Spiderman& spiderman) : SuperHero(spiderman) , AnimalBasedSuperHero(spiderman)
{
    setWebSize(spiderman.getWebSize());
}

Spiderman::~Spiderman()
{
}


void Spiderman::load(ifstream& in_file)
{
    int n;
    in_file.read((char*)&n, sizeof(n));
    _name = new char[n + 1];
    in_file.read(_name, n);
    _name[n] = '\0';
    in_file.read((char*)&_age, sizeof(_age));
    in_file.read((char*)&_radioactive, sizeof(_radioactive));
    in_file.read((char*)&_animal, sizeof(_animal));
    in_file.read((char*)&_webSize, sizeof(_webSize));

}

void Spiderman::save(ofstream& out_file) const
{
    int n = strlen(_name);
    out_file.write((char*)&n, sizeof(n));
    out_file.write(_name, n);
    out_file.write((char*)&_age, sizeof(_age));
    out_file.write((char*)&_radioactive, sizeof(_radioactive));
    out_file.write((char*)&_animal, sizeof(_animal));
    out_file.write((char*)&_webSize, sizeof(_webSize));

}