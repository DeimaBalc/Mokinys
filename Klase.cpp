#include "Klase.h"

void Klase::setPavadinimas(Str pavadinimas){

    this->pavadinimas = pavadinimas;
    // reikia neužmiršti dar pakeisti ir mokinio klasės lauką
    for(auto it = this->sarasas.begin(); it != this->sarasas.end(); ++it) {
       (*it)->setKlase(pavadinimas); 
    }

}

void Klase::pridekMokini(Mokinys* mok){

        mok->setKlase(this->pavadinimas);
        sarasas.push_back(mok);

}

void Klase::pasalinkMokini(Mokinys* mok){

    for(auto it = this->sarasas.begin(); it != this->sarasas.end(); ) {

        if(*it == mok){
           
            std::cout << (*it)->getPavarde() << std::endl;
            it = sarasas.erase(it); 
           

        }
        else 
           ++it;
    }
}

bool Klase::arCiaMokosi(std::string vardas, std::string pavarde) const {
    for (const auto& mokinys : sarasas) {
        if (mokinys->getVardas() == vardas && mokinys->getPavarde() == pavarde) {
            return true;
        }
    }
    return false;
}

Str Klase::getSarasas() const {
    Str rezultatas = "";
    for (const auto& mokinys : sarasas) {
        rezultatas += mokinys->to_string() + "\n";
    }
    return rezultatas;
}

Klase::~Klase() {
    for (auto* mok : sarasas) {
       delete mok;
       std::cout << "Deletes mokinys" << std::endl;
    }
 }

std::string Klase::to_string() const {
    return "Klase: " + pavadinimas + "\nMokiniai:\n" + getSarasas();
}