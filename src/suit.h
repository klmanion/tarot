/*-
 *suit.h
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#ifndef _SUIT_H_
#define _SUIT_H_

#include <stdlib.h>
#include <stdbool.h>

#define MAJOR_ARCANA_SUIT_NUM 22
#define MINOR_ARCANA_SUIT_NUM 14

typedef
enum _suit {
	major = 0,
	wands,
	cups,
	pentacles,
	swords
} suit_t;

#define LAST_SUIT (suit_t)swords

__BEGIN_DECLS
bool	suit_is_major_arcana (const suit_t) __pure2;
bool	suit_is_minor_arcana (const suit_t) __pure2;

bool	suit_is_valid (const suit_t) __pure2;

size_t	suit_card_num (const suit_t) __pure2;

const char	suit_to_char (const suit_t) __pure2;
const char*	suit_to_str (const suit_t) __pure2;

const char*	suit_numeration_str (const suit_t,const unsigned) __pure2;
const char*	suit_numeration_str_long (const suit_t,const unsigned) __pure2;
__END_DECLS

#endif /* !_SUIT_H_ */

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
