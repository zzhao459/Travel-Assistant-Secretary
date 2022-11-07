#include "loginwindow.h"
#include <QApplication>

#include <QFile>

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	LoginWindow loginWindow;
	loginWindow.setWindowTitle("Travel Assistance Secretary (2021)");
	loginWindow.show();
	return app.exec();
}
