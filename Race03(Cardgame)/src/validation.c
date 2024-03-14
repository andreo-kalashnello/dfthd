#include "poker.h"
#include <stdio.h>
#include <string.h>

bool is_valid_card(char *card) {
    char *valid_ranks = "23456789TJQKA";
    char *valid_suits = "HCSD";

    if (strlen(card) != 2 || strchr(valid_ranks, card[0]) == NULL || strchr(valid_suits, card[1]) == NULL) {
        printf("Invalid card: %s\n", card);
        return false;
    }
    return true;
}

bool has_duplicate(t_card *cards, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cards[i].rank == cards[j].rank && cards[i].suit == cards[j].suit) {
                printf("Duplicate cards: %c%c\n", cards[i].rank, cards[i].suit);
                return true;
            }
        }
    }
    return false;
}

