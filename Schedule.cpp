
#include "FDR.h"
#include "Bento.h"
#include "Schedule.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Schedule::Schedule(vector<FDR> myFDR, vector<Bento> myBento) {
	fdr = myFDR;
	bento = myBento;
}


//special functions to convert hours to mins....
int take24hAndConvertToMins(int original) {
	int length = 1, hrs = 0, mins = 0, totalmins = 0;
	//count number of digits
	int temp = original;
	while ((temp /= 10) > 0) {
		length++;
	}
	//seperate into hrs and mins
	if (length == 3 || length == 4) {
		hrs = original / 100;
		mins = original % 100;
	}
	else {
		cerr << "ERROR: deadline does not have 3/4 digits ONLY!";
	}
	totalmins = (hrs * 60) + mins;
	return totalmins;
}

void Schedule::startSchedulingDeadline() {  //point 3 of main menu

	for (int i = 0; i < fdr.size(); i++) {
		for (int j = 0; j < bento.size(); j++) {

			int bentoDeadlineInMins = take24hAndConvertToMins(bento[j].getdeadlineDelivery());
			int fdrDeadlineInMins = take24hAndConvertToMins(fdr[i].getdeadlineBatteryFDR());
			int timeComparison = bentoDeadlineInMins - fdrDeadlineInMins;

			if (timeComparison <= 30 && timeComparison >= 0
				&& fdr[i].getdropOffPointFDR() == bento[j].getdropOffpointBento()
				&& fdr[i].getfullFDR() == 0 && bento[j].getscheduledBento() == 0) {

				scheduleAll.push_back(bento[j].getNameBento() + " is allocated to " + fdr[i].getNameFDR() + "\n");

				bento[j].setscheduledBento(true);
				fdr[i].addToCurrentCapacityFDR(1);//add one bento into the FDR capacity
			}
		}
	}
}

void Schedule::displayFinalPlanByDeadline() {
	for (int i = 0; i < scheduleAll.size(); i++) {
		cout << scheduleAll[i];
	}

}

void Schedule::displayUnfullFDR() {
	for (int i = 0; i < scheduleAll.size(); i++) {
		if (fdr[i].getfullFDR() == 0)
			cout << scheduleAll[i];
	}
}

void Schedule::resetVectorsandFlags() {
	for (int i = 0; i < fdr.size(); i++) {
		fdr[i].setfullFDR(0);
	}
	for (int i = 0; i < bento.size(); i++) {
		bento[i].setscheduledBento(0);
	}
	scheduleAll.erase(scheduleAll.begin(), scheduleAll.end());
}



void Schedule::startSchedulingByMinFDRs() {    //point 4 of main menu 
	
	for (int i = 0; i < fdr.size(); i++) {
		for (int j = 0; j < bento.size()-1; j++) {

			if (bento[j].getscheduledBento() == 0
				&& fdr[i].getfullFDR() == 0
				&& fdr[i].getdropOffPointFDR() == bento[j].getdropOffpointBento()) {

				fdr[i].addToCurrentCapacityFDR(1);
				bento[j].setscheduledBento(1);
				scheduleAll.push_back(bento[j].getNameBento() + " is allocated to " + fdr[i].getNameFDR() + "\n");
				
			}
		}

	}
}

void Schedule::displayFinalPlanByMinimumFDR() {
	for (int i = 0; i < scheduleAll.size(); i++) {
		cout << scheduleAll[i];
	}

}






