#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <json/value.h>
#include <fstream>
#include "header.h"

using namespace std;

void GetData::readWeather(string cityName)
{
    string web = "https://api.openweathermap.org/data/2.5/weather?q=" + cityName + ",ca&appid=339219cb33b115495e570196e33e47b7";

    std::string url(web);

    CURL *curl = curl_easy_init();


    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, NULL);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);

    std::unique_ptr<std::string> hd(new std::string());

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, hd.get());

    curl_easy_perform(curl);
    long httpCode;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    const char *str = "{\"name\":\"shuiyixin\",\"age\":\"21\",\"sex\":\"man\"}";
    if (httpCode == 200)
    {
        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*hd.get(), jsonData))
        {
         

            int temperature = jsonData["main"]["temp"].asInt();
            tem= temperature;
           

            string des = jsonData["weather"][0]["description"].asString();
            description = des;
           
        }
        else
        {
            std::cout << "Could not parse HTTP data as JSON" << std::endl;
            std::cout << "HTTP data was:\n"
                      << *hd.get() << std::endl;
            
        }
    }
    else
    {
        std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
        
    }
}


/*
int main(){
    GetData * obj = new GetData();

    obj->readWeather("London");



    std::cout << "The Temperature of local area has been successfully retrieved from internet" << std::endl;
    std::cout << obj->getTemp() << std::endl;


    std::cout << "The description of local area has been successfully retrieved from internet" << std::endl;
    std::cout << obj->getDescription() << std::endl;
}
*/