// Cathy Erwan (Nolan)
//Groupr H7

#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Carte.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Joueur {
    string _nom;
    int _nbPrestige = 25;
    vector<Carte> _pile;

public:
    Joueur();
    Joueur(string, int prestige=25, const vector<Carte> & carte ={});
    string sonNom() const;
    int sonPrestige() const;
    void afficheJoueur() const;
    void pileAffiche() const;
    void InitialiserPile(const vector<Carte>&);
    bool pileVide() const;
    bool ToujoursEnJeu() const;
    void carteSuiv(Carte &);
    void jouentUneCarte(Joueur &);
    void PileAleatoire(vector<Carte>&);
    void ChoixCartePile(vector<Carte>&);
    vector<Carte>& GetPile();
    
    
};

vector<Carte> TrieCroissant(vector<Carte>& carte, char);
vector<Carte> TrieDecroissant(vector<Carte>& carte, char);
vector<Carte> RangeVeteur(vector <Carte>& carte);

#endif
