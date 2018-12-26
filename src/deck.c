/*-
 *deck.c
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#include "deck.h"
#include <err.h>

/* the deck_t* pointed to has been allocated */
deck_t*
deck_alloc(
    deck_t **ptr)
{
	deck_t *deck;

	deck = NULL;

	/* this must be revised when deck_t no longer is a card_t* */ 
	deck = (deck_t *)malloc(sizeof(card_t)*DECK_FULL_NUM);
	if (!deck)
	    errx(1,"malloc failure, %s: %d", __FILE__, __LINE__);

	return (*ptr = deck);
}

deck_t*
deck_init(
    deck_t **ptr)
{
	deck_alloc(ptr);

	return deck_fill(*ptr);
}

deck_t*
deck_free(
    deck_t *deck)
{
	if (deck) {
		free(deck);
	}

	return (deck = NULL);
}

deck_t*
deck_fill(
    deck_t *const deck)
{
	suit_t suit;
	unsigned ct;

	suit = major;
	ct = 0;

	for (size_t i=0; i<DECK_FULL_NUM; ++i)
	    {
		if (suit == major)
		    {
			card_set(deck_card_at(deck,i), suit, ct);

			/* Major arcana are 0-indexed */
			if (ct == MAJOR_ARCANA_NUM-1)
			    {
				++suit;
				ct = 1;
			    }
		    }
		else
		    {
			card_set(deck_card_at(deck,i), suit, ct);

			/* Minor arcana are 1-indexed */
			if (ct == MINOR_ARCANA_NUM)
			    {
				++suit;
				ct = 1;
			    }
		    }
	    }

	return deck;
}

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
