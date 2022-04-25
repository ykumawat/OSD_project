#include "JSON.h"
#include "map.h"
#include "road.h"
#include <vector>
#include <iostream>
#include <stdio.h>

void JSONSave::SaveMap(Map *map, ostream& stream)
{
	stream << "{" << endl;
	stream << "\"Roads\":";
	stream << "[" << endl;
	vector<Road*> roads = map->GetRoad();
	cout << roads.size();
	int i = 0;
	for (Road* road : roads) {
		road->Save(this, stream);
		if(i != roads.size()-1)
			{
			stream << ",";
			i++;
			}
	stream << endl;
	}
	stream << "]" << endl;
	stream << "}";
}

void JSONSave::SaveRoad(Road *road, ostream& stream)
{
	int hdg;
	hdg = (int)road->GetHeading();
	stream << "{" << endl;
	stream << "\"Name\":\"" << road->GetRoadName() << "\"," << endl;
	stream << "\"Length\":" << road->GetLength() << "," << endl;
	stream << "\"XLocation\":" << road->GetXLocation() << "," << endl;
	stream << "\"YLocation\":" << road->GetYLocation() << "," << endl;
	stream << "\"Heading\":" << hdg << endl;
	stream << "}";

	return;
}

/*ostream& operator<<(ostream& stream, const Road* road)
{
	stream << road->GetHeading();
}*/

void JSONLoad::LoadMap(Map *map, istream& stream)
{
	string identifier;
	char symbol, tempSym;

	getline(stream, identifier);
	symbol = identifier[0];
	if (symbol != '{')
		{
			return;
		}

	do {

		identifier = "";
		getline(stream, identifier);
		if(identifier.find('[') != string::npos)
		{
			tempSym = '[';
		}
		symbol = identifier[identifier.size()-2];
		if (symbol != ':')
			{
				return;
			}
		identifier.pop_back();
		identifier = identifier.substr(1,identifier.size()-3);
		if (identifier == "Roads")
		{
			//getline(stream, identifier);
			//symbol = identifier[identifier.size()-1];
			symbol = tempSym;
			if (symbol != '[')
				{
				return;
				}
			do
			{
				Road* r = new Road();
				r->Load(this, stream);
				map->AddRoad(r);
				getline(stream, identifier);
				symbol = identifier[1];
			} while (symbol == ',');
		}
		getline(stream, identifier);
		symbol = identifier[identifier.size()-1];

	} while (symbol == ',');
	if (symbol != '}') return;
}

void JSONLoad::LoadRoad(Road *road, istream& stream)
{
	string identifier, roadName;
	double xLocation, yLocation, length;
	Heading heading;
	char symbol;

	getline(stream, identifier);
	symbol = identifier[identifier.size()-1];
	if (symbol != '{')
		{
			return;
		}
	do {
		identifier = "";
		getline(stream, identifier, ':');
		symbol = ':';
		//else
		//{
		//	return;
		//}
		if (symbol != ':')
		{
			return;
		}
		identifier.pop_back();
		identifier = identifier.substr(1,identifier.size()-1);
		if (identifier == "Name")
		{
			getline(stream, roadName);
			roadName.pop_back();
			roadName = roadName.substr(1,roadName.size()-2);
			symbol = ',';
		}
		else if (identifier == "Length")
		{
			string temp;
			getline(stream, temp);
			temp.pop_back();
			length = stod(temp);
			symbol = ',';
		}
		else if (identifier == "XLocation")
		{
			string temp;
			getline(stream, temp);
			temp.pop_back();
			xLocation = stod(temp);
			symbol = ',';
		}
		else if (identifier == "YLocation")
		{
			string temp;
			getline(stream, temp);
			temp.pop_back();
			yLocation = stod(temp);
			symbol = ',';
		}
		else if (identifier == "Heading")
		{
			int hdg;
			string temp;
			getline(stream, temp);
			hdg = stoi(temp);
			heading = (Heading)hdg;
			symbol = '}';
		}
		else
		{
			return;
		}
	} while (symbol == ',');
	if (symbol != '}')
	{
		return;
	}
	road->initRoad(roadName, xLocation, yLocation, length, heading);
}