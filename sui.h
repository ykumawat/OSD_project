#ifndef SUI_H_
#define SUI_H_

#include "conversions.h"
#include "constants.h"
#include "vehicle.h"
#include "roadItem.h"

class GUI;
class ImperialGUI;
class MetricGUI;
class Road;

class Container {
    public:
        virtual ~Container() = default;

        char** map = new char*[Constants::CharMapSize];
};


class CharMatrix : public Container{
    public:
        CharMatrix();
};

class IPrintDriver{
    public:
        virtual void PrintRoad(Road* road, Container o) {};
        virtual void PrintCar(Car car, Container o) {};
};

class ConsolePrint : public IPrintDriver{
    public:
	    void PrintRoad(Road* road, Container o);
        void PrintCar(Car car, Container o);
};

class ISaveDriver {
    public:
        virtual void SaveMap(Map *map, ostream& stream) = 0;
        virtual void SaveRoad(Road *road, ostream& stream) = 0;
        virtual void SaveStopSign(StopSign *roadItem, ostream& stream) = 0;
        virtual void SaveSpeedLimit(SpeedLimit *roadItem, ostream& stream) = 0;
        virtual void SaveTrafficLight(TrafficLight *roadItem, ostream& stream) = 0;
};

class JsonMapSave : public ISaveDriver {
    public:
        void SaveMap(Map *map, ostream& stream) override;
        void SaveRoad(Road *road, ostream& stream) override;
        void SaveStopSign(StopSign *roadItem, ostream& stream) override;
        void SaveSpeedLimit(SpeedLimit *roadItem, ostream& stream) override;
        void SaveTrafficLight(TrafficLight *roadItem, ostream& stream) override;
};

class ILoadDriver {
    public:
        virtual void LoadMap(Map *map, istream& stream) = 0;
        virtual void LoadRoad(Road *road, istream& stream) = 0;
        virtual void LoadStopSign(StopSign *roadItem, ostream& stream) = 0;
        virtual void LoadSpeedLimit(SpeedLimit *roadItem, ostream& stream) = 0;
        virtual void LoadTrafficLight(TrafficLight *roadItem, ostream& stream) = 0;
};

class JsonMapLoad : public ILoadDriver {
    public:
        void LoadMap(Map *map, istream& stream) override;
        void LoadRoad(Road *road, istream& stream) override;
        void LoadStopSign(StopSign *roadItem, ostream& stream) override;
        void LoadSpeedLimit(SpeedLimit *roadItem, ostream& stream) override;
        void LoadTrafficLight(TrafficLight *roadItem, ostream& stream) override;
        bool GetString(string * str, istream& stream);
};

#endif 