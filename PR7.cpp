#include <iostream>
#include <ctime>

class Stopwatch {
private:
    std::clock_t startTime;
    std::clock_t stopTime;
    bool running;

public:
    Stopwatch() : startTime(0), stopTime(0), running(false) {}

    void start() {
        if (!running) {
            startTime = std::clock();
            running = true;
            std::cout << "���������� �������." << std::endl;
        }
        else {
            std::cout << "���������� ��� ��������." << std::endl;
        }
    }

    void stop() {
        if (running) {
            stopTime = std::clock();
            running = false;
            std::cout << "���������� ����������." << std::endl;
        }
        else {
            std::cout << "���������� �� ��������." << std::endl;
        }
    }

    void reset() {
        startTime = 0;
        stopTime = 0;
        running = false;
        std::cout << "����� �����������." << std::endl;
    }

    double elapsedSeconds() const {
        if (running) {
            return (std::clock() - startTime) / static_cast<double>(CLOCKS_PER_SEC);
        }
        else {
            return (stopTime - startTime) / static_cast<double>(CLOCKS_PER_SEC);
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Stopwatch& stopwatch) {
        out << "���������� �����: " << stopwatch.elapsedSeconds() << " �������";
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Stopwatch myStopwatch;

    myStopwatch.start();
    // Simulating some work
    for (int i = 0; i < 1000000; ++i) {}

    myStopwatch.stop();
    std::cout << myStopwatch << std::endl;

    myStopwatch.reset();
    myStopwatch.start();
    // Simulating more work
    for (int i = 0; i < 2000000; ++i) {}

    myStopwatch.stop();
    std::cout << myStopwatch << std::endl;

    return 0;
}