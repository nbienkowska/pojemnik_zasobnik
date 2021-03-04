#include <iostream>
#include <string>
#include "Zasobnik.h"


int main()
{
  std::cout<<"//////////////TWORZENIE OBIEKTU ZASOBNIKA////////////////\n";
  Zasobnik nowy;

  nowy.dodaj(100, 4);
  nowy.dodaj(300, 5);
  nowy.usun(1);
  nowy.substancja("cola");
  std::cout<<"//////////////DOLEWANIE DO ZASOBNIKA////////////////\n";
  try
  {
    nowy.dolej(700);
  }
  catch( Przepelnienie& e)
  {
    std::cout << e.what() << e.over() << std::endl;
  }
  std::cout<<"//////////////WYPISANIE ELEMENTOW ZASOBNIKA////////////////\n";
  std::cout << nowy;
  std::cout<<"\n//////////////TESTOWANIE FUNKCJI ZASOBNIKA////////////////\n";
  nowy.substancja("sok");
  std::cout << nowy;
  std::cout<<"//////////////DALSZE DOLEWANIE////////////////\n";
  try
  {
  nowy.dolej(3000);
  }
  catch( Przepelnienie& e )
  {
    std::cout << e.what() << e.over() << std::endl;
  }
  std::cout << nowy;
  nowy.usun(2);

}
