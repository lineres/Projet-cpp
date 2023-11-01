# Projet de programmation en C++ pour l'UE Langage Objet Avancé année 2022-2023

## Projet realisé par: (nom, prenom, n° etudiant)  
    - Tazouev Arbi, 21957896  
    - Guinet Virgile, 21952934  

## Compilation:  
    Dans la racine du projet, tapez: `make`  
    attendez jusqu'a que le message "Lancez avec ./go" apparait  
    
## Lancement:  
    Lancez avec `./go`  

## Utilisation:  
    Quand le menu principal apparait, vous n'avez que a selectionner votre jeu,  
    sauf pour DominoCarre où une entrée dans le terminal est requise pour appliquer la taille du plateau de jeu  
    Dans chaque jeu, vous avez le plateau du jeu a gauche, et les controlles a droite  
    dans la zone de controlles a toujours tout en haut le joueur dont il est actuellement le tour  
    le dessin du la tuile que vous avez actuellement piochée  
    une fleche tout en bas qui va a gauche qui vous fait revenir au menu principal  
    Ensuite en fonction des jeu:  
        DominoCarre:  
            - fleche qui permet de tourner votre tuile  
        Trax:  
            - premiere fleches pour tourner la tuile  
            - autre fleche pour retourner la tuile (changer la forme/dessin)  
        Carcassonne:  
            - premiere fleches pour tourner la tuile  
            - votre partisant, le mode placement doit etre activé/desactivé  
            - croix rouge pour reposer votre tuile et piocher une nouvelle  
            - bouton "END" pour finir votre tour (uniquement apres avoir placé votre tuile)  
    En Carcassonne vous pouvez deplacer la caméra avec les flèches, et Z pour zoomer, A pour zoomer  
    Sur carcassonne, si vous faites click droit, les scores des joueurs sont calculés et affiché dans le terminal  
  
## Nettoyage:  
    avec `make clean`  