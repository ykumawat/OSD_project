#include "vehicle.h"
#include "constants.h"
#include "conversions.h"
#include "map.h"
#include "sui.h"
#include "road.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

double Vehicle::GetCurrentSpeed() {
	return currentSpeed;
}

void Vehicle::SetDesiredSpeed(double mph) {
	desiredSpeed = mph;
}

void Vehicle::SetCurrentSpeed(double speed) {
	if (currentSpeed <= speed) { // Accelerating
		if (speed > desiredSpeed)
			currentSpeed = desiredSpeed;
		else currentSpeed = speed;
	}
	else {                     // Decelerating
		if (speed < desiredSpeed)
			currentSpeed = desiredSpeed;
		else currentSpeed = speed;
	}
}

void Vehicle::UpdateSpeed(int seconds) {

	if (currentSpeed > desiredSpeed)
		Decelerate(seconds);
	else if (currentSpeed < desiredSpeed)
		Accelerate(seconds);

}

void Car::Accelerate(int secondsDelta) {
	SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRate * secondsDelta);

}

void Car::Decelerate(int secondsDelta) {
	SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRate * secondsDelta);

}

Truck::Truck(int weight) {
	loadWeight = weight;
}

void Truck::Accelerate(int secondsDelta) {
	if (loadWeight <= 5)
		SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateEmpty * secondsDelta);
	else
		SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateFull * secondsDelta);

}

void Truck::Decelerate(int secondsDelta) {
	if (loadWeight <= 5)
		SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateEmpty * secondsDelta);
	else
		SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateFull * secondsDelta);

}

Road MetricGUI::CreateRoad(string name, double locx, double locy, double len, Heading hdg) {
	return Road(name, locx / Constants::MetersToKm, locy / Constants::MetersToKm, len / Constants::MetersToKm, hdg);
}

double MetricGUI::GetSpeed(Vehicle& v) {
	return v.GetCurrentSpeed() * Constants::MpsToKph;
}

void MetricGUI::SetSpeedLimit(Vehicle& v, double speed) {
	v.SetDesiredSpeed(speed / Constants::MpsToKph);
}

Road ImperialGUI::CreateRoad(string name, double locx, double locy, double len, Heading hdg) {
	return Road(name, locx / Constants::MetersToMiles, locy / Constants::MetersToMiles, len / Constants::MetersToMiles, hdg);
}

double ImperialGUI::GetSpeed(Vehicle& v) {
	return v.GetCurrentSpeed() * Constants::MpsToMph;
}

void ImperialGUI::SetSpeedLimit(Vehicle& v, double speed) {
	v.SetDesiredSpeed(speed / Constants::MpsToMph);
}

int main() {
	GUI* simInput;
	Map map;
	IPrintDriver* cp = new ConsolePrint();

	simInput = new MetricGUI();

	IPrintDriver* cp2 = new ConsolePrint();
	CharMatrix* cm2 = new CharMatrix();
	Map map2;
	// Heading north = North;
	// Heading east = East;
	Road *Uptown = simInput->CreateRoad("Uptown", 0.0, -0.09, .180, North);
	map2.AddRoad(Uptown);
	Road *Crosstown = simInput->CreateRoad("Crosstown", -0.09, 0.0, .180, East);
	map2.AddRoad(Crosstown);
	
	map2.Print(cp2, cm2);
	for (int i = 0; i < Constants::CharMapSize; i++) {
		std::string s = "";
		for (int j = 0; j < Constants::CharMapSize; j++) {
			s = s + cm2->map[i][j];
		}
		cout << s << endl;
	}
}