#include <iostream>
#include "Pojemnik.h"
#include "List.h"
#include "Zasobnik.h"
#include <string>
#include <vector>

using namespace std;

Zasobnik::Zasobnik()
{
  lista = new List;
  pojemnosc = 0;
  zajetosc = 0;
  l_pojemnikow = 0;
}

void Zasobnik::dodaj(double poj, size_t liczba)
{
  for(size_t i=0; i<liczba; i++)
  {
   lista->Add(poj);
   pojemnosc+=poj;
   l_pojemnikow++;
  }

}
 double Zasobnik::usun( size_t liczba )
 {
   double odjeta_obj = 0;
   Elem* pointer = lista->get_head()->previous;

       try
       {
           for(int i=liczba; i>0; i--)
            {
                if((pointer->value.get_objetosc()) == 0)
                {
                  odjeta_obj+=pointer->value.get_pojemnosc();
                  this->pojemnosc-=pointer->value.get_pojemnosc();
                  l_pojemnikow--;
                  pointer = pointer->previous;
                  lista->Delete();

                }
                else throw Dekonstrukcja();
              }
            }
        catch(Dekonstrukcja& x)
        {
          cout << x.what() <<  std::endl;
        }

        return odjeta_obj;

 }

void Zasobnik::dolej( double objetosc )
{
  Elem* pointer = lista->get_head();
  int x = 0;

      for(int i=0; i<lista->get_size(); i++)
      {
        try
        {
            if(pointer->value.is_full())
            {
              pointer = pointer->next;
              continue;
            }

            pointer->value.dolej( objetosc );
            this->zajetosc += objetosc;
            objetosc = 0;

        }

        catch( Przepelnienie &e )
        {
          cout << e.what() << e.over() << std::endl;
          this->zajetosc += (objetosc - e.over());
          objetosc = e.over();
          pointer = pointer->next;
        }

      }

      if(objetosc!=0)
        x = objetosc;

      if(!max_objetosc(x))
      {
           throw Przepelnienie(this->pojemnosc, x, this->zajetosc);
      }

}


bool Zasobnik::max_objetosc( double ilosc )
{
  if((this->zajetosc+ilosc) <= this->pojemnosc) return true;

  else return false;
}

bool Zasobnik::min_objetosc( double ilosc )
{
  if(this->zajetosc >= ilosc) return true;

  else return false;
}

double Zasobnik::pobierz( double objetosc )
{
  Elem* pointer = lista->get_head()->previous;
  double pobrano = 0;
  for(int i=lista->get_size(); i>0; i--)
  {
    int x = pointer->value.pobierz( objetosc );
    objetosc -= x;
    this->zajetosc-=x;
    pobrano += x;
    pointer = pointer->previous;
  }

  return pobrano;
}

void Zasobnik::substancja( std::string nazwa )
{
  Elem* pointer = lista->get_head();
  try
  {
    if(pointer->value.get_objetosc() == 0) pointer->value.substancja(nazwa);
    else throw Bad_name();
  }
  catch(Bad_name& x)
  {
    cout << x.what() << std::endl;
  }

}

std::string Zasobnik::substancja()
{
  return lista->get_head()->value.substancja();
}


std::ostream &operator <<(std::ostream& out, Zasobnik& z )
{
  Elem* pointer = z.lista->get_head();
  out << "Liczba pojemnikow: " << z.liczba_pojemnikow() << std::endl;
  out << "Zajetosc: " << z.get_zajetosc() << std::endl;
  out << "Pojemnosc: " << z.get_pojemnosc() << std::endl;

  for(int i=0; i < z.lista->get_size(); i++)
  {
    out << "Nazwa: " << pointer->value.substancja() << "\t";
    out << "Pojemnosc: " << pointer->value.get_pojemnosc() << "\t";
    out << "Aktualna objetosc: " << pointer->value.get_objetosc() << std::endl;
    pointer = pointer->next;
  }

  return out;
}

Zasobnik::~Zasobnik()
{
  delete lista;
}
