#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    // Конструктор класса
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    // Перегрузка оператора сравнения "=="
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // Перегрузка оператора сравнения "!="
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    // Метод для определения координатной четверти точки
    int quadrant() const {
        if (x > 0 && y > 0)
            return 1;
        else if (x < 0 && y > 0)
            return 2;
        else if (x < 0 && y < 0)
            return 3;
        else if (x > 0 && y < 0)
            return 4;
        else
            return 0; // На оси или в начале координат
    }

    // Метод для проверки, лежит ли точка на линии
    bool isOnLine(double m, double c) const {
        return (y == m * x + c);
    }

    // Метод для проверки, выше ли точка линии
    bool isAboveLine(double m, double c) const {
        return (y > m * x + c);
    }

    // Метод для проверки, ниже ли точка линии
    bool isBelowLine(double m, double c) const {
        return (y < m * x + c);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Point p1, p2;
    std::cout << "Введите координаты точки 1 (x y): ";
    std::cin >> p1;
    std::cout << "Введите координаты точки 2 (x y): ";
    std::cin >> p2;

    std::cout << "точка 1: " << p1 << std::endl;
    std::cout << "точка 2: " << p2 << std::endl;

    if (p1 == p2) {
        std::cout << "точка 1 и точка 2 равны." << std::endl;
    }
    else {
        std::cout << "точка 1 и точка 2 не равны." << std::endl;
    }

    std::cout << "Квадрант точки 1: " << p1.quadrant() << std::endl;
    std::cout << "Квадрант точки 2: " << p2.quadrant() << std::endl;

    double m, c;
    std::cout << "Введите наклон (m) точку пересечения (c) для линии (y = mx + c): ";
    std::cin >> m >> c;

    if (p1.isOnLine(m, c)) {
        std::cout << "Точка 1 лежит на прямой y = " << m << "x + " << c << std::endl;
    }
    else {
        std::cout << "Точка 1 не лежит на прямой y = " << m << "x + " << c << std::endl;
    }
}
