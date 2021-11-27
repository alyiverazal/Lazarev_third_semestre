#pragma once
#include <ostream>
#include <fstream>

class Comp_Station
{
    int id;
    std::string name;
    int number_of_workshops;
    int working_workshops;
    int performance;
    int MaxId;
public:
    Comp_Station();
    int GetId();
    int GetMaxId();
    std::string GetName();
    int GetNumber_of_workshops();
    int GetWorking_workshops();
    int GetPerformance();

    friend std::ostream& operator << (std::ostream& out, const Comp_Station& Station);
    friend std::istream& operator >> (std::istream& in, Comp_Station& Station);
};

