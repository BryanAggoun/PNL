Compte-rendu TP03 PNL :
========================

##Exercice 1 :

Lors du premier lancement de la commande 
> qemu-system-x86_64 -hda pnl-tp.img
le système n'a pas pu lancer correctement la distribution linux en raison de corruption de l'image disque.

Après l'ajout d'un autre disque dans `/root` et la génération d'une image personnelle dans `/home`, le script de lancement _qemu-run.sh_ à correctement fonctionner.

##Exercice 2 :

__Question 1 :__

Les options de debogage qui pourront être utile pour ce TP se trouve dans les sections **Kernel hacking** et **File systems**.

__Question 2 :__

Pour connaître le nombre de coeur d'une machine on peut utiliser la commande _nbproc_.
Le nombre de coeur de ma machine est 4.
La valeur du paramètre -j doit être alors au moins de 4.

__Question 4 :__

Non cela n'est pas sufisant pour être sûr qu'il s'agit bien de notre noyau car la commande uname ne permet pas de différencier 2 noyau d'une même version.

__Question 5 :__

C'est l'option _local version_ qui permet de rajouter un commentaire au "release" du noyau.

__Question 6 :__

Lorsque l'on affiche la liste des modules chargés on se rend compte qu'il n'y en a aucun. Ce qui semble logique car dans la configuration de notre noyau, l'option _Module unloading_ est coché. 

##Exercice 3 :

__Question 1 :__

Voici le programme de hello.c :

```c
#include<stdio.h>
#include<stdlib.h>
#include<unsitd.h>

int main(void){

        printf("hello world\n");
        sleep(5);
        return 0;
}
```

__Question 3 :__

Le système finit par crasher car une fois le programme _hello_ terminé celui-ci va entrainer la terminaison du système et cela ne peut se faire sans que le processus init soit terminé.

__Question 4 :__

On ne peut pas directement lancer une commande _ps_ dans le shell car cette commande utilise des fichiers d'un répertoire initisalisé par _init_.

__Question 6 :__

Pour lancer le script original _init_ depuis notre shell, on peut utiliser la commande 
> exec init

##Exercice 4 :

__Question 1 :__

L'option _-static_ permet d'éviter de compiler un exécutable ne reposant pas sur les librairies dynamiques. Cette option est nécessaire car au boot, pas toutes les partitions ne sont encore montées et l'executable init doit donc être monolithique.

