#include <stdio.h>

int main() {
    char subjects[][30] = {
        "M2", "PPS2", "BEE", "AP", "AP Lab", "PPS2 Lab", "EWS Lab", "ECS Lab", "BEE Lab"
    };

    float attendance[9], totalAttendance[9];
    int i;
    float totalSum = 0, attendancePercentage;
     printf("-------------------------------------------------------\n");
    printf("\t\t\t AU Attendace Calculator \n");
     printf("-------------------------------------------------------\n");
    printf("Enter attendance for each subject [0-100]:\n");
    for (i = 0; i < 9; i++) {
        printf("%s: ", subjects[i]);
        scanf("%f", &attendance[i]);
    }

    for (i = 0; i < 9; i++) {
        totalSum += attendance[i];
        totalAttendance[i] = 100; 
    }

    attendancePercentage = (totalSum / (100 * 9)) * 100;
    if (attendancePercentage < 75)
    {
        printf("\nBad luck! You might need to pay condonation as your Attendance Percentage is: %.2f%%\n", attendancePercentage);
    }
    else {
        printf("\nOverall Attendance Percentage: %.2f%%\n", attendancePercentage);
    }
    printf("Do take keen observation while entering your attendace\n*Note that your attendance is available in campx app input those attendace values into this \n");
    return 0;
}
