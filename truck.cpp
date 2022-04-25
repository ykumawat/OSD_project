#include "vehicle.h"
#include "constants.h"


    Truck::Truck(int weight) {
        loadWeight = weight;
    }

    void Truck::Accelerate(int secondsDelta) {
        if (loadWeight <= 5) {
            SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateEmpty * secondsDelta);
        } else {
            SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateFull * secondsDelta);
        }
    }

    void Truck::Decelerate(int secondsDelta) {
        if (loadWeight <= 5) {
            SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateEmpty * secondsDelta);
        } else {
            SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateFull * secondsDelta);
        }
    }


