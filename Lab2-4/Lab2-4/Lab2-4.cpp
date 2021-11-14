// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "unordered_map"
#include <algorithm>
using namespace std;

//std::cout << "" << "\n";
//std::cin >> ;


int Proverochka()
{
    while (true)
    {
        int a;
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n');

            return a;
        }
    }
}

int AddLength(Pipe& My_Pipe)
{
    cout << "Print length of pipe:" << "\n";
    My_Pipe.length = Proverochka();
    return My_Pipe.length;
}

double AddWidth(Pipe& My_Pipe)
{
    cout << "Print width of pipe:" << "\n";
    while (true)
    {
        cin >> My_Pipe.width;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n');

            return My_Pipe.width;
        }
    }
}

void OutputPipe(const Pipe& My_Pipe)
{
    cout << "pipe's id " << My_Pipe.id << "\n";
    cout << "pipe's length " << My_Pipe.length << "\n";
    cout << "pipe's width " << My_Pipe.width << "\n";
    cout << "Pipes under repair: " << My_Pipe.under_repair << "\n";
}

std::ostream& operator << (std::ostream& out, Pipe& My_Pipe)
{
    out << "pipe's id " << My_Pipe.id << "\n" << "pipe's length " << My_Pipe.length << "\n" << "pipe's width " << My_Pipe.width << "\n" << "Pipes under repair: " << My_Pipe.under_repair << "\n";

    return out;
}

void ChangePipeCond(Pipe& My_Pipe)
{
    My_Pipe.under_repair = !My_Pipe.under_repair;
    cout << "Condition of pipe was change" << "\n";
}


void AddPipe(Pipe& My_Pipe) {

    My_Pipe.id = ++My_Pipe.MaxID;

    AddLength(My_Pipe);
    AddWidth(My_Pipe);
    OutputPipe(My_Pipe);
}


void NameStation(Comp_Station& Station)
{
    cout << "Print name:" << "\n";
    cin >> Station.name;
}

int AllWorkshops(Comp_Station& Station)
{
    cout << "Print number of workshops:" << "\n";
    Station.number_of_workshops = Proverochka();
    return Station.number_of_workshops;
}

int WorkingWorkshops(Comp_Station& Station)
{
    cout << "Print working workshops:" << "\n";
    Station.working_workshops = Proverochka();
    return Station.working_workshops;
}

int Performance(Comp_Station& Station)
{
    cout << "Print performance:" << "\n";
    Station.performance = Proverochka();
    return Station.performance;
}

void OutputStation(const Comp_Station& Station)
{
    cout << "station's id: " << Station.id << "\n";
    cout << "station's name: " << Station.name << "\n";
    cout << "station's number of workshops: " << Station.number_of_workshops << "\n";
    cout << "station's performance: " << Station.performance << "\n";
    cout << "station's working workshops: " << Station.working_workshops << "\n";
    cout << "station's stopped workshops: " << (Station.number_of_workshops - Station.working_workshops) << "\n";
}

std::ostream& operator << (std::ostream& out, Comp_Station& Station)
{
    out << "station's id: " << Station.id << "\n" << "station's name: " << Station.name << "\n" << "station's number of workshops: " << Station.number_of_workshops << "\n" << "station's performance: " << Station.performance << "\n" << "station's working workshops: " << Station.working_workshops << "\n" << "station's stopped workshops: " << (Station.number_of_workshops - Station.working_workshops) << "\n";

    return out;
}

int StartWorkstation(Comp_Station& Station, int& StartW)
{
    cout << Station.working_workshops << " workshop(s) is(are) working now, so you can start " << (Station.number_of_workshops - Station.working_workshops) << "\n" << "How much workshops do you want to start?" << "\n";
    StartW = Proverochka();
    return StartW;
    return 1;
    while (StartW > (Station.number_of_workshops - Station.working_workshops) || StartW < 0) {
        cout << "Plz write a right number" << "\n";
        cin >> StartW;
    }
    Station.working_workshops = Station.working_workshops + StartW;
    cout << Station.working_workshops << " workshop(s) is(are) working now and " << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped" << "\n";
}

