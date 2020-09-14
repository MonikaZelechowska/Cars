#include "ElectricCar.hpp"
#include <iostream>
#include <type_traits>

ElectricCar::ElectricCar(ElectricEngine* engine)
    : electricEngine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    delete electricEngine_;
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::restore() {
    charge();
}

void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricCar::changeEngine(Engine* electricEngine) {
    std::cout << __FUNCTION__ << std::endl;
    if (currentSpeed_ != 0) {
        std::cout << "Changing of engine during driving is not possible!" << std::endl;
        return;
    }
    if (typeid(*electricEngine) != typeid(ElectricEngine)) {
        std::cout << "Engine can be changed only fo ELECTRIC type engine" << std::endl;
        return;
    }
    delete electricEngine_;
    electricEngine_ = static_cast<ElectricEngine*>(electricEngine);
}

void ElectricCar::setGear(int gear) {
    std::cout << "Set Gear to: " << gear << " - function not available for Electric Car\n";
}

int ElectricCar::getElectricEnginePower() const {
    return electricEngine_->getPower();
}

int ElectricCar::getElectricEngineBatteryCapacity() const {
    return electricEngine_->getBatteryCapacity();
}
