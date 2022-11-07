#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QComboBox>
#include <QPixmap>
#include <string>
#include <ctime>
#include "header.h"
#include "headerStrategy.h"
using namespace std;
namespace Ui {
		class MainWindow;
}

/*
 * With this window, user can interact with the system.
 *
 * @author Yuchao Wang 
 * @brief The main window of the system.
 *
 */
class MainWindow : public QWidget {
	Q_OBJECT
	public:
		explicit MainWindow();
		private slots:
		void handleSearchButton();
	private:
		QLabel *startMonthLabel;
		QComboBox *startMonth;
		QLabel *startDayLabel;
		QLineEdit *startDay;
		QLabel *endMonthLabel;
		QComboBox *endMonth;
		QLabel *endDayLabel;
		QLineEdit *endDay;
		QLabel *cityLabel;
		QLineEdit *city;
		QLabel *termLabel;
		QComboBox *term;
		QPushButton *searchButton;
		QLabel *image;
		QListWidget *output;
};

#endif


