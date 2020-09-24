#include "AnimalBasedSuperHero.h"
#include "SuperHero.h"

AnimalBasedSuperHero::AnimalBasedSuperHero()
{
    _animal = NULL;
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal) : SuperHero(name , age , radioactive)
{
    setAnimal(animal);

}

void AnimalBasedSuperHero::setAnimal(const char* animal)
{
    _animal = new char[strlen(animal) + 1];
    int size = strlen(animal) + 1;
    for (int i = 0 ; i< size ; i++)
    {
        _animal[i] = animal[i];

    }
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* animal) : SuperHero()
{
    setAnimal(animal);
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero)
{//make sure its OK;
    setName(animalBasedSuperHero.getName());
    setAge(animalBasedSuperHero.getAge());
    setRadioactive(animalBasedSuperHero.getRadioactive());
    setAnimal(animalBasedSuperHero.getAnimal());
}

AnimalBasedSuperHero::~AnimalBasedSuperHero()
{
    delete _animal;
}

const char* AnimalBasedSuperHero::getAnimal() const
{
    return _animal;
}

void AnimalBasedSuperHero::load(ifstream& in_file)
{
    int n;
    in_file.read((char*)&n, sizeof(n));
    _name = new char[n + 1];
    in_file.read(_name, n);
    _name[n] = '\0';
    in_file.read((char*)&_age, sizeof(_age));
    in_file.read((char*)&_radioactive, sizeof(_radioactive));
    in_file.read((char*)&_animal, sizeof(_animal));

}


void AnimalBasedSuperHero::save(ofstream& out_file) const
{
    int n = strlen(_name);
    out_file.write((char*)&n, sizeof(n));
    out_file.write(_name, n);
    out_file.write((char*)&_age, sizeof(_age));
    out_file.write((char*)&_radioactive, sizeof(_radioactive));
    out_file.write((char*)&_animal , sizeof(_animal));

}