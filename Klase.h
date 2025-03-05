#ifndef __Klase__H__
#define __Klase__H__
#include "Mokinys.h"
#include <list>
#include <string>

#define Str std::string

class Klase{
   private:
      
      Str pavadinimas;
      std::list< Mokinys* > sarasas;
   
   
   public:
     
      Klase(Str pavadinimas="<?>"): pavadinimas(pavadinimas){};
      ~Klase();
      Str getPavadinimas()const { return pavadinimas; }; 
      void setPavadinimas(Str pavadinimas); 

      void pridekMokini(Mokinys* mok);
      void pasalinkMokini(Mokinys* mok);
      bool arCiaMokosi(Str vardas, Str pavarde) const;

      Str getSarasas()const;

      std::string to_string() const;
      
   
};
#endif
