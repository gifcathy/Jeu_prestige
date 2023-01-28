// Cathy Erwan (Nolan)
//Groupr H7

#include "Jeu.h"
#include "Carte.h"
#include "Joueur.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// constructeur
Jeu::Jeu(int modeJeu) {

  if (modeJeu == 1) {
    string nomJoueur1;
    string nomJoueur2;

    cout << "Nom du premier joueur :" << endl;
    cin >> nomJoueur1;
    _joueur1 = Joueur(nomJoueur1);

    cout << "Nom du deuxième joueur :" << endl;
    cin >> nomJoueur2;
    _joueur2 = Joueur(nomJoueur2);

  } else {
    string nomJoueur;

    cout << "Nom du joueur :" << endl;
    cin >> nomJoueur;
    _joueur1 = Joueur(nomJoueur);
    _joueur2 = Joueur("IA");
  }
  _reserve = {};
}

// constructeur
Jeu::Jeu(Joueur j1, Joueur j2) {
  _joueur1 = j1;
  _joueur2 = j2;
}

// constructeur
 Jeu::Jeu(const vector<Carte> &carte, Joueur j1, Joueur j2) {
  _reserve = carte;
  _joueur1 = j1;
  _joueur2 = j2;
}

//afficher la reserve
void Jeu::reserveAffiche() {
  for (int i = 0; i < _reserve.size(); i++) {
    _reserve[i].afficheCourt();
  }
}

// savoir si la partie et fini et renvoie en paramettre le vainqueur
bool Jeu::fini(Joueur &vainqueur) {
  bool fini;
  if (_joueur1.pileVide() || _joueur2.pileVide()) {
    if (_joueur1.sonPrestige() > _joueur2.sonPrestige()) {
      vainqueur = _joueur1;
    } else if (_joueur1.sonPrestige() < _joueur2.sonPrestige()) {
      vainqueur = _joueur2;
    } else {
      cout << "Il n'y a pas de vainqueur entre " << _joueur1.sonNom() << " et "
           << _joueur2.sonNom() << ", ils sont à égalités" << endl;
    }
    fini = true;
  } else if ((_joueur1.ToujoursEnJeu() == 0) ||
             (_joueur2.ToujoursEnJeu() == 0)) {
    if (_joueur1.ToujoursEnJeu() == 0) {
      vainqueur = _joueur2;
    } else {
      vainqueur = _joueur1;
    }
    fini = true;
  } else {
    fini = false;
  }
  return fini;
}

// remplie la réserve a partir d'un fichier
void Jeu::rempliReserve(const string &nomFichier) {
  // Ouvrez le fichier en lecture
  ifstream Fichier(nomFichier);

  // Vérifiez si le fichier a pu être ouvert
  if (Fichier.is_open()) {
    // Déclarez une variable pour stocker chaque ligne lue
    string ligne;

    // Utilisez getline pour lire chaque ligne du fichier
    // jusqu'à ce que la fin du fichier soit atteinte
    while (getline(Fichier, ligne)) {
      // Ignorez les lignes vides
      if (ligne.empty()) {
        continue;
      }
      // Créez une nouvelle carte
      Carte maCarte;
      // Remplissez la carte avec les données de la ligne du fichier
      maCarte.remplir(ligne);
      // Affichez les informations de la carte sur la console
      _reserve.push_back(maCarte);
    }

    // Triez le vecteur de cartes par ordre alphabétique 
    sort(_reserve.begin(), _reserve.end(), comparaisonDeCartes);

    // Fermez le fichier
    Fichier.close();
  }

  else {
    // Affichez un message d'erreur si le fichier n'a pas pu être ouvert
    cout << "Impossible d'ouvrir le fichier." << endl;
  }
}

// fait jouer une carte
void Jeu::JouerCarte() { _joueur1.jouentUneCarte(_joueur2); }

// indique si la partie et fini
bool Jeu::PartieFini() const {
  bool fin = (!_joueur1.ToujoursEnJeu() || !_joueur2.ToujoursEnJeu() ||
              _joueur1.pileVide() || _joueur2.pileVide());
  return fin;
}

// renvoie par le biais d'un entier le vainqueur
int Jeu::Vainqueur() const {
  int numV = 2;

  // si la partie est fini
  if (PartieFini() == 1) {
    // si c'est parce que un des joueurs n'a plus de point de prestige
    if (!_joueur1.ToujoursEnJeu() || !_joueur2.ToujoursEnJeu()) {
      // si c'est parce que les 2 joureur n'ont plus de point de prestige
      if (!_joueur1.ToujoursEnJeu() && !_joueur2.ToujoursEnJeu()) {
        numV = 0;
      }
      // si c'est parce que le joureur1 n'a plus de point de prestige (joueur2
      // gagnant donc -1)
      else if (!_joueur1.ToujoursEnJeu()) {
        numV = -1;
      }
      // si c'est parce que le joureur2 n'a plus de point de prestige (joueur1
      // gagnant donc 1)
      else {
        numV = 1;
      }
    }
    // si c'est parce que les joureur n'on plus de carte
    else if (_joueur1.pileVide() || _joueur2.pileVide()) {
      // si le joueur2 a plus de point de prestige (joueur2 gagnant donc -1)
      if (_joueur1.sonPrestige() < _joueur2.sonPrestige()) {
        numV = -1;
      }
      // si le joueur1 a plus de point de prestige (joueur gagnant donc 1)
      if (_joueur1.sonPrestige() > _joueur2.sonPrestige()) {
        numV = 1;
      } else {
        numV = 0;
      }
    }
  }
  // si la partie n'est pas fini
  else {
    numV = 2;
  }

  return numV;
}

// retourne la réserve
vector<Carte> &Jeu::GetReserve() { return _reserve; }
