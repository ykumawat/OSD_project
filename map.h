#ifndef MAP_H_
#define MAP_H_

#include <vector>

#include "sui.h"
#include "road.h"
#include "JSON.h"
#include "constants.h"

class Map
{
private:
	std::vector<Road*> roads;

public:
	Map();
	vector<Road*> GetRoad();
    void AddRoad(Road* road);
    void Print(IPrintDriver* pd, Container* o);

    void Save(JSONSave* sv, ostream& str);
    void Load(JSONLoad* ld, istream& str);
};

#endif