#include <iostream>
#include <unordered_map>

void showMenu() {
    std::cout << "##### MENU #####" << std::endl;
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Create Account" << std::endl;
    std::cout << "5. Delete Account" << std::endl;
    std::cout << "6. Transfer Money" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "################" << std::endl;
}

struct Account {
    std::string name;
    double balance;
};

class Bank {
private:
    std::unordered_map<std::string, Account> accounts;

public:
    void createAccount() {
        Account newAccount;

        std::cout << "Enter name: ";
        std::cin >> newAccount.name;

        newAccount.balance = 500.0;

        accounts[newAccount.name] = newAccount;

        std::cout << "Account created successfully!\n";
    }

    void deleteAccount() {
        std::string name;
        std::cout << "Enter account name to delete: ";
        std::cin >> name;

        auto it = accounts.find(name);

        if (it != accounts.end()) {
            accounts.erase(it);
            std::cout << "Account deleted successfully!\n";
        } else {
            std::cout << "Account not found.\n";
        }
    }

    void transferMoney() {
        std::string sender, receiver;
        double amount;

        std::cout << "Enter sender account name: ";
        std::cin >> sender;

        auto senderIt = accounts.find(sender);
        if (senderIt == accounts.end()) {
            std::cout << "Sender account not found.\n";
            return;
        }

        std::cout << "Enter receiver account name: ";
        std::cin >> receiver;

        auto receiverIt = accounts.find(receiver);
        if (receiverIt == accounts.end()) {
            std::cout << "Receiver account not found.\n";
            return;
        }

        std::cout << "Enter amount to transfer: ";
        std::cin >> amount;

        if (amount > 0 && amount <= senderIt->second.balance) {
            senderIt->second.balance -= amount;
            receiverIt->second.balance += amount;
            std::cout << "Transfer successful!\n";
        } else {
            std::cout << "Invalid transfer amount or insufficient balance.\n";
        }
    }

    void processMenuOption(int option) {
        switch (option) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                createAccount();
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                transferMoney();
                break;
        }
    }

    
    void checkBalance() {
        std::string accountName;

        std::cout << "Enter account name: ";
        std::cin >> accountName;

        auto accountIt = accounts.find(accountName);

        if (accountIt == accounts.end()) {
            std::cout << "Account not found.\n";
            return;
        }

        std::cout << "Balance for account " << accountName << ": Rs." << accountIt->second.balance << std::endl;
    }

    void deposit() {
        std::string accountName;
        double amount;

        std::cout << "Enter account name for deposit: ";
        std::cin >> accountName;

        auto accountIt = accounts.find(accountName);

        if (accountIt == accounts.end()) {
            std::cout << "Account not found.\n";
            return;
        }

        std::cout << "Enter amount to deposit: ";
        std::cin >> amount;

        if (amount > 0) {
            accountIt->second.balance += amount;
            std::cout << "Deposit successful!\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw() {
        std::string accountName;
        double amount;

        std::cout << "Enter account name for withdrawal: ";
        std::cin >> accountName;

        auto accountIt = accounts.find(accountName);

        if (accountIt == accounts.end()) {
            std::cout << "Account not found.\n";
            return;
        }

        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;

        if (amount > 0 && amount <= accountIt->second.balance) {
            accountIt->second.balance -= amount;
            std::cout << "Withdrawal successful!\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient balance.\n";
        }
    }
};

int main() {
    Bank bank;
    int option;
    
    
    do {
        showMenu();
        std::cout << "Option: ";
        std::cin >> option;

        if (option >= 1 && option <= 7) {
            system("cls");
            if (option != 7) {
                bank.processMenuOption(option);
            }
        } else {
            std::cout << "Invalid option. Please choose a number between 1 and 7.\n";
        }

    } while (option != 7);

    return 0;
}