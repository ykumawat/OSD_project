#include "vehicle.h"
#include "constants.h"
#include "conversions.h"
#include "map.h"
#include "sui.h"
#include "road.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main() {
	GUI* simInput;
	Map map;
	IPrintDriver* cp = new ConsolePrint();

	simInput = new MetricGUI();

	IPrintDriver* cp2 = new ConsolePrint();
	CharMatrix* cm2 = new CharMatrix();
	Map map2;
	// Heading north = North;
	// Heading east = East;
	Road *Uptown = simInput->CreateRoad("Uptown", 0.0, -0.09, .180, North);
	map2.AddRoad(Uptown);
	Road *Crosstown = simInput->CreateRoad("Crosstown", -0.09, 0.0, .180, East);
	map2.AddRoad(Crosstown);
	
	map2.Print(cp2, cm2);
	for (int i = 0; i < Constants::CharMapSize; i++) {
		std::string s = "";
		for (int j = 0; j < Constants::CharMapSize; j++) {
			s = s + cm2->map[i][j];
		}
		cout << s << endl;
	}
}