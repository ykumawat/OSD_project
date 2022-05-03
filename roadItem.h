#include <iostream>
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