#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "mainwindow.h"
#include "headerStrategy.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <QTextStream>
#include <QDataStream>
#include <QIODevice>
namespace Ui {
	class LoginWindow;
}

/*
 * This class is a login window.
 * It shows a MainWindow if user logs in, or shows an error message.
 *
 * @author Yuchao Wang 
 * @brief Login window for the system.
 */
class LoginWindow : public QWidget {
	Q_OBJECT
	public:
		explicit LoginWindow();
	private slots:
		void login();
	private:
		QLabel *userLabel;
		QLineEdit *userEdit;
		QLabel *passwordLabel;
		QLineEdit *passwordEdit;
		QPushButton *loginButton;
};

#endif
