#include <stdio.h>

void win(int player, int winner, int pos[]) {
    
    printf("\n");
    printf("%c|%c|%c\n", pos[0], pos[1], pos[2]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", pos[3], pos[4], pos[5]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", pos[6], pos[7], pos[8]);

    // if winner == 1 i.e. there is a winner, print the winner
    // otherwise it's a draw
    if (winner) {
        printf("Player %d is the winner\n", player);
    } else {
        printf("Match draw\n");
    }
}

int main() {

    int winner = 0;     // boolean for if a player has won yet (0 or 1)
    int roundCount = 0;  
    int pos[9];         // this is our board (9 cells)
    int index;          // index of the board (1-9)
    int sign;           // either cross or naught (X or O)
    int player;         // 1 or 2    
    int flag;           // a variable to check win condition (if 3 of the same signs have been placed in a row)
    int i, k, j;        // counters for loops

    // initialise each board cell with empty value
    for (i = 0; i < 9; i++) {
        pos[i] = ' ';
    }

    while (roundCount < 9 && winner != 1) {
        flag = 0;
        // print the tictactoe board
        printf("\n");
        printf("%c|%c|%c\n", pos[0], pos[1], pos[2]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[3], pos[4], pos[5]);
        printf("-+-+-\n");
        printf("%c|%c|%c\n", pos[6], pos[7], pos[8]);

        // decide which player's turn it is
        if (roundCount % 2 == 0) {
            sign = 'X';
            player = 1;
        } else {
            sign = 'O';
            player = 2;
        }

        printf("Move for player %d: ", player);
        scanf("%d", &index);


        if (index < 1 || index > 9) {
            printf("Invalid index, choose from 1-9\n");
        } else if (pos[index - 1] == 'X' || pos[index - 1] == 'O') {
            printf("Position %d is occupied\n", index);
        } else {
            pos[index - 1] = sign;
            roundCount++;
        }

        // check if a player has won via 3 horizontal cells
        for (i = 0; i < 9; i++) {
            if (i % 3 == 0) flag = 0;
            if (pos[i] == sign) flag++;
            if (flag == 3) {
                winner = 1;
                win(player, winner, pos);
            }
        }

        // reset the flag back to 0 to check if a player has won via 3 vertical cells
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

        // check if a player has won via 3 diagonal cells
        if ((pos[0] == sign && pos[4] == sign && pos[8] == sign) || (pos[2] == sign && pos[4] == sign && pos[6] == sign)) {
            winner = 1;
            win(player, winner, pos);
        }  
    }
}

