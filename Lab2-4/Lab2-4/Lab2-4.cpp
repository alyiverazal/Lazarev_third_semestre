// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"
#include <fstream>
#include <string>

//std::cout << "" << "\n";
//std::cin >> ;


int AddLength(Pipe& My_Pipe)
{
    while (true)
    {
        std::cout << "Print length:" << "\n";
        std::cin >> My_Pipe.length;

        if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
        {
            std::cin.clear(); // �� ������� cin
            std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // ������� ������ ��������

            return My_Pipe.length;
        }
    }
}

double AddWidth(Pipe& My_Pipe)
{
    while (true)
    {
        std::cout << "Print width" << "\n";
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



void NameStation(Comp_Station& Station)
{
    std::cin >> Station.name;
}

int AllWorkshops(Comp_Station& Station)
{
    while (true) 
    {
        std::cin >> Station.number_of_workshops;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n'); 
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return Station.number_of_workshops;
        }
    }
}

int WorkingWorkshops(Comp_Station& Station)
{
    while (true) 
    {
        std::cin >> Station.working_workshops;

        if (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return Station.working_workshops;
        }
    }
}

int Performance(Comp_Station& Station)
{
    while (true)
    {
        std::cin >> Station.performance;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return Station.performance;
        }
    }
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



int menu1(int& InputW)
{
    std::cout << "Pirnt '1' to add pipe" << "\n";
    std::cout << "Print '2' to add compression station" << "\n";
    std::cout << "Print '3' to see all objects" << "\n";
    std::cout << "Print '4' to change pipe" << "\n";
    std::cout << "Print '5' to start some workshops" << "\n";
    std::cout << "Print '6' to stop some workshops" << "\n";
    std::cout << "Print '7' to save" << "\n";
    std::cout << "Print '8' to upload" << "\n";
    std::cout << "Print '9' to exit" << "\n";
    while (true)
    {
        std::cin >> InputW;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return InputW;
        }
    }

}

int menu2(int& InputW)
{
    std::cout << "Print '1' to change length of pipe" << "\n";
    std::cout << "Print '2' to change width of pipe" << "\n";
    std::cout << "Print '3' to see all info about pipe" << "\n";

    std::cout << "Print '4' to add name of station" << "\n";
    std::cout << "Print '5' to add how much worshops exists" << "\n";
    std::cout << "Print '6' to add how much workshops are working" << "\n";
    std::cout << "Print '7' to add what performance of station is" << "\n";
    std::cout << "Print '8' to see all info about workshop" << "\n";
    std::cout << "Print '9' to exit" << "\n";
    while (true)
    {
        std::cin >> InputW;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return InputW;
        }
    }
 }


void ChangePipeCond(Pipe& My_Pipe)
{
    My_Pipe.under_repair = !My_Pipe.under_repair;
    std::cout << "Condition of pipe was change" << "\n";
}

int StartWorkstation(Comp_Station& Station, int& StartW)
{
    std::cout << Station.working_workshops << " workshop(s) is(are) working now, so you can start " << (Station.number_of_workshops - Station.working_workshops) << "\n" << "How much workshops do you want to start?" << "\n";
    while (true)
    {
        std::cin >> StartW;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return StartW;
        }
    }
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
    while (true)
    {
        std::cin >> StopW;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return StopW;
        }
    }
    while (StopW > (Station.number_of_workshops - (Station.number_of_workshops - Station.working_workshops)) || StopW < 0) {
        std::cout << "Plz write a right number" << "\n";
        std::cin >> StopW;
    }
    Station.working_workshops = Station.working_workshops - StopW;
    std::cout << (Station.number_of_workshops - Station.working_workshops) << " workshop(s) was(were) stopped and " << Station.working_workshops << " workshop(s) is(are) working now" << "\n";
}


void Save(Comp_Station& Station, Pipe& My_Pipe)
{
    std::ofstream out;          // ����� ��� ������
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

    std::ifstream in("C:\\Users\\ilya-\\Documents\\GitHub\\Pipes\\Gas_Pipes.txt"); // ����� ��� ������
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

    int InputW = 0; //������� ����

    int StartW = 0;     //������ ��� ��������
    int StopW = 0;      //��������� ����� ��������

    
    while (1) {
        menu1(InputW);
        if (InputW == 1) {
            while (1) {
                menu2(InputW);
                if (InputW == 1) {
                    AddLength(My_Pipe);
                }
                if (InputW == 2) {
                    AddWidth(My_Pipe);
                }
                if (InputW == 3) {
                    OutputPipe(My_Pipe);
                }
                if (InputW == 4) {
                    NameStation(Station);
                }
                if (InputW == 5) {
                    AllWorkshops(Station);
                }
                if (InputW == 6) {
                    WorkingWorkshops(Station);
                }
                if (InputW == 7) {
                    Performance(Station);
                }
                if (InputW == 8) {
                    OutputStation(Station);
                }
                if (InputW == 9) return 0;
            }
        }
        if (InputW == 2) {

        }
        if (InputW == 3) {

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
            Upload();
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
