// Lab2-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab2-4.h"
#include "Pipe.h"
#include "Dops.h"
#include "Comp_Station.h"
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "unordered_map"
#include <algorithm>
using namespace std;

//std::cout << "" << "\n";
//std::cin >> ;



string NameOfFile() 
{
    string name;
    cout << "Print name of file:";
    cin.ignore(1, '\n');
    getline(cin, name);
    return name;
}

void delete_pipe(unordered_map<int, Pipe>& pipe_group)
{
    unordered_map<int, Pipe>::iterator number;
    unsigned int index;
    cout << "Print id of pipe, that you want to delete: ";
    index = Proverochka(1u, Pipe::GetMaxId());
    number = pipe_group.find(index);
    pipe_group.erase(number);
}

void delete_cs(unordered_map<int, Comp_Station>& cs_map)
{
    unordered_map<int, Comp_Station>::iterator number;
    unsigned int index;
    cout << "Print id of station, that you want to delete: ";
    index = Proverochka(1u, Comp_Station::GetMaxId());
    number = cs_map.find(index);
    cs_map.erase(number);
}

void menu()
{
    cout << "Pirnt '1' to add pipe" << "\n";
    cout << "Print '2' to add compression station" << "\n";
    cout << "Print '3' to see all components" << "\n";
    cout << "Print '4' to edit pipe" << "\n";
    cout << "Print '5' to edit Compression Station" << "\n";
    cout << "Print '6' to save" << "\n";
    cout << "Print '7' to upload" << "\n";
    cout << "Print '8' to search by filter 'repair'" << endl;
    cout << "Print '9' to search by % of unworking workshops" << endl;
    cout << "Print '10' to search by name" << endl;
    cout << "Print '11' to delete pipe" << endl;
    cout << "Print '12' to delete workshop" << endl;
    cout << "Print '13' to use package batch editing" << endl;

    cout << "Print '0' to exit" << "\n";
}


template<typename P, typename T>
using Filter = bool(*)(P& p, T param);

bool CheckPipeByRepair(Pipe& My_Pipe, bool GetUnder_repair)
{
    return My_Pipe.GetUnder_repair() == GetUnder_repair;
}

bool CheckByNotworkingStation(Comp_Station& Station, float percent)
{
    return percent > ((Station.GetNumber_of_workshops() - Station.GetWorking_workshops()) / Station.GetNumber_of_workshops() * 100);
}

bool CheckByName(Comp_Station& station, string param)
{
    return station.GetName() == param;
}

template<typename P, typename T>
vector<int> FindByFilter(unordered_map<int, P>& p, Filter<P, T> f, T param)
{
    vector <int> res;
    res.reserve(p.size());
    for (auto& something : p)
    {
        if (f(something.second, param))
            res.push_back(something.first);
    }
    return res;
}


