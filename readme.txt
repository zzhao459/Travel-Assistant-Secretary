please download following things before run the code
sudo apt-get install libcurl-dev
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install libcurl4-gnutls-dev
sudo apt-get install libjson-c-dev
sudo apt-get install libjsoncpp-dev
sudo apt-get install libjsoncpp-dev
sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json

for the program to run, simply type following commands:
make clean
qmake 
make

Then the program will generate a qt file

use the command:

./qt


It will prompt a login window, input the following user name and passwords:

user name: 001
password: test


Then there will be a mainwindow for you to request weather data and covid data

You can input a valid city to get current weather data

if the city is invalid, there will be a prompt window to tell you to input a valid data

For the weather, there will be descriptions for the weather, hence the user coould know

if it is appropriate to go out, we also indicate an icon image related to current weather
for visualizing(different icon images will show up if weather changes).


User can also input choose start month and end month for covid data,
User can only input valid day in a month, if the start month exceeds end month or the day in a month is
too big(inputing 32 in a month), then an message will be displayed to warn user to input a valid date

There is also a checking code to check if the user inputs numbers in the input text, user can only input numbers.
If the program recieves inputs other than numbers, the input box would not accept it.

The background colour will also change based on the the covid data fetched.




