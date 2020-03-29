#ifndef fdr_cpp
#define fdr_cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "FDR.h"

using namespace std;


FDR::FDR(string filePath)
{
	int FDRDeadline;
	string line;
	string FDRName;
	string FDRCapacity;
	string FDRDest;

	ifstream fdrFile;
	fdrFile.open(filePath);

	if (fdrFile.is_open())
	{
		while (getline(fdrFile, line))
		{
			/*cout << FDRName << "," << FDRCapacity << "," << FDRDest << "," << bentoDeadline << endl;*/
			stringstream check1(line); // convert string into a in stream which will use for getline 

			// Tokenizing check1 w.r.t. comma 
			getline(check1, FDRName, ','); //using getline to extract FDRName from in stream (instream = check1)
			getline(check1, FDRCapacity, ','); //using getline to extract FDRCapacity from in stream (instream = check1)
			getline(check1, FDRDest, ','); //using getline to extract FDRDest from in stream (instream = check1)
			/*getline(check1, FDRdeadline);*/
			(check1) >> FDRDeadline; //using getline to extract FDRDeadline from in stream (instream = check1) 
			// There is no ',' left in the stream therefore can use the output operator to initialise FDRDeadline 
			FDRData currentLineFDRInfo(FDRName, FDRCapacity, FDRDest, FDRDeadline);
			FDRs.push_back(currentLineFDRInfo);
		}
		fdrFile.close();
	}
	else
	{
		cout << "Unable to open file!";
	}
}
void FDR::showFDR()
{
	/*vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);

	for (int i : vec)
	{
		cout << i;
	}*/

	for (FDRData& currentLineBentoInfo : FDRs)
	{
		cout << currentLineBentoInfo.FDRName << ",";
		cout << currentLineBentoInfo.FDRCapacity << ",";
		cout << currentLineBentoInfo.FDRDestination << ",";
		cout << currentLineBentoInfo.FDRDeadline << endl;
	}
}


FDR::FDRData::FDRData(string FName, string FCap, string FDRDest, int FDeadline)
	: FDRName(FName), FDRCapacity(FCap),FDRDestination(FDRDest), FDRDeadline(FDeadline),
	FDRAvailability(false) //this boolean used to keep track whether there is available FDR
{}

FDR::FDRData::FDRData(FDRData const& fData)
	: FDRName(fData.FDRName), FDRCapacity(fData.FDRCapacity), FDRDestination(fData.FDRDestination), FDRDeadline(fData.FDRDeadline), FDRAvailability(false)
{
}

void FDR::addFDR(string FName, string FCap, string FDRDest, int FDeadline)
{
	FDRData currentLineFDRInfo(FName, FCap, FDRDest, FDeadline);
	FDRs.push_back(currentLineFDRInfo);
}

void FDR::removeFDR(string fNameToRemove)
{
	// (false), do nothing. Actually dont even need to have the false statement AKA dont need to handle false cases

	// cout << "Eh u trying to be funny, removing something that dont exist";
	vector<FDRData>::iterator iteratorOfFDRToRemove = FDRs.begin();
	// Go thru each FDR's name in FDRs(FDRs is a vector in my class FDR)
	while (iteratorOfFDRToRemove != FDRs.end())
	{
		// If there is a FDR's name matching fNameToRemove
		if (fNameToRemove == iteratorOfFDRToRemove->FDRName)
		{
			// (true), get the iterator then call FDRs.erase(iteratorOfFDRToRemove). After that, return from the function
			// YES I FOUND IT
			FDRs.erase(iteratorOfFDRToRemove); // erase horizontal line
			return; // Since this is a void function, I just type "return;" can liao. Don't need to type anything after return, if return
			// anything means its not void anymore. Even return void is not void;
		}

		iteratorOfFDRToRemove = next(iteratorOfFDRToRemove);
	}
	// By the time it looks thru each of the FDR in FDRs, still cannot find any FDR's name matching fNameToRemove. 
	// Meaning it never existed in ur FDRs before

	cout << "Eh u trying to be funny, removing something that dont exist";
}

