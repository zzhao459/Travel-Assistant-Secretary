#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <json/value.h>
#include <fstream>
#include "headerStrategy.h"

using namespace std;
int main()
{   
    Selection* selection=new Selection("10","06","10","07","toronto");
    StrategyFactory* factory=new CovidFactory();
    Context context(factory->createStrategy(selection));
    GetData dataObj = context.getResult();
    vector<int> cases = dataObj.getCovidCurrentCase();
    vector<string> date = dataObj.getCovidReportDate();
    cout << "Total " << dataObj.getLength() << " days COVID-19 report in toronto" << endl;
    for (int i = 0; i < dataObj.getLength(); i++)
    {
        cout << "date: " << date[i] << " case:" << cases[i] << endl;
    }
    
    StrategyFactory* factory1=new WeatherFactory();
    Context context1(factory1->createStrategy(new Selection("","","","","London")));
    GetData obj=context1.getResult();
    std::cout << "The Temperature of local area has been successfully retrieved from internet" << std::endl;
    std::cout << obj.getTemp() << std::endl;

    std::cout << "The description of local area has been successfully retrieved from internet" << std::endl;
    std::cout << obj.getDescription() << std::endl;

    
    return 0;
}
