#include <iostream>
#include <iomanip> // Для использования std::setw и std::setfill

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор класса
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Time& time) {
        is >> time.hours >> time.minutes >> time.seconds;
        return is;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << std::setw(2) << std::setfill('0') << time.hours << ":"
            << std::setw(2) << std::setfill('0') << time.minutes << ":"
            << std::setw(2) << std::setfill('0') << time.seconds;
        return os;
    }

    // Метод для перевода времени из 24-часового формата в 12-часовой
    void convertTo12HourFormat() {
        if (hours > 12) {
            hours -= 12;
        }
    }

    // Перегрузка оператора сравнения ">"
    bool operator>(const Time& other) const {
        if (hours > other.hours)
            return true;
        else if (hours == other.hours && minutes > other.minutes)
            return true;
        else if (hours == other.hours && minutes == other.minutes && seconds > other.seconds)
            return true;
        return false;
    }

    // Перегрузка оператора сравнения "<"
    bool operator<(const Time& other) const {
        return !(*this > other) && !(*this == other);
    }

    // Перегрузка оператора сравнения "!="
    bool operator!=(const Time& other) const {
        return !(*this == other);
    }

    // Перегрузка оператора сравнения "=="
    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    // Перегрузка оператора сложения "+"
    Time operator+(const Time& other) const {
        int h = hours + other.hours;
        int m = minutes + other.minutes;
        int s = seconds + other.seconds;

        if (s >= 60) {
            m += s / 60;
            s %= 60;
        }
        if (m >= 60) {
            h += m / 60;
            m %= 60;
        }
        if (h >= 24) {
            h %= 24;
        }

        return Time(h, m, s);
    }

    // Перегрузка оператора увеличения "+="
    Time& operator+=(const Time& other) {
        *this = *this + other;
        return *this;
    }

    // Перегрузка оператора вычитания "-"
    Time operator-(const Time& other) const {
        int h = hours - other.hours;
        int m = minutes - other.minutes;
        int s = seconds - other.seconds;

        if (s < 0) {
            m--;
            s += 60;
        }
        if (m < 0) {
            h--;
            m += 60;
        }
        if (h < 0) {
            h += 24;
        }

        return Time(h, m, s);
    }

    // Перегрузка оператора уменьшения "-="
    Time& operator-=(const Time& other) {
        *this = *this - other;
        return *this;
    }
};

int main() {
    Time t1, t2;
    std::cout << "Enter time 1 (hh:mm:ss): ";
    std::cin >> t1;
    std::cout << "Enter time 2 (hh:mm:ss): ";
    std::cin >> t2;

    std::cout << "Time 1: " << t1 << std::endl;
    std::cout << "Time 2: " << t2 << std::endl;

    if (t1 > t2) {
        std::cout << "Time 1 is greater than Time 2" << std::endl;
    }
    else if (t1 < t2) {
        std::cout << "Time 1 is less than Time 2" << std::endl;
    }
    else {
        std::cout << "Time 1 is equal to Time 2" << std::endl;
    }

    Time sum = t1 + t2;
    std::cout << "Sum of Time 1 and Time 2: " << sum << std::endl;

    Time diff = t1 - t2;
    std::cout << "Difference of Time 1 and Time 2: " << diff << std::endl;

    return 0;
}