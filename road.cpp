#include "road.h"
#include "sui.h"

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

            //public void AddRoadItem(RoadItem roadItem)
            //{
            //    roadItem.SetCurrentRoad(this);
            //    RoadItem currentItem = head;
            //    while (currentItem.GetNext() != null)
            //    {
            //        currentItem = currentItem.GetNext();
            //        if (currentItem.GetMileMarker() > roadItem.GetMileMarker())
            //        {
            //            InsertNewItemBefore(currentItem, roadItem);
            //            return;
            //        }
            //    }
            //    InsertNewItemAfter(currentItem, roadItem);
            //}

void Road::Print(IPrintDriver* print, Container* o){
    print->PrintRoad(this, *o);
}
            //    private void InsertNewItemBefore(RoadItem current, RoadItem newItem)
            //    {
            //        newItem.SetPrevious(current.GetPrevious());
            //        newItem.SetNext(current);
            //        current.SetPrevious(newItem);
            //        newItem.GetPrevious().SetNext(newItem);
            //    }

            //    private void InsertNewItemAfter(RoadItem current, RoadItem newItem)
            //    {
            //        newItem.SetNext(current.GetNext());
            //        current.SetNext(newItem);
            //        newItem.SetPrevious(current);
            //        if (newItem.GetNext() != null) newItem.GetNext().SetPrevious(newItem);
            //    }
            //}

void Road::Save(JSONSave* sv, ostream& str){
    sv->SaveRoad(this, str);
}

void Road::Load(JSONLoad* ld, istream& str){
    ld->LoadRoad(this, str);
}