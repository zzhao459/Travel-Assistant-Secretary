#include"headerStrategy.h"
/**
the comment of this class is written in header file*/
Strategy* CovidFactory::createStrategy(Selection* selection){
	return new CovidStrategy(selection);
}
