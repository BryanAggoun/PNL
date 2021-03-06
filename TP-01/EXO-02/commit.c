#include <stdio.h>
#include <stdlib.h>

#include "version.h"
#include "commit.h"

void display_commit(struct commit* c)
{	
	printf("&id = %p \n",&(c->id));
        printf("&version = %p \n",&(c->version));
        printf("&comment = %p \n",&c->comment);
        printf("&next = %p \n",&c->next);
        printf("&prev = %p \n",&c->prev);
}

struct commit *commit_of(struct version* v)
{
	return (struct commit*)((void*)v-(void*)&((struct commit*)0x0)->version);
}
