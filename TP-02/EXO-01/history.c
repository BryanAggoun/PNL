#include<stdlib.h>
#include<stdio.h>

#include"history.h"
#include"list.h"

/**
  * new_history - alloue, initialise et retourne un historique.
  *
  * @name: nom de l'historique
  */
struct history *new_history(char *name)
{
	/* TODO : Exercice 3 - Question 2 */

  struct history *h;
  struct commit *phantom;
  h = (struct history*)malloc(sizeof(struct history));
  phantom = new_commit(0,0,NULL); 

  phantom->id = 0;
  h->commit_count = 0;
  h->name = name;
  h->commit_list = phantom;
	return h;
}

/**
  * last_commit - retourne l'adresse du dernier commit de l'historique.
  *
  * @h: pointeur vers l'historique
  */
struct commit *last_commit(struct history *h)
{
  /* TODO : Exercice 3 - Question 2 */ 
  return list_last_entry(&(h->commit_list->list), struct commit, list);
}

/**
  * display_history - affiche tout l'historique, i.e. l'ensemble des commits de
  *                   la liste
  *
  * @h: pointeur vers l'historique a afficher
  */
void display_history(struct history *h)
{
	/* TODO : Exercice 3 - Question 2 */
  struct list_head head = h->commit_list->list;
  struct commit *c;
  printf("Historique de '%s' :\n",h->name);
  
  list_for_each_entry(c, &head, list)
  {
    display_commit(c);
  }
  printf("\n");
}

/*
  * infos - affiche le commit qui a pour numero de version <major>-<minor> ou
  *         'Not here !!!' s'il n'y a pas de commit correspondant.
  *
  * @major: major du commit affiche
  * @minor: minor du commit affiche
  */
void infos(struct history *h, int major, unsigned long minor)
{
	/* TODO : Exercice 3 - Question 2 */
  int i;
  for(i = 0; i<=h->commit_count; i++)
  {
    if(h->commit_list->version.major == major && 
       h->commit_list->version.minor == minor)
    {
      display_commit(h->commit_list);
      return;
    }
    //h->commit_list = h->commit_list->next;
  }
  printf("Not Here !!!\n");

}
