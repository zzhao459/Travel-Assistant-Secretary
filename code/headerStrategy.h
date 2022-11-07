#ifndef HEADERSTRATEGY_H
#define HEADERSTRATEGY_H

#include"header.h"
#include <string>
#include<iostream>
using namespace std;
/** 
  @author Tiancong Hou
  @brief selection used to store the data from the user
*/
class Selection
{
 private:
    string startDay;
    string startMonth;
    string endDay;
    string endMonth;
    string city;
  public:
  /** 
  this is a construction class
   @para sd start
   @para sm start month
   @para ed end month
   @para em end month
   */
   Selection(string sd,string sm,string ed,string em,string city);
   /**
   @return return the name of the string
   */
   string getCity();
   /**
   @return the start date
   */
   string getStartDay();
    /**
   @return the start month
   */
   string getStartMonth();
    /**
   @return the end month
   */
   string getEndMonth();
    /**
   @return the end month
   */
   string getEndDay();
   void setStartDay(string startDay);
   void setEndDay(string endDay);
    /**
   @para  the start month
   */
   void setStartMonth(string startMonth);
   void setEndMonth(string endMonth);
   void setCity(string city);
};
class Strategy{
	protected:
	Selection* selection;
	public:
	virtual GetData compute()=0;

};
class CovidStrategy:public Strategy{
	public:
	CovidStrategy(Selection* selection);
	GetData compute();
};
/**
@brief this class is inherient from strategy class
*/
class WeatherStrategy:public Strategy{
	public:
	WeatherStrategy(Selection* selection);
	GetData compute();

};
/**
@brief this class implemented the strategy design pattern
to select which strategy to use
*/
class Context{
	private:
		Strategy *strategy;
        public:
     /**
     @para strategy the strategy user wants to set up
     */
	 Context(Strategy *strategy);
         void setStrategy(Strategy *strategy);
    /**
    @return return the value of result just fetched
    */  
         GetData getResult();
         		

};
/**
@brief this class implement the design pattern of factory create different of object*/
class StrategyFactory{
      public:
            virtual Strategy* createStrategy(Selection* selection)=0;
};
/**
@brief this class is create covid strategy object
*/
class CovidFactory:public StrategyFactory{
  /**
  @para selection the result fetched from the user
  */
	Strategy* createStrategy(Selection* selection);
};
class WeatherFactory:public StrategyFactory{
	Strategy* createStrategy(Selection* selection);
};
#endif
