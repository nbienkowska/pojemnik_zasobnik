#ifndef POJEMNIK_H

#define POJEMNIK_H
#include <iostream>
#include <string>


class Przepelnienie;

class Pojemnik
{
  double pojemnosc;
  double objetosc;
  std::string nazwa;
  Pojemnik(const Pojemnik&) = delete;
  Pojemnik& operator=(const Pojemnik&) = delete;

public:
  Pojemnik( double objetosc );
  void dolej( double objetosc );
  double pobierz( double objetosc );
  std::string substancja();
  void substancja( std::string nazwa );
  bool min_objetosc( double ilosc );
  bool max_objetosc( double ilosc );
  friend std::ostream &operator <<(std::ostream& out, Pojemnik& poj );
  double get_pojemnosc() { return this->pojemnosc; };
  double get_objetosc() { return this->objetosc; };
  bool is_full();
  ~Pojemnik() {}
};

class Przepelnienie : public std::exception
{
  double objetosc;

public:
  Przepelnienie(double pojemnosc, double dolano, double objetosc): objetosc((dolano+objetosc) - pojemnosc)
  {
    //this->objetosc = ((dolano + objetosc)-pojemnosc);
  }
  const char * what () const noexcept { return "Przepelnienie: "; }
  double over() { return this->objetosc; }
};

struct Bad_name : public std::exception
{
  const char * what () const throw () { return "Nie mozna zmienic nazwy - pojemnik nie jest pusty!"; }
};

#endif
