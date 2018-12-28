/*-
 *suit.c
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#include "suit.h"

bool __pure2
suit_is_major_arcana(
    const suit_t suit)
{
	return suit == major;
}

bool __pure2
suit_is_minor_arcana(
    const suit_t suit)
{
	return suit > major && suit <= LAST_SUIT;
}

bool __pure2
suit_is_valid(
    const suit_t suit)
{
	return suit_is_major_arcana(suit) || suit_is_minor_arcana(suit);
}

size_t __pure2
suit_card_num(
    const suit_t suit)
{
	return suit_is_major_arcana(suit)
		? MAJOR_ARCANA_SUIT_NUM
		: MINOR_ARCANA_SUIT_NUM;
}

const char __pure2
suit_to_char(
    const suit_t suit)
{
	static const char tab[] = {'\0', 'W', 'C', 'P', 'S'};

	return tab[suit];
}

const char* __pure2
suit_to_str(
    const suit_t suit)
{
	static const char *tab[] = {
		"", "Wands", "Cups", "Pentacles", "Swords"
	};

	return tab[suit];
}

const char* __pure2
suit_numeration_str(
    const suit_t	suit,
    const unsigned	n)
{
	static const char *tab_major[] = {
		"0",
		"I",	"II",	"III",	"IV",	"V",
		"VI",	"VII",	"VIII",	"IX",	"X",
		"XI",	"XII",	"XIII",	"XIV",	"XV",
		"XVI",	"XVII", "XVIII",	"XIX",	"XX",
		"XXI",	"XXII", NULL
	};
	static const char *tab_minor[] = {
		"A",	"II",	"III",	"IV",	"V",
		"VI",	"VII",	"VIII",	"IX",	"X",
		"P",	"N",	"Q",	"K", NULL
	};

	return suit_is_major_arcana(suit)
		? tab_major[n]
		: tab_minor[n-1];
}

const char* __pure2
suit_numeration_str_long(
    const suit_t	suit,
    const unsigned	n)
{
	static const char *tab_major[] = {
		"the Fool",
		"the Magician",
		"the High Priestess",
		"the Empress",
		"the Emperor",
		"the Hierophant",
		"the Lovers",
		"the Chariot",
		"Strength",
		"the Hermit",
		"Wheel of Fortune",
		"Justice",
		"the Hanged Man",
		"Death",
		"Temperance",
		"the Devil",
		"the Tower",
		"the Star",
		"the Moon",
		"the Sun",
		"Judgment",
		"the World",
		NULL
	};
	static const char *tab_minor[] = {
		"Ace",	"II",	"III",	"IV",	"V",
		"VI",	"VII",	"VIII",	"IX",	"X",
		"Prince", "Knight", "Queen", "King", NULL
	};

	return suit_is_major_arcana(suit)
		? tab_major[n]
		: tab_minor[n-1];
}

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
