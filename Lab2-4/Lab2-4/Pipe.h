#pragma once
#include <iostream>
#include <fstream>

class Pipe
{
    int id;
    int length;
    double width;
    bool under_repair;
    int MaxId;
public:
    Pipe();
    int GetId();
    int GetMaxId();
    int GetLength();
    double GetWidth();
    bool GetUnder_repair();

    friend std::ostream& operator << (std::ostream& out, const Pipe& My_Pipe);
    friend std::istream& operator >> (std::istream& in, Pipe& My_Pipe);

};

