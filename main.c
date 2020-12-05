#include <stdio.h>
#include <ctype.h>
#include "myBank.h"

int main()
 {    int go_on = 1,account_number,interset_rate;
      double accounts[LINE_S][ROW_S];// hold the information of the accounts
      double amount;
      char letter_temp;
      // go over and rest all the account to 0 
      for (int i = 0; i < LINE_S; i++)
      {
        for (int j = 0; j < ROW_S; j++)
        {
          accounts[i][j]= 0;
        }
      }
      // go until go_on != 1
do
{
  // prints the transection menu
print_all_options();
// get a char 
scanf(" %c",&letter_temp);
    switch (letter_temp)
    {
      // if letter_temp is 'O' get a amount and open an account
    case 'O':
    printf("Please enter amount for deposit: ");
      if(scanf("%lf",&amount)==0)
     {printf("Failed to read the amount\n\n");
     break;}
     else{
       // if the amount is a negative number print error massage
    if(amount<0)
    {printf("Invalid Amount\n\n");
    break;}
    else
    {
      // if there is no account available print error massage
      if (open_accounts_counter(accounts) == 50)
      {
       printf("There is no bank accounts available\n\n");
        break;
      }
      else
      {
        open_new_account(accounts,amount);
      }
    }
    }
      break;
    
     // if letter_temp is 'B' get an account number and print the account balance
    case 'B':
    printf("Please enter account number: ");
      if(scanf("%d",&account_number)==0)
      {printf("Failed to read the account number\n\n");
      break;}
      // if the account number is not valid print error massage
       if(account_number >(900 + ROW_S )|| account_number < 901)
       {
        printf("Invalid account number\n\n");
         break;}
         // if the account is closed print an error massage
       if(accounts[0][account_number-901]==0)
       {
        printf("This account is closed\n\n");
         break;
        }
    else{
      account_balance(accounts,account_number);}
    break;

    // if letter_temp is 'D' get an account number and amount and print the account balance
    // after deposit the amount into the account
    case 'D':
      printf("Please enter account number: ");
      if(scanf("%d",&account_number)==0)
        {printf("Failed to read the account number\n\n");
        break;}
        // if the account number is not valid print error massage
      if(account_number >(900 + ROW_S )|| account_number < 901)
        {printf("Invalid account number\n\n");
          break;}
         // if the account is closed print an error massage
      if(accounts[0][account_number-901]==0)
         {
        printf("This account is closed\n\n");
       break;}
      printf("Please enter the amount to deposit: ");
      if(scanf("%lf",&amount)==0)
      {printf("Failed to read the amount\n\n");
      break;}
      // if the amount is a negative number print error massage
      if(amount<0)
      {
        printf("Cannot deposit a negative amount\n\n");
        break;
      }
      account_deposit(accounts,account_number,amount);
      break;
     
      // if letter_temp is 'W' get an account number and amount and print the account balance
    // after withdrawal of the amount from the account
    case 'W':
      printf("Please enter account number: ");
      if(scanf("%d",&account_number)==0)
      {printf("Failed to read the account number\n\n");
      break;}
      // if the account number is not valid print error massage
      if(account_number >(900 + ROW_S )|| account_number < 901)
      {printf("Invalid account number\n\n");
      break;}
       // if the account is closed print an error massage
      if(accounts[0][account_number-901]==0)
      {
         printf("This account is closed\n\n");
         break;
      }
      printf("Please enter the amount to withdraw: ");
      if(scanf("%lf",&amount)==0)
      {printf("Failed to read the amount\n\n");
      break;}
      // if the amount is a negative number print error massage
      if(amount<0)
    {
        printf("Invalid Amount\n\n");
        break;
    }
      account_withdrawal(accounts,account_number,amount);
      break;

   // if letter_temp is 'C' get an account number close the account
   // and print tht the account is closed
    case 'C':
     printf("Please enter account number: ");
      if(scanf("%d",&account_number)==0)
      {printf("Failed to read the account number\n\n");
      break;}
      // if the account number is not valid print error massage
      if(account_number>(900 + ROW_S )|| account_number < 901)
        {printf("Invalid account number\n\n");
      break;}
       // if the account is closed print an error massage
    if(accounts[0][account_number-901]==0)
    {
        printf("This account is alread cloded\n\n");
       break;
    }
      close_account(accounts,account_number);
      break;

    // if letter_temp is 'I' get an interset rate 
    // and change every open acount accordingly to the interset rate
      case 'I':
       printf("Please enter interest rate: ");
      if(scanf("%d",&interset_rate)==0)
      {printf("Failed to read the interset rate\n\n");
      break;}
      // if the interset rate is not valid print error massage
      if(interset_rate < 0 || interset_rate > 100)
        {printf("Invalid interest rate\n\n");
      break; }
      interset_accounts(accounts,interset_rate);
      break;
     
     // if letter_temp is 'P' prints all the open account details
    case 'P':
      print_accounts(accounts);
      break;

   // if letter_temp is 'E' close all the accounts and exits the program
    case 'E':
      close_all_accounts(accounts);
      // change go_on to exit the while
      go_on=0;
      break;

    // print when letter_temp is differnt from all of the transection options
    default:
    printf("Invalid transaction type\n\n");
      
    }
    
} while (go_on == 1);
return 1;
 }

