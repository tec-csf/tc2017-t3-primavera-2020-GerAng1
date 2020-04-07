#include <iostream> // cin y cout
#include <cstdlib>  // rand() y srand()
#include <fstream>  // archivos
#include <string>   // substr()
#include <cstdio>   // printf()
#include <ctime>    // time()
#include <stack>
#include <vector>

#include "Objeto.hpp"

namespace gal
{

    // Aquí van las funciones de hpp, pero ya con código
    //CONSTRUCTORES
    Objeto::Objeto(std::string new_name)
      : name(new_name) { }

    Objeto::Objeto(std::string new_name, int val);
      : name(new_name), var(val) { }

    // Destructor
    Objeto::~Objeto() {
      std::cout << "Goodbye " << title; // Optional
    }

    type Objeto::method(arguments) {
      /* code */
    }

}
