#include "vehicle.h"
#include "road.h"
#include "constants.h"

double Vehicle::GetCurrentSpeed() {
    return currentSpeed;
}

void Vehicle::SetDesiredSpeed(double mph) {
    desiredSpeed = mph;
}

void Vehicle::SetCurrentSpeed(double speed) {
    if (currentSpeed <= speed) {
        if (speed > desiredSpeed) {
            currentSpeed = desiredSpeed;
        } else {
            currentSpeed = speed;
        }
    } else {
        if (speed < desiredSpeed) {
            currentSpeed = desiredSpeed;
        } else {
            currentSpeed = speed;
        }
    }
}

void Vehicle::UpdateSpeed(int seconds) {
    if (currentSpeed > desiredSpeed) {
        Decelerate(seconds);
    } else if (currentSpeed < desiredSpeed) {
        Accelerate(seconds);
    }
}

void Vehicle::Accelerate(int secondsDelta) {};

void Vehicle::Decelerate(int secondsDelta) {};

Road* MetricGUI::CreateRoad(std::string name, double locx, double locy, double len, Heading hdg)
	{
		return new Road(name, locx / Constants::MetersToKm, locy / Constants::MetersToKm, len / Constants::MetersToKm, hdg);
	}

double MetricGUI::GetSpeed(Vehicle &v){
	return v.GetCurrentSpeed() * Constants::MpsToKph;
}
void MetricGUI::SetSpeedLimit(Vehicle &v, double speed){
	v.SetDesiredSpeed(speed/Constants::MpsToKph);
}

Road* ImperialGUI::CreateRoad(std::string name, double locx, double locy, double len, Heading hdg){
    return new Road(name, locx / Constants::MetersToMiles, locy / Constants::MetersToMiles, len / Constants::MetersToMiles, hdg);
}

double ImperialGUI::GetSpeed(Vehicle& v){
	return v.GetCurrentSpeed() * Constants::MpsToMph;
}

void ImperialGUI::SetSpeedLimit(Vehicle& v, double speed){
	v.SetDesiredSpeed(speed/Constants::MpsToMph);
}

StopSign* MetricGUI::CreateStopSign(double location){
    return new StopSign(location);
}

StopSign* ImperialGUI::CreateStopSign(double location){
    return new StopSign(location);
}

SpeedLimit* MetricGUI::CreateSpeedLimit(double speed, double location){
    return new SpeedLimit(speed, location);
}

SpeedLimit* ImperialGUI::CreateSpeedLimit(double speed, double location){
    return new SpeedLimit(speed, location);
}