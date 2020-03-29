#ifndef BENTO_CPP
#define BENTO_CPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Bento.h"

using namespace std;

Bento::Bento(string filePath)
{
	int bentoDeadline;
	string line;
	string bentoName;
	string bentoDest;

	ifstream bentoFile;
	bentoFile.open(filePath);

	if (bentoFile.is_open())
	{
		while (getline(bentoFile, line))
		{
			/*cout << bentoName << "," << bentoDest << "," << bentoDeadline << endl;*/
			stringstream check1(line); // convert string into a in stream which will use for getline 

			// Tokenizing check1 w.r.t. comma 
			getline(check1, bentoName, ','); //using getline to extract bentoName from in stream (instream = check1)
			getline(check1, bentoDest, ','); //using getline to extract bentoDest from in stream (instream = check1)
			/*getline(check1, bdeadline);*/
			(check1) >> bentoDeadline; //using getline to extract bentoDeadline from in stream (instream = check1) 
			// There is no ',' left in the stream therefore can use the output operator to initialise bentoDeadline 
			BentoData currentLineBentoInfo(bentoName, bentoDest, bentoDeadline);
			bentos.push_back(currentLineBentoInfo);
		}
		bentoFile.close();
	}
	else
	{
		cout << "Unable to open file!";
	}
}
void Bento::showBento()
{
	/*vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);

	for (int i : vec)
	{
		cout << i;
	}*/

	for (BentoData & currentLineBentoInfo : bentos)
	{
		cout << currentLineBentoInfo.bentoName << ",";
		cout << currentLineBentoInfo.bentoDestination << ",";
		cout << currentLineBentoInfo.bentoDeadline << endl;
	}
}


Bento::BentoData::BentoData(string bName, string bDest, int bDeadline)
	: bentoName(bName), bentoDestination(bDest), bentoDeadline(bDeadline),
	bentoUnassigned(false) //this boolean used to keep track whether the bento is assign to a FDR specified by assignedFDR
{}

Bento::BentoData::BentoData(BentoData const& bData) 
	: bentoName(bData.bentoName), bentoDestination(bData.bentoDestination), bentoDeadline(bData.bentoDeadline), bentoUnassigned(false)
{
}

void Bento::addBento(string bName, string bDest, int bDeadline)
{
	BentoData currentLineBentoInfo(bName, bDest, bDeadline);
	bentos.push_back(currentLineBentoInfo);
}

void Bento::removeBento(string bNameToRemove)
{
	// (false), do nothing. Actually dont even need to have the false statement AKA dont need to handle false cases

	// cout << "Eh u trying to be funny, removing something that dont exist";
	vector<BentoData>::iterator iteratorOfBentoToRemove = bentos.begin();
	// Go thru each bento's name in bentos(bentos is a vector in my class Bento)
	while (iteratorOfBentoToRemove != bentos.end())
	{
		// If there is a bento's name matching bNameToRemove
		if (bNameToRemove == iteratorOfBentoToRemove->bentoName)
		{
			// (true), get the iterator then call bentos.erase(iteratorOfBentoToRemove). After that, return from the function
			// YES I FOUND IT
			bentos.erase(iteratorOfBentoToRemove); // erase horizontal line
			return; // Since this is a void function, I just type "return;" can liao. Don't need to type anything after return, if return
			// anything means its not void anymore. Even return void is not void;
		}

		iteratorOfBentoToRemove =next(iteratorOfBentoToRemove);
	}
	// By the time it looks thru each of the bento in bentos, still cannot find any bento's name matching bNameToRemove. 
	// Meaning it never existed in ur bentos before

	cout << "Eh u trying to be funny, removing something that dont exist";
}
void Bento::editBento(string bNameToEdit, string newBdest)
{
	vector<BentoData>::iterator iteratorOfBentoToEdit = bentos.begin();
	// Go thru each bento's name in bentos(bentos is a vector in my class Bento)
	//while (iteratorOfBentoToEdit != bentos.end())
	//{
	//	// If there is a bento's name matching bNameToEdit 
	//	if (bNameToEdit == iteratorOfBentoToEdit->bentoName)
	//	{
	//		// (true), get the iterator then UPDATE by iteratorOfBentoToEdit->destination = newBdest. After that, return from the function
	//		iteratorOfBentoToEdit->bentoDest = newBdest;
	//		return;
	//	}
	//	// 
	//	iteratorOfBentoToEdit = next(iteratorOfBentoToEdit); // Move to next line
	//}

	// for each       lineOfBentoInfo   in vector bentos
	for (BentoData& currentLineBentoInfo : bentos)
		// if no &, means I make a copy of currentLine and give the copy a name called currentLineBentoInfo

	// if got &, means I make a ref of currentLine and give the reference a name called currentLineBentoInfo so I can edit
	{
		if (currentLineBentoInfo.bentoName == bNameToEdit)
		{
			currentLineBentoInfo.bentoDestination = newBdest;
			return;
		}
	}

}

void Bento::editBento(string bNameToEdit, int newBdeadline)
{
	vector<BentoData>::iterator iteratorOfBentoToEdit = bentos.begin();
	// Go thru each bento's name in bentos(bentos is a vector in my class Bento)
	//while (iteratorOfBentoToEdit != bentos.end())
	//{
	//	// If there is a bento's name matching bNameToEdit 
	//	if (bNameToEdit == iteratorOfBentoToEdit->bentoName)
	//	{
	//		// (true), get the iterator then UPDATE by iteratorOfBentoToEdit->deadline = newBdeadline. After that, return from the function
	//		iteratorOfBentoToEdit->bentoDeadline = newBdeadline;
	//		return;
	//	}
	//	// 
	//	iteratorOfBentoToEdit = std::next(iteratorOfBentoToEdit); // Move to next line
	//}
	
	// for each       lineOfBentoInfo   in vector bentos
	for (BentoData& currentLineBentoInfo : bentos)
		// if no &, means I make a copy of currentLine and give the copy a name called currentLineBentoInfo

	// if got &, means I make a ref of currentLine and give the reference a name called currentLineBentoInfo so I can edit
	{
		if (currentLineBentoInfo.bentoName == bNameToEdit)
		{
			currentLineBentoInfo.bentoDeadline = newBdeadline;
			return;
		}
	}
	
}
//MAIN PROGRAM TEST
#include "Bento.h"
int main()
{
	Bento bentoManager("D:/School work/Y1T2/Object Oriented Programming/VS tutorial files/Projectcoding/bentos.txt"); //need to format bentos.txt with comma after each variable 
	bentoManager.addBento("BentoXX", "stop CASS", 1000);
	bentoManager.showBento();
	bentoManager.editBento("BentoXX", "Stop CAS");
	bentoManager.editBento("BentoXX", 2359);
	bentoManager.showBento();
	bentoManager.removeBento("BentoXX");
	bentoManager.showBento();
	return 0;
}
#endif
