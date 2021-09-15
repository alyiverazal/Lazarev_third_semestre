// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"
#include <fstream>
#include <string>

//std::cout << "" << "\n";
//std::cin >> ;



void InputPipe(Pipe& My_Pipe)
{
    std::cout << "Enter what length of pipe do you want:" << "\n";
    std::cin >> My_Pipe.length;
    std::cout << "Enter what width of pipe do you want:" << "\n";
    std::cin >> My_Pipe.width;
}

void OutputPipe(Pipe& My_Pipe)
{
    std::cout << "pipe's id " << My_Pipe.id << "\n";
    std::cout << "pipe's length " << My_Pipe.length << "\n";
    std::cout << "pipe's width " << My_Pipe.width << "\n";
    std::cout << "Pipes under repair: " << My_Pipe.under_repair << "\n";
}

void InputStation(Comp_Station& Station)
{
    std::cout << "Enter what name of Station do you want:" << "\n";
    std::cin >> Station.name;
    std::cout << "Enter how much workshops do you want for compression station:" << "\n";
    std::cin >> Station.number_of_workshops;
    std::cout << "Enter how much workshops are working:" << "\n";
    std::cin >> Station.working_workshops;
    std::cout << "Enter what performance of Station do you want:" << "\n";
    std::cin >> Station.performance;
}

void OutputStation(Comp_Station& Station)
{
    std::cout << "station's id: " << Station.id << "\n";
    std::cout << "station's name: " << Station.name << "\n";
    std::cout << "station's number of workshops: " << Station.number_of_workshops << "\n";
    std::cout << "station's performance: " << Station.performance << "\n";
    std::cout << "station's working workshops: " << Station.working_workshops << "\n";
    Station.stopped_workshops = Station.number_of_workshops - Station.working_workshops;
    std::cout << "station's stopped workshops: " << Station.stopped_workshops << "\n";
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

    int StartW;     //запуск доп воркшопс
    int StopW;      //остановка части воркшопс

    InputPipe(My_Pipe);
    OutputPipe(My_Pipe);
    InputStation(Station);
    OutputStation(Station);
    
    while (1) {
        std::cout << "Pirnt '1' if you want to add pipe" << "\n";
        std::cout << "Print '2' if you want to add compression station" << "\n";
        std::cout << "Print '3' if you want to see all objects" << "\n";
        std::cout << "Print '4' if you want to change pipe" << "\n";
        std::cout << "Print '5' if you want to start some workshops" << "\n";
        std::cout << "Print '6' if you want to stop some workshops" << "\n";
        std::cout << "Print '7' if you want to save" << "\n";
        std::cout << "Print '8' if you want to upload" << "\n";
        std::cout << "Print '9' if you want to exit" << "\n";
        std::cin >> InputW;
        if (InputW == "1") {
            
        }
        if (InputW == "2") {

        }
        if (InputW == "3") {

        }
        if (InputW == "4") {
            if (My_Pipe.under_repair == false) {
                My_Pipe.under_repair = true;
                s = "under_repair";
            }
            else {
                My_Pipe.under_repair = false;
                s = "is_working";
            }
            std::cout << "Condition of pipe was change" << s << "\n";
        }
        if (InputW == "5") {
            std::cout << Station.working_workshops << " workshop(s) is(are) working now, so you can start " << Station.stopped_workshops << "\n" << "How much workshops do you want to start?" << "\n";
            std::cin >> StartW;
            while (StartW > (Station.number_of_workshops - Station.working_workshops) || StartW < 0) {
                std::cout << "Plz write a right number" << "\n";
                std::cin >> StartW;
            }
            Station.working_workshops = Station.working_workshops + StartW;
            Station.stopped_workshops = Station.stopped_workshops - StartW;
            std::cout << Station.working_workshops << " workshop(s) is(are) working now and " << Station.stopped_workshops << " workshop(s) was(were) stopped" << "\n";
        }
        if (InputW == "6") {
            std::cout << Station.stopped_workshops << " workshop(s) was(were) stopped, so you can stop " << Station.working_workshops << "\n" << "How much workshops do you want to stop?" << "\n";
            std::cin >> StopW;
            while (StopW > (Station.number_of_workshops - Station.stopped_workshops) || StopW < 0) {
                std::cout << "Plz write a right number" << "\n";
                std::cin >> StopW;
            }
            Station.stopped_workshops = Station.stopped_workshops + StopW;
            Station.working_workshops = Station.working_workshops - StopW;
            std::cout << Station.stopped_workshops << " workshop(s) was(were) stopped and " << Station.working_workshops << " workshop(s) is(are) working now" << "\n";
            
        }
        if (InputW == "7") {
            std::ofstream out;          // поток для записи
            out.open("C:\\Users\\ilya-\\Documents\\GitHub\\Pipes\\Gas_Pipes.txt");
            if (out.is_open())
            {

                out << "station's id: " << Station.id << "\n";
                out << "station's name: " << Station.name << "\n";
                out << "station's number of workshops: " << Station.number_of_workshops << "\n";
                out << "station's performance: " << Station.performance << "\n";
                out << "station's working workshops: " << Station.working_workshops << "\n";
                Station.stopped_workshops = Station.number_of_workshops - Station.working_workshops;
                out << "station's stopped workshops: " << Station.stopped_workshops << "\n";
                out << "pipe's id " << My_Pipe.id << "\n";
                out << "pipe's length " << My_Pipe.length << "\n";
                out << "pipe's width " << My_Pipe.width << "\n";
                out << "pipes under repair: " << My_Pipe.under_repair << "\n";
            }
            std::cout << "Pipes and Comp_Stations were save" << "\n";
        }
        if (InputW == "8") {
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
