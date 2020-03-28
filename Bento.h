#ifndef BENTO_H
#define BENTO_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bento
{
public:
	Bento(string); //Bento constructor
	class BentoData
	{
	public:
		BentoData(string bName, string bDest, int bDeadline);

		BentoData(BentoData const&); //Copy constructor

		//void assignedRobot(FDR toThisRobot);
		string bentoName, bentoDestination;
		int bentoDeadline;
		string assignedFDR;
		bool bentoUnassigned;
	};
	void showBento();
	void addBento(string bName, string bDest, int bDeadline);
	void removeBento(string bNameToRemove);
	void editBento(string bNameToEdit, string newBdest);
	void editBento(string bNameToEdit, int newBdeadline);
	/*void sortBento();
	void getBentoDeadline();
	void setBentoDeadline();
	void showBentoUnassigned(int);*/
private:
	vector <BentoData> bentos;
};

#endif
