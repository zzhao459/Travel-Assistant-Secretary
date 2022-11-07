#include "header.h"
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <json/value.h>
#include <fstream>
/**

@author:Shuaijie Xu
@date 29th November 2021
*/
using namespace std;
/**
the comment of those fucntions is written in header file*/
GetData::GetData(){}
void GetData::setCovidCity(string covidCity)
{
	this->covidCity = covidCity;
}
void GetData::setCovidCurrentCase(int cases)
{
	covidCurrentCase.push_back(cases);
}
void GetData::setCovidReportDate(string date)
{
	covidReportDate.push_back(date);
}
void GetData::setLength(int length)
{
	this->length = length;
}
vector<string> GetData::getCovidReportDate()
{
	return covidReportDate;
}
vector<int> GetData::getCovidCurrentCase()
{
	return covidCurrentCase;
}
int GetData::getLength()
{
	return length;
}

