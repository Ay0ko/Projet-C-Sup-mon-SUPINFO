# Projet-C-Sup-mon-SUPINFO

Documentation Utilisateur - Règles et Fonctionnalités
1. Introduction
Bienvenue dans Supemon! Ce guide est destiné à vous familiariser avec les règles du jeu et les fonctionnalités principales disponibles, telles que le Shop, le Center, et le Combat. Vous y trouverez également des explications pour les nouveaux joueurs afin de comprendre les bases du jeu et comment interagir avec les différents éléments.

1.1 Objectif du jeu
L'objectif du jeu est d'augmenter le niveau de vos Supemon et d'avoir l'équipe de Supemon la plus forte. Vous pouvez interagir avec plusieurs fonctionnalités du jeu pour progresser, comme le Shop pour acheter des objets, le Center pour soigner vos personnages et le Combat pour affronter d'autres joueurs ou ennemis.

2. Règles du Jeu
Système de niveau
Votre personnage ou compte a un niveau qui peut augmenter à mesure que vous gagnez des points d’expérience (XP). L’XP est obtenue par le biais de combats, de missions ou d’autres activités du jeu.
Certains éléments, comme les objets ou compétences, ne peuvent être utilisés qu'à partir d'un certain niveau. (en développement)

3. Fonctionnalités
3.1. Le Shop - Achats et Gestion des Ressources
Le Shop est l'endroit où vous pouvez acheter des objets, des équipements et des améliorations pour votre personnage ou équipe.

Fonctionnalités du Shop :
Acheter des objets : Utilisez vos ressources pour acheter des objets utiles comme des potions de soin, des armes ou des armures.
Vendre des objets : Vous pouvez vendre certains objets de votre inventaire pour récupérer des ressources.
Règles du Shop :
3.2. Le Center - Soins et Repos
Le Center est un endroit où vous pouvez soigner vos personnages, récupérer des ressources.

Fonctionnalités du Center :
Soins : Si votre personnage a subi des blessures pendant un combat, vous pouvez le soigner au Center gratuitement.
Repos et récupération : Certaines activités demandent à vos personnages de se reposer. Le Center permet de récupérer de l'énergie pour continuer à jouer.
3.3. Le Combat - Affrontements et Stratégie
Le Combat est une partie essentielle du jeu où vous affrontez d'autres joueurs ou des ennemis contrôlés par l'IA pour obtenir des ressources et de l'expérience.

Fonctionnalités du Combat :
Combats en solo : Affrontez des ennemis pour progresser dans l'histoire du jeu ou gagner des ressources.
Compétences et capacités : Chaque personnage ou équipe a des compétences spécifiques qu'il peut utiliser pendant les combats.
Règles du Combat :
Stratégie et compétences : La victoire n’est pas uniquement basée sur la puissance brute. Utilisez vos compétences de manière stratégique pour maximiser vos chances de succès.

4. FAQ
5.1. Que faire si mon personnage est gravement blessé ?
Si votre personnage est gravement blessé, rendez-vous au Center pour le soigner et récupérer ses points de vie. Certaines potions de soin peuvent aussi être utilisées si vous en avez dans votre inventaire.

5.2. Comment gagner des ressources ?
Les ressources peuvent être obtenues en gagnant des combats ou en vendant des objets au Shop.

5.3. Comment améliorer mon personnage ?
Votre Supemon peut être amélioré en accumulant de l'expérience lors des combats et en achetant des équipements dans le Shop.



Documentation Technique - Explication des Fonctionnalités des Fichiers

1. Introduction

Cette documentation a pour but de décrire les différentes fonctions et leurs rôles techniques dans les fichiers du projet. Chaque fonction est expliquée en termes de sa fonctionnalité, de sa logique interne, des entrées et des sorties qu'elle prend en charge.

2. Fichier : shop.py
Le fichier shop.py gère toutes les interactions liées au Shop du jeu, y compris l'achat, la vente d'objets, et la gestion des ressources associées.

2.1 Fonction : buy_item(player, item)
Description :
La fonction buy_item permet à un joueur d'acheter un objet du Shop. Elle vérifie si le joueur a suffisamment de ressources pour acheter l’objet, puis met à jour l'inventaire du joueur et ses ressources.

