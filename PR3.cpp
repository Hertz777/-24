#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    // ����������� ������
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // ���������� ��������� �����
    friend std::istream& operator>>(std::istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    // ���������� ��������� ��������� "=="
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // ���������� ��������� ��������� "!="
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    // ����� ��� ����������� ������������ �������� �����
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
            return 0; // �� ��� ��� � ������ ���������
    }

    // ����� ��� ��������, ����� �� ����� �� �����
    bool isOnLine(double m, double c) const {
        return (y == m * x + c);
    }

    // ����� ��� ��������, ���� �� ����� �����
    bool isAboveLine(double m, double c) const {
        return (y > m * x + c);
    }

    // ����� ��� ��������, ���� �� ����� �����
    bool isBelowLine(double m, double c) const {
        return (y < m * x + c);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Point p1, p2;
    std::cout << "������� ���������� ����� 1 (x y): ";
    std::cin >> p1;
    std::cout << "������� ���������� ����� 2 (x y): ";
    std::cin >> p2;

    std::cout << "����� 1: " << p1 << std::endl;
    std::cout << "����� 2: " << p2 << std::endl;

    if (p1 == p2) {
        std::cout << "����� 1 � ����� 2 �����." << std::endl;
    }
    else {
        std::cout << "����� 1 � ����� 2 �� �����." << std::endl;
    }

    std::cout << "�������� ����� 1: " << p1.quadrant() << std::endl;
    std::cout << "�������� ����� 2: " << p2.quadrant() << std::endl;

    double m, c;
    std::cout << "������� ������ (m) ����� ����������� (c) ��� ����� (y = mx + c): ";
    std::cin >> m >> c;

    if (p1.isOnLine(m, c)) {
        std::cout << "����� 1 ����� �� ������ y = " << m << "x + " << c << std::endl;
    }
    else {
        std::cout << "����� 1 �� ����� �� ������ y = " << m << "x + " << c << std::endl;
    }
}
