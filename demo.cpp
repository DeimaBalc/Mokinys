#include <iostream>
#include <cassert>
#include "Klase.h"
#include "Mokinys.h"

void printHeader(const std::string& header) {
    std::cout << "\n=== " << header << " ===\n";
}

void testMokinys() {
    printHeader("Testing Mokinys Class");
    
    // Test constructor and getters
    Mokinys mok1("Jonas", "Jonaitis", "8A");
    std::cout << "Created student: " << mok1 << "\n";
    assert(mok1.getVardas() == "Jonas");
    assert(mok1.getPavarde() == "Jonaitis");
    assert(mok1.getKlase() == "8A");
    std::cout << "Constructor test passed\n";
    
    // Test setters
    mok1.setVardas("Petras");
    mok1.setPavarde("Petraitis");
    mok1.setKlase("9B");
    std::cout << "Modified student: " << mok1 << "\n";
    assert(mok1.getVardas() == "Petras");
    assert(mok1.getPavarde() == "Petraitis");
    assert(mok1.getKlase() == "9B");
    std::cout << "Setters test passed\n";
    
    // Test default constructor
    Mokinys mok2;
    std::cout << "Default student: " << mok2 << "\n";
    assert(mok2.getVardas() == "<?>");
    assert(mok2.getPavarde() == "<?>");
    assert(mok2.getKlase() == "<?>");
    std::cout << "Default constructor test passed\n";
}

void testKlase() {
    printHeader("Testing Klase Class");
    
    // Create class and test getPavadinimas
    Klase klase("10A");
    std::cout << "Created class: " << klase.getPavadinimas() << "\n";
    assert(klase.getPavadinimas() == "10A");
    std::cout << "Class creation test passed\n";
    
    // Create and add students
    Mokinys mok1 = Mokinys("Tomas", "Tomauskas");
    Mokinys mok2 = Mokinys("Ruta", "Rutauskaite");
    Mokinys mok3 = Mokinys("Matas", "Matauskas");
    
    // Test pridekMokini and arCiaMokosi
    klase.pridekMokini(&mok1);
    klase.pridekMokini(&mok2);
    klase.pridekMokini(&mok3);
    std::cout << "\nAfter adding students:\n" << klase.getSarasas();
    
    assert(klase.arCiaMokosi("Tomas", "Tomauskas"));
    assert(klase.arCiaMokosi("Ruta", "Rutauskaite"));
    assert(!klase.arCiaMokosi("Jonas", "Jonaitis"));
    std::cout << "Student addition and search test passed\n";
    
    // Test setPavadinimas
    klase.setPavadinimas("11A");
    std::cout << "\nAfter changing class to 11A:\n" << klase.getSarasas();
    assert(klase.getPavadinimas() == "11A");
    assert(mok1.getKlase() == "11A");
    assert(mok2.getKlase() == "11A");
    assert(mok3.getKlase() == "11A");
    std::cout << "Class name change test passed\n";
    
    // Test pasalinkMokini
    klase.pasalinkMokini(&mok2);
    std::cout << "\nAfter removing Ruta:\n" << klase.getSarasas();
    assert(!klase.arCiaMokosi("Ruta", "Rutauskaite"));
    assert(klase.arCiaMokosi("Tomas", "Tomauskas"));
    std::cout << "Student removal test passed\n";
    
    // Test multiple operations
    Mokinys* mok4 = new Mokinys("Elena", "Elenauskaite", "11A");
    klase.pridekMokini(mok4);
    std::cout << "\nAfter adding Elena:\n" << klase.getSarasas();
    assert(klase.arCiaMokosi("Elena", "Elenauskaite"));
    
    klase.setPavadinimas("12A");
    std::cout << "\nAfter final class change to 12A:\n" << klase.getSarasas();
    assert(mok4->getKlase() == "12A");
    std::cout << "Multiple operations test passed\n";
}

int main() {
    std::cout << "Starting Comprehensive Tests\n";
    std::cout << "============================\n";
    
    testMokinys();
    testKlase();
    
    std::cout << "\nAll Tests Passed Successfully!\n";
    std::cout << "============================\n";
    return 0;
}