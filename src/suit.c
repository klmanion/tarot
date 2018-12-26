/*-
 *suit.c
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#include "suit.h"

bool __pure2
suit_is_minor_arcana(
    const suit_t suit)
{
	return suit > major && suit <= swords;
}

bool __pure2
suit_is_major_arcana(
    const suit_t suit)
{
	return !suit_is_minor_arcana(suit);
}

size_t __pure2
suit_card_num(
    const suit_t suit)
{
	return suit_is_major_arcana(suit)
		? MAJOR_ARCANA_SUIT_NUM
		: MINOR_ARCANA_SUIT_NUM;
}

char __pure2
suit_to_char(
    const suit_t suit)
{
	static char tab[] = {"", "W", "C", "P", "S"};

	return tab[suit];
}

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
