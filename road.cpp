#include "road.h"
#include "sui.h"
#include "roadItem.h"

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