int StopWorkstation(Comp_Station& Station, int& StopW)
{
    cout << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped, so you can stop " << Station.working_workshops << "\n" << "How much workshops do you want to stop?" << "\n";
    StopW = Proverochka();
    return StopW;
    return 1;
    while (StopW > (Station.number_of_workshops - (Station.number_of_workshops - Station.working_workshops)) || StopW < 0) {
        cout << "Plz write a right number" << "\n";
        cin >> StopW;
    }
    Station.working_workshops = Station.working_workshops - StopW;
    cout << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped and " << Station.working_workshops << " workshop(s) is(are) working now" << "\n";
}

void AddStation(Comp_Station& Station) {

    Station.id = ++Station.MaxID;

    NameStation(Station);
    AllWorkshops(Station);
    WorkingWorkshops(Station);
    Performance(Station);
    OutputStation(Station);
}


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
    cout << "Print '12' to search by name of workshop" << endl;
    cout << "Print '13' to delete pipe" << endl;
    cout << "Print '14' to delete workshop" << endl;
    cout << "Print '15' to use package batch editing" << endl;

    cout << "Print '0' to exit" << "\n";
}


void Save(Comp_Station& Station, Pipe& My_Pipe)
{
    ofstream out;          // поток для записи
    out.open("C:\\Users\\ILazarev\\Documents\\GitHub\\Lazarev_third_semestre\\Gas_Pipes.txt");
    if (out.is_open())
    {

        out << "Pipe: " << "\n" << My_Pipe.id << "\n" << My_Pipe.length << "\n" << My_Pipe.width << "\n" << My_Pipe.under_repair << "\n";

        out << "Station: " << "\n" << (Station.number_of_workshops - Station.working_workshops) << "\n" << Station.id << "\n" << Station.name << "\n" << Station.number_of_workshops << "\n" << Station.performance << "\n" << Station.working_workshops << "\n";
    }
    else {
        cout << "Appier some problems" << "\n";
    }
    cout << "Save" << "\n";
}

void Upload(Comp_Station& Station, Pipe& My_Pipe)
{
    ifstream in("C:\\Users\\ILazarev\\Documents\\GitHub\\Lazarev_third_semestre\\Gas_Pipes.txt"); // поток для чтения
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
                in >> My_Pipe.id;
                in >> My_Pipe.length;
                in >> My_Pipe.width;
                in >> My_Pipe.under_repair;
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
    cout << "Upload" << "\n";

}





int main()
{
    Pipe My_Pipe;
    My_Pipe.id = 0;
    My_Pipe.under_repair = false;
    My_Pipe.length = 0;
    My_Pipe.width = 0;
    My_Pipe.MaxID = 0;

    Comp_Station Station;
    Station.id = 0;
    Station.name = "";
    Station.number_of_workshops = 0;
    Station.performance = 0;
    Station.working_workshops = 0;
    Station.MaxID = 0;

    int InputW = 0; //команда меню

    int StartW = 0;     //запуск доп воркшопс
    int StopW = 0;      //остановка части воркшопс

    unordered_map<int, Pipe> pipe_map;
    unordered_map<int, Comp_Station> cs_map;

    while (1) {
        menu();
        InputW = Proverochka();
        if (InputW == 1) {
            AddPipe(My_Pipe);
            pipe_map.insert(pair<int, Pipe>(My_Pipe.MaxID, My_Pipe));
        }
        if (InputW == 2) {
            AddStation(Station);
            cs_map.insert(pair<int, Comp_Station>(Station.MaxID, Station));
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
            ChangePipeCond(My_Pipe);
        }
        if (InputW == 5) {
            StartWorkstation(Station, StartW);
        }
        if (InputW == 6) {
            StopWorkstation(Station, StopW);
        }
        if (InputW == 7) {
            Save(Station, My_Pipe);
        }
        if (InputW == 8) {
            Upload(Station, My_Pipe);
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
        else {
            cout << "Invalid input, try again" << endl;
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
