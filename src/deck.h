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



typedef card_t * deck_t;

__BEGIN_DECLS
deck_t* deck_alloc __P((deck_t **));
deck_t*	deck_init __P((deck_t **));

deck_t*	deck_free __P((deck_t *));

deck_t*	deck_fill __P((deck_t *const));
deck_t*	deck_shuffle __P((deck_t *const));

deck_t*	deck_card_at __P((deck_t *,size_t));

card_t*	deck_draw __P((deck_t *const));
__END_DECLS

#endif /* !_DECK_H_ */

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
