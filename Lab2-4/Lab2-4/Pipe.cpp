#include "Pipe.h"
#include "Dops.h"
using namespace std;

unsigned int Pipe::MaxId = 0;

Pipe::Pipe() 
{
    id = ++MaxId;
    id_cs_in = 0;
    id_cs_out = 0;
}

int Pipe::GetId() 
{
    return id;
}

unsigned int Pipe::GetMaxId() 
{
    return MaxId;
}

int Pipe::GetLength() 
{
    return length;
}
    
bool Pipe::GetUnder_repair() 
{
    return under_repair;
}

double Pipe::GetWidth()
{
    return width;
}

int Pipe::GetPerformance() const
{
    return (int)sqrt(pow(width, 5) / length);
}

void Pipe::EditingPipe()
{
    under_repair = !under_repair;
    cout << "Successful editing to " << under_repair << endl;
}

int Pipe::GetId_CS_In()
{
    return id_cs_in;
}

int Pipe::GetId_CS_Out()
{
    return id_cs_out;
}

void Pipe::SetId_CS_Out(int id_cs_out)
{
    this->id_cs_out = id_cs_out;
}

void Pipe::SetId_CS_In(int id_cs_in)
{
    this->id_cs_in = id_cs_in;
}

void Pipe::in_Pipe_out(int cs_out, int cs_in)
{
    id_cs_out = cs_out;
    id_cs_in = cs_in;
}

ostream& operator << (ostream& out, const Pipe& My_Pipe)
{
    out << "pipe's id " << My_Pipe.id << "\n" << "pipe's length " << My_Pipe.length << "\n" << "pipe's width " << My_Pipe.width << "\n" << "Pipes under repair: " << My_Pipe.under_repair << "\n";

    return out;
}

istream& operator >> (istream& in, Pipe& My_Pipe)
{
    cout << "Print length of pipe:" << "\n";
    My_Pipe.length = Proverochka(0, 1000);
    cout << "Print width of pipe:" << "\n";
    My_Pipe.width = Proverochka(0, 1000);
    cout << "Pipe under repair: " << "\n";
    My_Pipe.under_repair = Proverochka(0, 1);

    return in;
}

ofstream& operator << (ofstream& fout, const Pipe& My_Pipe)
{
    fout << "pipe's id " << My_Pipe.id << "\n" << "pipe's length " << My_Pipe.length << "\n" << "pipe's width " << My_Pipe.width << "\n" << "Pipes under repair: " << My_Pipe.under_repair << "\n";
    return fout;
}

ifstream& operator >> (ifstream& fin, Pipe& My_Pipe)
{
    fin >> My_Pipe.id >> My_Pipe.length >> My_Pipe.width >> My_Pipe.under_repair;
    return fin;
}