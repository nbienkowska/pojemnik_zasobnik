#include <iostream>
#include "Pojemnik.h"
#include <string>
#include <exception>


Pojemnik::Pojemnik( double objetosc ):pojemnosc(objetosc), objetosc(0) {}

bool Pojemnik::max_objetosc( double ilosc )
{
  if((this->objetosc + ilosc)<=pojemnosc) return true;

  else return false;
}

std::string Pojemnik::substancja()
{
  return nazwa;
}

bool Pojemnik::min_objetosc( double ilosc )
{
  if(this->objetosc >= ilosc) return true;

  else return false;
}

double Pojemnik::pobierz( double objetosc )
{
  double obj = 0;
  if(min_objetosc(objetosc))
  {
    this->objetosc-=objetosc;
    return objetosc;
  }

  else
  {
    obj = this->objetosc;
    this->objetosc = 0;
    return obj;
  }
}

std::ostream& operator <<(std::ostream& out, Pojemnik& poj )
{
  out << "Nazwa: " << poj.nazwa << "\tPojemnosc: " << poj.pojemnosc << "\tAktualna objetosc: " << poj.objetosc << std::endl;
  return out;
}

void Pojemnik::dolej( double objetosc )
{

    if(max_objetosc(objetosc))
    {
      this->objetosc+=objetosc;
    }

    else
    {
      double obj1 = this->objetosc;
      this->objetosc = pojemnosc;
      throw Przepelnienie(pojemnosc, objetosc, obj1);
    }

}

void Pojemnik::substancja( std::string nazwa )
{
  try
  {
    if(objetosc == 0) this->nazwa = nazwa;
    else throw Bad_name();
  }
  catch(Bad_name& x)
  {
    std::cout << x.what() << std::endl;
  }
}

bool Pojemnik::is_full()
{
  if(objetosc!=0 && pojemnosc==objetosc) return true;
  else return false;
}
