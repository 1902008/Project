#ifndef SCHEDULE_H
#define SCHEDULE_H

#pragma once
#include <vector>
#include <string>
#include "FDR.h"
#include "Bento.h"
class Schedule {
private:
	vector<FDR> fdr; //fdr object
	vector<Bento> bento; //bento object
	vector <string> scheduleAll;
public:
	Schedule(vector<FDR>, vector<Bento>);
	void startSchedulingDeadline();
	void displayFinalPlanByDeadline();
	void displayUnfullFDR();
	void resetVectorsandFlags();
	void startSchedulingByMinFDRs();
	void displayFinalPlanByMinimumFDR();
	
};
#endif