Détails techniques :
Entrées :
player (objet représentant le joueur)
item (objet représentant l'élément à acheter)
Sorties :
Mise à jour de l'inventaire du joueur
Mise à jour des ressources du joueur (réduction du nombre de ressources)
Processus :
Vérifie si le joueur dispose des ressources nécessaires (ex : or, pièces, etc.).
Si le joueur a suffisamment de ressources, l'objet est ajouté à son inventaire.
Les ressources du joueur sont mises à jour pour refléter l'achat.
Retourne un message de succès ou d'échec selon l'état de la transaction.
2.2 Fonction : sell_item(player, item)
Description :
Permet à un joueur de vendre un objet de son inventaire. Le joueur reçoit des ressources en retour.

Détails techniques :
Entrées :

player (objet représentant le joueur)
item (objet représentant l'élément à vendre)
Sorties :

Mise à jour de l'inventaire du joueur (l'objet est retiré)
Augmentation des ressources du joueur
Processus :

Vérifie si l'objet est dans l'inventaire du joueur.
Si l'objet est présent, il est retiré de l'inventaire et les ressources du joueur sont augmentées.
Retourne un message de succès ou d’échec.
3. Fichier : center.py
Le fichier center.py gère les interactions du joueur avec le Center, notamment les soins, la récupération d'énergie, etc.

3.1 Fonction : heal_player(player)
Description :
La fonction heal_player restaure les points de vie du joueur en utilisant des ressources du jeu ou un service gratuit, selon les règles du Center.

Détails techniques :
Entrées :

player (objet représentant le joueur)
Sorties :

Mise à jour des points de vie du joueur
Potentielle diminution des ressources du joueur (si le soin est payant)
Processus :

Vérifie l'état actuel des points de vie du joueur.
Si les points de vie sont inférieurs au maximum, elle restaure une partie de ces points.
Selon la règle du jeu, le joueur peut devoir payer une certaine somme ou utiliser des objets pour bénéficier des soins.
Retourne un message de succès ou d'échec.
3.2 Fonction : rest_player(player)
Description :
Permet au joueur de se reposer pour récupérer de l’énergie ou des ressources.

Détails techniques :
Entrées :

player (objet représentant le joueur)
Sorties :

Mise à jour de l’énergie du joueur
Peut impliquer une attente ou un coût en ressources
Processus :

Vérifie l'état de l'énergie du joueur.
Le joueur peut se reposer pendant un certain temps (temps d'attente dans le jeu).
L'énergie du joueur est restaurée à un certain pourcentage.
Retourne un message de succès ou d’échec.
4. Fichier : combat.py
Le fichier combat.py est responsable de la logique des combats entre les joueurs, ainsi que des interactions avec les ennemis.

4.1 Fonction : start_combat(player1, player2)
Description :
La fonction start_combat lance un combat entre deux joueurs (ou un joueur et un ennemi).

Détails techniques :
Entrées :

player1 (objet représentant le premier joueur)
player2 (objet représentant le deuxième joueur ou un ennemi)
Sorties :

Mise à jour des points de vie des deux joueurs
Résultat du combat (gagnant, perdant)
Processus :

Vérifie si les deux joueurs sont prêts pour le combat (par exemple, points de vie, niveau, état).
Lance le combat en alternant les attaques des joueurs selon des règles prédéfinies.
Calcule l'issue du combat (victoire, défaite, égalité) et met à jour les statistiques des joueurs.
Retourne un message avec le résultat du combat.
4.2 Fonction : calculate_damage(attacker, defender)
Description :
Calcule le dommages infligés par un attaquant à un défenseur pendant un combat.

Détails techniques :
Entrées :

attacker (objet représentant l'attaquant)
defender (objet représentant le défenseur)
Sorties :

Nombre de points de dégâts infligés au défenseur
Processus :

Calcule le dommage en fonction des statistiques des personnages, telles que la force de l'attaquant et la défense du défenseur.
Applique des modificateurs comme les armes, les buffs, ou les effets de terrain.
Retourne le montant des dégâts calculés.