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
#include "Graph.h"
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
    cout << "Print '14' to create/change graph" << endl;
    cout << "Print '15' to see graph" << endl;
    cout << "Print '16' to delete graph" << endl;
    cout << "Print '17' to use topological sort of graph" << endl;
    cout << "Print '18' to delete station from graph" << endl;
    cout << "Print '19' to calculate the shortest way between stations" << endl;
    cout << "Print '20' to calculate the maximum traffic in graph" << endl;

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
    unordered_map<int, vector<p_id_in>> graph;
    unordered_map<int, bool> used;

    while (1) 
    {
        menu();
        InputW = Proverochka(0, 20);
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

                fout << endl;
                for (auto& el : graph)
                {
                    fout << el.second.size() << " ";
                    fout << el.first << " ";
                    for (auto cs = el.second.begin(); cs != el.second.end(); ++cs)
                    {
                        fout << cs->cs_id_in << " " << cs->pipe_id << " ";
                    }
                    fout << endl;
                }

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

                int count;
                while (fin >> count)
                {
                    int cs_id_out;
                    fin >> cs_id_out;
                    for (int i = 0; i < count; i++)
                    {
                        int cs_id_in;
                        fin >> cs_id_in;
                        int pipe_id;
                        fin >> pipe_id;
                        p_id_in pair;
                        pair.cs_id_in = cs_id_in;
                        pair.pipe_id = pipe_id;
                        pipe_map[pipe_id].SetId_CS_In(cs_id_in);
                        pipe_map[pipe_id].SetId_CS_Out(cs_id_out);
                        graph[cs_id_out].push_back(AddConnection(pipe_id, cs_id_in));
                    }
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
                    cout << "Editing " << k << " of found pipe" << endl;
                    pipe_map[i].EditingPipe();
                }
            }
            else
                cout << "You forget to add pipes" << endl;
        }
        if (InputW == 14) 
        {
            bool next = 1;
            for (auto iter : pipe_map)
                used[iter.second.GetId()] = iter.second.GetId_CS_In() != 0;
            while (next && pipe_map.size() > 0 && cs_map.size() >= 2)
            {
                cout << "Print id of pipe, which will connect 2 pipes: ";
                int pipe_id = Proverochka(1u, Pipe::GetMaxId());
                while (pipe_map.find(pipe_id) == pipe_map.end() || pipe_map.find(pipe_id)->second.GetUnder_repair() || used[pipe_id])
                {
                    cout << "Try again" << endl;
                    cout << "Print id of pipe, which will connect 2 pipes: ";
                    pipe_id = Proverochka(1u, Pipe::GetMaxId());
                }
                used[pipe_id] = true;
                cout << "Print id of station, from which pipe is out: ";
                int cs_id_out = Proverochka(1u, Comp_Station::GetMaxId());
                while (cs_map.find(cs_id_out) == cs_map.end())
                {
                    cout << "Try again" << endl;
                    cout << "Print id of station, from which pipe is out: ";
                    cs_id_out = Proverochka(1u, Comp_Station::GetMaxId());
                }
                cout << "Print id of station, which pipe in: ";
                int cs_id_in = Proverochka(1u, Comp_Station::GetMaxId());
                while (cs_map.find(cs_id_in) == cs_map.end())
                {
                    cout << "Try again" << endl;
                    cout << "Print id of station, which pipe in: ";
                    cs_id_in = Proverochka(1u, Comp_Station::GetMaxId());
                }
                cout << endl;
                cout << "print 1 to continue; 0 to stop" << endl;
                next = Proverochka(0, 1);
                pipe_map.find(pipe_id)->second.in_Pipe_out(cs_id_out, cs_id_in);
                graph[cs_id_out].push_back(AddConnection(pipe_id, cs_id_in));
            }
        }
        if (InputW == 15) 
        {
            Print_Graph(graph);
        }
        if (InputW == 16)
        {
            graph.clear();
            cout << "Graph was deleted" << endl;
            for (auto& iter : pipe_map)
            {
                iter.second.SetId_CS_In(0);
                iter.second.SetId_CS_Out(0);
            }
        }
        if (InputW == 17)
        {
            vector<int> ans;
            topological_sort(graph, ans);
            for (auto index = ans.begin(); index != ans.end(); index++)
            {
                cout << *index;
                if (index + 1 != ans.end())
                    cout << " - ";
            }
        }
        if (InputW == 18)
        {
            cout << "Print id of pipe, which you want to delete from graph: ";
            int cs_id_delete = Proverochka(1u, Comp_Station::GetMaxId());
            cs_delete_fromGraph(graph, cs_map, cs_id_delete);
        }
        if (InputW == 19)
        {
            find_shortest_path(graph, pipe_map);
        }
        if (InputW == 20)
        {
            unordered_map<int, bool> count_cs = count_vertex(graph);
            get_maxflow(graph, cs_map, pipe_map, count_cs);
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