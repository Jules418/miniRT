# miniRT
## Introduction
miniRT est un projet de l'école 42 visant à implémenter un simple moteur de raytracing.

## Installation
Pour installer et exécuter ce projet, suivez les étapes ci-dessous :

Clonez le dépôt :

``git clone https://github.com/Jules418/miniRT``

``cd miniRT``

Compilez le projet :

``make``

## Utilisation
Pour lancer miniRT : 

``./miniRT map/nom_de_la_scene.rt``

L'extension .rt correspond au type de fichier à utiliser.
Le fichier de scène .rt doit suivre un format spécifique pour décrire les objets et les lumières dans la scène. Voici un exemple de fichier de scène :

## Exemples de configurations de la scène

### Lumières
A 0.2 255,255,255

L -40,50,30 0.6 10,0,255 (Il est possible de mettre plusieurs lumières)

### Caméra
C -50,0,20 0,0,0 70

### Objets
sp 0,0,20 20 255,0,0

pl 0,1,0 0,0,0 0,255,0

cy 50,0,20 0,1,0 14 30 0,0,255


## Dépendances
Le projet utilise les bibliothèques suivantes :

[``minilibx``](https://github.com/42Paris/minilibx-linux) pour l'affichage graphique.

[``libft``](https://github.com/Axiaaa/libft) pour les fonctions utilitaires. 


Auteurs

[Jules418](https://github.com/Jules418)

[Nephtys](https://github.com/Axiaaa)
