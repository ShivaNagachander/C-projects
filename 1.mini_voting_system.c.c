#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    int id;
    char symbol[20];
    int votes;
};

void createData(struct Candidate* candidates, int numCandidates);
void displayData();
void voteCount(struct Candidate* candidates, int numCandidates);
void endAndExit(struct Candidate* candidates, int numCandidates);

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    struct Candidate* candidates = (struct Candidate*)malloc(numCandidates * sizeof(struct Candidate));
    if (candidates == NULL) {
        printf("!!Memory not allocated!!\n");
        return 1;
    }

    createData(candidates, numCandidates);

    int choice;
    do {
        printf("\nVoting System Menu:\n");
        printf("-------------------------------------------------------\n");
        printf("| 1. Vote                                               |\n");
        printf("| 2. View Data                                          |\n");
        printf("| 3. End and Exit Election                              |\n");
        printf("-------------------------------------------------------\n");
        printf("Enter your choice [1-3]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                voteCount(candidates, numCandidates);
                break;
            case 2:
                displayData();
                system("start candidates.txt");
                break;
            case 3:
                endAndExit(candidates, numCandidates);
                system("start candidates.txt");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    } while (choice != 3);

    free(candidates);
    return 0;
}

void createData(struct Candidate* candidates, int numCandidates) {
    FILE* file = fopen("candidates.txt", "w");
    if (file == NULL) {
        printf("file not created.\n");
        return;
    }

    fprintf(file, "+-----------------+-------+--------------+\n");
    fprintf(file, "|   ID   |   Candidate     |    Symbol    |\n");
    fprintf(file, "+-------+-----------------+--------------+\n");

    for (int i = 0; i < numCandidates; i++) {
        printf("\nCandidate %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].id = i + 1;
        printf("Symbol: ");
        scanf("%s", candidates[i].symbol);
        candidates[i].votes = 0;

        fprintf(file, "| %d\t| %s\t\t| %s\t\t|\n",
                candidates[i].id, candidates[i].name, candidates[i].symbol);
    }

    fprintf(file, "+-------+-----------------+--------------+\n");

    fclose(file);
    printf("\nData saved in the file.Checkout!.\n");
}

void voteCount(struct Candidate* candidates, int numCandidates) {
    int candidateNum;
    displayData();
    printf("\nEnter the candidate number you want to vote for: ");
    scanf("%d", &candidateNum);

    if (candidateNum >= 1 && candidateNum <= numCandidates) {
        candidates[candidateNum - 1].votes++;
        printf("Vote successfully recorded!\n");
        printf("Press 'y' to return to the main menu: ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            return; // Return to the main menu
        }
    } else {
        printf("Invalid candidate number.\n");
    }
}

void displayData() {
    FILE* file = fopen("candidates.txt", "r");
    if (file == NULL) {
        printf("Unable to Operate File !\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void endAndExit(struct Candidate* candidates, int numCandidates) {
    int totalVotes = 0;
    int maxVotes = 0;
    int winnerIndex = -1;

    for (int i = 0; i < numCandidates; i++) {
        totalVotes += candidates[i].votes;

        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    printf("\nResult:\n");
    printf("+-------+-----------------+--------------+--------+\n");
    printf("|  ID   |   Candidate     |    Symbol    | Votes  |\n");
    printf("+-------+-----------------+--------------+--------+\n");

    for (int i = 0; i < numCandidates; i++) {
        printf("| %d\t| %s\t\t| %s\t\t| %d|\n",
               candidates[i].id, candidates[i].name, candidates[i].symbol, candidates[i].votes);
    }

    printf("+-------+-----------------+--------------+--------+\n");

    printf("\nTotal Number of Votes Casted: %d\n", totalVotes);

    if (winnerIndex != -1) {
        printf("Winner: %s\n", candidates[winnerIndex].name);
        printf("Votes received: %d\n", candidates[winnerIndex].votes);
    } else {
        printf("No votes casted.\n");
    }

    FILE* file = fopen("candidates.txt", "a");
    if (file == NULL) {
        printf("unable to operate file!\n");
        return;
    }

    fprintf(file, "\nResult Statistics:\n");
    fprintf(file, "+-------+-----------------+--------------+--------+\n");
    fprintf(file, "|  ID   |   Candidate     |    Symbol    | Votes  |\n");
    fprintf(file, "+-------+-----------------+--------------+--------+\n");

    for (int i = 0; i < numCandidates; i++) {
        fprintf(file, "| %d\t| %s\t\t| %s\t\t| %d|\n",
                candidates[i].id, candidates[i].name, candidates[i].symbol, candidates[i].votes);
    }

    fprintf(file, "+-------+-----------------+--------------+--------+\n");

    if (winnerIndex != -1) {
        fprintf(file, "\nWinner: %s\n", candidates[winnerIndex].name);
        fprintf(file, "Votes received: %d\n", candidates[winnerIndex].votes);
    } else {
        fprintf(file, "\nNo votes casted.\n");
    }

    fclose(file);
}
