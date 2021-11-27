// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"
#include "Pipe.h"
#include "Pipe.cpp"
#include "Comp_Station.h"
#include "Comp_Station.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "unordered_map"
#include <algorithm>
using namespace std;

//std::cout << "" << "\n";
//std::cin >> ;






void menu()
{
    cout << "Pirnt '1' to add pipe" << "\n";
    cout << "Print '2' to add compression station" << "\n";
    cout << "Print '3' to see all pipes" << "\n";
    cout << "Print '4' to change pipe condition" << "\n";
    cout << "Print '5' to start some workshops" << "\n";
    cout << "Print '6' to stop some workshops" << "\n";
    cout << "Print '7' to save" << "\n";
    cout << "Print '8' to upload" << "\n";
    cout << "Print '9' to exit" << "\n";
    cout << "Print '10' to search by filter 'repair'" << endl;
    cout << "Print '11' to search by unworking workshops" << endl;
    cout << "Print '12' to search by name" << endl;
    cout << "Print '13' to delete pipe" << endl;
    cout << "Print '14' to delete workshop" << endl;
    cout << "Print '15' to use package batch editing" << endl;

    cout << "Print '0' to exit" << "\n";
}


/*
void Save(Comp_Station& Station, Pipe& My_Pipe)
{
    ofstream out;          // поток дл€ записи
    out.open("C:\\Users\\ILazarev\\Documents\\GitHub\\Lazarev_third_semestre\\Gas_Pipes.txt");
    if (out.is_open())
    {

        out << "Pipe: " << "\n" << My_Pipe.id << "\n" << My_Pipe.length << "\n" << My_Pipe.width << "\n" << My_Pipe.under_repair << "\n";

        out << "Station: " << "\n" << (Station.number_of_workshops - Station.working_workshops) << "\n" << Station.id << "\n" << Station.name << "\n" << Station.number_of_workshops << "\n" << Station.performance << "\n" << Station.working_workshops << "\n";
    }
    else {
        cout << "Appier some problems" << "\n";
    }
    cout << "Saved" << "\n";
}

void Upload(Comp_Station& Station, Pipe& My_Pipe)
{
    ifstream in("C:\\Users\\ILazarev\\Documents\\GitHub\\Lazarev_third_semestre\\Gas_Pipes.txt"); // поток дл€ чтени€
    string line;
    string m = "Pipe: ";
    string k = "Station: ";

    if (in.is_open())
    {
        while (getline(in, line)) {
            in >> line;
            bool PIn = (line == m);
            bool SIn = (line == k);
            if (PIn) {
                in >> My_Pipe.GetId;
                in >> My_Pipe.GetLength;
                in >> My_Pipe.GetWidth;
                in >> My_Pipe.GetUnder_repair;
            }
            if (SIn) {
                in >> Station.id;
                in >> Station.name;
                in >> Station.number_of_workshops;
                in >> Station.working_workshops;
                in >> Station.performance;
            }
        }
    }
    in.close();
    cout << "Uploaded" << "\n";

}
*/





int main()
{


    int InputW = 0;     //команда меню

    int StartW = 0;     //запуск доп воркшопс
    int StopW = 0;      //остановка части воркшопс

    unordered_map<int, Pipe> pipe_map;
    unordered_map<int, Comp_Station> cs_map;

    while (1) {
        menu();
        InputW = Proverochka(0, 15);
        if (InputW == 1) {
            Pipe My_Pipe;
            cin >> My_Pipe;
            pipe_map.insert(pair<int, Pipe>(My_Pipe.GetId(), My_Pipe));
        }
        if (InputW == 2) {
            Comp_Station Station;
            cin >> Station;
            cs_map.insert(pair<int, Comp_Station>(Station.GetId(), Station));
        }
        if (InputW == 3) {
            if (pipe_map.size() > 0)
                for (auto iter = pipe_map.begin(); iter != pipe_map.end(); ++iter)
                {
                    cout << endl;
                    cout << iter->second << endl;
                }

            if (cs_map.size() > 0)
                for (auto iter = cs_map.begin(); iter != cs_map.end(); ++iter)
                {
                    cout << endl;
                    cout << iter->second << endl;
                }
        }
        if (InputW == 4) {
            //unordered_map <int, Pipe>::iterator number;
            //cout << "¬ведите ID трубы: ";
            //if (pipe_map.size() > 0)
            {
               // unsigned index = Proverochka(1u, Pipe::MaxID, "¬ведите ID трубы: ");
               // number = pipe_map.find(index);
               // number->second.editing_pipe();
            }

           // ChangePipeCond(My_Pipe);
        }
        if (InputW == 5) {
           // StartWorkstation(Station, StartW);
        }
        if (InputW == 6) {
           // StopWorkstation(Station, StopW);
        }
        if (InputW == 7) {
           // Save(Station, My_Pipe);
        }
        if (InputW == 8) {
           // Upload(Station, My_Pipe);
        }
        if (InputW == 9) {

        }
        if (InputW == 10) {

        }
        if (InputW == 11) {

        }
        if (InputW == 12) {

        }
        if (InputW == 13) {

        }
        if (InputW == 14) {

        }
        if (InputW == 15) {

        }
        if (InputW == 0) {
            return 0;
        }
    }
    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
