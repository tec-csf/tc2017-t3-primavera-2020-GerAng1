#ifndef Objeto_hpp
#define Objeto_hpp

#include <iostream> // cin y cout
#include <cstdlib>  // rand() y srand()
#include <fstream>  // archivos
#include <string>   // substr()
#include <cstdio>   // printf()
#include <ctime>    // time()
#include <stack>
#include <vector>


namespace gal
{
    // type name(parameters);
    // void asterisk(std::string word, std::string &text, int i);

    // Only if there is a class
    class Objeto
    {
      // variables (todo estos son privados)

      // method declaration (definition will be made in cpp)
      public:

        // CONSTRUCTORES
        Objeto(std::string);
        Objeto(std::string, int);

        // Destructor (SOLO UNO)
        virtual ~Objeto();

        /* Comentario generico de lo que hace el metodo
        *
        * @param &valor: descripcion del parametro.
        */
        // type name(parameters);
        // void asterisk(std::string word, std::string &text, int i);


      protected:
        /* Comentario generico de lo que hace el metodo
        *
        * @param &valor: descripcion del parametro.
        */
        // type name(parameters);
        // void asterisk(std::string word, std::string &text, int i);

      private:
        /* Comentario generico de lo que hace el metodo
        *
        * @param &valor: descripcion del parametro.
        */
        // type name(parameters);
        // void asterisk(std::string, std::string &, int i);
    };

}
#endif /* Objeto_hpp */
