#include <string>
#include "road.h"
#ifndef VEHICLE_H
#define VEHICLE_H

class Road;

// Explicit abstract classes are not supported in C++. A C++ class is abstract if it contains at least one virtual method.
class Vehicle {

	private:
		double currentSpeed = 0.0;
		double desiredSpeed;

	protected:
		virtual void Accelerate(int secondsDelta) = 0;
		virtual void Decelerate(int secondsDelta) = 0;

	public:
		double GetCurrentSpeed();
		void SetDesiredSpeed(double mph);
		void SetCurrentSpeed(double speed);
		void UpdateSpeed(int seconds);

	};

class Car : public Vehicle {

	protected:
		void Accelerate(int secondsDelta) override;
		void Decelerate(int secondsDelta) override;
	};

class Truck : public Vehicle {

	private:
		int loadWeight;   //in tons

	protected:
		void Accelerate(int secondsDelta) override;
		void Decelerate(int secondsDelta) override;

	public:
		Truck(int weight);

	};

class ISimOutput {
	public:
		virtual double GetSpeed(Vehicle& v) = 0;
};

class ISimInput {
	public:
		virtual Road* CreateRoad(std::string name, double locx, double locy, double len, Heading hdg) = 0;
		virtual void SetSpeedLimit(Vehicle &v, double speed) = 0;
		virtual SpeedLimit* CreateSpeedLimit(double speed, double location) = 0;
		virtual StopSign* CreateStopSign(double location) = 0;
};

class GUI : public ISimInput, public ISimOutput {
	public:
		virtual Road* CreateRoad(std::string name, double locx, double locy, double len, Heading hdg) = 0;
		virtual double GetSpeed(Vehicle& v) = 0;
		virtual void SetSpeedLimit(Vehicle& v, double speed) {};
		virtual SpeedLimit* CreateSpeedLimit(double speed, double location) = 0;
		virtual StopSign* CreateStopSign(double location) = 0;
};

class MetricGUI : public GUI {
	public:
		virtual Road* CreateRoad(std::string name, double locx, double locy, double len, Heading hdg) override;
		double GetSpeed(Vehicle& v) override;
		void SetSpeedLimit(Vehicle& v, double speed) override;
		virtual SpeedLimit* CreateSpeedLimit(double speed, double location) override;
		virtual StopSign* CreateStopSign(double location) override;
};

class ImperialGUI : public GUI {
	public:
		virtual Road* CreateRoad(std::string name, double locx, double locy, double len, Heading hdg) override;
		double GetSpeed(Vehicle& v) override;
		void SetSpeedLimit(Vehicle& v, double speed) override;
		virtual SpeedLimit* CreateSpeedLimit(double speed, double location) override;
		virtual StopSign* CreateStopSign(double location) override;
};

#endif