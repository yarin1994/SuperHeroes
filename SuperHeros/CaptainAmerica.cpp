#include "CaptainAmerica.h"
#include "ProfessionBasedSuperHero.h"


CaptainAmerica::CaptainAmerica()
{
    _ageIncludingFreezing = 0;
}

CaptainAmerica::CaptainAmerica(const char* name, double age, bool radioactive, const char* profession, int yearsExperience, double ageIncludingFreezing) : SuperHero(name, age, radioactive), ProfessionBasedSuperHero(profession, yearsExperience)
{
    setAgeIncludingFreezing(ageIncludingFreezing);
}

CaptainAmerica::CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing) :SuperHero() , ProfessionBasedSuperHero(profession , yearsExperience)
{
    setAgeIncludingFreezing(ageIncludingFreezing);

}

CaptainAmerica::CaptainAmerica(double ageIncludingFreezing)
{
    setAgeIncludingFreezing(ageIncludingFreezing);
}

CaptainAmerica::CaptainAmerica(const CaptainAmerica& captainAmerica) :SuperHero(captainAmerica), ProfessionBasedSuperHero(captainAmerica)
{
    setAgeIncludingFreezing(captainAmerica.getAgeIncludingFreezing());
}

CaptainAmerica::~CaptainAmerica(){}

double CaptainAmerica::getAgeIncludingFreezing() const
{
    return _ageIncludingFreezing;
}

void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing)
{
    if (ageIncludingFreezing > _age)
        _ageIncludingFreezing = ageIncludingFreezing;
}


void CaptainAmerica::load(ifstream& in_file)
{
    int n;
    in_file.read((char*)&n, sizeof(n));
    _name = new char[n + 1];
    in_file.read(_name, n);
    _name[n] = '\0';
    in_file.read((char*)&_age, sizeof(_age));
    in_file.read((char*)&_radioactive, sizeof(_radioactive));
    in_file.read((char*)&_profession, sizeof(_profession));
    in_file.read((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));


}

void CaptainAmerica::save(ofstream& out_file) const
{
    int n = strlen(_name);
    out_file.write((char*)&n, sizeof(n));
    out_file.write(_name, n);
    out_file.write((char*)&_age, sizeof(_age));
    out_file.write((char*)&_radioactive, sizeof(_radioactive));
    out_file.write((char*)&_profession, sizeof(_profession));
    out_file.write((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
}
