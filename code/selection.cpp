/**
the comment was written in the header file
*/
#include "headerStrategy.h"
Selection::Selection(string sm,string sd,string em,string ed,string city){
	this->startDay=sd;
	this->startMonth=sm;
	this->endDay=ed;
	this->endMonth=em;
	this->city=city;
}
string Selection::getCity(){
	return city;
}
string Selection::getStartDay(){
	return startDay;
}
string Selection::getStartMonth(){
	return startMonth;
}
string Selection::getEndMonth(){
	return endMonth;
}
string Selection::getEndDay(){
	return endDay;
}
void Selection::setStartDay(string startDay){
	this->startDay=startDay;
}
void Selection::setEndDay(string endDay){
	this->endDay=endDay;
}
void Selection::setStartMonth(string startMonth){
	this->startMonth=startMonth;
}
void Selection::setEndMonth(string endMonth){
	this->endMonth=endMonth;
}
void Selection::setCity(string city){
	this->city=city;
}

