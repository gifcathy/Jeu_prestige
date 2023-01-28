// Cathy Erwan (Nolan)
//Groupr H7

#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <string>

using namespace std;

class Carte {
    string _nom;
    int _attaque;
    int _defense;
    int _magie;

public:
    Carte();
    Carte(const string&, int, int, int);
    Carte(ifstream& entrer);
    ~Carte();
    void afficheLong() const;
    void afficheCourt() const;
    int degatPhysique(const Carte &) const;
    int degatMagique(const Carte &) const;
    void remplir(const string & ligne);
    
    string getNom() { return _nom; }
    int getAttaque() { return _attaque; }
    int getDefense() { return _defense; }
    int getMagie() { return _magie; }
    
    int ScoreCarte();
};

bool comparaisonDeCartes( Carte & carte1,  Carte & carte2);
bool compareCards(Carte a, Carte b);

#endif
