// Cathy Erwan (Nolan)
//Groupr H7

#include "Carte.h"
#include "Jeu.h"
#include "Joueur.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

  char rejouer = 'O';
  while (rejouer == 'O' || rejouer == 'o') {

    int modeJeu = 0;
    // choix du mode
    cout << "Vous avez au choix 2 mode de jeu : " << endl;
    cout << "Un mode 2 joueurs humains et un mode humain contre IA " << endl;
    cout << "A quelle mode voulez-vous jouer ?" << endl;
    cout << "1 - Mode deux joueurs" << endl;
    cout << "2 - Mode solo" << endl;
    cout << "Indiquez votre choix (1 ou 2) : ";
    cin >> modeJeu;
    // redemander tant que mode different de 1 ou 2
    while ((modeJeu != 1) && (modeJeu != 2)) {
      cout << "errreur veillez re saisir votre mode de jeu : " << endl;
      // pour pas que ça face une boucle infini si on met un autre caractere
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> modeJeu;
    }

    // creation partie
    Jeu Partie(modeJeu);
    // remplir la reserve avec le fichier carte.tkt
    Partie.rempliReserve("cartes.txt");

    cout << endl;
    cout << "----------" << endl;
    cout << endl;
    // affiche regle
    cout << "Regles du jeu :" << endl;
    cout << "Ce jeu se joue à 2 ou tout seul contre l'ordinateur." << endl;
    cout << "Chaqu'un commence avec 25 point de prestige et une pile de 20 "
            "cartes sélectionnées à partir d'une réserve identique."
         << endl;
    cout
        << "Chaque carte a trois statistiques : une valeur d’attaque physique, "
           "une valeur de puissance magique et une valeur de défense physique."
        << endl;
    cout << "L’objectif est de réduire les points de prestige de son "
            "adversaire et de défendre les siens."
         << endl;
    cout << "Le gagnant est le premier a faire perdre tout les points de "
            "prestige de sont adversaire ou d'en avoir le plus si il n'on plus "
            "de carte a jouer."
         << endl;

    cout << endl;
    cout << "----------" << endl;
    cout << endl;

    // affiche reserve
    cout << "Voici les carte disponibles dans la réserve : " << endl;
    Partie.reserveAffiche();

    cout << endl;
    cout << "----------" << endl;
    cout << endl;

    /// --- mode 2 joueurs
    if (modeJeu == 1) {

      // Pour joueur1
      // affiche nom + demande choix carte
      cout << "\033[1;35m" << Partie.getJ1().sonNom() << "\033[0m"
           << " : " << endl;
      Partie.getJ1().ChoixCartePile(Partie.GetReserve());

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      char typeJ1;
      int statJ1;

      // demande la strategie
      cout << "\033[1;35m" << Partie.getJ1().sonNom() << "\033[0m"
           << " : " << endl;
      cout << "Quel strategie voulez vous adopter pour constituer votre pile ??"
           << endl;
      cout << "a - Par rapport a l'attaque" << endl;
      cout << "m - Par rapport a la magie" << endl;
      cout << "d - Par rapport a la defence" << endl;
      cout << "s - Par rapport au score de la carte (somme attaque, magie et "
              "defence)"
           << endl;
      cout << "r - Ne pas changer l'odre des carte (garder l'odre comme choisi "
              "avant)"
           << endl;
      cout << "Indiquez votre choix (a, m, d, s ou r) : ";
      cin >> typeJ1;
      cout << endl;
      while (typeJ1 != 'a' && typeJ1 != 'm' && typeJ1 != 'd' && typeJ1 != 's' &&
             typeJ1 != 'r') {
        cout << "\033[1;31merreur veuillez reessayer \033[0m" << endl;
        cout << "Indiquez votre choix (a, m, d, s ou r) : ";
        cin >> typeJ1;
        cout << endl;
      }

      if (typeJ1 != 'r') {
        cout << "Voulez vous que ca soit renger par ordre : " << endl;
        cout << "1 - Croissant" << endl;
        cout << "2 - Décroissant" << endl;
        cout << "Indiquez votre choix (1 ou 2) : ";
        cin >> statJ1;
        cout << endl;
        while (statJ1 != 1 && statJ1 != 2) {
          cout << "\033[1;31merreur veuillez reessayer \033[0m" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Indiquez votre choix (1 ou 2) : ";
          cin >> statJ1;
        }

        // trie la pile en fonction de la strategie
        if (statJ1 == 1) {
          TrieCroissant(Partie.getJ1().GetPile(), typeJ1);
        } else {
          if (typeJ1 == 'a') {
            RangeVeteur(Partie.getJ1().GetPile());
          } else {
            TrieDecroissant(Partie.getJ1().GetPile(), typeJ1);
          }
        }
      }
      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      // affiche reserve
      cout << "Voici les carte disponibles dans la réserve : " << endl;
      Partie.reserveAffiche();

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      // Pour joueur2
      // affiche nom + demande choix carte
      cout << "\033[1;36m" << Partie.getJ2().sonNom() << "\033[0m"
           << " : " << endl;
      Partie.getJ2().ChoixCartePile(Partie.GetReserve());

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      char typeJ2;
      int statJ2;

      // demande la strategie
      cout << "\033[1;36m" << Partie.getJ2().sonNom() << "\033[0m"
           << " : " << endl;
      cout << "Quel strategie voulez vous adopter pour constituer votre pile ??"
           << endl;
      cout << "a - Par rapport a l'attaque" << endl;
      cout << "m - Par rapport a la magie" << endl;
      cout << "d - Par rapport a la defence" << endl;
      cout << "s - Par rapport au score de la carte (somme attaque, magie et "
              "defence)"
           << endl;
      cout << "r - Ne pas changer l'odre des carte (garder l'odre comme choisi "
              "avant)"
           << endl;
      cout << "Indiquez votre choix (a, m, d, s ou r) : ";
      cin >> typeJ2;
      cout << endl;
      while (typeJ2 != 'a' && typeJ2 != 'm' && typeJ2 != 'd' && typeJ2 != 's' &&
             typeJ2 != 'r') {
        cout << "\033[1;31merreur veuillez reessayer \033[0m" << endl;
        cout << "Indiquez votre choix (a, m, d, s ou r) : ";
        cin >> typeJ2;
        cout << endl;
      }

      if (typeJ2 != 'r') {
        cout << "Voulez vous que ca soit renger par ordre : " << endl;
        cout << "1 - Croissant" << endl;
        cout << "2 - Décroissant" << endl;
        cout << "Indiquez votre choix (1 ou 2) : ";
        cin >> statJ2;
        cout << endl;
        while (statJ2 != 1 && statJ2 != 2) {
          cout << "\033[1;31merreur veuillez reessayer \033[0m" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Indiquez votre choix (1 ou 2) : ";
          cin >> statJ2;
        }

        // trie la pile en fonction de la strategie
        if (statJ2 == 1) {
          TrieCroissant(Partie.getJ2().GetPile(), typeJ2);
        } else {
          if (typeJ2 == 'a') {
            RangeVeteur(Partie.getJ2().GetPile());
          } else {
            TrieDecroissant(Partie.getJ2().GetPile(), typeJ2);
          }
        }
      }
      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      // affiche pile joueur1
      cout << "\033[1;35m" << Partie.getJ1().sonNom() << "\033[0m"
           << " : " << endl;
      Partie.getJ1().pileAffiche();

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      // affiche pile joueur2
      cout << "\033[1;36m" << Partie.getJ2().sonNom() << "\033[0m"
           << " : " << endl;
      Partie.getJ2().pileAffiche();

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      bool fin = false;
      int gagnan = 2;

      // execution de la partie
      while (fin == false) {

        Carte carteJ1 = Partie.getJ1().GetPile()[0];
        Carte carteJ2 = Partie.getJ2().GetPile()[0];

        // affiche les cartes jouees
        Partie.getJ1().jouentUneCarte(Partie.getJ2());
        cout << "\033[1;35m" << Partie.getJ1().sonNom() << "\033[0m"
             << " : " << endl;
        carteJ1.afficheCourt();
        cout << "\033[1;36m" << Partie.getJ2().sonNom() << "\033[0m"
             << " : " << endl;
        carteJ2.afficheCourt();

        cout << endl;
        cout << endl;

        int degatPhysique = carteJ1.degatPhysique(carteJ2);
        // affiche les degats physique
        cout << "Degat physique : ";
        if (degatPhysique > 0) {
          cout << "\033[1;35m" << Partie.getJ1().sonNom() << "\033[0m"
               << " : ";
          cout << -degatPhysique << endl;
        } else if (degatPhysique < 0) {
          cout << "\033[1;36m" << Partie.getJ2().sonNom() << "\033[0m"
               << " : ";
          cout << degatPhysique << endl;
        } else {
          cout << "\033[1;31mAucun \033[0m" << endl;
        }

        int degatMagique = carteJ1.degatMagique(carteJ2);
        // affiche les degats magique
        cout << "Degat Magique : ";
        if (degatMagique > 0) {
          cout << "\033[1;35m" << Partie.getJ1().sonNom() << "\033[0m"
               << " : ";
          cout << -degatMagique << endl;
        } else if (degatMagique < 0) {
          cout << "\033[1;36m" << Partie.getJ2().sonNom() << "\033[0m"
               << " : ";
          cout << degatMagique << endl;
        } else {
          cout << "\033[1;31mAucun \033[0m" << endl;
        }

        cout << endl;
        // affiche les joueur
        cout << "\033[1;35m - \033[0m";
        Partie.getJ1().afficheJoueur();
        cout << "\033[1;36m - \033[0m";
        Partie.getJ2().afficheJoueur();
        cout << endl;

        // montre si la partie est fini (0=non ; 1=oui)
        fin = Partie.PartieFini();
        cout << "Partie fini ? " << fin << endl;
        // affiche le gagnant (0=aucun ; 1 = joueur1 ; -1 = Joueur2 ; 2 = partie
        // pas fini)
        gagnan = Partie.Vainqueur();
        cout << "Vainqueur ? " << gagnan << endl;

        cout << endl;
        cout << "----------" << endl;
        cout << endl;
      }

      // affiche le gagnant
      if (gagnan == 1) {
        cout << "Bravo !! \033[1;35m" << Partie.getJ1().sonNom()
             << "\033[0m vous avez remporte la partie avec "
             << Partie.getJ1().sonPrestige() << " points de prestige." << endl;
      } else if (gagnan == -1) {
        cout << "Bravo !! \033[1;36m" << Partie.getJ2().sonNom()
             << "\033[0m vous avez remporte la partie avec "
             << Partie.getJ2().sonPrestige() << " points de prestige restant."
             << endl;
      } else {
        cout << "match nul" << endl;
      }

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

    }

    //------------------
    // --- mode solo
    else {

      Partie.getJ2().PileAleatoire(Partie.GetReserve());

      cout << "\033[1;32m" << Partie.getJ1().sonNom() << "\033[0m"
           << " : " << endl;
      Partie.getJ1().ChoixCartePile(Partie.GetReserve());

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      char type;
      int stat;

      cout << "\033[1;32m" << Partie.getJ1().sonNom() << "\033[0m"
           << " : " << endl;
      cout << "Quel strategie voulez vous adopter pour constituer votre pile ??"
           << endl;
      cout << "a - Par rapport a l'attaque" << endl;
      cout << "m - Par rapport a la magie" << endl;
      cout << "d - Par rapport a la defence" << endl;
      cout << "s - Par rapport au score de la carte (somme attaque, magie et "
              "defence)"
           << endl;
      cout << "r - Ne pas changer l'odre des carte (garder l'odre comme choisi "
              "avant)"
           << endl;
      cout << "Indiquez votre choix (a, m, d, s ou r) : ";
      cin >> type;
      cout << endl;
      while (type != 'a' && type != 'm' && type != 'd' && type != 's' &&
             type != 'r') {
        cout << "\033[1;31merreur veuillez reessayer \033[0m" << endl;
        cout << "Indiquez votre choix (a, m, d, s ou r) : ";
        cin >> type;
        cout << endl;
      }

      if (type != 'r') {
        cout << "Voulez vous que ca soit renger par ordre : " << endl;
        cout << "1 - Croissant" << endl;
        cout << "2 - Décroissant" << endl;
        cout << "Indiquez votre choix (1 ou 2) : ";
        cin >> stat;
        cout << endl;
        while (stat != 1 && stat != 2) {
          cout << "\033[1;31merreur veuillez reessayer \033[0m" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Indiquez votre choix (1 ou 2) : ";
          cin >> stat;
        }

        if (stat == 1) {
          TrieCroissant(Partie.getJ1().GetPile(), type);
        } else {
          if (type == 'a') {
            RangeVeteur(Partie.getJ1().GetPile());
          } else {
            TrieDecroissant(Partie.getJ1().GetPile(), type);
          }
        }
      }
      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      cout << "\033[1;32m" << Partie.getJ1().sonNom() << "\033[0m"
           << " : " << endl;
      Partie.getJ1().pileAffiche();

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      cout << "\033[1;33m" << Partie.getJ2().sonNom() << "\033[0m"
           << " : " << endl;
      Partie.getJ2().pileAffiche();

      cout << endl;
      cout << "----------" << endl;
      cout << endl;

      bool fin = false;
      int gagnan = 2;

      while (fin == false) {

        Carte carteJ1 = Partie.getJ1().GetPile()[0];
        Carte carteJ2 = Partie.getJ2().GetPile()[0];

        //Partie.getJ1().jouentUneCarte(Partie.getJ2());
        Partie.JouerCarte();
        cout << "\033[1;32m" << Partie.getJ1().sonNom() << "\033[0m"
             << " : " << endl;
        carteJ1.afficheCourt();
        cout << "\033[1;33m" << Partie.getJ2().sonNom() << "\033[0m"
             << " : " << endl;
        carteJ2.afficheCourt();

        cout << endl;
        cout << endl;

        int degatPhysique = carteJ1.degatPhysique(carteJ2);

        cout << "Degat physique : ";
        if (degatPhysique > 0) {
          cout << "\033[1;32m" << Partie.getJ1().sonNom() << "\033[0m"
               << " : ";
          cout << -degatPhysique << endl;
        } else if (degatPhysique < 0) {
          cout << "\033[1;33m" << Partie.getJ2().sonNom() << "\033[0m"
               << " : ";
          cout << degatPhysique << endl;
        } else {
          cout << "\033[1;31mAucun \033[0m" << endl;
        }

        int degatMagique = carteJ1.degatMagique(carteJ2);

        cout << "Degat Magique : ";
        if (degatMagique > 0) {
          cout << "\033[1;32m" << Partie.getJ1().sonNom() << "\033[0m"
               << " : ";
          cout << -degatMagique << endl;
        } else if (degatMagique < 0) {
          cout << "\033[1;33m" << Partie.getJ2().sonNom() << "\033[0m"
               << " : ";
          cout << degatMagique << endl;
        } else {
          cout << "\033[1;31mAucun \033[0m" << endl;
        }

        cout << endl;

        cout << "\033[1;32m - \033[0m";
        Partie.getJ1().afficheJoueur();
        cout << "\033[1;33m - \033[0m";
        Partie.getJ2().afficheJoueur();
        cout << endl;
        fin = Partie.PartieFini();
        cout << "Partie fini ? " << fin << endl;
        gagnan = Partie.Vainqueur();
        cout << "Vainqueur ? " << gagnan << endl;

        cout << endl;
        cout << "----------" << endl;
        cout << endl;
      }

      if (gagnan == 1) {
        cout << "Bravo !! \033[1;32m" << Partie.getJ1().sonNom()
             << "\033[0m vous avez remporte la partie avec "
             << Partie.getJ1().sonPrestige() << " points de prestige." << endl;
      } else if (gagnan == -1) {
        cout << "Bravo !! \033[1;33m" << Partie.getJ2().sonNom()
             << "\033[0m vous avez remporte la partie avec "
             << Partie.getJ2().sonPrestige() << " points de prestige restant."
             << endl;
      } else {
        cout << "match nul" << endl;
      }

      cout << endl;
      cout << "----------" << endl;
      cout << endl;
    }

    // demande de rejoue
    cout << "Voulez vous rejouer ?? (o/n)" << endl;
    cin >> rejouer;
    while (rejouer != 'o' && rejouer != 'O' && rejouer != 'n' &&
           rejouer != 'N') {
      cout << "erreur veuillez reessayer" << endl;
      cout << "Indiquez votre choix (o/n) : ";
      cin >> rejouer;
      cout << endl;
    }
    cout << endl;
    cout << "----------" << endl;
    cout << endl;
  }
  return 0;
}