void FDR::editFDRCap(string fNameToEdit, string newFCap)
{
	vector <FDRData>::iterator iteratorOfFDRToEdit = FDRs.begin();
	// Go thru each FDR's name in FDRs(FDRs is a vector in my class FDR)
	//while (iteratorOfFDRToEdit != FDRs.end())
	//{
	//	// If there is a FDR's name matching fNameToEdit 
	//	if (fNameToEdit == iteratorOfFDRToEdit->FDRName)
	//	{
	//		// (true), get the iterator then UPDATE by iteratorOfFDRToEdit->capacity = newFCap. After that, return from the function
	//		iteratorOfFDRToEdit->FDRCapacity = newFCap;
	//		return;
	//	}
	//	// 
	//	iteratorOfBentoToEdit = next(iteratorOfFDRToEdit); // Move to next line
	//}

	// for each     lineOfFDRInfo   in vector FDRs
	for (FDRData& currentLineFDRInfo : FDRs)
		// if no &, means I make a copy of currentLine and give the copy a name called currentLineFDRInfo

	// if got &, means I make a ref of currentLine and give the reference a name called currentLineFDRInfo so I can edit
	{
		if (currentLineFDRInfo.FDRName == fNameToEdit)
		{
			currentLineFDRInfo.FDRCapacity = newFCap;
			return;
		}
	}
}

void FDR::editFDRDest(string fNameToEdit, string newFDest)
{
	vector <FDRData>::iterator iteratorOfFDRToEdit = FDRs.begin();
	// Go thru each FDR's name in FDRs(FDRs is a vector in my class FDR)
	//while (iteratorOfFDRToEdit != FDRs.end())
	//{
	//	// If there is a FDR's name matching fNameToEdit 
	//	if (fNameToEdit == iteratorOfFDRToEdit->FDRName)
	//	{
	//		// (true), get the iterator then UPDATE by iteratorOfFDRToEdit->capacity = newFCap. After that, return from the function
	//		iteratorOfFDRToEdit->FDRDestination = newFDest;
	//		return;
	//	}
	//	// 
	//	iteratorOfBentoToEdit = next(iteratorOfFDRToEdit); // Move to next line
	//}

	// for each      lineOfFDRInfo   in vector FDRs
	for (FDRData& currentLineFDRInfo : FDRs)
		// if no &, means I make a copy of currentLine and give the copy a name called currentLineFDRInfo

	// if got &, means I make a ref of currentLine and give the reference a name called currentLineFDRInfo so I can edit
	{
		if (currentLineFDRInfo.FDRName == fNameToEdit)
		{
			currentLineFDRInfo.FDRDestination = newFDest;
			return;
		}
	}
}
void FDR::editFDRDeadline(string fNameToEdit, int newFDeadline)
{
	vector<FDRData>::iterator iteratorOfFDRToEdit = FDRs.begin();
	// Go thru each FDR's name in FDRs(FDRs is a vector in my class FDR)
	//while (iteratorOfFDRToEdit != FDRs.end())
	//{
	//	// If there is a FDR's name matching fNameToEdit 
	//	if (fNameToEdit == iteratorOfBentoToEdit->FDRName)
	//	{
	//		// (true), get the iterator then UPDATE by iteratorOfFDRToEdit->deadline = newFdeadline. After that, return from the function
	//		iteratorOfFDRToEdit->FDRDeadline = newFdeadline;
	//		return;
	//	}
	//	// 
	//	iteratorOfBentoToEdit = std::next(iteratorOfBentoToEdit); // Move to next line
	//}

	// for each       lineOfFDRInfo   in vector FDRs
	for (FDRData& currentLineBentoInfo : FDRs)
		// if no &, means I make a copy of currentLine and give the copy a name called currentLineFDRInfo

	// if got &, means I make a ref of currentLine and give the reference a name called currentLineFDRInfo so I can edit
	{
		if (currentLineBentoInfo.FDRName == fNameToEdit)
		{
			currentLineBentoInfo.FDRDeadline = newFDeadline;
			return;
		}
	}
}
//MAIN PROGRAM
#include "FDR.h"
int main()
{
	FDR fdrManager("D:/School work/Y1T2/Object Oriented Programming/VS tutorial files/Projectcoding/FDR.txt"); //need to format FDR.txt with comma after each variable 
	fdrManager.addFDR("FDRXX", "12", "stop CASS", 1000);
	fdrManager.showFDR();
	fdrManager.editFDRCap("FDRXX", "10");
	fdrManager.editFDRDest("FDRXX", "stop CAS");
	fdrManager.editFDRDeadline("FDRXX", 2359);
	fdrManager.showFDR();
	fdrManager.removeFDR("FDRXX");
	fdrManager.showFDR();
	return 0;
}
#endif
