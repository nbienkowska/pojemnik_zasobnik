#ifndef ZASOBNIK_H

#define ZASOBNIK_H
#include <iostream>
#include "Pojemnik.h"
#include "List.h"
#include <string>
#include <vector>

class Zasobnik
{
  double pojemnosc;
  double zajetosc;
  size_t l_pojemnikow;
  List* lista;
  Zasobnik(const Zasobnik&) = delete;
  Zasobnik& operator=(const Zasobnik&) = delete;
public:

  Zasobnik();
  void dodaj(double poj, size_t liczba = 1);
  double usun( size_t liczba = 1 );
  void dolej( double objetosc );
  double pobierz( double objetosc );
  void substancja( std::string nazwa );
  std::string substancja();
  bool min_objetosc( double ilosc );
  bool max_objetosc( double ilosc );
  size_t liczba_pojemnikow() { return l_pojemnikow; };
  double get_pojemnosc() { return this->pojemnosc; };
  double get_zajetosc() { return this->zajetosc; };
  friend std::ostream &operator <<(std::ostream& out, Zasobnik& z );
  ~Zasobnik();
};

struct Dekonstrukcja : public std::exception
{
  const char * what () const noexcept
  {
    return "Nie mozna usunac pojemnika - pojemnik nie jest pusty!";
  }
};

#endif
