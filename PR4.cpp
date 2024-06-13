#include <iostream>

class Color {
private:
    int red;
    int green;
    int blue;

public:
    Color() : red(0), green(0), blue(0) {}

    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    bool isValidValue(int value) const {
        return value >= 0 && value <= 255;
    }

    bool isValidColor() const {
        return isValidValue(red) && isValidValue(green) && isValidValue(blue);
    }

    bool operator==(const Color& other) const {
        return red == other.red && green == other.green && blue == other.blue;
    }

    bool operator!=(const Color& other) const {
        return !(*this == other);
    }

    friend std::istream& operator>>(std::istream& in, Color& color) {
        int r, g, b;
        in >> r >> g >> b;
        color.red = r;
        color.green = g;
        color.blue = b;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Color& color) {
        out << "RGB(" << color.red << ", " << color.green << ", " << color.blue << ")";
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Color myColor;
    std::cout << "������� �������� RGB (0�255) ��� �����: ";
    std::cin >> myColor;
    if (myColor.isValidColor()) {
        std::cout << "���������� ����: " << myColor << std::endl;
    }
    else {
        std::cout << "������� �������� �������� �����.." << std::endl;
    }
    return 0;
}
