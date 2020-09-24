#include "Avengers.h"
#include "SuperHero.h"



Avengers::Avengers()
{
    _superHeros = NULL;
    _numSuperHeros = 0;
}
//----------------------------------------------------------------------------------------------------------------------
Avengers::~Avengers()
{
    for(int i=0;i<_numSuperHeros;i++)
    {
        delete _superHeros[i];
    }
}
//----------------------------------------------------------------------------------------------------------------------

void Avengers::saveType(ofstream& out, const SuperHero* hero) const
{
    char name[2];

    if (typeid(*hero) == typeid(SuperHero))
    {
        name[0] = 'S';
        name[1] = 'H';
        out.write(name, sizeof(name));
    }

    if (typeid(*hero) == typeid(AnimalBasedSuperHero))
    {
        name[0] = 'A';
        name[1] = 'B';
        out.write(name, sizeof(name));
    }

    if (typeid(*hero) == typeid(Spiderman))
    {
        name[0] = 'S';
        name[1] = 'P';
        out.write(name, sizeof(name));
    }

    if (typeid(*hero) == typeid(ProfessionBasedSuperHero))
    {
        name[0] = 'P';
        name[1] = 'B';
        out.write(name, sizeof(name));
    }

    if (typeid(*hero) == typeid(CaptainAmerica))
    {
        name[0] = 'C';
        name[1] = 'A';
        out.write(name, sizeof(name));
    }

    if (typeid(*hero) == typeid(CaptainSpider))
    {
        name[0] = 'C';
        name[1] = 'S';
        out.write(name, sizeof(name));
    }

}
//----------------------------------------------------------------------------------------------------------------------
void Avengers::save(ofstream& out) const
{
    out.write((char*)&_numSuperHeros, sizeof(_numSuperHeros));
    for (int i = 0; i < _numSuperHeros; i++)
    {
        saveType(out, _superHeros[i]);
        _superHeros[i]->save(out);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Avengers::load(ifstream& in)
{
    in.read((char*)&_numSuperHeros, sizeof(_numSuperHeros));
    _superHeros = new SuperHero*[_numSuperHeros];
    for (int i = 0; i < _numSuperHeros; i++)
    {
        char type[2];
        in.read((char*)&type, sizeof(type));

        if (strncmp(type, "SH", 2) == 0)
        {
            _superHeros[i] = new SuperHero;


        }

        if (strncmp(type, "AB", 2) == 0)
        {
            _superHeros[i] = new AnimalBasedSuperHero;


        }

        if (strncmp(type, "PB", 2) == 0)
        {
            _superHeros[i] = new ProfessionBasedSuperHero;


        }

        if (strncmp(type, "SP", 2) == 0)
        {
            _superHeros[i] = new Spiderman;


        }

        if (strncmp(type, "CA", 2) == 0)
        {
            _superHeros[i] = new CaptainAmerica;


        }

        if (strncmp(type, "CS", 2) == 0)
        {
            _superHeros[i] = new CaptainSpider;

        }

        _superHeros[i]->load(in);

    }

}
//----------------------------------------------------------------------------------------------------------------------


void Avengers::setSuperHeros(SuperHero** superHeros, int size)
{
    _numSuperHeros = size;
    _superHeros = superHeros;

}
//----------------------------------------------------------------------------------------------------------------------
SuperHero** Avengers::getSuperHeros() const
{
    return _superHeros;
}
//----------------------------------------------------------------------------------------------------------------------
