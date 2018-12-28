/*-
 *deck.h
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 *
 * eventualy deck_t will be more than a simple typedef of a card_t array
 */

#ifndef _DECK_H_
#define _DECK_H_

#include <stdlib.h>
#include "card.h"

typedef
struct _deck {
	/* content */
	card_t 	**cnt;
	card_t	**head;

	/* flags */
	bool	major_arcana_only;
} deck_t;
#define deck_sz sizeof(deck_t)

#define FULL_DECK (MAJOR_ARCANA_SUIT_NUM + (MINOR_ARCANA_SUIT_NUM * 4))

__BEGIN_DECLS
deck_t* deck_alloc (deck_t **);
deck_t*	deck_init (deck_t **);

deck_t*	deck_free (deck_t *);

size_t	deck_card_num (const deck_t *const) __pure;

deck_t*	deck_fill (deck_t *const);
//deck_t*	deck_shuffle (deck_t *const);

bool	deck_empty (const deck_t *const) __pure;

card_t*	deck_draw (deck_t *const);
__END_DECLS

#endif /* !_DECK_H_ */

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
