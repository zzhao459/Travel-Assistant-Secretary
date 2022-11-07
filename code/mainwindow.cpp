#include "mainwindow.h"
#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPixmap>
#include <QMessageBox>

#include <boost/format.hpp>
/**

@author:Yuchao Wang Tiancong Hou Songyuan Sang
@date 29th November 2021
*/

using namespace std;
using namespace boost;
//Interface creation part

/*
 * This function initialize members in a MainWindow instance, then put them into the layout of the instance.
 *
 * @brief Constructor for MainWindow
 * @author Yuchao Wang
 */
MainWindow::MainWindow()
{
	this->startMonthLabel = new QLabel("Start Month:"); //! Create a drop-down menu to display the month
	this->startMonth = new QComboBox();
	this->startMonth->addItem("January");
	this->startMonth->addItem("February");
	this->startMonth->addItem("March");
	this->startMonth->addItem("April");
	this->startMonth->addItem("May");
	this->startMonth->addItem("June");
	this->startMonth->addItem("July");
	this->startMonth->addItem("August");
	this->startMonth->addItem("September");
	this->startMonth->addItem("October");
	this->startMonth->addItem("November");
	this->startMonth->addItem("December");

	this->startDayLabel = new QLabel("Start Day:"); //! Create input box
	this->startDay = new QLineEdit();
	startDay->setValidator(new QIntValidator(1, 31, this));
	
	this->endMonthLabel = new QLabel("End Month:");//! Create a drop-down menu to display the month
	this->endMonth = new QComboBox();
	this->endMonth->addItem("January");
	this->endMonth->addItem("February");
	this->endMonth->addItem("March");
	this->endMonth->addItem("April");
	this->endMonth->addItem("May");
	this->endMonth->addItem("June");
	this->endMonth->addItem("July");
	this->endMonth->addItem("August");
	this->endMonth->addItem("September");
	this->endMonth->addItem("October");
	this->endMonth->addItem("November");
	this->endMonth->addItem("December");

	this->endDayLabel = new QLabel("End Day:");//! Create input box
	this->endDay = new QLineEdit();
	endDay->setValidator(new QIntValidator(1, 31, this));

	this->cityLabel = new QLabel("City:");
	this->city = new QLineEdit();
	this->termLabel = new QLabel("Type:");
	this->term = new QComboBox();//Create a drop-down menu 
	this->term->addItem("Weather");
	this->term->addItem("COVID-19");
	this->searchButton = new QPushButton("Search");//! Create a Search Button
	this->image = new QLabel();
	this->output = new QListWidget();

	QHBoxLayout *searchLayout = new QHBoxLayout();
	searchLayout->addWidget(this->startMonthLabel);
	searchLayout->addWidget(this->startMonth);
	searchLayout->addWidget(this->startDayLabel);
	searchLayout->addWidget(this->startDay);
	searchLayout->addWidget(this->endMonthLabel);
	searchLayout->addWidget(this->endMonth);
	searchLayout->addWidget(this->endDayLabel);
	searchLayout->addWidget(this->endDay);
	searchLayout->addWidget(this->cityLabel);
	searchLayout->addWidget(this->city);
	searchLayout->addWidget(this->termLabel);
	searchLayout->addWidget(this->term);
	searchLayout->addWidget(this->searchButton);

	QHBoxLayout *outputLayout = new QHBoxLayout(); //! The interface displays a map of Canada
	QPixmap canada(":/Canada.png");
	image->setPixmap(canada.scaled(image->width(), image->height()));
	outputLayout->addWidget(this->image);
	outputLayout->addWidget(this->output);

	QVBoxLayout *layout = new QVBoxLayout();
	layout->addLayout(searchLayout);
	layout->addLayout(outputLayout);
	setLayout(layout);
    //The interface displays the default output information, introducing the regions included in this program.
	this->output->addItem(QString::fromStdString("Welcome to use this program."));
	this->output->addItem(QString::fromStdString("We provides ten cites:"));
	this->output->addItem(QString::fromStdString("1. Toronto"));
	this->output->addItem(QString::fromStdString("2. Montreal "));
	this->output->addItem(QString::fromStdString("3. Calgary"));
	this->output->addItem(QString::fromStdString("4. Ottaway"));
	this->output->addItem(QString::fromStdString("5. Edmonton"));
	this->output->addItem(QString::fromStdString("6. Mississauga"));
	this->output->addItem(QString::fromStdString("7. Winnipeg"));
	this->output->addItem(QString::fromStdString("8. Vancouver"));
	this->output->addItem(QString::fromStdString("9. Brampton"));
	this->output->addItem(QString::fromStdString("10. London"));

	QObject::connect(this->searchButton, &QPushButton::released, this, &MainWindow::handleSearchButton);
}

