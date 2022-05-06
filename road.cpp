#include "road.h"
#include "sui.h"
#include "roadItem.h"
#include <iostream>

Road::Road(std::string streetName, double locX, double locY, double len, Heading hdg){
    name = streetName;
    length = len;
    heading = hdg;
    xlocation = locX;
    ylocation = locY;
    NumOfRoads++;
}

Road::Road(){
	name = "";
    length = 0;
    heading = Heading::North;
    xlocation = 0;
    ylocation = 0;
    NumOfRoads = 0;
}

void Road::initRoad(string streetName, double locX, double locY, double len, Heading hdg){
	name = streetName;
	length = len;
	heading = hdg;
	xlocation = locX;
	ylocation = locY;
	NumOfRoads++;
}

double Road::GetLength() { return length; }
double Road::GetXLocation() { return xlocation; }
double Road::GetYLocation() { return ylocation; }
Heading Road::GetHeading() { return heading; }
std::string Road::GetRoadName() { return name; }

void Road::AddRoadItem(RoadItem *roadItem) {
    
}

// void Road::InsertNewRoadItemBefore(RoadItem *currentRoadItem, RoadItem *previousItem){
// };

// void Road::InsertNewRoadItemAfter(RoadItem *currentRoadItem, RoadItem *nextItem){

// };

void Road::Print(IPrintDriver* print, Container* o){
    print->PrintRoad(this, *o);
}


void Road::Save(JSONSave* sv, ostream& str){
    sv->SaveRoad(this, str);
}

void Road::Load(JSONLoad* ld, istream& str){
    ld->LoadRoad(this, str);
}

StopSign::StopSign(double dist) {
    distance = dist;
}

SpeedLimit::SpeedLimit(double speed, double dist){
    postedSpeed = speed;
    distance = dist;
}

double SpeedLimit::GetSpeedLimit(){
    return postedSpeed;
}

void SpeedLimit::Save(ISaveDriver *sd, ostream& stream){
    sd->SaveSpeedLimit(this, stream); 
}

void StopSign::Save(ISaveDriver *sd, ostream& stream){
    sd->SaveStopSign(this, stream);
}

double StopSign::GetDistance(){
    return distance;
}

double RoadItem::GetMileMarker(){
    return mileMarker;
}

void RoadItem::SetMileMarker(double distance){
    mileMarker = distance;
}

RoadItem* RoadItemsElement::GetRoadItem(){
	return roadItem;
}

RoadItemsElement* RoadItemsElement::GetNext(){
	return nextRoadItem;
}

RoadItemsElement* RoadItemsElement::GetPrev(){
	return prevRoadItem;
}

void RoadItemsElement::AddNew(RoadItem* item){
	roadItem = item;
}

TrafficLight::TrafficLight(int redT, int yellowT, int greenT, string startColor, double mm, string trafficLightNum) {
    redTime = redT;
    yellowTime = yellowT;
    greenTime = greenT;
    currentColor = startColor;
    mileMarker = mm;
    timeOn = 0;
    name = trafficLightNum;
}

void TrafficLight::Save(ISaveDriver *sd, ostream& stream){
    sd->SaveTrafficLight(this, stream);
}

void TrafficLight::Update(int seconds){
	timeOn += seconds;
    cout << "--> Current traffic light " << name << " from color: " << currentColor << "<--" << endl;
        if ((currentColor == "red") && (timeOn >= redTime)){
            currentColor = "green";
            cout << "**New traffic light " << name << " to: "<< currentColor << "**" << endl;
            timeOn = 0; // Re-visit this: only works if updates are 1 second
            return;
        } else if ((currentColor == "yellow") && (timeOn >= yellowTime)){
            currentColor = "red";
            cout << "**New traffic light " << name << " to: "<< currentColor << "**" << endl;
            timeOn = 0; // Re-visit this: only works if updates are 1 second
            return;
        } else if ((currentColor == "green") && (timeOn >= greenTime)){
            currentColor = "yellow";
            cout << "**New traffic light " << name << " to: "<< currentColor << "**" << endl;
            timeOn = 0; // Re-visit this: only works if updates are 1 second
            return;
        }
}

void DynamicRoadItem::Update(int seconds){
    // displacement = CalcDisplacement(seconds);
    // switch (this.nextItem) {
    //     case TrafficLight t:
    //                 // physics stuff here!
    //         cout << "traffic light" << endl;
    //     break;
    //     case SpeedLimit s:
 	// 	  // physics stuff here!
    //        cout << "speed limit" << endl;
    //     break;
    //     case Vehicle v:
    //                 // physics stuff here!
    //         cout << "vehicle" << endl;
    //     break;
    //     case Intersection i:
    //                  // physics stuff here!
    //         cout << "intersection" << endl;
    //     break;
    //     default:
    //     break;
    // };

    // UpdateLocation(displacement);
    // UpdateSpeed(seconds);
    // if (this.nextItem != null) {
    //     if (this.GetMileMarker() > this.nextItem.GetMileMarker()) {
    //         this.GetNext().SetPrevious(this.GetPrevious());
    //         this.GetPrevious().SetNext(this.GetNext());
    //         this.SetPrevious(this.GetNext());
    //         this.SetNext(this.GetNext().GetNext());
    //         this.GetPrevious().SetNext(this);
    //     }
    //     if (this.GetNext() != null) {
    //        this.GetNext().SetPrevious(this);
    //     }
    // }
}



