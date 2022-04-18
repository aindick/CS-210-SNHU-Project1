                                                                                                         
/*
* Alexis Indick
* 3/20/22
* Twelve Hour and Twenty-Four Hour Clock
*/
#define _CRT_SECURE_NO_WARNINGS //Suppresses warnings that will block the complier.
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

#pragma warning (disable : 4996) //Disables an error due to a deprecated variable localtime.
time_t ttime = time(0);
tm* local_time = localtime(&ttime);

int hours = local_time->tm_hour;
int minutes = local_time->tm_min;
int seconds = local_time->tm_sec;


string abreviations;//The AM and PM


int TwelveHourClock() { //Twelve hour clock function.
	int hrs = hours;
	if (hours > 12) {
		hrs = hours - 12;
	}
	return hrs;
}


void TwentyFourClock() { //Twenty four clock function.
	if (seconds > 59) {
		seconds = 0;
		minutes += 1;
	}
	if (minutes > 59) {
		minutes = 0;
		hours += 1;
	}
	if (hours > 24) {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	if (hours <= 11) {
		abreviations = "A M";
	}
	else {
		abreviations = "P M";
	}
}

// formats the time to transform variables on the clock into a string for display

string Formatting(int time) {
	string format = "0";
	if (time >= 0 && time <= 9) {
		format.append(to_string(time));
	}
	else {
		format = to_string(time);
	}
	return format;
}



void Display() {//For displaying the clocks.


	TwelveHourClock();

	int hour12 = TwelveHourClock();

	string Hour12;
	string Hour24;

	string min;
	string sec;

	Hour24 = Formatting(hours);
	Hour12 = Formatting(hour12);

	min = Formatting(minutes);
	sec = Formatting(seconds);


	cout << setw(60) << string(26, '*') << setw(30) << string(26, '*') << endl;
	cout << setw(60) << "*      12-Hour Clock     *" << setw(30) << "*      24-Hour Clock     *" << endl;
	cout << setw(41) << "*      " << Hour12 << ":" << min << ":" << sec << " " << abreviations << "      *" << setw(11) << "*      " << Hour24 << ":" << min << ":" << sec << "          *" << endl;
	cout << setw(60) << string(26, '*') << setw(30) << string(26, '*') << endl;


	cout << setw(75) << string(26, '*') << endl;
	cout << setw(75) << "*   1 - Add One Hour     *" << endl;
	cout << setw(75) << "*   2 - Add One Minute   *" << endl;
	cout << setw(75) << "*   3 - Add One Second   *" << endl;
	cout << setw(75) << "*   4 - Exit             *" << endl;
	cout << setw(75) << string(26, '*') << endl;

	cout << "Enter a menu option: ";
}
void Clear() { //Clears the screen.
	system("cls");
}

int main() { 
	int userInput = 0;
	int f = 0; //Flag
	
	while (userInput != 4) {
		
		while (!kbhit() && f == 0) {
			
			Clear();
			Display();
			seconds++;
			Sleep(1000);
			main();
			
		}
		
		cin >> userInput;

		switch (userInput) {
		case 1:
			hours = hours + 1;
			minutes = minutes - 1;
			seconds = seconds - 1;

		case 2:
			minutes = minutes + 1;
			seconds = seconds - 1;

		case 3:
			seconds = seconds + 1;

		}
		
	}
	

	exit(0);
}


  
  