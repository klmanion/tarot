/*-
 *deck.c
 * created by: Kurt L. Manion
 * on: Wed., 26 Dec. 2018
 */

#include "deck.h"
#include <err.h>

deck_t*
deck_alloc(
    deck_t **ptr)
{
	deck_t *deck;

	deck = (deck_t *)malloc(deck_sz);
	if (!deck)
	    errx(1,"malloc failure, %s: %d", __FILE__, __LINE__);

	return (*ptr = deck);
}

deck_t*
deck_init(
    deck_t **ptr)
{
	deck_t *deck;

	deck = *ptr;

	if (!deck)
	    deck = deck_alloc(ptr);
       
	deck->head = deck->cnt = NULL;

	deck->major_arcana_only = false;

	return deck;
}

#ifdef DEBUG
#include <stdio.h>
#endif

deck_t*
deck_free(
    deck_t *deck)
{
	if (deck) {
		if (deck->cnt) {
			for (card_t **ptr=deck->head; *ptr; ++ptr)
			    free(*ptr);

			free(deck->cnt);
		}

		free(deck);
	}

	return (deck = NULL);
}

size_t __pure
deck_card_num(
    const deck_t *const deck)
{
	return deck->major_arcana_only
		? MAJOR_ARCANA_SUIT_NUM
		: FULL_DECK;
}

deck_t*
deck_fill(
    deck_t *const deck)
{
	size_t deck_num;
	suit_t suit;

	if (deck->cnt) {
		for (card_t *ptr=*deck->head; ptr; ++ptr)
		    free(ptr);

		deck->head = NULL;

		free(deck->cnt);
	}

	deck_num = deck_card_num(deck);

	deck->cnt = (card_t **)malloc(sizeof(card_t *) * (deck_num+1));
	if (!deck->cnt)
	    errx(1,"malloc failure, %s:%d", __FILE__, __LINE__);

	suit = major;

	for (size_t ct=0; ct<deck_num; ++ct)
	    {
		card_t *card;

		card = deck->cnt[ct] = (card_t *)malloc(card_sz);
		if (!card)
		    errx(1,"malloc failure, %s:%d", __FILE__, __LINE__);

		if (ct == MAJOR_ARCANA_SUIT_NUM
			|| (ct > MAJOR_ARCANA_SUIT_NUM
			    && (ct-MAJOR_ARCANA_SUIT_NUM) % MINOR_ARCANA_SUIT_NUM == 0))
		    ++suit;

		card->suit = suit;

		if (suit_is_major_arcana(suit))
		    {
			card->n = ct;
		    }
		else
		    {
			card->n = ct - MAJOR_ARCANA_SUIT_NUM;
			card->n %= MINOR_ARCANA_SUIT_NUM;
			card->n += 1;
		    }
	    }

	deck->head = deck->cnt;
	deck->cnt[deck_num] = NULL;

	return deck;
}

bool __pure
deck_empty(
    const deck_t *const deck)
{
	return !deck->cnt || !deck->head;
}

card_t* __pure
deck_draw(
    deck_t *const deck)
{
	return (deck->cnt && deck->head) ? *(deck->head++) : NULL;
}

/* vim: set ts=8 sw=8 noexpandtab tw=79: */
