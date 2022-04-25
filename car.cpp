#include "vehicle.h"
#include "constants.h"


void Car::Accelerate(int secondsDelta) {
    SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRate * secondsDelta);
}

void Car::Decelerate(int secondsDelta) {
    SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRate * secondsDelta);
}


