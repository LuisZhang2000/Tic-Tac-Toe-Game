#include <stdio.h>

void win(int player, int winner, int pos[]) {
    printf("\n");
    printf("%c|%c|%c\n", pos[0], pos[1], pos[2]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", pos[3], pos[4], pos[5]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", pos[6], pos[7], pos[8]);

    if (winner) {
        printf("Player %d is the winner\n", player);
    } else {
        printf("Math draw\n");
    }
}

int main() {
    int winner = 0, count = 0;
    int pos[9];     // this is our board
    int index, sign, player, flag, i, k, j;

    // initialise the board
    for (i = 0; i < 9; i++) {
        pos[i] = ' ';
    }

    while (count < 9 && winner != 1) {
        flag = 0;
        // print board
        printf("\n");
        printf("%c|%c|%c\n", pos[0], pos[1], pos[2]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[3], pos[4], pos[5]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[6], pos[7], pos[8]);

        // decide which player's turn it is
        if (count % 2 == 0) {
            sign = 'X';
            player = 1;
        } else {
            sign = 'O';
            player = 2;
        }

        printf("Move for player %d (1-9): ", player);
        scanf("%d", &index);
        if (index < 1 || index > 9) {
            printf("Invalid index, choose from 1-9\n");
        }

        if (pos[index - 1] == 'X' || pos[index - 1] == 'O') {
            printf("Position is occupied\n");
        }

        pos[index - 1] = sign;
        count++;

        for (i = 0; i < 9; i++) {
            if (i % 3 == 0) flag = 0;
            if (pos[i] == sign) flag++;
            if (flag == 3) {
                winner = 1;
                win(player, winner, pos);
            }
        }

        flag = 0;

        for (i = 0; i < 3; i++) {
            for (k = i; k <= i + 6; k += 3) {
                if (pos[k] == sign) 
                    flag++;
            }

            if (flag == 3) {
                winner = 1;
                win(player, winner, pos);
            }
            flag = 0;
        }

        if ((pos[0] == sign && pos[4] == sign && pos[8] == sign) || (pos[2] == sign && pos[4] == sign && pos[6] == sign)) {
            winner = 1;
            win(player, winner, pos);
        }  
    }
}

