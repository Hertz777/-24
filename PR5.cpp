#include <iostream>
#include <string>
#include <regex>

class Password {
private:
    std::string password;

public:
    Password() : password("") {}

    Password(const std::string& pass) : password(pass) {}

    enum class SecurityLevel { Weak, Medium, Strong };

    SecurityLevel getSecurityLevel() const {
        // �������� �� ����� ������
        if (password.length() < 8) {
            return SecurityLevel::Weak;
        }

        // �������� �� ���������� ��� ������� ����� �����, ����� ����� � ������� � ������ ���������
        bool hasDigit = std::regex_search(password, std::regex("\\d"));
        bool hasLower = std::regex_search(password, std::regex("[a-z]"));
        bool hasUpper = std::regex_search(password, std::regex("[A-Z]"));

        if (hasDigit && (hasLower || hasUpper)) {
            return SecurityLevel::Strong;
        }
        else if (hasDigit || (hasLower && hasUpper)) {
            return SecurityLevel::Medium;
        }
        else {
            return SecurityLevel::Weak;
        }
    }

    bool operator==(const Password& other) const {
        return password == other.password;
    }

    bool operator!=(const Password& other) const {
        return !(*this == other);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Password myPassword;
    std::cout << "������� ������: ";
    std::string input;
    std::cin >> input;
    myPassword = Password(input);

    Password::SecurityLevel securityLevel = myPassword.getSecurityLevel();

    switch (securityLevel) {
    case Password::SecurityLevel::Weak:
        std::cout << "������ ������." << std::endl;
        break;
    case Password::SecurityLevel::Medium:
        std::cout << "������� ������." << std::endl;
        break;
    case Password::SecurityLevel::Strong:
        std::cout << "�������� ������." << std::endl;
        break;
    }

    return 0;
}