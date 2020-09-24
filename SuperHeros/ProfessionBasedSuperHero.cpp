#include "ProfessionBasedSuperHero.h"
#include "SuperHero.h"

ProfessionBasedSuperHero::ProfessionBasedSuperHero()
{
    _yearsExperience = 0;
    _profession = NULL;

}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience) : SuperHero(name , age , radioactive)
{
    setProfession(profession);
    setYearsExperience(yearsExperience);
}

void ProfessionBasedSuperHero::setProfession(const char* profession)
{
    int size = strlen(profession);
    _profession = new char[strlen(profession) + 1];
    for (int i = 0; i < size + 1; i++)
    {
        _profession[i] = profession[i];
    }

}

void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience)
{
    if(yearsExperience>=0)
        _yearsExperience = yearsExperience;
}


ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience) : SuperHero()
{
    setProfession(profession);
    setYearsExperience(yearsExperience);
}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero)
{
    setName(professionBasedSuperHero.getName());
    setAge(professionBasedSuperHero.getAge());
    setRadioactive(professionBasedSuperHero.getRadioactive());
    setProfession(professionBasedSuperHero.getProfession());
    setYearsExperience(professionBasedSuperHero.getYearsExperience());
}

ProfessionBasedSuperHero::~ProfessionBasedSuperHero()
{
    delete _profession;
}

int ProfessionBasedSuperHero::getYearsExperience() const
{
    return _yearsExperience;
}

void ProfessionBasedSuperHero::load(ifstream& in_file)
{
    int n;
    in_file.read((char*)&n, sizeof(n));
    _name = new char[n + 1];
    in_file.read(_name, n);
    _name[n] = '\0';
    in_file.read((char*)&_age, sizeof(_age));
    in_file.read((char*)&_radioactive, sizeof(_radioactive));
    in_file.read((char*)&_profession ,  sizeof(_profession));
    in_file.read((char*)&_yearsExperience, sizeof(_yearsExperience));

}


void ProfessionBasedSuperHero::save(ofstream& out_file) const
{
    int n = strlen(_name);
    out_file.write((char*)&n, sizeof(n));
    out_file.write(_name, n);
    out_file.write((char*)&_age, sizeof(_age));
    out_file.write((char*)&_radioactive, sizeof(_radioactive));
    out_file.write((char*)&_profession, sizeof(_profession));
    out_file.write((char*)&_yearsExperience, sizeof(_yearsExperience));

}