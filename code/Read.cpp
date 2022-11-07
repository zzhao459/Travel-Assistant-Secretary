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
@author:Shuaijie Xu, Tiancong Hou
@date 29th November 2021
*/
using namespace std;
namespace
    {
        std::size_t cb(char* in,std::size_t s,std::size_t n,std::string* out)
        {
            std::size_t totalBytes(s * n);
            out->append(in, totalBytes);
            return totalBytes;
        }
    }
/**
the comment of this function is written in header file*/
GetData Read::retrieve(string startYear, string startMonth, string startDay, string endYear, string endMonth, string endDay, string city)
{
	string startDate;
	string endDate;
	if(stoi(startDay)<10)
	{
		startDay = '0' + startDay;
		cout<<startDay<<endl;
		startDate = startDay + "-" + startMonth + "-" + startYear;
	}
	else
	{
		startDate = startDay + "-" + startMonth + "-" + startYear;
	}
	if(stoi(endDay)<10)
	{
		endDay = '0' + endDay;
		cout<<endDay<<endl;
		endDate =  endDay + "-" + endMonth + "-" + endYear;
	}
	else
	{
		endDate =  endDay + "-" + endMonth + "-" + endYear;
	}
	if (city == "Toronto")
	{
		city = "3595";
	}
	else if (city == "Montreal") {
		city = "2406";
	}
	else if (city == "Calgary")
	{
		city = "4832";
	}
	else if (city == "Ottawa")
	{
		city = "3551";
	}
	else if (city == "Edmonton")
	{
		city = "4834";
	}
	else if (city == "Mississauga") {
		city = "3595";
	}
	else if (city == "Winnipeg") {
		city = "4601";
	}
	else if (city == "Vancouver") {
		city = "595";
	}
	else if (city == "Brampton") {
		city = "3527";
	}
	else {
		city = "3544";
	}
	string web = "https://api.opencovid.ca/timeseries?stat=cases&loc=" + city + "&after=" + startDate + "&before=" + endDate;
	cout<< web<<endl;
	string url(web); //go to url

	CURL* curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10); 
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
	std::unique_ptr<std::string> hd(new std::string());
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, hd.get());
	curl_easy_perform(curl);
	long httpCode;
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
	if (httpCode == 200)
	{
		Json::Value jsonData;
		Json::Reader jsonReader;
		GetData dataObj;
		if (jsonReader.parse(*hd.get(), jsonData))
		{
			const Json::Value arrayObj = jsonData["cases"];
			int dayCounter = 0;
			while(arrayObj[dayCounter]["date_report"].asString()!=endDate)//count how many days get from url
			{
				dayCounter++;
			}
			dataObj.setLength(dayCounter + 1);
			for (int i = 0; i < dayCounter + 1; i++)
			{
				dataObj.setCovidCurrentCase(arrayObj[i]["cases"].asInt());
				dataObj.setCovidReportDate(arrayObj[i]["date_report"].asString());
			}
			return dataObj;//return the GetData object which already contains all the information of Covid-19
		}
		else
		{
			cout << "HTTP data was:\n" << *hd.get() << endl;
		}
	}
	else
	{
		cout << "Couldn't GET from " << url << " - exiting" << std::endl;
	}
}
