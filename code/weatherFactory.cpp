#include"headerStrategy.h"
/**
the comment of this class is written in header file
*/
Strategy* WeatherFactory::createStrategy(Selection* selection){
	return new WeatherStrategy(selection);
}
