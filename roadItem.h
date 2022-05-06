#include <iostream>
#include <string>
using namespace std;
#ifndef ROADITEM_H
#define ROADITEM_H

class ISaveDriver;
class ILoadDriver;

class RoadItem {
    private:
        double mileMarker = 0.0;

    public:
        double GetMileMarker();
        void SetMileMarker(double distance);
        virtual void Save(ISaveDriver *sd, ostream& stream) = 0;
};

class StaticRoadItem : public RoadItem {
};

class StopSign : public StaticRoadItem {
    private:
        double distance;
    public:
        StopSign(double dist);
        virtual void Save(ISaveDriver *sd, ostream& stream) override;
        double GetDistance();
};

class SpeedLimit : public StaticRoadItem {
    private:
        double postedSpeed;
        double distance;

    public:
        SpeedLimit(double speed, double dist);
        double GetSpeedLimit();
        virtual void Save(ISaveDriver *sd, ostream& stream) override;
};

class DynamicRoadItem : public RoadItem {
    public:
        virtual void Update(int seconds) = 0;
        virtual void Save(ISaveDriver *sd, ostream& stream) = 0;
};

class TrafficLight : public DynamicRoadItem {
    private:
        int redTime;
        int yellowTime;
        int greenTime;
        int timeOn;
        double mileMarker;
        string currentColor;
        string name;
    public:
        TrafficLight(int redT, int yellowT, int greenT, string startColor, double mm, string trafficLightNum);
        virtual void Update(int seconds) override;
        virtual void Save(ISaveDriver *sd, ostream& stream) override;
};

class RoadItemsElement {
    private:
        RoadItem *roadItem;
        RoadItemsElement *nextRoadItem;
        RoadItemsElement *prevRoadItem;
        void AddNext(RoadItem *roadItem);
        void AddPrev(RoadItem *roadItem);

    public:
        RoadItemsElement();
        RoadItem* GetRoadItem();
        RoadItemsElement* GetNext();
        RoadItemsElement* GetPrev();
        void AddNew(RoadItem * item);
};

#endif