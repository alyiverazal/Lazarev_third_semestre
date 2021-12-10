#include "Pipe.h"
#include "Dops.h"
using namespace std;

unsigned int Pipe::MaxId = 0;

Pipe::Pipe() 
{
    id = ++MaxId;
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

void Pipe::EditingPipe()
{
    under_repair = !under_repair;
    cout << "Successful editing to " << under_repair << endl;
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