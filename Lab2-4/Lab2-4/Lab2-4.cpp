// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"
#include <fstream>
#include <string>
#include <vector>
#include "unordered_map"

//std::cout << "" << "\n";
//std::cin >> ;


int Proverochka()
{
    while (true)
    {
        int a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return a;
        }
    }
}

int AddLength(Pipe& My_Pipe)
{
    std::cout << "Print length of pipe:" << "\n";
    std::cin >> My_Pipe.length;
    My_Pipe.length = Proverochka();
    return My_Pipe.length;
}

double AddWidth(Pipe& My_Pipe)
{
    std::cout << "Print width of pipe:" << "\n";
    while (true)
    {
        std::cin >> My_Pipe.width;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return My_Pipe.width;
        }
    }
}

void OutputPipe(const Pipe& My_Pipe)
{
    std::cout << "pipe's id " << My_Pipe.id << "\n";
    std::cout << "pipe's length " << My_Pipe.length << "\n";
    std::cout << "pipe's width " << My_Pipe.width << "\n";
    std::cout << "Pipes under repair: " << My_Pipe.under_repair << "\n";
}

void ChangePipeCond(Pipe& My_Pipe)
{
    My_Pipe.under_repair = !My_Pipe.under_repair;
    std::cout << "Condition of pipe was change" << "\n";
}

void AddPipe(Pipe& My_Pipe) {
    AddLength(My_Pipe);
    AddWidth(My_Pipe);
    OutputPipe(My_Pipe);
}


void NameStation(Comp_Station& Station)
{
    std::cout << "Print name:" << "\n";
    std::cin >> Station.name;
}

int AllWorkshops(Comp_Station& Station)
{
    std::cout << "Print number of workshops:" << "\n";
    std::cin >> Station.number_of_workshops;
    Station.number_of_workshops = Proverochka();
    return Station.number_of_workshops;
}

int WorkingWorkshops(Comp_Station& Station)
{
    std::cout << "Print working workshops:" << "\n";
    std::cin >> Station.working_workshops;
    Station.working_workshops = Proverochka();
    return Station.working_workshops;
}

int Performance(Comp_Station& Station)
{
    std::cout << "Print performance:" << "\n";
    std::cin >> Station.performance;
    Station.performance = Proverochka();
    return Station.performance;
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

int StartWorkstation(Comp_Station& Station, int& StartW)
{
    std::cout << Station.working_workshops << " workshop(s) is(are) working now, so you can start " << (Station.number_of_workshops - Station.working_workshops) << "\n" << "How much workshops do you want to start?" << "\n";
    StartW = Proverochka();
    return StartW;
    return 1;
    while (StartW > (Station.number_of_workshops - Station.working_workshops) || StartW < 0) {
        std::cout << "Plz write a right number" << "\n";
        std::cin >> StartW;
    }
    Station.working_workshops = Station.working_workshops + StartW;
    std::cout << Station.working_workshops << " workshop(s) is(are) working now and " << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped" << "\n";
}

int StopWorkstation(Comp_Station& Station, int& StopW)
{
    std::cout << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped, so you can stop " << Station.working_workshops << "\n" << "How much workshops do you want to stop?" << "\n";
    StopW = Proverochka();
    return StopW;
    return 1;
    while (StopW > (Station.number_of_workshops - (Station.number_of_workshops - Station.working_workshops)) || StopW < 0) {
        std::cout << "Plz write a right number" << "\n";
        std::cin >> StopW;
    }
    Station.working_workshops = Station.working_workshops - StopW;
    std::cout << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped and " << Station.working_workshops << " workshop(s) is(are) working now" << "\n";
}

void AddStation(Comp_Station& Station) {

    NameStation(Station);
    AllWorkshops(Station);
    WorkingWorkshops(Station);
    Performance(Station);
    OutputStation(Station);
}


int menu1(int& InputW)
{
    std::cout << "Pirnt '1' to add pipe" << "\n";
    std::cout << "Print '2' to add compression station" << "\n";
    std::cout << "Print '3' to see all objects" << "\n";
    std::cout << "Print '4' to change pipe condition" << "\n";
    std::cout << "Print '5' to start some workshops" << "\n";
    std::cout << "Print '6' to stop some workshops" << "\n";
    std::cout << "Print '7' to save" << "\n";
    std::cout << "Print '8' to upload" << "\n";
    std::cout << "Print '9' to exit" << "\n";
    //InputW = Proverochka();
    //return InputW;
    return 1;
}


void Save(Comp_Station& Station, Pipe& My_Pipe)
{
    std::ofstream out;          // поток для записи
    out.open("C:\\Users\\ILazarev\\Documents\\GitHub\\Lazarev_third_semestre\\Gas_Pipes.txt");
    if (out.is_open())
    {

        out << "Pipe: " << "\n" << My_Pipe.id << "\n" << My_Pipe.length << "\n" << My_Pipe.width << "\n" << My_Pipe.under_repair << "\n";

        out << "Station: " << "\n" << (Station.number_of_workshops - Station.working_workshops) << "\n" << Station.id << "\n" << Station.name << "\n" << Station.number_of_workshops << "\n" << Station.performance << "\n" << Station.working_workshops << "\n";
    }
    else {
        std::cout << "Appier some problems" << "\n";
    }
    std::cout << "Save" << "\n";
}

void Upload(Comp_Station& Station, Pipe& My_Pipe)
{
    std::ifstream in("C:\\Users\\ILazarev\\Documents\\GitHub\\Lazarev_third_semestre\\Gas_Pipes.txt"); // поток для чтения
    std::string line;
    std::string m = "Pipe: ";
    std::string k = "Station: ";

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
    std::cout << "Upload" << "\n";

}



int main()
{
    Pipe My_Pipe;
    My_Pipe.id = 0;
    My_Pipe.under_repair = false;
    My_Pipe.length = 0;
    My_Pipe.width = 0;

    Comp_Station Station;
    Station.id = 0;
    Station.name = "";
    Station.number_of_workshops = 0;
    Station.performance = 0;
    Station.working_workshops = 0;

    int InputW = 0; //команда меню

    int StartW = 0;     //запуск доп воркшопс
    int StopW = 0;      //остановка части воркшопс

    std::cout << "Enter any number";
    std::cin >> InputW;
    while (1) {
        menu1(InputW);
        std::cin >> InputW;
        if (InputW == 1) {
            AddPipe(My_Pipe);
        }
        if (InputW == 2) {
            AddStation(Station);
        }
        if (InputW == 3) {
            OutputPipe(My_Pipe);
            OutputStation(Station);
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
        if (InputW == 9) return 0;
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
