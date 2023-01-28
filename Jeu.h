// Cathy Erwan (Nolan)
//Groupr H7

#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "Carte.h"
#include "Joueur.h"

#include <string>
#include <vector>

using namespace std;

class Jeu {
    vector<Carte> _reserve;
    Joueur _joueur1;
    Joueur _joueur2;

public:
    Jeu(int);
    Jeu(Joueur, Joueur);
    Jeu(const vector<Carte> &, Joueur, Joueur);
    void reserveAffiche();
    bool fini(Joueur &vainqueur);
    void rempliReserve(const string&);
    void JouerCarte();
    bool PartieFini()const;
    int Vainqueur()const;
    vector<Carte>& GetReserve();
    
    // retourne le joueur1
    Joueur& getJ1() { return _joueur1; }
    // retourne le joueur2
    Joueur& getJ2() { return _joueur2; }
};

#endif
