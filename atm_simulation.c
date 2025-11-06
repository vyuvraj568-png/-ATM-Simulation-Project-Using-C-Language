#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234, enteredPin, choice;
    float balance = 10000.0;  // initial balance
    float deposit, withdraw;

    printf("*******************************\n");
    printf("   Welcome to Simple ATM\n");
    printf("*******************************\n");

    printf("\nEnter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("\nInvalid PIN! Access Denied.\n");
        return 0; // Exit program
    }

    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYour current balance is: ₹%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: ₹");
                scanf("%f", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("₹%.2f deposited successfully.\n", deposit);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: ₹");
                scanf("%f", &withdraw);
                if (withdraw > balance) {
                    printf("Insufficient balance!\n");
                } else if (withdraw <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else {
                    balance -= withdraw;
                    printf("₹%.2f withdrawn successfully.\n", withdraw);
                }
                break;

            case 4:
                printf("\nThank you for using our ATM. Have a nice day!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
