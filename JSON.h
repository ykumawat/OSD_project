#ifndef JSON_H_
#define JSON_H_

#include <ostream>
#include <istream>

using namespace std;

class Map;
class Road;

class JSONSave
{
public:
	void SaveMap(Map* map, ostream& str);
	void SaveRoad(Road* rd, ostream& str);
	//friend ostream& operator<<(ostream& stream, const Road& road);
};

class JSONLoad
{
public:
	void LoadMap(Map* map, istream& str);
	void LoadRoad(Road* rd, istream& str);
};

#endif