#pragma once
#include <iostream>
#include <fstream>

class Pipe
{
    int id;
    int length;
    double width;
    bool under_repair;
    static unsigned int MaxId;
public:
    Pipe();
    static unsigned int GetMaxId();
    int GetLength();
    double GetWidth();
    bool GetUnder_repair();
    void EditingPipe();
    int GetId();

    friend std::ostream& operator << (std::ostream& out, const Pipe& My_Pipe);
    friend std::istream& operator >> (std::istream& in, Pipe& My_Pipe);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipe& pipe);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipe& pipe);
};

