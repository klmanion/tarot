/*-
 *main.c
 * tarot
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

int
main(
    int argc,
    char *argv[])
{
	deck_t *deck = NULL;

	deck_fill(deck_init(&deck));

	for (size_t i=0,num=deck_card_num(deck); i<num; ++i)
	    {
		card_t *card;
		char *s;

		s = card_to_str((card = deck_draw(deck)));

		if (card)
		    {
			free(card);

			if (s)
			    {
				printf("%zu. %s\n", i+1, s);
				free(s);
			    }
		    }
	    }

	deck = deck_free(deck);

	return EXIT_SUCCESS;
}

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
