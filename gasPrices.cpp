// Assignment 4 for CS 161 Goble
// This program compares gas prices in Oregon, Califonia and Washington.
// Author: Mia Armstrong
// Date: October 30,2011
// Sources: None
// Compiled with: Visual C++ 2008 Express Edition

#include <iostream>
#include <iomanip>		// needed for fixed and setprecision below.
#include <string>
#include <fstream>     // to open files on disk

using namespace std;

int main ()
{

	                          // Set the output stream to display floating point numbers..
                              // ... in fixed point notation rather than scientific notation.
    cout << fixed << showpoint << setprecision(3);  
	                          // Set the output stream to display exactly 3 places of decimals...
	                          // show decimals even if at zero.
                              
	double caTotal;
	double orTotal;
	double waTotal;
	double price;
	double caAverage;
	double orAverage;
	double waAverage;
	double totalAverage;
	int caCount;
	int orCount;
	int waCount;
	string reply;
	string city;
	string state;
	string line;
	string Ca;
	string Or;
	string Wa;
	string inputFileName;
	ifstream inputFile;


	cout<< "Please enter the full pathname to the data file on disk: "<< endl;
	getline (cin, inputFileName);
	inputFile.open (inputFileName.c_str()); // to open the file and convert c++ string to c string type.
	if ( ! inputFile.is_open()) {      //checks the file opens successfully 
		cout<< "Unable to open input file: "<< endl;
		cout<< "Press ENTER to continue. "<< endl;
		getline (cin, reply);
		exit(1);
	}
	 while (inputFile.peek() != EOF) {  //displays the contents of the file.
        getline(inputFile, line);
        cout << line << endl;
    }
	 inputFile.clear();  //clear error flags.
	 inputFile.seekg(0); //rewind input stream.

	 caTotal = 0;
	 orTotal = 0;
	 waTotal = 0;
	 caCount = 0;    // sets all totals and counts to zero.
	 orCount = 0;
	 waCount = 0;
	 price = 0;

	 while (inputFile >> city >> state >> price){
		 getline (inputFile, line);
		 if (state == "Ca") {
			 caTotal = caTotal + price;
			 caCount ++;
		 }
		 else if (state == "Or") {
			 orTotal = orTotal + price;
			 orCount ++;
		 }
		 else if (state == "Wa"){
			 waTotal = waTotal + price;
			 waCount ++;
		 }
	 }

	 inputFile.close();  //close the input file.
	 caAverage = caTotal / caCount;
	 orAverage = orTotal / orCount;
	 waAverage = waTotal / waCount;
	 //Outputs the average price for the three states.
	 cout << "The average gas price in California is " << caAverage << " per gallon."<< endl;
	 cout << "The average gas price in Oregon is " << orAverage << " per gallon."<< endl;
	 cout << "The average gas price in Washington is " << waAverage << " per gallon."<< endl;
	 totalAverage = (caTotal + orTotal +waTotal) / (caCount + orCount + waCount);
	 cout << "The average gas price for all stations surveyed is " << totalAverage << "per gallon."<< endl;

     //Outputs the state with the lowest and highest average.
	 if (caAverage < orAverage && orAverage < waAverage){
		 cout << "California has the lowest average gas price.\nWashinton has the highest average gas price."<< endl;
		 }
	 else if (caAverage < waAverage && waAverage < orAverage){
		 cout << "California has the lowest average gas price. \nOregon has the highest average gas price."<< endl;
		 }
	 else if (orAverage < caAverage && caAverage < waAverage){
		 cout << "Oregon has the lowest average gas price. \nWashington has the highest average gas price."<< endl;
		 }
	 else if (orAverage < waAverage && waAverage < caAverage){
		 cout << "Oregon has the lowest average gas price. \nCalifornia has the highest average gas price."<< endl;
	   	 }
	 else if (waAverage < caAverage && caAverage < orAverage){
		 cout << "Washington has the lowest average gas price. \nOregon has the highest average gas price."<< endl;
		 }
	 else if (waAverage < orAverage && orAverage < caAverage){
		 cout << "Washington has the lowest average gas price. \nCalifornia has the highest average gas price."<< endl;
		 }
	 

	 cout << "Please press ENTER to continue: "<< endl;
	 getline (cin, reply);
	 return 0;
}
		 





