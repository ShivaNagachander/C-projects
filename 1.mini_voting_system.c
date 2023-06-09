#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
char name[100];
int id;
char symbol[50];
int votes;
} Candidatedata;

void createData(Candidatedata *, int);
void displayData();
void voteCount(Candidatedata *, int);
void endAndExit(Candidatedata *, int);
void saveVoterList(int);

int main() {
int num_of_Cand;
printf("-------------------------------------------------------\n");
printf("\t\t\tVoting System\n");
printf("-------------------------------------------------------\n");
printf("Enter the number of candidates: ");
scanf("%d", &num_of_Cand);
Candidatedata *candidates =(Candidatedata *)malloc(num_of_Cand * sizeof(Candidatedata));
if (candidates == NULL) {
printf("!!Memory not allocated!!\n");
return 1;
}
createData(candidates, num_of_Cand);
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
  voteCount(candidates, num_of_Cand);
  break;
case 2:
  displayData();
  system("start candidates.txt");          //system("xdg-open candidates.txt");
  break;
case 3:
  endAndExit(candidates, num_of_Cand);
  system("start candidates.txt");
   system("start voter_list.txt");
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

// to take contestant details
void createData(Candidatedata *candidates, int num_of_Cand) {
FILE *file = fopen("candidates.txt", "w");
if (file == NULL) {
printf("file not created.\n");
return;
}
fprintf(file, "+-----------------+-------+--------------+\n");
fprintf(file, "|   ID   |   Candidate     |    Symbol    |\n");
fprintf(file, "+-------+-----------------+--------------+\n");
for (int i = 0; i < num_of_Cand; i++) {
printf("\nCandidate %d:\n", i + 1);
printf("Name: ");
scanf("%s", candidates[i].name);
candidates[i].id = i + 1;
printf("Symbol: ");
scanf("%s", candidates[i].symbol);
candidates[i].votes = 0;
fprintf(file, "| %d\t| %s\t\t| %s\t\t|\n", candidates[i].id,candidates[i].name, candidates[i].symbol);
}
fprintf(file, "+-------+-----------------+--------------+\n");
fclose(file);
printf("\nData saved in the file.Checkout!.\n");
}

//to take vote input
void voteCount(Candidatedata* candidates, int num_of_Cand) {
int Cand_id;
displayData();
printf("\nEnter the candidate number you want to vote for: ");
scanf("%d", &Cand_id);
if (Cand_id >= 1 && Cand_id <= num_of_Cand) {
candidates[Cand_id - 1].votes++;
printf("Vote successfully recorded!\n");
int voterID;
printf("Enter your voter ID and Leave: ");
scanf("%d", &voterID);
saveVoterList(voterID);
printf("-------------------------------------------------------\n");
return; // Return to the main menu
 } 
else {
printf("Invalid candidate number.\n");
 }
}

//to display data
void displayData() {
FILE *file = fopen("candidates.txt", "r");
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

//to save voter time and id
void saveVoterList(int voterID) {
FILE* file = fopen("voter_list.txt", "a");
if (file == NULL) {
printf("Unable to operate file!\n");
return;
}
time_t currentTime;
time(&currentTime);
fprintf(file, "Voter ID: %d - Time: %s", voterID, ctime(&currentTime));
fclose(file);
}

//to calculate winner and display result 
void endAndExit(Candidatedata* candidates, int numCandidates) {
int totalVotes = 0,maxVotes = 0,drawCount = 0;
Candidatedata* winner = NULL;
for (int i = 0; i < numCandidates; i++) {
    totalVotes += candidates[i].votes;
    if (candidates[i].votes > maxVotes) {
        maxVotes = candidates[i].votes;
        winner = &candidates[i];
        drawCount = 0;  // Reset draw count when a new leader is found
    } else if (candidates[i].votes == maxVotes) {
        drawCount++;  // Increment draw count if there's a tie
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
if (winner != NULL && drawCount == 0) {
    printf("Winner: %s\n", winner->name);
    printf("Votes received: %d\n", winner->votes);
} else if (drawCount > 0) {
    printf("Election Draw: Multiple winners with the same votes.\n");
} else {
    printf("No Win Situation\n");
}
FILE* file = fopen("candidates.txt", "a");
if (file == NULL) {
    printf("Unable to operate file!\n");
    return;
}
fprintf(file, "\nResult Statistics:\n");
fprintf(file, "+-------+-----------------+--------------+--------+\n");
fprintf(file, "|  ID   |   Candidate     |    Symbol    | Votes  |\n");
fprintf(file, "+-------+-----------------+--------------+--------+\n");
for (int i = 0; i < numCandidates; i++) {
    fprintf(file, "| %d\t|\t %s\t\t|\t %s\t\t|\t %d|\n",candidates[i].id, candidates[i].name, candidates[i].symbol, candidates[i].votes);
}
fprintf(file, "+-------+-----------------+--------------+--------+\n");
if (winner != NULL && drawCount == 0) {
    fprintf(file, "\nWinner: %s\n", winner->name);
    fprintf(file, "Votes received: %d\n", winner->votes);
} else if (drawCount > 0) {
    fprintf(file, "\nElection Draw: Multiple winners with the same votes.\n");
} else {
    fprintf(file, "\nNo Win Situation\n");
}
fclose(file);
}
