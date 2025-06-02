Modélisation d'une fourmilière souterraine

Dans ce projet, nous avons modélisé une fourmilière souterraine composée de salles interconnectées par des tunnels.
Un groupe de F fourmis rouges, initialement situées dans une salle d'entrée appelée le vestibule, doit atteindre une salle finale nommée le dortoir en un temps minimal, tout en respectant des contraintes de déplacement strictes.

Choix algorithmique : BFS (Parcours en largeur)
Nous avons opté pour l'algorithme BFS (Breadth-First Search) en raison de sa simplicité d'implémentation pour ce problème.

Démarche de résolution

Représentation du graphe :

Nous avons d'abord construit une modélisation par graphes (nœuds = salles, arêtes = tunnels).

Pour faciliter les calculs, nous avons ensuite traduit cette structure en matrices d'adjacence.

Évolution de l'algorithme :

Notre première approche reposait sur une méthode heuristique, mais celle-ci s'est avérée peu optimale.

Nous avons finalement adopté un BFS, garantissant un chemin le plus court (en nombre de tunnels) entre le vestibule et le dortoir.
