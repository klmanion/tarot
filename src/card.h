/*-
 *main.c
 * tarot
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#ifndef _CARD_H_
#define _CARD_H_

#include <stdlib.h>
#include <stdbool.h>
#include "suit.h"

typedef
struct _card {
	suit_t		 suit;
	unsigned	 n;
} card_t;
#define card_sz sizeof(card_t)

__BEGIN_DECLS
bool	card_is_major_arcana (const card_t *const) __pure;
bool	card_is_minor_arcana (const card_t *const) __pure;

const char*	card_numeration_to_str (const card_t *const card) __pure;
const char*	card_numeration_to_str_long (const card_t *const card) __pure;

char*	card_to_str (const card_t *const) __pure;
__END_DECLS

#endif /* !_CARD_H_ */

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
