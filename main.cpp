#include <iostream>
#include <exception>
#include <string>
#include "Pojemnik.h"


int main()
{
    std::cout<<"//////////////TWORZENIE OBIEKTU POJEMNIKA////////////////\n";
    Pojemnik a(100);
    std::cout<<"//////////////DOLANIE DO POJEMNIKA////////////////\n";
    std::cout << a << std::endl;
    try
    {
      a.dolej(50);
    }
    catch(Przepelnienie &x)
    {
      std::cout << x.what() << x.over();
    }
    std::cout << a << std::endl;
    std::cout<<"////////////// PROBA ZMIANA NAZWY////////////////\n";
    a.substancja("sok");


    std::cout << a << std::endl;

    std::cout << a.pobierz(70) << std::endl;


    a.substancja("sok");

    std::cout << a << std::endl;
    try
    {
      a.dolej(120);
    }
    catch(Przepelnienie &x)
    {
      std::cout << x.what() << x.over() << std::endl;
    }

    std::cout<<"////////////// WYPISANIE NAZWY////////////////\n";
    std::cout << a.substancja() << std::endl;


}
