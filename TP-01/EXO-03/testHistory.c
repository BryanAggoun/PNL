#include<stdlib.h>
#include<stdio.h>

#include"history.h"


int main(int argc, char const *argv[])
{
	struct history *history = new_history("Tout une histoire");
	struct commit *tmp, *victim, *last;
  
  display_commit(last_commit(history));
	printf("\n");

	display_history(history);
	
  
	tmp = add_minor_commit(last_commit(history), "Work 1",history);
	tmp = add_minor_commit(tmp, "Work 2",history);
	victim = add_minor_commit(tmp, "Work 3",history);
	last = add_minor_commit(victim, "Work 4",history);
	display_history(history);

	//del_commit(victim, history);
	display_history(history);

	tmp = add_major_commit(last, "Realse 1",history);
	tmp = add_minor_commit(tmp, "Work 1",history);
	tmp = add_minor_commit(tmp, "Work 2",history);
	tmp = add_major_commit(tmp, "Realse 2",history);
	tmp = add_minor_commit(tmp, "Work 1",history);
	display_history(history);

	add_minor_commit(last, "Oversight !!!", history);
	display_history(history);

	printf("Recherche du commit 1.2 :   ");
	infos(history, 1, 2);
	printf("\n");

	printf("Recherche du commit 1.7 :   ");
	infos(history, 1, 7);
	printf("\n");

	printf("Recherche du commit 4.2 :   ");
	infos(history, 4, 2);
	printf("\n");

	return 0;
}
