#include<stdio.h>
#include<stdlib.h>

#include "version.h"
#include "commit.h"

int main(int argc, char const *argv[])
{
	struct version v = {.major = 3,
                            .minor = 5,
                            .flags = 0};

	struct commit c = {.id = 5,
			   .version = v,
			   .comment = "coucou",
			   .next = NULL,
			   .prev = NULL};

	display_commit(&c);

	printf("offset = %p \n", &((struct commit*)0x0)->version);
	
	printf("&commit = %p \n", commit_of(&(c.version)));
return 0;
}
