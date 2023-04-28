#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>

char user_input[];

void menu() {
    printf("\n");
    printf("=====================================\n");
    printf("         PROMPT MENU      \n");
    printf("=====================================\n");
    printf("   1. Open Chrome\n");
    printf("   2. Open Notepad\n");
    printf("   3. Open Command Prompt\n");
    printf("   4. Display Current Time\n");
    printf("   5. Open YouTube\n");
    printf("   6. Open Google\n");
    printf("   7. Open ChatGPT\n");
    printf("   8. Open Nc pedia\n");
    printf("   9. Exit\n");
    
    printf("=====================================\n");
    printf("\n");
}

int main() {
    system("cls");
    printf(" \tHELLO I AM C LANGUAGE BOT~Limited addition \n \tHOW CAN I HELP YOU\n");

    while(1) {
        menu();

        printf("Enter your choice (1-9): ");
        int choice;
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1:
                printf("ok bhai, opening Chrome browser\n");
                system("start chrome");
                break;

            case 2:
                printf("ok bhai, opening Notepad editor\n");
                system("start notepad");
                break;

            case 3:
                printf("ok bhai, opening Command Prompt\n");
                system("start cmd");
                break;

            case 4: {
                time_t s, val = 1;
                struct tm* current_time;
                s = time(NULL);
                current_time = localtime(&s);
                printf("bot ==> %02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
                break;
            }

            case 5:
                printf("ok bhai, opening YouTube\n");
                system("start http://youtube.com");
                break;

            case 6:
                printf("ok bhai, opening Google\n");
                system("start https://www.google.com/");
                break;

            case 7:
                printf("ok bhai, opening ChatGPT\n");
                system("start https://www.chatgpt.com/");
                break;
            
            case 8:
                printf("ok bhai, opening NC pedia\n");
                system("start https://www.youtube.com/channel/UCjdcIf4Y8SldDYTTD2zXpuA");
                break;
            case 9:
                printf("ok bhai, goodbye!\n");
                return 0;

            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
        fflush(stdin);
    }
    return 0;
}
