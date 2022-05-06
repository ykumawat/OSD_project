#include "simulation.h"
#include <list>

void Simulation::addDynamicRoadItem(DynamicRoadItem *dri){
	roadItems.push_back(dri);
}

void Simulation::Update(int seconds){
    for (DynamicRoadItem* dri : roadItems) {
        dri -> Update(seconds);
    }
}