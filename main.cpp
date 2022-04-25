using namespace std;

#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
#include <fstream>

#include "sui.h"
#include "vehicle.h"
#include "map.h"
#include "road.h"


int main(){
	GUI* simInput;
	Map map;
	IPrintDriver *cp = new ConsolePrint();
	JSONSave *sd = new JSONSave();
	JSONLoad *ld = new JSONLoad();

	ifstream loadfile;
	loadfile.open("./JSONinput.json");
	map.Load(ld, loadfile);

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

	return 0;
}