#include "conversions.h"
#include "constants.h"

int Conversions::WCpointToCCpoint(double val) {

	return (int)(val * (Constants::CharMapSize / Constants::WorldSize) + (Constants::CharMapSize / 2));

}

int Conversions::WClengthToCClength(double val) {

	return (int)(val * (Constants::CharMapSize / Constants::WorldSize));

}