#include<stdio.h>

char CANDIDATE1[20] = "CANDIDATE A";
char CANDIDATE2[20] = "CANDIDATE B";
char CANDIDATE3[20] = "CANDIDATE C";
char CANDIDATE4[20] = "CANDIDATE D";
void castVote();
void votesStats(int i);
void getLeadingCandidate();
void getWonCandidate();
void Candidatedata();
void getback();
int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0,choice;

int main()
{
int i=0,j;
printf("\n---------------------------------------------");
printf("\n-------------PROJECT NUMBER 25---------------");
printf("\n------------Simple Voting system-------------");
printf("\n---------------------------------------------");
jump:
do
{
printf("\n\n ##### Welcome #####\n");
printf("============================================\n");
printf("\n \t 1. Cast Vote");
printf("\n \t 2. Candidate Data");
printf("\n \t 3. Vote Statistics");
printf("\n \t 0. Exit the Poll\n");
printf("\n============================================\n");
printf("\n\n Please enter your choice : ");
scanf("%d", &choice);
switch(choice)
{
case 1: castVote();i++;break;
case 2: Candidatedata();break;
case 3: votesStats(i);break;
case 0: break;
default: printf("\n Error: Invalid Choice");
}
}
while(choice!=0&&choice!=3);
if(choice==0)
{
    if(i>=5)
    {
        printf("The poll is Ended");
        votesStats(i);
        printf("------------------------Total Votes Casted %d-----------------------\n",i);
    printf("-------------------------------------------------------------------\n");
        getWonCandidate();
    }
    else
    {
        printf("-------------------------------------------------------------------\n");
        printf("To end the poll u should cast atleast 5 votes\n More %d votes to be casted to end",5-i);
        printf("\n Do you want to stop the election progress and exit?\n Enter:\n 1 for Yes\n 0 for No\n");
        printf("-------------------------------------------------------------------\n");
        scanf("%d",&j);
        if(j==1)
        {
            printf("The poll is Ended");
        votesStats(i);
        printf("------------------------Total Votes Casted %d-----------------------\n",i);
    printf("-------------------------------------------------------------------\n");
        getWonCandidate();
        }
        else
        {
        getback();
        goto jump;
        }
    }
}
else if(choice==3)
{
    printf("------------------------Total Votes Casted %d-----------------------\n",i);
    printf("-------------------------------------------------------------------\n");
    void getback();
    goto jump;
}
return 0;
}

void castVote()
{
int choice;
printf("\n\n #### Please Choose your Candidate ####\n");
    printf("---------------------------\n");
    printf(" Candidate Name\t\tCode\n");
    printf("---------------------------\n");
    printf("  CANDIDATE A\t\t 1\n");
    printf("  CANDIDATE B\t\t 2\n");
    printf("  CANDIDATE C\t\t 3\n");
    printf("  CANDIDATE D\t\t 4\n");
    printf("     NOTA\t\t     5\n");
    printf("---------------------------\n");
printf("\n\n\a Input Your Choice Candidate Code : ");
scanf("%d",&choice);

switch(choice)
{
    case 1: votesCount1++; break;
    case 2: votesCount2++; break;
    case 3: votesCount3++; break;
    case 4: votesCount4++; break;
    case 5: spoiledtvotes++; break;
    default: printf("\n Error: Wrong Choice !! Please retry");
             getchar();
}
printf("\n Thanks for vote !!!!");
getback();
}

void votesStats(int i)
{
    printf("\n\n #### Voting Statics ####\n");
    printf("-------------------------------------------------------------------\n");
    printf(" Candidate Name\t\tCode\t\tVote Count\t\t Vote Percentage\n");
    printf("-------------------------------------------------------------------\n");
    printf("  CANDIDATE A\t\t 1\t\t\t\t %d\t\t\t\t\t%.2f\n",votesCount1,(votesCount1*100.0)/i);
    printf("  CANDIDATE B\t\t 2\t\t\t\t %d\t\t\t\t\t%.2f\n",votesCount2,(votesCount2*100.0)/i);
    printf("  CANDIDATE C\t\t 3\t\t\t\t %d\t\t\t\t\t%.2f\n",votesCount3,(votesCount3*100.0)/i);
    printf("  CANDIDATE D\t\t 4\t\t\t\t %d\t\t\t\t\t%.2f\n",votesCount4,(votesCount4*100.0)/i);
    printf("     NOTA\t\t     5\t\t\t\t %d\t\t\t\t\t%.2f\n",spoiledtvotes,(spoiledtvotes*100.0)/i);
    printf("-------------------------------------------------------------------\n");
}
void getWonCandidate()
{
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------Result------------------------------\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    printf("----------------[%s] has won the Election-----------------",CANDIDATE1);
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    printf("----------------[%s] has won the Election-----------------",CANDIDATE2);
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    printf("----------------[%s] has won the Election-----------------",CANDIDATE3);
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    printf("----------------[%s] has won the Election-----------------",CANDIDATE4);
    else
    printf("--------------------Warning !!! No-win situation--------------------");
    printf("\n-------------------------------------------------------------------\n");
}
void Candidatedata()
{
    printf("\n\n #### Candidate Profile ####\n");
    printf("---------------------------\n");
    printf(" Candidate Name\t\tCode\n");
    printf("---------------------------\n");
    printf("  CANDIDATE A\t\t 1\n");
    printf("  CANDIDATE B\t\t 2\n");
    printf("  CANDIDATE C\t\t 3\n");
    printf("  CANDIDATE D\t\t 4\n");
    printf("     NOTA\t\t     5\n");
    printf("---------------------------\n");
    getback();
}
void getback()
{
    printf("\n---------------------------\n");
    printf("\n PRESS ANY KEY TO RETURN MENU:\t");
    getchar();
    getchar();
}
