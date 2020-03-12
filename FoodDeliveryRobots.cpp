#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream fdrfile;
    ifstream bentofile;
    string folderpath_fdr;
    string folderpath_bento;
    string fdrline;
    string bentoline;

    //INTRO PAGE
    /*
    cout << "Welcome to TLM1008 Food Delivery Robot System (FDRS)!\n" << endl;

    cout << "Please enter the input folder path name for the available food delivery robots (FDRs):\n> ";
    cin >> folderpath_fdr;

    fdrfile.open(folderpath_fdr);

    if (fdrfile.is_open())
    {
        cout << "File has successfully opened." << endl;

        while (!fdrfile.eof())
        {
            getline(fdrfile, fdrline);
        }

        fdrfile.close();
    }

    else
    {
        cout << "Failed to locate FDR file." << endl;
    }

    cout << "Please enter the input folder pathname for the available bentos:\n> ";
    cin >> folderpath_bento;

    bentofile.open(folderpath_bento);

    if (bentofile.is_open())
    {
        cout << "File has successfully opened." << endl;

        while (!bentofile.eof())
        {
            getline(bentofile, bentoline);
        }

        bentofile.close();
    }

    else
    {
        cout << "Failed to locate Bento file." << endl;
    }
    */

    //MAIN MENU
    int UserOption = 0;
    while (UserOption != 11) //do while loop
    {
        system("cls");
        cout << "MAIN MENU:\n";
        cout << "1. Display all FDR information\n";
        cout << "2. Display all Bentos information\n";
        cout << "3. Schedule all Bentos (by deadline)\n";
        cout << "4. Schedule all Bentos (minimum # of FDRs)\n";
        cout << "5. Display FDRs that are not full\n";
        cout << "6. Display final scheduling plan sorted by FDRs\n";
        cout << "7. Display final scheduling plan sorted by Bentos\n";
        cout << "8. Save scheduling plan\n";
        cout << "9. Add/Delete/Edit FDR\n";
        cout << "10. Add/Delete/Edit Bento\n";
        cout << "11. Exit application\n\n";
        cout << "Please enter your option:\n> ";
        cin >> UserOption;

        //still having some errors when input characters instead.
        switch (UserOption) //switch case between options
        {
        case 1:
            system("cls");
            cout << "Option 1 - Display all FDR information\n";
            cout << "---------------------------------------\n";

            //function

            system("pause");
            break;

        case 2:
            system("cls");
            cout << "Option 2 - Display all Bentos information\n";
            cout << "------------------------------------------\n";

            //function

            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Option 3 - Scheduling all Bentos by deadline\n";
            cout << "---------------------------------------------\n";

            //function

            system("pause");
            break;

        case 4:
            system("cls");
            cout << "Option 4 - Scheduling all Bentos by minimum # of FDRs\n";
            cout << "------------------------------------------------------\n";

            //function

            system("pause");
            break;

        case 5:
            system("cls");
            cout << "Option 5 - FDRs that are not full\n";
            cout << "----------------------------------\n";

            //function

            system("pause");
            break;

        case 6:
            system("cls");
            cout << "Option 6 - Final scheduling plan sorted by FDRs\n";
            cout << "------------------------------------------------\n";

            //function

            system("pause");
            break;

        case 7:
            system("cls");
            cout << "Option 7 - Final scheduling plan sorted by Bentos\n";
            cout << "--------------------------------------------------\n";

            //function

            system("pause");
            break;

        case 8:
            system("cls");
            cout << "Option 8 - Save scheduling plan\n";
            cout << "--------------------------------\n";

            //function

            system("pause");
            break;

        case 9:
            system("cls");
            cout << "Option 9 - Add/Delete/Edit FDR\n";
            cout << "-------------------------------\n";

            //create sub-menu

            //function

            system("pause");
            break;

        case 10:
            system("cls");
            cout << "Option 10 - Add/Delete/Edit Bento\n";
            cout << "----------------------------------\n";

            //create sub-menu

            //function

            system("pause");
            break;

        case 11:
            system("cls");
            cout << "Thank you for using Group 10's FoodDeliveryRobot!\n";
            break;

        default:
            cout << "Please enter correct option!\n";
            system("pause");
            break;
        }
    }

    return 0;
}