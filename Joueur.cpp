// Cathy Erwan (Nolan)
//Groupr H7

#include "Joueur.h"

using namespace std;

// constructeur vide
Joueur::Joueur() {
  _nom = "Yugi";
  Carte c1("MainDroite", 1, 0, 0);
  Carte c2("MainGauche", 0, 1, 0);
  Carte c3("Tête", 1, -2, 0);
  Carte c4("Bouche", 1, -1, 2);
  Carte c5("Genou", 2, 0, 0);
  _pile = {c1, c2, c3, c4, c5};
}

// constructeur
Joueur::Joueur(string nom, int Prestige, const vector<Carte> &carte) {
  _nom = nom;
  _nbPrestige = Prestige;
  _pile = carte;
}

// retourne le nom du joueur
string Joueur::sonNom() const { return _nom; }

// retourne le prestige du joueur
int Joueur::sonPrestige() const { return _nbPrestige; }

// affiche un joueur
void Joueur::afficheJoueur() const {
  cout << "Le joueur " << _nom << " a " << _nbPrestige
       << " points de prestige, il reste " << _pile.size()
       << " cartes dans sa pile." << endl;
}

// affiche la pile du joueur
void Joueur::pileAffiche() const {
  for (int i = 0; i < _pile.size(); i++) {
    _pile[i].afficheCourt();
  }
}

// initialise la pile du joueur avec les 20 premiere cate du vecteur passer en parametre
void Joueur::InitialiserPile(const vector<Carte> &carte) {
  for (int i = 0; i < 20; i++) {
    _pile.push_back(carte[i]);
  }
}

// indique si la pile du joueur est vide
bool Joueur::pileVide() const {
  bool vide = (_pile.size() == 0);
  return vide;
}

// indique si le joueur a un prestige positif
bool Joueur::ToujoursEnJeu() const {
  bool prestige = (_nbPrestige > 0);
  return prestige;
}

// fait passer a la carte suivante
void Joueur::carteSuiv(Carte &carte) {
  if (pileVide()) {
    throw(invalid_argument("Il n'y a plus de carte"));
  } else {
    carte = _pile[0];
    for (int i = 0; i < _pile.size() - 1; i++) {
      _pile[i] = _pile[i + 1];
    }
    _pile.pop_back();
  }
}

// fait jouer la carte d'un joueur contre celle d'un autre joueur et calcul les point de prestige
void Joueur::jouentUneCarte(Joueur &j) {
  if (pileVide() || j.pileVide()) {
    throw(invalid_argument("Un joueur n'a plus de carte"));
  } else {
    int physique = _pile[0].degatPhysique(j._pile[0]);
    int magie = _pile[0].degatMagique(j._pile[0]);

    if (physique > 0) {
      _nbPrestige = _nbPrestige - physique;
    } else {
      j._nbPrestige = j._nbPrestige + physique;
    }

    if (magie > 0) {
      _nbPrestige = _nbPrestige - magie;
    } else {
      j._nbPrestige = j._nbPrestige + magie;
    }
    if (_pile.size() == 0 || j._pile.size() == 0) {
      throw(invalid_argument("Un joueur n'a plus de carte"));
    }
  }
  Carte c;
  carteSuiv(c);
  j.carteSuiv(c);
}

// initialise la pile aléatoirement avec le vecteur placé en paramettre
void Joueur::PileAleatoire(vector<Carte> &carte) {
  random_device rd;
  mt19937 g(rd());

  shuffle(carte.begin(), carte.end(), g);
  for (int i = 0; i < 20; i++) {
    _pile.push_back(carte[i]);
  }
}

// trie une un vecteur par rappot à l'attaque, la defense, la magie et le score dans l'ordre croissant
vector<Carte> TrieCroissant(vector<Carte> &carte, char type) { // trie bulle
  int fin = carte.size();
  int finTemp = 0;
  Carte c;
  int i = 0;
  while (fin > 1) {
    finTemp = 0;
    for (i = 1; i < carte.size(); i++) {
      switch (type) {
      case 'a':
        if (carte[i - 1].getAttaque() > carte[i].getAttaque()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;

      case 'd':
        if (carte[i - 1].getDefense() > carte[i].getDefense()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;

      case 'm':
        if (carte[i - 1].getMagie() > carte[i].getMagie()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;
      case 's':
        if (carte[i - 1].ScoreCarte() < carte[i].ScoreCarte()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;

      default:
        throw(invalid_argument("erreur : sur le type pour le trie"));
        break;
      }
    }
    fin = finTemp;
  }
  return carte;
}

// trie une un vecteur par rappot à l'attaque, la defense, la magie et le score dans l'ordre décroissant
vector<Carte> TrieDecroissant(vector<Carte> &carte, char type) { // trie bulle
  int fin = carte.size();
  int finTemp = 0;
  Carte c;
  int i = 0;
  while (fin > 1) {
    finTemp = 0;
    for (i = 1; i < carte.size(); i++) {
      switch (type) {
      case 'a':
        if (carte[i - 1].getAttaque() < carte[i].getAttaque()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;

      case 'd':
        if (carte[i - 1].getDefense() < carte[i].getDefense()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;

      case 'm':
        if (carte[i - 1].getMagie() < carte[i].getMagie()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;

      case 's':
        if (carte[i - 1].ScoreCarte() < carte[i].ScoreCarte()) {
          c = carte[i];
          carte[i] = carte[i - 1];
          carte[i - 1] = c;
          finTemp = i;
        }
        break;

      default:
        throw(invalid_argument("erreur : sur le type pour le trie"));
        break;
      }
    }
    fin = finTemp;
  }
  return carte;
}

// range le vecteur par rapport a l'attaque puis la magie et enfin la defense
vector<Carte> RangeVeteur(vector<Carte> &carte) {
  sort(carte.begin(), carte.end(), compareCards);
  return carte;
}

// retourne la pile du joueur
vector<Carte> &Joueur::GetPile() { return _pile; }

// fait choisir au joueur les carte qu'il veut par rapport a un vecteur
void Joueur::ChoixCartePile(vector<Carte> &carte) {
  
  string nomCarte;
  bool trouver = false;
  int i = 0;
  int cpt = 0;
  cout << "Vous devez choisir 20 carte de la réserve (ecrivez son nom et "
          "faites attention a l'écriture)."
       << endl;
  while (_pile.size() < 20) {
    cpt++;
    cout << "carte " << cpt << " : ";
    cin >> nomCarte;
    while (!trouver && i < carte.size()) {
      trouver = (nomCarte == carte[i].getNom());
      i++;
    }
    if (trouver) {
      _pile.push_back(carte[i - 1]);

      bool existe = false;
      int j = 0;
      while (!existe && j < _pile.size() - 1) {
        existe = (nomCarte == _pile[j].getNom());
        j++;
      }
      if (existe) {
        _pile.pop_back();
        cpt--;
        cout << "\033[1;31mcarte deja utilisee \033[0m" << endl;
      }
    } else {
      cout << "\033[1;31mAttention a votre ecriture, votre carte n'a pas ete "
              "prise en compte \033[0m"
           << endl;
      cpt--;
    }
    i = 0;
    trouver = false;
  }
}
