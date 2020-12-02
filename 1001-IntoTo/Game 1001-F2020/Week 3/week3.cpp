#include <iostream>
using namespace std;

int main()
{
	int length, width, area;

	// title
	cout << "Triangle Area Calculator\n";

	cout << "enter a length then a width seperated by a space: ";
	cin >> length >> width;

	// user input 
	/*
	cout << "enter the length(in meters): ";
	cin >> length;
	cout << "enter the width (in meters): ";
	cin >> width;
	*/

	// calculate area
	area = length * width;
	cout << "the area is: " << area << endl;

	return 0;
}