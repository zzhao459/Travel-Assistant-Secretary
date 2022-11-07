#include "header.h"
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <json/value.h>
#include <fstream>
using namespace std;
GetData Read::retrieve(string startYear, string startMonth, string startDay, string endYear, string endMonth, string endDay, string city)
{
	string startDate = startDay + "-" + startMonth + "-" + startYear;
	string endDate = endDay + "-" + endMonth + "-" + endYear;
	if (city == "toronto")
	{
		city = "3595";
	}
	else if (city == "montreal") {
		city = "2406";
	}
	else if (city == "calgary")
	{
		city = "4832";
	}
	else if (city == "ottawa")
	{
		city = "3551";
	}
	else if (city == "edmonton")
	{
		city = "4834";
	}
	else if (city == "mississauga") {
		city = "3595";
	}
	else if (city == "winnipeg") {
		city = "4601";
	}
	else if (city == "vancouver") {
		city = "595";
	}
	else if (city == "brampton") {
		city = "3527";
	}
	else {
		city = "3544";
	}
	string web = "https://api.opencovid.ca/timeseries?stat=cases&loc=" + city + "&after=" + startDate + "&before=" + endDate;
	string url(web);

	CURL* curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_IPRESOLVE, NULL);
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
			for (int i = 0; arrayObj[i]["date_report"].asString() != endDate; i++)
			{
				dayCounter++;
			}
			dataObj.setLength(dayCounter + 1);
			for (int i = 0; i < dayCounter + 1; i++)
			{
				dataObj.setCovidCurrentCase(arrayObj[i]["cases"].asInt());
				dataObj.setCovidReportDate(arrayObj[i]["date_report"].asString());
			}
			return dataObj;
		}
		else
		{
			cout << "Could not parse HTTP data as JSON" << endl;
			cout << "HTTP data was:\n" << *hd.get() << endl;
		}
	}
	else
	{
		std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
	}
}