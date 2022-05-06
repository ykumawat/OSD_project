#include <list>
#include "roadItem.h"

#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
    private:
        list<DynamicRoadItem*> roadItems;
    public:
        void addDynamicRoadItem(DynamicRoadItem * dri);
        void Update(int seconds);
};

#endif