//to add loop for completion of project

#include <stdio.h>
#include<math.h>
int main()
{
    float a,b;
    char op,x='%';
    char answer;
    do{
    printf("\n \n \t HEY THERE, U ARE USING SHIVA NC'S CALCULATOR \t\n");
    printf("\n\nEnter two numbers   : \n");
    scanf("%f%f",&a,&b);    //\t for space \n for next line
    printf("\t + is for addition \n \t - is for subtraction \n \t / is for division \n \t * is for multiplication \n \t %c is for retaining remainder \n \t ^ denotes exponentiation #pow\n",x);
    printf ("\t Enter the operation that you want to perform + ,- ,/,*,^,%c :\n",x);
    scanf(" %c",&op);

    switch(op)
    {
        case '+':
        printf("The above entered numbers for performing the calculation are %f and %f\n",a,b);
        printf("The result of + is : %f\n",a+b);
        break;

        case '-':
        printf("The above entered numbers for performing the calculation are %f and %f\n",a,b);
        printf("The result of - is : %f\n",a-b);
        break;

        case '*':
        printf("The above entered numbers for performing the calculation are %f and %f\n",a,b);
        printf("The result of * is : %f\n",a*b);
        break;

        case '%':
        printf("The above entered numbers for performing the calculation are %f and %f\n",a,b);
        printf("The result of %c is : %f\n",x,(int)a%(int)b);
        break;

        case '^':
        printf("The above entered numbers for performing the calculation are %f and %f\n",a,b);
        printf("The result of * is : %f\n",pow(a,b));
        break;
        
    }
printf("\nPress Y to continue. Press any Key To Exit");
scanf(" %c",&answer); // dont forget type &=
}
while(answer == 'y' || answer == 'Y');
}
