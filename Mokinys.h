#ifndef __Mokinys__H__
#define __Mokinys__H__
#include <string>
#include <iostream>

#define Str std::string

class Mokinys {
private:
    Str vardas;
    Str pavarde;
    Str klase;

public:
    Mokinys(Str vardas="<?>", Str pavarde="<?>", Str klase="<?>"):
        vardas(vardas), pavarde(pavarde), klase(klase) {}
    //~Mokinys();

    // Getters
    Str getVardas() const { return vardas; }
    Str getPavarde() const { return pavarde; }
    Str getKlase() const { return klase; }

    // Setters
    void setVardas(Str vardas) { this->vardas = vardas; }
    void setPavarde(Str pavarde) { this->pavarde = pavarde; }
    void setKlase(Str klase) { this->klase = klase; }

    Str to_string() const {
        return "Mokinys: " + vardas + " " + pavarde + ", Klase: " + klase;
    }

    friend std::ostream& operator<<(std::ostream& os, const Mokinys& mok);
};

#endif