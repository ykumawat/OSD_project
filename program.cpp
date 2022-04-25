// #include "vehicle.h"
// #include "constants.h"
// #include "conversions.h"
// #include "map.h"
// #include "sui.h"
// #include <iostream>
// #include <vector>
// #include <fstream>

// using namespace std;

// // void JsonMapLoad::LoadMap(Map *map, istream& stream)
// // {
// // 	string identifier;
// // 	char symbol;
// // 	stream >> symbol;
// // 	if (symbol != '{') return;

// // 	do {
// // 		identifier = "";
// // 		GetString(&identifier, stream))
// // 		stream >> symbol;
// // 		if (symbol != ':') return;
// // 		if (identifier == "Roads")
// // 		{
// // 			stream >> symbol;
// // 			if (symbol != '[') return;
// // 			do
// // 			{
// // 				Road r;
// // 				r.Load(this, stream);
// // 				map->AddRoad(r);
// // 				stream >> symbol;
// // 			} while (symbol == ',');
// // 		}
// // 		stream >> symbol;
// // 	} while (symbol == ',');
// // 	if (symbol != '}') return;
// // }

// // void JsonMapLoad::LoadRoad(Road *road, istream& stream)
// // {
// // 	string identifier, roadName;
// // 	double xLocation, yLocation, length;
// // 	Heading heading;
// // 	char symbol;
// // 	stream >> symbol;
// // 	if (symbol != '{') return;

// // 	do {
// // 		identifier = "";
// // 		if (!GetString(&identifier, stream)) return;
// // 		stream >> symbol;
// // 		if (symbol != ':') return;
// // 		if (identifier == "Name") GetString(&roadName, stream);
// // 		else if (identifier == "Length") stream >> length;
// // 		else if (identifier == "XLocation") stream >> xLocation;
// // 		else if (identifier == "YLocation") stream >> yLocation;
// // 		else if (identifier == "Heading")
// // 		{
// // 			int hdg;
// // 			stream >> hdg;
// // 			heading = (Heading)hdg;
// // 		}
// // 		else return;
// // 		stream >> symbol;
// // 	} while (symbol == ',');
// // 	if (symbol != '}') return;
// // 	road->InitRoad(roadName, xLocation, yLocation, length, heading);
// // }

// int main() {

// 	GUI* simInput;
// 	Map map;
// 	IPrintDriver* cp = new ConsolePrint();

// 	simInput = new MetricGUI();

// 	IPrintDriver* cp2 = new ConsolePrint();
// 	CharMatrix* cm2 = new CharMatrix();
// 	Map map2;
// 	Road Uptown = simInput->CreateRoad("Uptown", 0.0, -0.09, .180, North);
// 	map2.AddRoad(Uptown);
// 	Road Crosstown = simInput->CreateRoad("Crosstown", -0.09, 0.0, .180, East);
// 	map2.AddRoad(Crosstown);
	
// 	map2.Print(cp2, cm2);
// 	for (int i = 0; i < Constants::CharMapSize; i++) {
// 		std::string s = "";
// 		for (int j = 0; j < Constants::CharMapSize; j++) {
// 			s = s + cm2->map[i][j];
// 		}
// 		cout << s << endl;
// 	}
// }