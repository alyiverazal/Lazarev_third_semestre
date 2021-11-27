#include "Pipe.h"
#include "Dops.h"
using namespace std;

Pipe::Pipe() {
    id = 0;
    under_repair = false;
    length = 0;
    width = 0;
    MaxId = 0;
}

int Pipe::GetId() {
    return id;
}

int Pipe::GetMaxId() {
    return MaxId;
}

int Pipe::GetLength() {
    return length;
}
    
bool Pipe::GetUnder_repair() {
    return under_repair;
}

double Pipe::GetWidth()
{
    return width;
}

ostream& operator << (ostream& out, const Pipe& My_Pipe)
{
    out << "pipe's id " << My_Pipe.id << "\n" << "pipe's length " << My_Pipe.length << "\n" << "pipe's width " << My_Pipe.width << "\n" << "Pipes under repair: " << My_Pipe.under_repair << "\n";

    return out;
}

istream& operator >> (istream& in, Pipe& My_Pipe)
{
    cout << "Print length of pipe:" << "\n";
    My_Pipe.length = Proverochka(0, 100);
    cout << "Print width of pipe:" << "\n";
    My_Pipe.width = Proverochka(0, 100);
    cout << "Pipes under repair: " << "\n";
    My_Pipe.under_repair = Proverochka(0, 1);

    return in;
}