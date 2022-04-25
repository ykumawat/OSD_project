#ifndef ROAD_H_
#define ROAD_H_

#include "JSON.h"

class IPrintDriver;
class Container;

enum Heading{
  North,
  South,
  East,
  West
};

class Road{
	private:
		std::string name;
		double length;
		double xlocation;
		double ylocation;
		Heading heading;

	public:
		int NumOfRoads = 0;

		void initRoad(string streetName, double locX, double locY, double len, Heading hdg);

		Road();
		Road(std::string streetName, double locX, double locY, double len, Heading hdg);

		double GetLength();
		double GetXLocation();
		double GetYLocation();
		Heading GetHeading();
		std::string GetRoadName();

			//public void AddRoadItem(RoadItem roadItem);

		void Print(IPrintDriver* print, Container *o);

			//    private void InsertNewItemBefore(RoadItem current, RoadItem newItem);

			//    private void InsertNewItemAfter(RoadItem current, RoadItem newItem);

		void Save(JSONSave* sv, ostream& str);
		void Load(JSONLoad* ld, istream& str);
};



#endif