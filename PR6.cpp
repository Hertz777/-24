#include <iostream>
#include <cmath>

class Deposit {
private:
    double interestRate;
    int term;
    bool canDepositWithdraw;

public:
    Deposit() : interestRate(0.0), term(0), canDepositWithdraw(false) {}

    Deposit(double rate, int t, bool canDW) : interestRate(rate), term(t), canDepositWithdraw(canDW) {}

    void deposit(double amount) {
        if (canDepositWithdraw) {
            // Deposit operation
            // Implement deposit logic here
            std::cout << "��������������: " << amount << std::endl;
        }
        else {
            std::cout << "���������� ������ ������� �� ���� ����." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (canDepositWithdraw) {
            // Withdrawal operation
            // Implement withdrawal logic here
            std::cout << "�����: " << amount << std::endl;
        }
        else {
            std::cout << "���������� ������� ������ � ����� �����." << std::endl;
        }
    }

    double calculateIncome(double principal) const {
        // Interest calculation
        double interest = principal * (interestRate / 100.0) * (term / 12.0);
        return principal + interest;
    }

    friend std::ostream& operator<<(std::ostream& out, const Deposit& deposit) {
        out << "���������� ������: " << deposit.interestRate << "%\n";
        out << "����: " << deposit.term << " ������\n";
        out << "�������/����� ��������: " << (deposit.canDepositWithdraw ? "�" : "�") << "\n";
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Deposit myDeposit(5.0, 12, true);
    double principal = 1250.0;
    myDeposit.deposit(principal);
    std::cout << "����� ����� ����� ��������� ������: " << myDeposit.calculateIncome(principal) << std::endl;
    std::cout << "������ ��������:\n" << myDeposit << std::endl;
    return 0;
}