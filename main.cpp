// using namespace std;
#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
#include <fstream>

#include "sui.h"
#include "vehicle.h"
#include "map.h"
#include "road.h"
#include "simulation.h"


int main(){
	GUI* simInput;
	Map map;
	IPrintDriver *cp = new ConsolePrint();
	JSONSave *sd = new JSONSave();
	JSONLoad *ld = new JSONLoad();

	ifstream loadfile;
	loadfile.open("./JSONinput.json");
	map.Load(ld, loadfile);
	
	simInput = new MetricGUI();
    Road *Uptown = simInput->CreateRoad("Uptown", 0.0, -0.09, .180, North);
    map.AddRoad(Uptown);
    Road *Crosstown = simInput->CreateRoad("Crosstown", -0.09, 0.0, .180, East);
    map.AddRoad(Crosstown);
    StopSign *sign = simInput->CreateStopSign(.01);
    Crosstown->AddRoadItem(sign);
    StopSign *sign2 = simInput->CreateStopSign(.23);
    Uptown->AddRoadItem(sign2);
    StopSign *sign3 = simInput->CreateStopSign(.32);
    Uptown->AddRoadItem(sign3);
    StopSign *sign4 = simInput->CreateStopSign(.302);
    Uptown->AddRoadItem(sign4);
    SpeedLimit *limit = simInput->CreateSpeedLimit(80.0, .02);
    Crosstown->AddRoadItem(limit);
    SpeedLimit *limit2 = simInput->CreateSpeedLimit(50.0, .123);
    Uptown->AddRoadItem(limit2);

		// Display map
	CharMatrix *cm = new CharMatrix();
	map.Print(cp, cm);
	for (int i = 0; i < Constants::CharMapSize; i++) {
		string s = "";
		for (int j = 0; j < Constants::CharMapSize; j++) {
			s = s + cm->map[i][j];
		}
		cout << s << endl;
	}

		// Save map
	ofstream savefile;
	savefile.open("./JSONoutput.json");
	map.Save(sd, savefile);

	Simulation Sim = Simulation();
	TrafficLight *t1 = new TrafficLight(7, 2, 5, "green", 0.0, "1");
	TrafficLight *t2 = new TrafficLight(7, 2, 5, "red", 0.0, "2");
	Sim.addDynamicRoadItem(t1);
	Sim.addDynamicRoadItem(t2);

	for (int i = 0; i < 20; i++) {
		Sim.Update(1);
	}

	return 0;
}