/*
 * This function 
 *
 * @brief Handler for searchButton
 * @author Yuchao Wang
 */
void MainWindow::handleSearchButton() 
{
	string sMonth;
	int start_num = 0;
	int end_num= 0;

	this->output->clear();
	this->output->addItem(QString::fromStdString("These are the data we have fetched based on your requests"));

	if(this->startMonth->currentText().toStdString()=="January")
	{
		sMonth = "01";
		start_num = 1;
	}
	else if(this->startMonth->currentText().toStdString()=="February")
	{
		sMonth = "02";
		start_num = 2;
	}
	else if(this->startMonth->currentText().toStdString()=="March")
	{
		sMonth = "03";
		start_num = 3;
	}
	else if(this->startMonth->currentText().toStdString()=="April")
	{
		sMonth = "04";
		start_num = 4;
	}
	else if(this->startMonth->currentText().toStdString()=="May")
	{
		sMonth = "05";
		start_num = 5;
	}
	else if(this->startMonth->currentText().toStdString()=="June")
	{
		sMonth = "06";
		start_num = 6;
	}
	else if(this->startMonth->currentText().toStdString()=="July")
	{
		sMonth = "07";
		start_num = 7;
	}
	else if(this->startMonth->currentText().toStdString()=="August")
	{
		sMonth = "08";
		start_num = 8;
	}
	else if(this->startMonth->currentText().toStdString()=="September")
	{
		sMonth = "09";
		start_num = 9;
	}
	else if(this->startMonth->currentText().toStdString()=="October")
	{
		sMonth = "10";
		start_num = 10;
	}
	else if(this->startMonth->currentText().toStdString()=="November")
	{
		sMonth = "11";
		start_num = 11;
	}
	else if(this->startMonth->currentText().toStdString()=="December")
	{
		sMonth = "12";
		start_num = 12;
	}

	string eMonth;
	if(this->endMonth->currentText().toStdString()=="January")
	{
		eMonth = "01";
		end_num = 1;
	}
	else if(this->endMonth->currentText().toStdString()=="February")
	{
		eMonth = "02";
		end_num = 2;
	}
	else if(this->endMonth->currentText().toStdString()=="March")
	{
		eMonth = "03";
		end_num = 3;
	}
	else if(this->endMonth->currentText().toStdString()=="April")
	{
		eMonth = "04";
		end_num = 4;
	}
	else if(this->endMonth->currentText().toStdString()=="May")
	{
		eMonth = "05";
		end_num = 5;
	}
	else if(this->endMonth->currentText().toStdString()=="June")
	{
		eMonth = "06";
		end_num = 6;
	}
	else if(this->endMonth->currentText().toStdString()=="July")
	{
		eMonth = "07";
		end_num = 7;
	}
	else if(this->endMonth->currentText().toStdString()=="August")
	{
		eMonth = "08";
		end_num = 8;
	}
	else if(this->endMonth->currentText().toStdString()=="September")
	{
		eMonth = "09";
		end_num = 9;
	}
	else if(this->endMonth->currentText().toStdString()=="October")
	{
		eMonth = "10";
		end_num = 10;
	}
	else if(this->endMonth->currentText().toStdString()=="November")
	{
		eMonth = "11";
		end_num = 11;
	}
	else if(this->endMonth->currentText().toStdString()=="December")
	{
		eMonth = "12";
		end_num = 12;
	}
    /**Get the current daate
        */
        std::time_t t = std::time(0); 
        std::tm* now = std::localtime(&t);
         int currentM=now->tm_mon + 1;
         int currentD=now->tm_mday;
         int start = this->startDay->text().toInt();
         int end = this->endDay->text().toInt();
         printf("%d\n",currentM);
           printf("%d\n",currentD);
         if(start_num>currentM){
         	QMessageBox month_error;
		month_error.setText("Error: data not available");
		month_error.exec();
		return;
         }
  /**Check if the user inpute data is availiable
        */
         if(start_num==currentM){
         	if(start>currentD-3){
		 	QMessageBox month_error;
			month_error.setText("Error: data not available");
			month_error.exec();
			return;
         	}
         }
         if(end_num>currentM){
         	QMessageBox month_error;
		month_error.setText("Error: data not available");
		month_error.exec();
		return;
         }
         if(end_num==currentM){
         	if(end>currentD-3){
		 	QMessageBox month_error;
			month_error.setText("Error: data not available");
			month_error.exec();
			return;
         	}
         }
	if (start_num > end_num)
	{
		QMessageBox month_error;
		month_error.setText("Error: start month cannot exceed end month");
		month_error.exec();
		return;
	}

	
	if(this->startDay->text().toStdString()[0]=='0')
	{
		QMessageBox day_error;
		day_error.setText("Error: Invalue day ");
		day_error.exec();
		return;
	}
	
	if(this->endDay->text().toStdString()[0]=='0')
	{
		QMessageBox day_error;
		day_error.setText("Error: Invalue day ");
		day_error.exec();
		return;
	}
	if(start_num == 2){
		if(start > 28){
			QMessageBox day_error;
			day_error.setText("Error: Invalue day ");
			day_error.exec();
			return;
		}

	}
	if(end_num == 2){
		if(end > 28){
			QMessageBox day_error;
			day_error.setText("Error: Invalue day ");
			day_error.exec();
			return;
		}

	}
	if(start_num == end_num){
		if(start > end){
			QMessageBox day_error;
			day_error.setText("Error: Invalue day ");
			day_error.exec();
			return;
		}

	}
	if(start_num == 1 || start_num == 3 ||start_num == 5|| start_num == 7|| start_num == 8 || start_num == 10 || start_num == 12){
		if(start > 31){
			QMessageBox day_error;
			day_error.setText("Error: Invalue day ");
			day_error.exec();
			return;
		}

	}

	else{
		if(start > 30){
		        printf("3\n");
			QMessageBox day_error;
			day_error.setText("Error: Invalue day ");
			day_error.exec();
			return;
		}
	}
	
        if(end_num == 1 || end_num == 3 ||end_num == 5|| end_num == 7|| end_num == 8 || end_num == 10 || end_num == 12){
          
          if(end >31){
                  printf("1\n");
              QMessageBox day_error;
              day_error.setText("Error: Invalue day ");
              day_error.exec();
              return;
          }

	}

	else{
		if(end >30){
			QMessageBox day_error;
			day_error.setText("Error: Invalue day ");
			day_error.exec();
			return;
		}
	}

	//! Determine whether the input result is the 10 cities set by the system, if yes, display the map.
	string city= this->city->text().toStdString();
	do {
		if (city == "Canada") {
			break;
		}
		if (city == "Brampton") {
			break;
		}
		if (city == "Calgary") {
			break;
		}
		if (city == "Edmonton") {
			break;
		}
		if (city == "Mississauga") {
			break;
		}
		if (city == "Montreal") {
			break;
		}
		if (city == "Ottawa") {
			break;
		}
		if (city == "Vancouver") {
			break;
		}
		if (city == "Winnipeg") {
			break;
		}
		if (city == "London") {
			break;
		}
		if (city == "Toronto") {
			break;
		}
		
		QMessageBox box;
		box.setText("Error: please enter a valid city");//! if not, report an error.
		box.exec();
		return;
	} while (false);
        
	QPixmap map(QString::fromStdString(str(format(":/%1%.png") % city)));
	this->image->setPixmap(map.scaled(this->image->width(), this->image->height()));
	string sDay=this->startDay->text().toStdString();
	string eDay=this->endDay->text().toStdString();
	string type = this->term->currentText().toStdString();

	Selection* selectionObj= new Selection(sMonth,sDay,eMonth,eDay,city);
	Context* context;
  	/**if user choose covid-19, then the data of covid will display in the textbox
        */
	if(type=="COVID-19"){
	        
		StrategyFactory* factory=new CovidFactory();
		context = new Context(factory->createStrategy(selectionObj));
		GetData dataObj = context->getResult();
		vector<int> cases = dataObj.getCovidCurrentCase();
		vector<string> date = dataObj.getCovidReportDate();
		this->output->addItem("The text colour will be changed by the number of covid cases");
		this->output->addItem("green : average covid cases<=50   yellow: 50 <average covid cases <= 150  red: average covid cases > 150 ");
		this->output->addItem(QString::fromStdString("City: " + selectionObj->getCity()));
		this->output->addItem(QString::fromStdString("Total : ") + QString::number(dataObj.getLength())+ QString::fromStdString(" days COVID-19 report in " + selectionObj->getCity()));
                       
        int q=4;
        int total=0;
      
            for (int i = 0; i < dataObj.getLength(); i++)
		    {
		               
				int k=QString::number(cases[i]).toInt();
				total =total +k;
		    }
      
		    total =total/dataObj.getLength();
		    string var;
      			/**color of word will change with the average number of coivd
        			*/
		        if(total <=50){
		        	this->output->item(0)->setForeground(Qt::green);
		               this->output->item(1)->setForeground(Qt::green);
		               this->output->item(2)->setForeground(Qt::green);
		               this->output->item(3)->setForeground(Qt::green);
                       
		        }
		        else if(total>50&&total<=150){
		        	this->output->item(0)->setForeground(Qt::darkYellow);
                       	this->output->item(1)->setForeground(Qt::darkYellow);
                       	this->output->item(2)->setForeground(Qt::darkYellow);
                       	this->output->item(3)->setForeground(Qt::darkYellow);
                       	
		        }
		        else{
				this->output->item(0)->setForeground(Qt::red);
		               this->output->item(1)->setForeground(Qt::red);
		               this->output->item(2)->setForeground(Qt::red);
		               this->output->item(3)->setForeground(Qt::red);
		        }
                       
			for (int i = 0; i < dataObj.getLength(); i++)
		    {
		               if(total <=50){
					this->output->addItem(QString::fromStdString("Date: " + date[i]));
					
					this->output->addItem(QString::fromStdString("Case: ") + QString::number(cases[i]));

					this->output->addItem("");
					this->output->item(q)->setForeground(Qt::green);
					q++;
					this->output->item(q)->setForeground(Qt::green);
					q++;
					this->output->item(q)->setForeground(Qt::green);
					q++;
					}
				else if(total>50&&total<=150){
					this->output->addItem(QString::fromStdString("Date: " + date[i]));
					
					this->output->addItem(QString::fromStdString("Case: ") + QString::number(cases[i]));

					this->output->addItem("");
					this->output->item(q)->setForeground(Qt::darkYellow);
					q++;
					this->output->item(q)->setForeground(Qt::darkYellow);
					q++;
					this->output->item(q)->setForeground(Qt::darkYellow);
					q++;
					}
				else{
					this->output->addItem(QString::fromStdString("Date: " + date[i]));
					
					this->output->addItem(QString::fromStdString("Case: ") + QString::number(cases[i]));

					this->output->addItem("");
					this->output->item(q)->setForeground(Qt::red);
					q++;
					this->output->item(q)->setForeground(Qt::red);
					q++;
					this->output->item(q)->setForeground(Qt::red);
					q++;
				}
				//this->output->item(i+3)->setForeground(Qt::red);
				//this->output->item(i+4)->setForeground(Qt::red);
		    }
		   
	}
  /**image will change with diffent description of weather
        */
	else{
		StrategyFactory* factory1=new WeatherFactory();
		    context=new Context(factory1->createStrategy(selectionObj));
		    GetData obj=context->getResult();
			string newMain = obj.getMain();
			QListWidgetItem *itm = new QListWidgetItem();
			if(newMain == "Thunderstorm"){
				itm->setIcon(QIcon("./map/Thunderstorm.png"));
			}

			if(newMain == "Drizzle"){
				itm->setIcon(QIcon("./map/Drizzle.png"));
			}

			if(newMain == "Rain"){
				itm->setIcon(QIcon("./map/Rain.png"));
			}

			if(newMain == "Snow"){
				itm->setIcon(QIcon("./map/Snow.png"));
			}

			if(newMain == "Atmosphere"){
				itm->setIcon(QIcon("./map/Atmosphere.png"));
			}

			if(newMain == "Clear"){
				itm->setIcon(QIcon("./map/Clear.png"));
			}

			if(newMain == "Clouds"){
				itm->setIcon(QIcon("./map/Clouds.png"));
			}
			/**Display the weather of chosen city in textbox
        		*/
			this->output->addItem(QString::fromStdString("The data from selection city: " + selectionObj->getCity()));
            this->output->addItem(" ");
			this->output->addItem(QString::fromStdString("The current temperature of " + selectionObj->getCity() + ": ") + QString::number(obj.getTemp()) + " K");
			this->output->addItem(" ");
            this->output->addItem(QString::fromStdString("The current minumum temperature of " + selectionObj->getCity() + ": ") + QString::number(obj.getMin()) + " K");
			this->output->addItem(" ");
            this->output->addItem(QString::fromStdString("The current maximum temperature of " + selectionObj->getCity() + ": ") + QString::number(obj.getMax()) + " K");
			this->output->addItem(" ");
			this->output->addItem(QString::fromStdString("The description of city " + selectionObj->getCity() + "is: " + obj.getDescription()));
			this->output->addItem(itm);
			this->output->addItem(" ");
            this->output->addItem(QString::fromStdString("The current pressure of " + selectionObj->getCity() + ": ") + QString::number(obj.getPressure()) + " hPa");
			this->output->addItem(" ");
            this->output->addItem(QString::fromStdString("The current huminity of " + selectionObj->getCity() + ": ") + QString::number(obj.getHumidity()) + " %");
			

            
            
            
	}
    
}
