#include "loginwindow.h"
#include <QApplication>
using namespace std;

/*
 * This function is the constructor of LoginWindow class.
 * When one calls this function, each member of LoginWindow (i.e., userLabel, userEdit, passwordLabel, passwordEdit, and loginButton) will be initialized.
 * After all the members are initialized, they will be put into QHBoxLayout and QVBoxLayout separately, then this function tells Qt to call LoginWindow::login when loginButton is undergoing a QPushButton::released event.
 *
 * @author Yuchao Wang
 * @brief Constructor for LoginWindow
 */
 
LoginWindow::LoginWindow() {
	this->userLabel = new QLabel("User name");
	this->userEdit = new QLineEdit();
	this->passwordLabel = new QLabel("Password");
	this->passwordEdit = new QLineEdit();
	this->loginButton = new QPushButton("Login");

	QHBoxLayout *userLayout = new QHBoxLayout();
	userLayout->addWidget(userLabel);
	userLayout->addWidget(userEdit);

	QHBoxLayout *passwordLayout = new QHBoxLayout();
	passwordLayout->addWidget(passwordLabel);
	passwordLayout->addWidget(passwordEdit);

	QVBoxLayout *layout = new QVBoxLayout();
	layout->addLayout(userLayout);
	layout->addLayout(passwordLayout);
	layout->addWidget(loginButton);
	setLayout(layout);

	QObject::connect(this->loginButton, &QPushButton::released, this, &LoginWindow::login);
}

/*
 * This function tries to login a user.
 * When logged in, a MainWindow will be shown.
 * Otherwise, a QMessageBox with an error message will be shown.
 *
 * @author Yuchao Wang
 * @brief Login to the system
 */
void LoginWindow::login() {
	QString username = this->userEdit->text();
	QString password = this->passwordEdit->text();
	QFile infile(QString::fromStdString("./account"));//Determine whether you have the right to enter the program according to the file information in the account
	if (infile.open(QIODevice::ReadOnly)) {
		QTextStream in(&infile);
		while (!in.atEnd()) {
			QString user = in.readLine();
			QString pass = in.readLine();
			if (user == username && pass == password) {
			        
				MainWindow *mainWindow = new MainWindow();
				mainWindow->setWindowTitle("Travel Assistance Secretary(2021)");
			        mainWindow->show();
			        hide();
			    return;
			}

		}
      //If the input information does not match, an error will be reported
		QMessageBox box;
		box.setText("Error. Input again.");
		box.exec();
	}
}

