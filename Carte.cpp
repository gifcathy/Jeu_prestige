// Cathy Erwan (Nolan)
//Groupr H7

#include "Carte.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// constructeur vide
Carte::Carte() {
  _nom = "MainsNues";
  _attaque = 1;
  _defense = 1;
  _magie = 1;
}

// constructeur
Carte::Carte(const string &nom, int attaque, int defense, int magie) {
  _nom = nom;
  _attaque = attaque;
  _defense = defense;
  _magie = magie;
}

// constructeur
// --pour fonction membre remplir--
Carte::Carte(ifstream &entrer) {
  getline(entrer, _nom);
  entrer >> _attaque >> _defense >> _magie;
}

Carte::~Carte() {}

// affichage long carte
void Carte::afficheLong() const {
  string etoile = "***************";
  cout << etoile << endl;
  cout << "Nom : " << _nom << endl;
  cout << "Attaque : " << _attaque << endl;
  cout << "Defense : " << _defense << endl;
  cout << "Magie : " << _magie << endl;
  cout << etoile << endl;
}

// affichage court carte
void Carte::afficheCourt() const {
  cout << _nom << " [ " << _attaque << " ; " << _defense << " ; " << _magie
       << " ]" << endl;
}

// degat physique carte
int Carte::degatPhysique(const Carte &c) const {

  int attaqueSubit = 0;

  if (_attaque != c._attaque) {
    if (_attaque > c._attaque) {
      if (_attaque >= c._defense) {
        attaqueSubit = -(_attaque - c._defense);
      } else {
        attaqueSubit = 0;
      }
    }

    else {
      if (c._attaque >= _defense) {
        attaqueSubit = c._attaque - _defense;
      } else {
        attaqueSubit = 0;
      }
    }
  } else {
    attaqueSubit = 0;
  }
  return attaqueSubit;
}

// degat magique carte
int Carte::degatMagique(const Carte &c) const {
  int magieSubit = 0;

  if (_magie != c._magie) {
    if (_magie > c._magie) {
      magieSubit = -(_magie - c._magie);
    }

    else {
      magieSubit = c._magie - _magie;
    }
  }

  else {
    magieSubit = 0;
  }
  return magieSubit;
}

// remplir une carte par rapport a une ligne du fichier et qui remplit une carte
// avec les valeurs stockée dans la ligne du fichier
void Carte::remplir(const string &ligne) {
  // Déclarez une variable stringstream pour séparer chaque mot de la ligne
  stringstream ss(ligne);

  // Déclarez des variables pour stocker chaque mot
  string mot1, mot2, mot3, mot4;
  getline(ss, mot1, ',');
  getline(ss, mot2, ',');
  getline(ss, mot3, ',');
  getline(ss, mot4);

  // Utilisez stringstream pour lire chaque mot dans la ligne
  ss >> mot1 >> mot2 >> mot3 >> mot4;

  // Convertissez les valeurs de chaque mot en entier
  _nom = mot1;

  try {
    _attaque = stoi(mot2);
    _defense = stoi(mot3);
    _magie = stoi(mot4);
  } catch (const std::exception &e) {
    // Affichez un message d'erreur si la conversion échoue
    cerr << "Erreur lors de la conversion de la chaîne en entier : " << e.what()
         << endl;
  }
}

// comparer 2 carte par rapport a leur nom pour les trie par ordre alphabetique
// --pour fonction membre rempliReserve--
bool comparaisonDeCartes(Carte &carte1, Carte &carte2) {
  return (carte1.getNom() < carte2.getNom());
}

// retourne le score d'une carte
int Carte::ScoreCarte() {
  int score = _attaque + _defense + _magie;
  return score;
}

// compare 2 carte dabord par rapport a l'attaque puis la magie et enfin la defense
// --pour fonction RangeVecteur--
bool compareCards(Carte a, Carte b) {
  if (a.getAttaque() != b.getAttaque()) {
    return a.getAttaque() > b.getAttaque();
  } else if (a.getMagie() != b.getMagie()) {
    return a.getMagie() > b.getMagie();
  } else {
    return a.getDefense() > b.getDefense();
  }
}
