#include <iostream>

class Account {
public:
    std::string holderName;
    double balance = 500;

    Account(std::string& name) {
         holderName = name;
    }

    void showBalance() {
        std::cout << "Balance for " << holderName << ": Rs." << balance << std::endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful!"<<std::endl;
        } else {
            std::cout << "Invalid deposit amount."<<std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful!"<<std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient balance."<<std::endl;
        }
    }
};

void showMenu() {
    std::cout << "##### MENU #####"<<std::endl;
    std::cout << "1. Check Balance"<<std::endl;
    std::cout << "2. Deposit"<<std::endl;
    std::cout << "3. Withdraw"<<std::endl;
    std::cout << "4. Exit"<<std::endl;
    std::cout << "################"<<std::endl;
}

int main() {
    std::string accountHolderName;
    std::cout << "Enter account holder name: ";
    std::cin >> accountHolderName;

    Account account(accountHolderName);

    int option;

    do {
        showMenu();
        std::cout << "Option: ";
        std::cin >> option;
        system("cls");

        switch (option) {
            case 1:
                account.showBalance();
                break;
            case 2:
                std::cout << "Deposit Amount: ";
                double depositAmount;
                std::cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            case 3:
                std::cout << "Withdraw Amount: ";
                double withdrawAmount;
                std::cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            case 4: 
                std::cout<<"Bye! Have a great day"<<std::endl;
        }
    } while (option != 4);

    return 0;
}
