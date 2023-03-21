#include <stdio.h>
#include <stdlib.h>

/**
 * define maximum number of accounts
 * create accounts
 * withdraw
 * check balance
*/

#define MAX_ACCOUNTS 100

struct account
{
    int account_number;
    char name[100];
    float balance;
    char account_type;
};

int main(void)
{
    struct account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice, account_num;
    float amount;

    printf("***Welcome to BT payment system***\n");

    while (1)
    {
        printf("\n1. Add account.\n2. Deposit.\n3. Withdraw.\n4. Check Balance.\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (num_accounts < MAX_ACCOUNTS)
            {
                printf("\nEnter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Enter name: ");
                scanf("%s", accounts[num_accounts].name);
                printf("Enter initial balance: ");
                scanf("%f", &accounts[num_accounts].balance);
                printf("Enter account type (savings or current): ");
                scanf("%s", accounts[num_accounts].account_type);
                num_accounts++;
                printf("\nAccount created successfully!\n");
            }
            else
            {
                printf("\nMaximum number of accounts reached!\n");
            }
            break;

        case 2:
            printf("\nEnter account number: ");
            scanf("%d", &account_num);

            for (int i = 0; i < num_accounts; i++)
            {
                if (accounts[i].account_number == account_num)
                {
                    printf("Enter amount to deposit: ");
                    scanf("%f", &amount);
                    accounts[i].balance += amount;
                    printf("\nDeposit successful!\n");
                    break;
                }
                else if (i == num_accounts - 1)
                {
                    printf("\nAccount not found!\n");
                }
            }
            break;

        case 3:
            printf("\nEnter account number:");
            scanf("%d", &account_num);

            for (int i = 0; i < num_accounts; i++)
            {
                if (accounts[i].account_number == account_num)
                {
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &amount);

                    if (amount > accounts[i].balance)
                    {
                        printf("\nInsufficient balance!\n");
                    }
                    else
                    {
                        accounts[i].balance -= amount;
                        printf("\nWithdrawal successful!\n");
                    }
                    break;
                }
                else if (i == num_accounts - 1)
                {
                    printf("\nAccount not found!\n");
                }
            }
            break;

        case 4:
            printf("\nEnter account number: ");
            scanf("%d", &account_num);

            for (int i = 0; i < num_accounts; i++)
            {
                if (accounts[i].account_number == account_num)
                {
                    printf("\nAccount Number: %d\n", accounts[i].account_number);
                    printf("Name: %s\n", accounts[i].name);
                    printf("Balance: %.2f\n", accounts[i].balance);
                    printf("Account type: %s\n", accounts[i].account_type);
                    break;
                }
                else if (i == num_accounts - 1)
                {
                    printf("\nAccount not found!\n");
                }
            }
            break;

        case 5:
            printf("\nThank you for using BT payment system!\n");
            exit(0);

        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }

    return (0);
}