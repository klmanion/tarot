/*-
 *main.c
 * tarot
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

typedef
struct _card {
	suit_t		 suit;
	unsigned	 n;
} card_t;

__BEGIN_DECLS
char*	card_to_str __P((card_t *const));
__END_DECLS

int
main(
    int argc,
    char *argv[])
{
	deck_t *deck;

	deck_shuffle(deck_init(&deck));

	for (size_t i=0; i<deck_sz; ++i)
	    printf("%s\n", card_to_str(deck_draw(deck)));

	deck = deck_free(deck);

	return EXIT_SUCCESS;
}

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
