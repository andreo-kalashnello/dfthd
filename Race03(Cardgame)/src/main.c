#include "poker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 6) {
        printf("usage: ./race03 [card1] [card2] [card3] [card4] [card5]\n");
        return 1;
    }

    t_card cards[5];
    for (int i = 1; i < argc; i++) {
        if (!is_valid_card(argv[i])) {
            return 1; // Валидация и сообщение об ошибке в is_valid_card
        }
        cards[i - 1].rank = argv[i][0];
        cards[i - 1].suit = argv[i][1];
    }

    if (has_duplicate(cards, 5)) {
        return 1; // Сообщение о дубликате в has_duplicate
    }

    print_combination(cards, 5);
    return 0;
}

