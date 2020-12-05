#include "myBank.h"
#include <stdio.h>

// open a new account and insert the anount to it
// print the new account number
int open_new_account(double accounts[LINE_S][ROW_S],double amount)
{    
    int account_n=-1,find=1;
for (int i = 0; i < ROW_S && find==1; i++)
{
    // if the account is closed open it 
    if(accounts[0][i]==0)
       { account_n = 901 + i;
       accounts[0][i]=1;
       accounts[1][i]= amount;
       find = 0;
       }
}
printf("New account number is: %d\n\n",account_n);
return 1;    
}

// print the balance of the cuurent account
int account_balance(double accounts[LINE_S][ROW_S ],int account_number)
{
    double temp1;
        temp1 = accounts[1][account_number-901];
        printf("The balance of account number %d is: %0.2lf\n\n",account_number,temp1);
        return 1;
}

// add the amount to the account balance, print the new blalance
int account_deposit(double accounts[LINE_S ][ROW_S],int account_number,double amount)
{
        double temp_sum;
        temp_sum = accounts[1][account_number-901] + amount;
        accounts[1][account_number-901] = temp_sum;
        printf("The new balance is: %0.2lf\n\n",temp_sum);
        return 1;
}

// withdrawal the sum of the amount from the account balance and print the new balance
// if the amount is lower than the account balance, else print error massage
int account_withdrawal(double accounts[LINE_S ][ROW_S],int account_number,double amount)
{
     double temp,balance;
    balance = accounts[1][account_number-901];
    // if the blanace is lower than the amount don't withdrawal
    if((balance-amount) <0)
    { 
         printf("Cannot withdraw more than the balance\n\n");
         return 0;
    }
    else{
        temp = balance - amount;
        accounts[1][account_number-901] = temp;
        printf("The new balance is: %0.2lf\n\n",temp);
        return 1;
    }
    }

    //close the current acount if not been closed already and print it
    int close_account(double accounts[LINE_S ][ROW_S],int account_number)
    {
        accounts[0][account_number-901]=0;
        printf("Closed account number %d\n\n",account_number);
        return 1;
    }
    
    //change all the open accounts balances accordingly to the interset rate
    int interset_accounts(double accounts[LINE_S ][ROW_S ],int interset_rate)
    {
        double rate;
        rate = (100 + (double)interset_rate)/100;
        // go over the account and if open change the balance 
        for (int i = 0; i < ROW_S; i++)
        {
            if(accounts[0][i] ==1)
            accounts[1][i] = ((accounts[1][i]) * rate);
        }
        printf("\n");
        return 1;
      
    }

    // print all the open accounts details
    int print_accounts(double accounts[LINE_S][ROW_S])
    {
        // go over all the open accounts and print them 
        for (int i = 0; i < ROW_S; i++)
        {
            if(accounts[0][i]==1)
             printf("The balance of account number %d is: %0.2lf\n",(i+901),accounts[1][i]);
        }
        printf("\n");
        return 1;
    }

    // close all the accounts
    int close_all_accounts(double accounts[LINE_S ][ROW_S])
    {
        for (int i = 0; i < ROW_S; i++)
        {
            accounts[0][i] =0;
        }
        return 1;
    }

    // print the transaction menu
     int print_all_options()
   {
     printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
      return 1;
   }

   // return how many account are open 
   int open_accounts_counter(double accounts[LINE_S][ROW_S])
   {
     int counter=0;
     for (int i = 0; i < ROW_S; i++)
     {
       if(accounts[0][i] == 1)
       {counter++;}
     }
     return counter;
   }
