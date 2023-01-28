# Jeu_prestige


À l’attention du professeur, afin d’une meilleure compréhension et vision lors de la compilation du jeu vous pouvez le faire compiler sur Replit. Nous vous avions partagé le lien vers notre Replit pour pouvoir visualiser la compilation explicitement avec de la couleur. Le projet sur repli se nomme S102 - Jeu de prestige.  ( https://replit.com/@eblanc13/S102-Jeu-de-prestige#README.txt )

‼️ Nous avons mis des couleur dans notre code mais il ne marche pas sur codeBlocks

 - Pour les jouer au jeu sur codeBlocks :
il vous faudra créer un projet en ajoutant les fichier main.cpp, Carte.cpp, Joueur.cpp, Jeu.cpp, Carte.h, Joueaur.h et Jeu.h. Dans votre dossier il vous faudra aussi rajouter carte.txt
 - Pour les test automatique sur codeBlocks :
il vous faudra créer un projet en ajoutant les fichier main-test.cpp, Carte.cpp, Joueur.cpp, Jeu.cpp, Carte.h, Joueaur.h et Jeu.h. Dans votre dossier il vous faudra aussi rajouter carte.txt



———————————————————————————————



Bonjour,
Voici notre nouveau jeu, concu par des étudiants de l'IUT d'Orsay de première année.
Les règles vous seront rappellées lors du jeu mais voici ce qu'il faut faire.

Tout d'abbord c'est un jeu qui peut se jouer entre une à deux personnes.
Il existe deux modes de jeu :
        - Joueur contre Joueur (mode deux Joueurs)
        - Joueur contre IA (mode solo)

Le but est simple il faut gagner !! Vous avez deux façons :
        - Que votre adversaire n'ai plus de points de prestiges
        - Avoir plus de points de prestiges que votre adversaire lorsque les joueurs n'ont plus de cartes 

Ne plus avoir de carte signifie que le jeu est finit.

(Dans le shell)  {

Nous avons des test automatiques qui vérifient plusieurs de nos fonctions : pour pouvoir lancer les tests automatiques veuillez saisir ce qui suit : 'g++ main-test.cpp Jeu.cpp Carte.cpp Joueur.cpp' (effectue la compilation) il faut donc l'afficher avec : './a.out'. 

Nous avons la même méthode mais pour lancer leu jeu pour pouvoir lancer les jeu veuillez saisir ce qui suit : 'g++ main.cpp Jeu.cpp Carte.cpp Joueur.cpp' (effectue la compilation) il faut donc l'afficher avec : './a.out'.

}


Tout d'abord une méthode 'Jeu' va vous demander de choisir un mode de jeu solo ou a deux.
si 1 est saisie alors la partie joueur contre joueur serra exécutée sinon si c'est deux alors se serra la partie joueur contre IA. Tant que ce n'est pas 1 ou 2 le jeu vous redemande de saisir.

Ensuite une fois les noms rentrés pour jouer
Une reserve de jeu va se remplir à partir du fichier 'Cartes.txt', les cartes proviennent donc de la-bas.

Vous devrez donc choisir parmis ces 25 cartes, 20 cartes à ajoutées a votre pile. Veuillez saisir des cartes différentes à chaque fois sinon le jeu vous demandera de ressaisir une carte car il saura que vous l'avez déja rentrée, faite attention aussi à l'écriture de cette dernière.
Si vous êtes contre un IA sa pile se remplira toute seule et aléatoirement.

Une fois les 20 cartes renseignées le jeu vous demanderas de trier vos cartes choisies vis à vis de si vous preferez les trier en fonction de leur attaque (a), magie (m), defense (d), ou le score cumulé des trois (s), ou encore de le garder comme tel (r).

En fonction de votre réponse précédente vous aurez le choix entre les trier par ordre croissant ou décroissant, c'est-à-dire que si vous avez choisis la magie et que vous choisissez Croissant alors vos cartes seront triées du plus petit au plus grand. Vos cartes avec le moins de magie seront jouées en première.

Le jeu s'éxécutera tout seul en affichant les dégats subits par chacun à chaque fois.

A la fin vous saurez si le match est nul ou si il est gagné par quelqu'un et par qui.

Vous aurez le choix de rejouer ou non.



INFORMATION pour les couleur:
//------------------------------//
Code ANSI pour changer la couleur de la sortie de console, exemple :
Noir : "\033[0;30m"
Rouge : "\033[0;31m"
Vert : "\033[0;32m"
Jaune : "\033[0;33m"
Bleu : "\033[0;34m"
Violet : "\033[0;35m"
Cyan : "\033[0;36m"
Blanc : "\033[0;37m"
pour réinitialiser la couleur de la sortie de console à la couleur par défaut, il faut utiliser : "\033[0m"
‼️ Ces codes ne fonctionneront que dans les environnements qui prennent en charge les codes ANSI (pour Xcode ils ne fonctionne pas)
//------------------------------//
