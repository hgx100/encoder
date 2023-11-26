#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include "Functions.hpp"
using namespace std;


int main()
{
    
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string str, fileOutput, logAll;
    int mode, algReps;
    cout << "Enter string: ";
    std::getline(std::cin, str);
    cout << "Enter mode (1-encode, 2-decode): ";
    cin >> mode;
    cout << "Enter the number of algorithm repetitions: ";
    cin >> algReps;
    cout << "Output to file? y/n: ";
    cin >> fileOutput;
    cout << "Log all? y/n: ";
    cin >> logAll;
    if (logAll[0] == 'y')
    {
        if (fileOutput[0] == 'y')
        {
            ofstream output;
            output.open("output.txt");
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    output << i + 1 << ". " << alg(str) << endl;
                }
                else if (mode == 2) {
                    output << i + 1 << ". " << algReverse(str) << endl;
                }
            }
            cout << "Done!" << endl;
            output.close();
        }
        else if (fileOutput[0] == 'n')
        {
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    cout << i + 1 << ". " << alg(str) << endl;
                }
                else if (mode == 2) {
                    cout << i + 1 << ". " << algReverse(str) << endl;
                }
            };
        };
    }
    else if (logAll[0] == 'n')
    {
        if (fileOutput[0] == 'y')
        {
            ofstream output;
            output.open("output.txt");
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    alg(str);
                }
                else if (mode == 2) {
                    algReverse(str);
                }
            }
            output << str << endl << algReps << " repetitions";
            cout << "Done!" << endl;
            output.close();
        }
        else if (fileOutput[0] == 'n')
        {
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    alg(str);
                }
                else if (mode == 2) {
                    algReverse(str);
                }
            };
            cout << str << endl << algReps << " repetitions\n";

        };
    };
    system("pause");
    return 0;
}
