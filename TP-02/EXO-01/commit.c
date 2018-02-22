#include<stdlib.h>
#include<stdio.h>

#include"commit.h"
static int nextId = 0;

/**
  * new_commit - alloue et initialise une structure commit correspondant aux
  *              parametres
  *
  * @major: numero de version majeure
  * @minor: numero de version mineure
  * @comment: pointeur vers une chaine de caracteres contenant un commentaire
  *
  * @return: retourne un pointeur vers la structure allouee et initialisee
  */
struct commit *new_commit(unsigned short major, unsigned long minor,
			  char *comment)
{
	/* TODO : Exercice 3 - Question 2 */

  struct commit *c;
  nextId ++;
  /*J'alloue une struct commit*/
  c = malloc(sizeof(struct commit));

  /*j'initialise ma struct commit*/
  c->id = nextId;
  c->version.major = major;
  c->version.minor = minor;
  c->comment = comment;
  INIT_LIST_HEAD(&(c->list)); 

	return c;
}

/**
  * insert_commit - insere sans le modifier un commit dans la liste doublement
  *                 chainee
  *
  * @from: commit qui deviendra le predecesseur du commit insere
  * @new: commit a inserer - seuls ses champs next et prev seront modifies
  *
  * @return: retourne un pointeur vers la structure inseree
  */
static struct commit *insert_commit(struct commit *from, struct commit *new)
{
	/* TODO : Exercice 3 - Question 3 */

  /*new->next = from->next;
  from->next->prev = new;
  new->prev = from;
  from->next = new;*/

  list_add(&(new->list), &(from->list));
  


	return new;
}

/**
  * add_minor_commit - genere et insere un commit correspondant a une version
  *                    mineure
  *
  * @from: commit qui deviendra le predecesseur du commit insere
  * @comment: commentaire du commit
  *
  * @return: retourne un pointeur vers la structure inseree
  */
struct commit *add_minor_commit(struct commit *from, char *comment)
{
	/* TODO : Exercice 3 - Question 3 */
  struct commit *c;
  unsigned long m;
  m = from->version.minor + 1;
  c = new_commit(from->version.major,m,comment);
  insert_commit(from,c);


	return c;
}

/**
	* add_major_commit - genere et insere un commit correspondant a une version
  *                    majeure
  *
  * @from: commit qui deviendra le predecesseur du commit insere
  * @comment: commentaire du commit
  *
  * @return: retourne un pointeur vers la structure inseree
  */
struct commit *add_major_commit(struct commit *from, char *comment)
{
	/* TODO : Exercice 3 - Question 3 */
  struct commit *c;
  unsigned long m;
  m = from->version.major + 1;
  c = new_commit(m,0,comment);
  insert_commit(from,c);
  return c;
}

/**
  * del_commit - extrait le commit de l'historique
  *
  * @victim: commit qui sera sorti de la liste doublement chainee
  *
  * @return: retourne un pointeur vers la structure extraite
  */
struct commit *del_commit(struct commit *victim)
{
	/* TODO : Exercice 3 - Question 5 */
  /*victim->next->prev = victim->prev;
  victim->prev->next = victim->next;
  victim->next = NULL;
  victim->prev = NULL;

  (h->commit_count)--;*/

	return NULL;
}

/**
  * display_commit - affiche un commit : "2:  0-2 (stable) 'Work 2'"
  *
  * @c: commit qui sera affiche
  */
void display_commit(struct commit *c)
{
	/* TODO : Exercice 3 - Question 4 */

  //if((c->id) == 0)
    //return;

  if(c->version.minor & 1)
  {
    printf(" %lu:  %d.%lu (unstable)\t'%s'\n",c->id,
    c->version.major, c->version.minor,c->comment);
    return;
  }
  printf(" %lu:  %d.%lu (stable)\t'%s'\n",c->id,
  c->version.major, c->version.minor, c->comment);  
}

/**
  * commitOf - retourne le commit qui contient la version passee en parametre
  *
  * @version: pointeur vers la structure version dont on recherche le commit
  *
  * @return: un pointeur vers la structure commit qui contient 'version'
  *
  * Note:      cette fonction continue de fonctionner meme si l'on modifie
  *            l'ordre et le nombre des champs de la structure commit.
  */
struct commit *commitOf(struct version *version)
{
	/* TODO : Exercice 2 - Question 2 */
	return NULL;
}
