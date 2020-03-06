#ifndef SCHEDULE_H
#define SCHEDULE_H
#pragma once
#include <string>

using namespace std;

class Schedule
{   
	//Private Variables  
	private:
		char destinations;
		string planByDeadline;
		string planByMinimumFDR;

	//Public Methods 
	public:

		//Methods for displaying stuffs relevant to main menu call
		void showAllFDR();
		void showAllBento();
		void showFDRCapacity();
		void DisplayFDRSort();
		void DisplayBentoSort();
		void showBentoDeadline(int);
		void showBentoAssignment(string);

		//Methods for sorting Bento into FDR
		void scheduleBentoByDeadline(string, char, int, string, char, int);
		void scheduleBentoByMinimumFDRs(string, char, int, string, char, int);

		//Method for writing & saving Schedule plan back to excel 
		void writeSaveSchedulingPlan();
		
		//Method for displaying empty fdr
		void showEmptyFDR(int);

		//Method to call FDR's add delete and edit functions
		void AddDeleteEditFDR();
		void AddDeleteEditBento();

};

#endif 

