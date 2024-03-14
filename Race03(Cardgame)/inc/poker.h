#ifndef POKER_H
#define POKER_H

#include <stdbool.h>

typedef struct {
    char rank;
    char suit;
} t_card;

typedef int (*combination_checker)(t_card *);

int is_straight_flush(t_card *cards);
int is_four_of_a_kind(t_card *cards);
int is_full_house(t_card *cards);
int is_flush(t_card *cards);
int is_straight(t_card *cards);
int is_three_of_a_kind(t_card *cards);
int is_two_pair(t_card *cards);
int is_one_pair(t_card *cards);
void print_combination(t_card *cards, int n);
bool is_valid_card(char *card);
bool has_duplicate(t_card *cards, int n);

#endif
