#ifndef FDR_H
#define FDR_H
#include <iostream>
#include <string>
#include <vector>
#include "FDR.h"

using namespace std;

class FDR
{
public:
	FDR(string); //FDR constructor
	class FDRData
	{
	public:
		FDRData(string FName, string FCap, string FDRDest, int FDeadline);
		FDRData(FDRData const&); //Copy constructor

		string FDRName, FDRDestination, FDRCapacity;
		int FDRDeadline;
		bool FDRAvailability;
	};

	void showFDR();
	void addFDR(string FName, string FCap, string FDRDest, int FDeadline);
	void removeFDR(string fNameToRemove);
	void editFDRCap(string fNameToEdit, string newFCap);
	void editFDRDest(string fNameToEdit, string newFDest);
	void editFDRDeadline(string fNameToEdit, int newFDeadline);
	/*void getRemainingFDR();
	void sortFDR();*/
private:
	vector <FDRData> FDRs;
};
//MAIN PROGRAM

#endif


