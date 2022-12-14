#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void) {
    return (rand() % 6) + (rand() % 6) + 2;
}

int play_game(void) {
    int point, sum;

    sum = roll_dice();
    printf("You rolled: %d\n", sum);
    if (sum == 7 || sum == 11) {
        return 1;
    }
    else if (sum == 2 || sum == 3 || sum == 12) {
        return 0;
    }
    else {
        printf("Your point is: %d\n", point = sum);
        while ((sum = roll_dice())) {
            printf("You rolled: %d\n", sum);
            if (sum == point) {
                return 1;
            }
            else if (sum == 7) {
                return 0;
            }
        }
        return 2;
    }
}

int main(void) {
    int wins, losses;
    char play;
    
    wins = 0, losses = 0;
    play = 'y';
    
    srand((unsigned) time(NULL));

    while (play == 'y') {
        outcome = play_game();
        if (outcome == 1) {
            printf("You win!\n");
            wins += 1;
        }
        else if (outcome == 0) {
            printf("You lose!\n");
            losses += 1;
        }
        else {
            printf("Something went wrong.\n");
        }
        printf("Would you like to play again?: ");
        scanf(" %c", &play);
    }
    printf("\nWins: %d, Losses: %d", wins, losses);
    
    return 0;
}
