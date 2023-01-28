// Cathy Erwan (Nolan)
//Groupr H7

#include "Carte.h"
#include "Jeu.h"
#include "Joueur.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  //----------test auto---------
  Carte c1("cuillere", 7, 7, 3);
  Carte c2("caserole", 2, 5, 5);
  Carte c("poele", 5, 7, 2);

    
  Joueur J1("cathy");// pas de points de prestige pour verifire que c'est bien à 25 prestige
  Joueur J2("erwan", 20,{});
  Joueur J3("bonsoir", 0 ,{c1,c2,c});

  cout<<endl;
  
 // verification des points de prestige au debut de la partie des deux joueurs

  cout << "\033[1;35m----- verification point de prestige joueurs au debut -----\033[0;m"<< endl;
  if (J1.sonPrestige()==25) {
    cout << "\033[1;33mtest ok\033[0;m le joueur1 à bien "<<J1.sonPrestige()<<" point de prestige"<<endl;
  }
  else {
    cout << "\033[1;33mtest ok\033[0;m resultat attendu : 25 resultat obtenu "<<J1.sonPrestige()<< endl;
  }
  
  cout<<endl;

  if (J2.sonPrestige()==20) {
    cout << "\033[1;33mtest ok\033[0;m le joueur2 à bien "<<J2.sonPrestige()<<" point de prestige"<<endl;
  }
  else {
    cout<<"\033[1;33mTest echouer\033[0;m"<<endl;
    cout << "resultat attendu : 20 resultat obtenu "<<J1.sonPrestige()<< endl;
  }
  cout<<endl;

  
  // verification du noms des joueurs
  cout<<"\033[1;35m----- verification noms joueur -----\033[0m"<< endl;
  if(J1.sonNom()=="cathy"){
    cout <<" \033[1;33mtest ok\033[0;m la reponse était bien :"<<J1.sonNom()<<endl;
  }
  else{
    cout<<"\033[1;33mTest echouer\033[0;m"<<endl;
    cout<< "reponse obtenue : "<<J1.sonNom()<<" reponse attendu : cathy"<<endl;
  }

  cout<<endl;

  
  // verification de si apres 20 tours soit 20 cartes jouées les piles soient bien vides

  // pour le joueur 1
  cout<<"\033[1;35m----- verification des piles -----\033[0;m"<<endl;
  if(J1.pileVide()==1){//true = 1
    cout<<"\033[1;33mtest ok\033[0;m"<<" pour le joueur 1"<<endl;
    }
  else {
    cout<<"\033[1;33mtest pas ok\033[0;m"<<" la pile est  egale a "<<J1.pileVide()<<endl;
  }
  // pour le joueur 3
  if (J3.pileVide()==0){// false = 0
    cout<<"\033[1;33mtest ok\033[0;m"<<" pour le joueur 3 il y a bien une carte dans sa pile"<<endl;
    }
  else {
    cout<<"\033[1;33mtest pas ok\033[0;m"<<" - la reponse attendu est faux car il a une carte dans sa pile"<<endl;
  }
  
  cout<<endl;

  // degat magique
  cout<<"\033[1;35m----- verification degat magique -----\033[0;m"<<endl;
  if(c1.degatMagique(c2) ==  2){
    cout<<"\033[1;33mtest ok\033[0;m"<<" (vrai)"<<endl;
  }
  else{
    cout<<"\033[1;33mtest pas ok\033[0;m"<<" (faux)"<<endl;
  }
  cout<<endl;

  //degat physique
  cout<<"\033[1;35m----- verification degat physique -----\033[0;m"<<endl;
  if(c1.degatPhysique(c2) ==  -2 ){
    cout<<"\033[1;33mtest ok\033[0;m"<<" (vrai)"<<endl;
  }
  else{
    cout<<"\033[1;33mtest pas ok\033[0;m"<<" (faux)"<<endl;
  }
  cout<<endl;
  
  cout<<"----- verification de l'addition des scores de la carte -----"<<endl;
  cout<<"cas general"<<endl;
  int score = c1.getDefense()+c1.getAttaque()+c1.getMagie();
  if(score == c1.ScoreCarte()){
    cout<<"\033[1;33mtest ok\033[0;m"<<" le score est exact"<<endl;
  }
  else {
    cout<<"test faux le resultat attendu est "<<score<<" et votre resultat est "<<c1.ScoreCarte()<<endl;
  }
  
  cout <<endl;

  // verification vainqueur
  cout<<"\033[1;35m----- verification du vainqueur -----\033[0;m"<<endl;
  if(J2.sonPrestige()==J3.sonPrestige()){

    
  }
  cout<<"\033[1;35m----- verification toujours en jeu (prestige>0) -----\033[0;m"<<endl;
  if(J1.ToujoursEnJeu()==1){// true = 1
      cout<<"\033[1;33mtest ok\033[0;m"<<" le joueur 1 est bien encore en jeu "<<endl;
    }
  if(J2.ToujoursEnJeu()==1){// true = 1
      cout<<"\033[1;33mtest ok\033[0;m"<<" le joueur 2 est bien encore en jeu "<<endl;
  }
  else {
    cout<<"\033[1;33mtest pas ok\033[0;m"<<" un joueur n'a plus de points de prestiges"<<endl;
    }
  if(J3.ToujoursEnJeu()==0){// false =0
    cout<<"\033[1;33mtest ok\033[0;m"<<" le joueur 3 est bien hors jeu "<<endl;
  }
    
    
    
  
}
