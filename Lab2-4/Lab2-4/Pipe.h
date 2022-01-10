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
    int GetPerformance() const;
    int id_cs_in;
    int id_cs_out;
    int GetId_CS_In();
    int GetId_CS_Out();
    void SetId_CS_Out(int id_cs_out);
    void SetId_CS_In(int id_cs_in);
    void in_Pipe_out(int cs_out, int cs_in);

    friend std::ostream& operator << (std::ostream& out, const Pipe& My_Pipe);
    friend std::istream& operator >> (std::istream& in, Pipe& My_Pipe);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipe& pipe);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipe& pipe);
};

