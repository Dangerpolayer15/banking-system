
#include <iostream>
#include <iomanip>

// Function declarations
void showbalance(double balance);
double deposit();
double withdraw(double balance);

int main() {
    double balance = 0;
    int choice = 0;

    do {
        std::cout << "\n************************\n";
        std::cout << "       BANKING MENU\n";
        std::cout << "************************\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "************************\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showbalance(balance);
            break;

        case 2:
            balance += deposit();
            break;

        case 3:
            balance -= withdraw(balance);
            break;

        case 4:
            std::cout << "Thank you for using our bank!\n";
            break;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// Display balance
void showbalance(double balance) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your balance is: €" << balance << '\n';
}

// Deposit money
double deposit() {
    double amount = 0;

    std::cout << "Enter amount to deposit: €";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "Invalid deposit amount!\n";
        return 0;
    }

    std::cout << "Deposit successful!\n";
    return amount;
}

// Withdraw money
double withdraw(double balance) {
    double amount = 0;

    std::cout << "Enter amount to withdraw: €";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "Invalid withdrawal amount!\n";
        return 0;
    }

    if (amount > balance) {
        std::cout << "Insufficient funds!\n";
        return 0;
    }

    std::cout << "Withdrawal successful!\n";
    return amount;
}
