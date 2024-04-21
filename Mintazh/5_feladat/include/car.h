#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car {
private:
    int number;
    int order;

public:
    Car(int number) : number(number), order(-1) {}

    void entersTrack() {
        static int trackOrder = 1;
        order = trackOrder++;
    }

    int getNumber() const {
        return number;
    }

    int getOrder() const {
        return order;
    }

    bool operator<(const Car& other) const {
        return order < other.order;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Car: " << car.getNumber() << " entered the track as the " << (car.getOrder() == -1 ? "N/A" : std::to_string(car.getOrder())) << std::endl;
        return os;
    }
};

#endif // CAR_H
