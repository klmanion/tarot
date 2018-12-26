/*-
 *suit.h
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#ifndef _SUIT_H_
#define _SUIT_H_

#include <stdlib.h>
#include <stdbool.h>

#define MAJOR_ARCANA_SUIT_NUM 23
#define MINOR_ARCANA_SUIT_NUM 14

typedef
enum _suit __attribute__((packed)) {
	major = 0,
	wands,
	cups,
	pentacles,
	swords
} suit_t;

__BEGIN_DECLS
bool	suit_is_minor_arcana __P((const suit_t)) __pure2;
bool	suit_is_major_arcana __P((const suit_t)) __pure2;

size_t	suit_card_num __P((const suit_t)) __pure2;

char	suit_to_char __P((const suit_t)) __pure2;
__END_DECLS

#endif /* !_SUIT_H_ */

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
