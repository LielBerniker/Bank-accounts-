#ifndef MTBANK_H
#define MYBANK_H
#define LINE_S 2
#define ROW_S 50

int open_new_account(double accounts[LINE_S][ROW_S],double amount);
int account_balance(double accounts[LINE_S][ROW_S],int account_number);
int account_deposit(double accounts[LINE_S][ROW_S],int account_number,double amount);
int account_withdrawal(double accounts[LINE_S][ROW_S],int account_number,double amount);
int close_account(double accounts[LINE_S][ROW_S],int account_number);
int interset_accounts(double accounts[LINE_S][ROW_S],int interset_rate);
int print_accounts(double accounts[LINE_S][ROW_S]);
int close_all_accounts(double accounts[LINE_S][ROW_S]);
int print_all_options();
int open_accounts_counter(double accounts[LINE_S][ROW_S]);
#endif