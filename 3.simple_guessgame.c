#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
int num,guess,nguesses=1;
printf("\t\t*** HELLO WELCOME TO THE GUESS U GUSS GAME NC***\n");
srand(time(0));
num=rand()%100+1;
printf("\n##The number u should guess is between %d and %d\n##",num-10,num+10);
do{
    printf("\n--guess the num bw 1 to 100--\n::");
    scanf("%d",&guess);
    if(guess>num){
printf("\n***lower num please***\n");
    }
    else if(guess<num){
printf("\n***higher num please***\n");
    }
    else{
        printf("\n***you guessed it in %d attempts***\n",nguesses);
    }
    nguesses++;

}
while (guess!=num);
if(nguesses<=10)
printf("\n***winner winner chicken dinner***");
else
printf("\n***try again ----->restart***");
printf("\n***the number is %d***\n",num);
return 0;
}