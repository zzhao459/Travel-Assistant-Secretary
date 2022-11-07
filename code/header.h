#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <vector>

/** @GetData class used for retrive the data of coivid and weather.
    @author Songyuan Sang, Shuaijie Xu, Tiancong Hou, Ziye Zhao
    @date 29th November 2021
    */
class GetData
{
private:
        std::vector<int> covidCurrentCase; /**<initial covid current case*/
        std::vector<std::string> covidReportDate; /**<initial covid report date*/
        std::vector<std::string> covidStartDate; /**<initial covid start date*/
        std::vector<std::string> covidEndDate; /**<initial covid end date*/
        std::string covidCity; /**<initial covid city*/
        int length; /**<initial period of date*/
        int tem; /**<initial current temperature*/
        int min_temp; /**<initial minimum temperature*/
        int max_temp; /**<initial maximum temperature*/
        int pressure; /**<initial pressure*/
        int humidity; /**<initial humidity*/
        std::string mainDes; /**<initial the brief description of weather*/
        std::string description; /**<initial the detail description of weather*/
public:
		/**this a contructor*/
        GetData();
        /**set the covid city
        @para covidCity name of the city
        */
        void setCovidCity(std::string covidCity);
        /**set the covid current day cases
        @para cases covid cases 
        */
        void setCovidCurrentCase(int cases);
        /**set the covid report date
        @para date covid date
        */
        void setCovidReportDate(std::string date);
        /**set the period of date
        @para length the length of period
        */
        void setLength(int length);
      	/**get the  covid report date
        @return the covid report date as a string vector
        */
        std::vector<std::string> getCovidReportDate();
        /**get the  covid current day cases
        @return the covid report date as a string vector
        */
        std::vector<int> getCovidCurrentCase();
        /**get the covid period of date
        @return the covid period of date as integer 
        */
        int getLength();
        
        /**retrive the data of weather.
        @param cityName name of city that user chosen
        @return non
        */
        void readWeather(std::string cityName);
        
        /**Get the mimimum tempurature of current day
        	*/
        int getMin(){
            return min_temp;
        }
		/**Get the maximum tempurature of current day
        	*/
        int getMax(){
            return max_temp;
        }
		/**Get the pressure of current day
        	*/
        int getPressure(){
            return pressure;
        }
		/**Get the humidity of current day
        	*/
        int getHumidity(){
            return humidity;
        }
		/**Get the current tempurature of current day
        	*/
        int getTemp(){
            return tem;
        }
        /**Get the brief weather description tempurature of current day
        	*/
        std::string getMain(){
            return mainDes;
        } 
        /**Get the detail weather description tempurature of current day
        	*/
        std::string getDescription(){
            return description;
        }       
};
/** @Read class used for retrive the data of coivid from API.
    @author Shuaijie Xu, Tiancong Hou
    @date 29th November 2021
    */
class Read
{
    public:
    /** 
   @brief this function retrieve data from Covid-19 API
   @para startYear start year from user interface
   @para startMonth start month from user interface
   @para startDay start day from user interface
   @para endYear end year from user interface
   @para endMonth end month from user interface
   @para endDay end day from user interface
   @para city city from user interface
   @return GetData object that contain all information about Covid-19
   */
    GetData retrieve(std::string startYear,std::string startMonth,std::string startDay,std::string endYear,std::string endMonth,std::string endDay,std::string city);
};
#endif
