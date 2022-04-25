#include "map.h"
#include <vector>
#include <iostream>
using namespace std;

Map::Map()
{
    std::vector<Road*> roads;
}

vector<Road*> Map::GetRoad()
{
	return roads;
}

void Map::AddRoad(Road* road)
{
    roads.push_back(road);
}

void Map::Print(IPrintDriver* pd, Container *o)
{
    for (Road *road : roads)
    {
        road->Print(pd, o);
    }
    return;
}


CharMatrix::CharMatrix()
{
    for (int i = 0; i < Constants::CharMapSize; i++)
    {
        map[i] = new char[Constants::CharMapSize];
        for (int j = 0; j < Constants::CharMapSize; j++)
        {
        	map[i][j] = ' ';
        }
        map[i][Constants::CharMapSize-1] = '\0';
    }
}

void Map::Save(JSONSave* sv, ostream& str)
{
	sv->SaveMap(this, str);
}
void Map::Load(JSONLoad* ld, istream& str)
{
	ld->LoadMap(this, str);
}