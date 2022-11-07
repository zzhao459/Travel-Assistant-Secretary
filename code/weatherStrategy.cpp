#include"headerStrategy.h"
/**
the comment of this class is written in header file*/
WeatherStrategy::WeatherStrategy(Selection* selection){
	this->selection=selection;
}
GetData WeatherStrategy::compute(){
        GetData data;
  // return the results of weather data just fetched
        data.readWeather(selection->getCity());
	return data;
}
