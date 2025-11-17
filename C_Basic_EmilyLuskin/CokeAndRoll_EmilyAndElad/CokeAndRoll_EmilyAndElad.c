/*------------------------------------------------------
* Filename: CokeAndRoll_EmilyAndElad.c
* Description: A program that simulates a drinks vending machine and returns change in coins,
 and if a special secret code is entered, it displays a secret message.
* Author: Emily Luskin and Elad Mor.
-------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

void print_charge(double payment) {
    int tens, fives, twos, ones, halves, tenths;

    tens = payment / 10;
    payment -= tens * 10;

    fives = payment / 5;
    payment -= fives * 5;

    twos = payment / 2;
    payment -= twos * 2;

    ones = payment / 1;
    payment -= ones * 1;

    halves = payment / 0.5;
    payment -= halves * 0.5;

    tenths = payment / 0.1; 
    payment -= tenths * 0.1;

    printf("Payment received.\n");
    printf("Machine returned %d coins of 0.1 NIS\n", tenths);
    printf("Machine returned %d coins of 0.5 NIS\n", halves);
    printf("Machine returned %d coins of 1 NIS\n", ones);
    printf("Machine returned %d coins of 2 NIS\n", twos);
    printf("Machine returned %d coins of 5 NIS\n", fives);
    printf("Machine returned %d coins of 10 NIS\n\n", tens);
    printf("Enjoy your drink!!\n");
}

int main() {
    char drink; 
    double price = 0;
    int agora10, agora05, shekel1, shekel2, shekel5, shekel10;
    while (1) {

        printf("************** Welcome to the drinks machine **************\n");
        printf("Please select the drink you would like to order:\n");
        printf("press 'C' for Coca-Cola\n");
        printf("press 'D' for Diet-Cola\n");
        printf("press 'O' for Orangeade\n");
        printf("press 'S' for Schweppes\n");
        printf("press 'G' for Grape juice\n");
        printf("press 'W' for Mineral water\n");
        printf("press 'E' to exit the machine\n");
       
        if (scanf(" %c", &drink) != 1) {
            printf("Bad Input!!!\n");
            return 0;
        }
        drink = toupper(drink);

        if (drink == 'E') {
            printf("Machine shutting down, goodbye!\n");
            break;
        }

        switch (drink) {
            case 'C': price = 5.20; break;
            case 'D': price = 7.20; break;
            case 'O': price = 3.40; break;
            case 'S': price = 4.50; break;
            case 'G': price = 3.50; break;
            case 'W': price = 2.50; break;
            default:
                printf("Error: invalid drink choice.\n");
                continue;
        }

        printf("The price of the drink is %.2f NIS\n", price);
        printf("Enter amount of 0.1 NIS: ");
        scanf("%d", &agora10);
        printf("Enter amount of 0.5 NIS: ");
        scanf("%d", &agora05);
        printf("Enter amount of 1 NIS: ");
        scanf("%d", &shekel1);
        printf("Enter amount of 2 NIS: ");
        scanf("%d", &shekel2);
        printf("Enter amount of 5 NIS: ");
        scanf("%d", &shekel5);
        printf("Enter amount of 10 NIS: ");
        scanf("%d", &shekel10);

        double total =
            agora10 * 0.10 +
            agora05 * 0.50 +
            shekel1  * 1.00 +
            shekel2  * 2.00 +
            shekel5  * 5.00 +
            shekel10 * 10.00;

        printf("The machine received payment of %.2f NIS\n", total);

        if (total < price) {
            printf("You need to pay more...\n");
            continue;
        }

        printf("Payment received.\n");

        if (drink == 'C' &&
            agora10 == 1 &&
            shekel2 == 3 &&
            shekel5 == 3 &&
            shekel10 == 7)
        {
            printf("SECRET: Welcome agent, mission authorized.\n");
        }
        
        double change = total - price;
        print_charge(change);

    }

    return 0;
}