int main()
{
    int InputW = 0;

    unordered_map<int, Pipe> pipe_map;
    unordered_map<int, Comp_Station> cs_map;

    while (1) 
    {
        menu();
        InputW = Proverochka(0, 15);
        if (InputW == 1) 
        {
            Pipe My_Pipe;
            cin >> My_Pipe;
            pipe_map.insert(pair<int, Pipe>(My_Pipe.GetId(), My_Pipe));
        }
        if (InputW == 2) 
        {
            Comp_Station Station;
            cin >> Station;
            cs_map.insert(pair<int, Comp_Station>(Station.GetId(), Station));
        }
        if (InputW == 3) 
        {
            if (pipe_map.size() > 0)
                for (auto iter = pipe_map.begin(); iter != pipe_map.end(); ++iter)
                {
                    cout << endl;
                    cout << iter->second << endl;
                }
            else {
                cout << "Add pipe(s) plz" << "\n";
            }


            if (cs_map.size() > 0)
                for (auto iter = cs_map.begin(); iter != cs_map.end(); ++iter)
                {
                    cout << endl;
                    cout << iter->second << endl;
                }
            else {
                cout << "Add station(s) plz" << "\n";
            } 
        }
        if (InputW == 4) 
        {
            unordered_map <int, Pipe>::iterator number;
            cout << "Print id of pipe:\n";
            if (pipe_map.size() > 0)
            {
                 unsigned index = Proverochka(1u, Pipe::GetMaxId());
                 number = pipe_map.find(index);
                 number->second.EditingPipe();
            }
            else cout << "Add pipe(s) plz\n";

        }
        if (InputW == 5) 
        {
            unordered_map <int, Comp_Station>::iterator number;
            cout << "Print ID of CS: ";
            if (cs_map.size() > 0)
            {
                unsigned index = Proverochka(1u, Comp_Station::GetMaxId());
                number = cs_map.find(index);
                number->second.EditingStation();
            }
            else cout << "Add station(s) plz\n";
        }
        if (InputW == 6) 
        {
            ofstream fout;
            fout.open(NameOfFile(), ios::out);

            if (fout.is_open())
            {
                if (pipe_map.size() > 0)
                {
                    fout << pipe_map.size() << endl;
                    for (auto iter = pipe_map.begin(); iter != pipe_map.end(); ++iter)
                        fout << iter->second;
                }
                if (cs_map.size() > 0)
                {
                    fout << cs_map.size() << endl;
                    for (auto iter = cs_map.begin(); iter != cs_map.end(); ++iter)
                        fout << iter->second;
                }
                else cout << "Add pipe(s) and station(s)\n";
                fout.close();
            }
            else cout << "File is not open" << endl;
            
        }
        if (InputW == 7) 
        {
            ifstream fin;
            fin.open(NameOfFile(), ios::in);
            if (fin.is_open())
            {
                pipe_map.erase(pipe_map.begin(), pipe_map.end());
                int count1;
                fin >> count1;
                for (int i = 1; i <= count1; ++i)
                {
                    Pipe pipe;
                    fin >> pipe;
                    pipe_map.insert(pair<int, Pipe>(pipe.GetId(), pipe));
                }
                cs_map.erase(cs_map.begin(), cs_map.end());
                int count2;
                fin >> count2;
                for (int i = 1; i <= count2; ++i)
                {
                    Comp_Station Station;
                    fin >> Station;
                    cs_map.insert(pair<int, Comp_Station>(Station.GetId(), Station));
                }
                fin.close();
            }
            else cout << "File is not open" << endl;
        }
        if (InputW == 8) 
        {
            bool rep;
            cout << "Repair filter(1 or 0): ";
            rep = Proverochka(0, 1);
            if (pipe_map.size() != 0)
            {
                for (int i : FindByFilter(pipe_map, CheckPipeByRepair, rep))
                    cout << pipe_map[i];
            }
            else cout << "You forget to add pipes" << endl;
        }
        if (InputW == 9)
        {
            float CSpr;
            cout << "Print % of unworkink workshops: ";
            cin >> CSpr;
            if (cs_map.size() != 0)
            {
                for (int i : FindByFilter(cs_map, CheckByNotworkingStation, CSpr))
                    cout << cs_map[i];
            }
            else cout << "You forget to add stations" << endl;
        }
        if (InputW == 10) 
        {
            string name;
            cout << "Print name of station to search: ";
            cin.ignore(1, '\n');
            getline(cin, name);
            if (cs_map.size() != 0)
            {
                for (int i : FindByFilter(cs_map, CheckByName, name))
                    cout << cs_map[i];
            }
            else
                cout << "You forget to add stations" << endl;
        }
        if (InputW == 11) 
        {
            if (pipe_map.size() > 0)
                delete_pipe(pipe_map); else cout << "You forget to add pipes" << endl;
        }
        if (InputW == 12) 
        {
            if (cs_map.size() > 0)
                delete_cs(cs_map); else cout << "You forget to add stations" << endl;
        }
        if (InputW == 13) 
        {
            unsigned int k;
            k = 0;
            bool rep;
            cout << "Repair filter(1 or 0): ";
            rep = Proverochka(0, 1);
            if (pipe_map.size() != 0)
            {
                for (int& i : FindByFilter(pipe_map, CheckPipeByRepair, rep))
                {
                    k = k + 1;
                    cout << "Editing " << k << "-й найденной трубы" << endl;
                    pipe_map[i].EditingPipe();
                }
            }
            else
                cout << "Забыли добавить трубы" << endl;
        }
        if (InputW == 14) 
        {

        }
        if (InputW == 15) 
        {

        }
        if (InputW == 0) 
        {
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