/*-
 *main.c
 * tarot
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#include "card.h"
#include <limits.h>
#include <err.h>
#include <stdio.h>

bool __pure
card_is_major_arcana(
    const card_t *const card)
{
	return suit_is_major_arcana(card->suit);
}

bool __pure
card_is_minor_arcana(
    const card_t *const card)
{
	return suit_is_minor_arcana(card->suit);
}

/* TODO allow customization of the numeration */
const char* __pure
card_numeration_to_str(
    const card_t *const card)
{
	return suit_numeration_str(card->suit, card->n);
}

const char* __pure
card_numeration_to_str_long(
    const card_t *const card)
{
	return suit_numeration_str_long(card->suit, card->n);
}

char* __pure
card_to_str(
    const card_t *const card)
{
	char *s;

	if (!card)
	    return NULL;

	s = (char *)malloc(CHAR_BIT*80);
	if (!s)
	    errx(1,"malloc failure, %s:%d", __FILE__, __LINE__);

	snprintf(s, 80, "%s%s%s",
		card_numeration_to_str_long(card),
		card_is_major_arcana(card) ? "" : " of ",
		suit_to_str(card->suit));

	return s;
}

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
