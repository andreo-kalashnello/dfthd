#include "poker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rank_to_int(char rank) {
    if (rank >= '2' && rank <= '9') return rank - '0';
    if (rank == 'T') return 10;
    if (rank == 'J') return 11;
    if (rank == 'Q') return 12;
    if (rank == 'K') return 13;
    if (rank == 'A') return 14;
    return -1;
}

int compare_cards(const void *a, const void *b) {
    t_card *card_a = (t_card *)a;
    t_card *card_b = (t_card *)b;
    return rank_to_int(card_a->rank) - rank_to_int(card_b->rank);
}

void sort_cards(t_card *cards, int n) {
    qsort(cards, n, sizeof(t_card), compare_cards);
}

int is_straight_flush(t_card *cards) {
    return is_straight(cards) && is_flush(cards);
}

int is_four_of_a_kind(t_card *cards) {
    sort_cards(cards, 5);
    return (rank_to_int(cards[0].rank) == rank_to_int(cards[3].rank)) ||
           (rank_to_int(cards[1].rank) == rank_to_int(cards[4].rank));
}

int is_full_house(t_card *cards) {
    sort_cards(cards, 5);
    return (rank_to_int(cards[0].rank) == rank_to_int(cards[2].rank) && rank_to_int(cards[3].rank) == rank_to_int(cards[4].rank)) ||
           (rank_to_int(cards[0].rank) == rank_to_int(cards[1].rank) && rank_to_int(cards[2].rank) == rank_to_int(cards[4].rank));
}

int is_flush(t_card *cards) {
    for (int i = 1; i < 5; i++) {
        if (cards[0].suit != cards[i].suit) return 0;
    }
    return 1;
}

int is_straight(t_card *cards) {
    sort_cards(cards, 5);
    for (int i = 0; i < 4; i++) {
        if (rank_to_int(cards[i].rank) + 1 != rank_to_int(cards[i + 1].rank)) return 0;
    }
    return 1;
}

int is_three_of_a_kind(t_card *cards) {
    sort_cards(cards, 5);
    for (int i = 0; i < 3; i++) {
        if (rank_to_int(cards[i].rank) == rank_to_int(cards[i + 1].rank) && rank_to_int(cards[i].rank) == rank_to_int(cards[i + 2].rank)) return 1;
    }
    return 0;
}

int is_two_pair(t_card *cards) {
    sort_cards(cards, 5);
    int pairs = 0;
    for (int i = 0; i < 4; i++) {
        if (rank_to_int(cards[i].rank) == rank_to_int(cards[i + 1].rank)) {
            pairs++;
            i++; // Пропустить следующую карту, так как она уже составляет пару
        }
    }
    return pairs == 2;
}

int is_one_pair(t_card *cards) {
    sort_cards(cards, 5);
    for (int i = 0; i < 4; i++) {
        if (rank_to_int(cards[i].rank) == rank_to_int(cards[i + 1].rank)) return 1;
    }
    return 0;
}

void print_combination(t_card *cards, int n) {
	(void)n;
    if (is_straight_flush(cards)) printf("Straight flush\n");
    else if (is_four_of_a_kind(cards)) printf("Four of a kind\n");
    else if (is_full_house(cards)) printf("Full house\n");
    else if (is_flush(cards)) printf("Flush\n");
    else if (is_straight(cards)) printf("Straight\n");
    else if (is_three_of_a_kind(cards)) printf("Three of a kind\n");
    else if (is_two_pair(cards)) printf("Two pair\n");
    else if (is_one_pair(cards)) printf("One pair\n");
    else printf("No pair\n");
}

