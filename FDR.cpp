#ifndef fdr_cpp
#define fdr_cpp
#include <iostream>
#include <fstream>
#include <string>
#include "fdr.h"

using namespace std;


void FDR::showFDR()
{
	/*string fdrName;
	string fdrCapacity;
	string fdrDest;
	string fdrDeadline;

	ifstream fdrFile;
	fdrFile.open("FDRs.csv");

	if (fdrFile.is_open())
	{
		while (!fdrFile.eof())
		{
			getline(fdrFile, fdrName, ',');
			getline(fdrFile, fdrCapacity, ',');
			getline(fdrFile, fdrDest, ',');
			getline(fdrFile, fdrDeadline, '\n');

			cout << fdrName << "\t" << fdrCapacity << "\t\t" << fdrDest << " \t\t" << fdrDeadline << endl;
		}
		fdrFile.close();
	}
	else
	{
		cout << "Unable to open file!";
	}*/

	ifstream fdrFile;
	fdrFile.open("FDRs.csv");

	if (!fdrFile.is_open())
	{
		cout << "Unable to open file!";
		return 0;
	}
	else
	{
		string fdrName, fdrDest, tempString, fdrDeadline;
		int fdrCapacity;

		string myString;
		string line;

		while (getline(fdrFile, line))
		{
			stringstream FDR(line);
			getline(FDR, fdrName, ',');
			getline(FDR, tempString, ',');
			fdrCapacity = stoi(tempString);
			getline(FDR, fdrDest, ',');
			getline(FDR, fdrDeadline, '\n');

			cout << fdrCapacity;
		}
		fdrFile.close(); //trying the stoi function to convert string variables to int but having issue with it
	}
}

#endif
