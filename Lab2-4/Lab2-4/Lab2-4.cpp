// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"

void OutputPipe(Pipe& My_Pipe)
{
    std::cout << "pipe's id" << My_Pipe.id;
    std::cout << "pipe's length " << My_Pipe.length << "\n";
    std::cout << "pipe's width " << My_Pipe.width << "\n";
    std::cout << "Pipes under repair: " << My_Pipe.under_repair;
}

void InputPipe(Pipe& My_Pipe)
{
    std::cout << "Enter what length of pipe do you want:";
    std::cin >> My_Pipe.length;
    std::cout << "Enter what width of pipe do you want:";
    std::cin >> My_Pipe.width;
}

void InputStation(Comp_Station& Station)
{
    std::cout << "Enter what name of Station do you want:";
    std::cin >> Station.name;
    std::cout << "Enter what number_of_workshops of Station do you want:";
    std::cin >> Station.number_of_workshops;
    std::cout << "Enter what working_workshops of Station do you want:";
    std::cin >> Station.working_workshops;
    std::cout << "Enter what performance of Station do you want:";
    std::cin >> Station.performance;
}

void OutputStation(Comp_Station& Station)
{
    std::cout << "station's id: " << Station.id << "\n";
    std::cout << "station's name: " << Station.name << "\n";
    std::cout << "station's number of workshops: " << Station.number_of_workshops << "\n";
    std::cout << "station's performance " << Station.performance << "\n";
    std::cout << "station's working workshops " << Station.working_workshops;
}

int main()
{
    Pipe My_Pipe;
    My_Pipe.id = 0;
    My_Pipe.under_repair = false;
    Comp_Station Station;
    Station.id = 0;
    InputPipe(My_Pipe);
    OutputPipe(My_Pipe);
    InputStation(Station);
    OutputStation(Station);


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
