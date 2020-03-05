#ifndef SCHEDULE_H
#define SCHEDULE_H
#pragma once
#include <string>

using namespace std;

class Schedule
{   
	//Private Variables  
	private:
		char stop;
		string schedulingPlan;

	//Public Methods 
	public:
		//Methods for reading excel files
		void readFDR();
		void readBento();

		//Methods for displaying stuffs relevant to main menu call
		void showMainMenu();
		void showAllFDR();
		void showAllBento();
		void showFDRCapacity();
		void displaySort();
		void showBentoDeadline(int);
		void showBentoAssignment(string);

		//Methods for sorting schedule 
		void scheduleByDeadline(string, char, int, string, char, int);
		void scheduleMinimumFDRs(string, char, int, string, char, int);

		
		//Methods for manipulating data
		void add();
		void remove();
		void edit();

		//Method for writing Schedule plan to 
		void writeSchedulingPlan();
		

		//Method for saving schedule into excel 
		void SaveSchedulePlan(string, char, int, string, char, int);

		//Method for displaying empty fdr
		void EmptyFDR(int);









};

#endif 

