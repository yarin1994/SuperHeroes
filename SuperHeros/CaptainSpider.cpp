#include "SuperHero.h"
#include "CaptainSpider.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"

CaptainSpider::CaptainSpider()
{

}

//-------------------------------------------------------------------------------------------------------------------------------------------//

CaptainSpider::CaptainSpider(const char* name, double age, bool radioactive, const char* profession, int yearsExperience, double ageIncludingFreezing, const char* animal, double webSize)
        : SuperHero(name , age , radioactive) , CaptainAmerica(profession , yearsExperience , ageIncludingFreezing) , Spiderman(animal , webSize)
{

}

//-------------------------------------------------------------------------------------------------------------------------------------------//

CaptainSpider::CaptainSpider(const char* profession, int yearsExperience, double ageIncludingFreezing, const char* animal, double webSize)
        : CaptainAmerica(profession , yearsExperience , ageIncludingFreezing) , Spiderman(animal, webSize)
{

}

//-------------------------------------------------------------------------------------------------------------------------------------------//

CaptainSpider::CaptainSpider(double ageIncludingFreezing, double webSize)
        : CaptainAmerica(ageIncludingFreezing) , Spiderman(webSize)
{

}

//-------------------------------------------------------------------------------------------------------------------------------------------//

CaptainSpider::CaptainSpider(const CaptainSpider& captainSpider)
        : SuperHero(captainSpider) , Spiderman(captainSpider) , CaptainAmerica(captainSpider)
{

}

//-------------------------------------------------------------------------------------------------------------------------------------------//

CaptainSpider::~CaptainSpider()
{

}

//-------------------------------------------------------------------------------------------------------------------------------------------//

void CaptainSpider::load(ifstream& in_file)
{
    int n;
    in_file.read((char*)&n, sizeof(n));
    _name = new char[n + 1];
    in_file.read(_name, n);
    _name[n] = '\0';
    in_file.read((char*)&_age, sizeof(_age));
    in_file.read((char*)&_radioactive, sizeof(_radioactive));
    in_file.read((char*)&_profession, sizeof(_profession));
    in_file.read((char*)&_yearsExperience, sizeof(_yearsExperience));
    in_file.read((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
    in_file.read((char*)&_animal, sizeof(_animal));
    in_file.read((char*)&_webSize, sizeof(_webSize));

}
//-------------------------------------------------------------------------------------------------------------------------------------------//
void CaptainSpider::save(ofstream& out_file) const
{
    int n = strlen(_name);
    out_file.write((char*)&n, sizeof(n));
    out_file.write(_name, n);
    out_file.write((char*)&_age, sizeof(_age));
    out_file.write((char*)&_radioactive, sizeof(_radioactive));
    out_file.write((char*)&_profession, sizeof(_profession));
    out_file.write((char*)&_yearsExperience, sizeof(_yearsExperience));
    out_file.write((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));
    out_file.write((char*)&_animal, sizeof(_animal));
    out_file.write((char*)&_webSize, sizeof(_webSize));
}
//-------------------------------------------------------------------------------------------------------------------------------------------//

