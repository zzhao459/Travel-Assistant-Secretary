#include"headerStrategy.h"
/**
the comment of this class is written in header file*/

CovidStrategy::CovidStrategy(Selection* selection){
	this->selection=selection;
}
GetData CovidStrategy::compute(){
	Read read;
  //! return the value of the results
	return read.retrieve("2021",selection->getStartMonth(),selection->getStartDay(),"2021",selection->getEndMonth(),selection->getEndDay(),selection->getCity());
}
