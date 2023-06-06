#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rice;
    int wheat;
    int moong;
    int chana;
    int oil;
} Cart;

void daily_staples();
void bill(Cart *cart);
void addToCart(Cart *cart, int code, int quantity);

int main() {
    Cart *cart = (Cart *)malloc(sizeof(Cart));
    cart->rice = 0;
    cart->wheat = 0;
    cart->moong = 0;
    cart->chana = 0;
    cart->oil = 0;
    
    printf("----------------------------------------\n");
    printf("----------Anurag Grocery Shop-----------\n");
    printf("-------------Item Display---------------\n");
    
    int code;
    while (1) {
        daily_staples();
        printf("\nEnter Product Code: ");
        scanf("%d", &code);
        
        if (code == 0) {
            bill(cart);
            break;
        }
        
        int quantity;
        printf("Enter Quantity: ");
        scanf("%d", &quantity);
        
        addToCart(cart, code, quantity);
        printf("Item added to your cart.\n");
    }

    free(cart);
    return 0;
}

void daily_staples() {
    printf("----------------------------------------\n");
    printf("Daily Staples\n");
    printf("----------------------------------------\n");
    printf("Name          Code   Quantity   Price\n");
    printf("Rice            1      1kg      Rs.50/-\n");
    printf("Wheat Flour     2      1kg      Rs.45/-\n");
    printf("Moong Dal       3      1kg      Rs.150/-\n");
    printf("Chana Dal       4      1kg      Rs.120/-\n");
    printf("Groundnut Oil   5      1lt      Rs.195/-\n");
    printf("----------------------------------------\n");
    printf("Enter '0' to End Shopping and get Bill\n");
    printf("----------------------------------------\n");
}

void bill(Cart *cart) {
    int r_cost = cart->rice * 50;
    int w_cost = cart->wheat * 45;
    int m_cost = cart->moong * 150;
    int c_cost = cart->chana * 120;
    int o_cost = cart->oil * 195;

    FILE *file = fopen("bill.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    fprintf(file, "--------------------------------------\n");
    fprintf(file, "---------Anurag Grocery Shop----------\n");
    fprintf(file, "----------------Bill------------------\n");
    fprintf(file, "--------------------------------------\n");  
    fprintf(file, "   Name         Quantity    Cost\n");
    
    if (cart->rice != 0) {
        fprintf(file, "   Rice           %dkg     Rs.%d/-\n", cart->rice, r_cost);
    }
    if (cart->wheat != 0) {
        fprintf(file, "   Wheat Flour    %dkg     Rs.%d/-\n", cart->wheat, w_cost);
    }
    if (cart->moong != 0) {
        fprintf(file, "   Moong Dal      %dkg     Rs.%d/-\n", cart->moong, m_cost);
    }
    if (cart->chana != 0) {
        fprintf(file, "   Chana Dal      %dkg     Rs.%d/-\n", cart->chana, c_cost);
    }
    if (cart->oil != 0) {
        fprintf(file, "   Groundnut Oil  %dlt     Rs.%d/-\n", cart->oil, o_cost);
    }
    fprintf(file, "--------------------------------------\n");
    fprintf(file, "      Amount to be Paid Rs.%d/-\n", r_cost + w_cost + c_cost + m_cost + o_cost);
    fprintf(file, "--------------------------------------\n");
    fprintf(file, "        Thank You Visit Again\n");
    fprintf(file, "--------------------------------------\n");
    
    fclose(file);
    printf("Bill generated successfully. Please check the 'bill.txt' file.\n");
}

void addToCart(Cart *cart, int code, int quantity) {
    switch (code) {
        case 1:
            cart->rice += quantity;
            break;
        case 2:
            cart->wheat += quantity;
            break;
        case 3:
            cart->moong += quantity;
            break;
        case 4:
            cart->chana += quantity;
            break;
        case 5:
            cart->oil += quantity;
            break;
        default:
            printf("Incorrect Code.\n");
            break;
    }
}