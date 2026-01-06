#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int n, i;
    int choice, vote;
    int totalVotes = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &n);

    char candidates[n][30];

    int votes[n];

    for (i = 0; i < n; i++) {
        votes[i] = 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i]);
    }

    while (1) {
        printf("\n--- Voting System ---\n");
        printf("1. Vote\n");
        printf("2. Show Results\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nCandidates:\n");
            for (i = 0; i < n; i++) {
                printf("%d. %s\n", i + 1, candidates[i]);
            }

            printf("Enter your vote: ");
            scanf("%d", &vote);

            if (vote >= 1 && vote <= n) {
                votes[vote - 1]++;
                totalVotes++;
                printf("Vote registered successfully.\n");
            } else {
                printf("Invalid vote!\n");
            }
        }

        else if (choice == 2) {
            int maxVotes = votes[0];
            int winnerIndex = 0;
            int tie = 0;

            printf("\n--- Results ---\n");

            for (i = 0; i < n; i++) {
                printf("%s: %d votes\n", candidates[i], votes[i]);

                if (votes[i] > maxVotes) {
                    maxVotes = votes[i];
                    winnerIndex = i;
                    tie = 0;
                }
                else if (votes[i] == maxVotes && i != winnerIndex) {
                    tie = 1;
                }
            }

            printf("Total votes: %d\n", totalVotes);

            if (tie == 1) {
                printf("Result: Tie between candidates\n");
            } else {
                printf("Winner: %s \n", candidates[winnerIndex]);
            }
        }

        else if (choice == 3) {
            printf("Exiting voting system...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

	return 0;
}
