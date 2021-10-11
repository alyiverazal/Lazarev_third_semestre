// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"
#include <fstream>
#include <string>

//std::cout << "" << "\n";
//std::cin >> ;



void AddLength(Pipe& My_Pipe)
{
    std::cout << "Print length:" << "\n";
    std::cin >> My_Pipe.length;
}

void AddWidth(Pipe& My_Pipe)
{
    std::cout << "Print width" << "\n";
    std::cin >> My_Pipe.width;
}

void OutputPipe(const Pipe& My_Pipe)
{
    std::cout << "pipe's id " << My_Pipe.id << "\n";
    std::cout << "pipe's length " << My_Pipe.length << "\n";
    std::cout << "pipe's width " << My_Pipe.width << "\n";
    std::cout << "Pipes under repair: " << My_Pipe.under_repair << "\n";
}



void NameStation(Comp_Station& Station)
{
    std::cin >> Station.name;
}

void AllWorkshops(Comp_Station& Station)
{
    std::cin >> Station.number_of_workshops;
}

void WorkingWorkshops(Comp_Station& Station)
{
    std::cin >> Station.working_workshops;
}

void Performance(Comp_Station& Station)
{
    std::cin >> Station.performance;
}

void OutputStation(const Comp_Station& Station)
{
    std::cout << "station's id: " << Station.id << "\n";
    std::cout << "station's name: " << Station.name << "\n";
    std::cout << "station's number of workshops: " << Station.number_of_workshops << "\n";
    std::cout << "station's performance: " << Station.performance << "\n";
    std::cout << "station's working workshops: " << Station.working_workshops << "\n";
    std::cout << "station's stopped workshops: " << (Station.number_of_workshops - Station.working_workshops) << "\n";
}



void menu(std::string& InputW)
{
    std::cout << "Print 'lp' to change length of pipe: " << "\n";
    std::cout << "Print 'wp' to change width of pipe:" << "\n";
    std::cout << "Print 'allp' to see all info about pipe" << "\n";

    std::cout << "Print 'as' to add name of station:" << "\n";
    std::cout << "Print 'aw' to add how much worshops exists:" << "\n";
    std::cout << "Print 'ww' to add how much workshops are working:" << "\n";
    std::cout << "Print 'p' to add what performance of station is:" << "\n";
    std::cout << "Print 'allw' to see all info about workshop" << "\n";

    std::cout << "Pirnt '1' to add pipe" << "\n";
    std::cout << "Print '2' to add compression station" << "\n";
    std::cout << "Print '3' to see all objects" << "\n";
    std::cout << "Print '4' to change pipe" << "\n";
    std::cout << "Print '5' to start some workshops" << "\n";
    std::cout << "Print '6' to stop some workshops" << "\n";
    std::cout << "Print '7' to save" << "\n";
    std::cout << "Print '8' to upload" << "\n";
    std::cout << "Print '9' to exit" << "\n";
    std::cin >> InputW;
}


void ChangePipeCond(Pipe& My_Pipe)
{
    My_Pipe.under_repair = !My_Pipe.under_repair;
    std::cout << "Condition of pipe was change" << "\n";
}

void StartWorkstation(Comp_Station& Station, int& StartW)
{
    std::cout << Station.working_workshops << " workshop(s) is(are) working now, so you can start " << (Station.number_of_workshops - Station.working_workshops) << "\n" << "How much workshops do you want to start?" << "\n";
    std::cin >> StartW;
    while (StartW > (Station.number_of_workshops - Station.working_workshops) || StartW < 0) {
        std::cout << "Plz write a right number" << "\n";
        std::cin >> StartW;
    }
    Station.working_workshops = Station.working_workshops + StartW;
    std::cout << Station.working_workshops << " workshop(s) is(are) working now and " << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped" << "\n";
}

void StopWorkstation(Comp_Station& Station, int& StopW)
{
    std::cout << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped, so you can stop " << Station.working_workshops << "\n" << "How much workshops do you want to stop?" << "\n";
    std::cin >> StopW;
    while (StopW > (Station.number_of_workshops - (Station.number_of_workshops - Station.working_workshops)) || StopW < 0) {
        std::cout << "Plz write a right number" << "\n";
        std::cin >> StopW;
    }
    Station.working_workshops = Station.working_workshops - StopW;
    std::cout << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped and " << Station.working_workshops << " workshop(s) is(are) working now" << "\n";
}

void Save(Comp_Station& Station, Pipe& My_Pipe)
{
    std::ofstream out;          // поток для записи
    out.open("C:\\Users\\ilya-\\Documents\\GitHub\\Pipes\\Gas_Pipes.txt");
    if (out.is_open())
    {

        out << "station's id: " << Station.id << "\n";
        out << "station's name: " << Station.name << "\n";
        out << "station's number of workshops: " << Station.number_of_workshops << "\n";
        out << "station's performance: " << Station.performance << "\n";
        out << "station's working workshops: " << Station.working_workshops << "\n";

        out << "station's stopped workshops: " << (Station.number_of_workshops - Station.working_workshops) << "\n";
        out << "pipe's id " << My_Pipe.id << "\n";
        out << "pipe's length " << My_Pipe.length << "\n";
        out << "pipe's width " << My_Pipe.width << "\n";
        out << "pipes under repair: " << My_Pipe.under_repair << "\n";
    }
    std::cout << "Pipes and Comp_Stations were save" << "\n";
}

void Upload()
{
    std::string line;

    std::ifstream in("C:\\Users\\ilya-\\Documents\\GitHub\\Pipes\\Gas_Pipes.txt"); // поток для чтения
    if (in.is_open())
    {
        while (getline(in, line)) {
            std::cout << line << "\n";
        }
    }
    in.close();
}



int main()
{
    Pipe My_Pipe;
    My_Pipe.id = 0;
    My_Pipe.under_repair = false;

    Comp_Station Station;
    Station.id = 0;

    std::string InputW; //команда меню
    std::string s;

    int StartW = 0;     //запуск доп воркшопс
    int StopW = 0;      //остановка части воркшопс

    
    while (1) {
        menu(InputW);
        if (InputW == "lp") {
            AddLength(My_Pipe);
        }
        if (InputW == "wp") {
            AddWidth(My_Pipe);
        }
        if (InputW == "allp") {
            OutputPipe(My_Pipe);
        }
        if (InputW == "as") {
            NameStation(Station);
        }
        if (InputW == "aw") {
            AllWorkshops(Station);
        }
        if (InputW == "ww") {
            WorkingWorkshops(Station);
        }
        if (InputW == "p") {
            Performance(Station);
        }
        if (InputW == "allw") {
            OutputStation(Station);
        }
        if (InputW == "1") {
            
        }
        if (InputW == "2") {

        }
        if (InputW == "3") {

        }
        if (InputW == "4") {
            ChangePipeCond(My_Pipe);
        }
        if (InputW == "5") {
            StartWorkstation(Station, StartW);
        }
        if (InputW == "6") {
            StopWorkstation(Station, StopW);
        }
        if (InputW == "7") {
            Save(Station, My_Pipe);
        }
        if (InputW == "8") {
            Upload();
        }
        if (InputW == "9") return 0;
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
