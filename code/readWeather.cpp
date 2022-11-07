#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <json/value.h>
#include <fstream>
#include "header.h"
namespace
    {
        std::size_t cb(char* in,std::size_t s,std::size_t n,std::string* out)
        {
            std::size_t totalBytes(s * n);
            out->append(in, totalBytes);
            return totalBytes;
        }
    }
using namespace std;

/** @This class is used to retrive the data of weather.

    @author Songyuan Sang, Ziye Zhao
    @date 29th Movember 2021
    */


/**retrive the data of weather.
        @param cityName name of city that use chosen
        @return non
        */
void GetData::readWeather(string cityName)
{
    string web = "https://api.openweathermap.org/data/2.5/weather?q=" + cityName + ",ca&appid=339219cb33b115495e570196e33e47b7"; //! The Address of Weather API

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
    //const char *str = "{\"name\":\"shuiyixin\",\"age\":\"21\",\"sex\":\"man\"}";
    if (httpCode == 200)
    {
        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*hd.get(), jsonData))
        {        
            tem = jsonData["main"]["temp"].asInt();           
            mainDes = jsonData["weather"][0]["main"].asString();
            min_temp = jsonData["main"]["temp_min"].asInt();
            max_temp = jsonData["main"]["temp_max"].asInt();
            pressure = jsonData["main"]["pressure"].asInt();
            humidity = jsonData["main"]["humidity"].asInt();
            tem = jsonData["main"]["temp"].asInt();
            description = jsonData["weather"][0]["description"].asString();
           
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
