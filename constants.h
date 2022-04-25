#ifndef CONSTANTS_H
#define CONSTANTS_H

// Static classes are not supported in C++;
// therefore, all members of an ordinary class must be individually declared as static to achieve the desired effect.
class Constants {

public:
	static const double AccRate;
	static const double AccRateEmpty;
	static const double AccRateFull;
	static const double DecRate;
	static const double DecRateEmpty;
	static const double DecRateFull;
	static const double MpsToMph;
	static const double MpsToKph;
	static const double MetersToMiles;
	static const double MetersToKm;
	static const int CharMapSize;
	static const double WorldSize;
};

#endif