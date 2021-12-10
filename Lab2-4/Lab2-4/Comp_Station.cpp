#include "Comp_Station.h"
#include "Dops.h"
#include <string>
using namespace std;

unsigned int Comp_Station::MaxId = 0;

Comp_Station::Comp_Station() 
{
	id = ++MaxId;
}

unsigned int Comp_Station::GetMaxId() 
{
	return MaxId;
}

int Comp_Station::GetId() 
{
	return id;
}

std::string Comp_Station::GetName() 
{
	return name;
}

int Comp_Station::GetNumber_of_workshops() 
{
	return number_of_workshops;
}

int Comp_Station::GetWorking_workshops() 
{
	return working_workshops;
}

int Comp_Station::GetPerformance() 
{
	return performance;
}

void Comp_Station::EditingStation()
{
	cout << "Print new number of stations ";
	working_workshops = Proverochka(0, number_of_workshops);
}

ostream& operator << (std::ostream& out, const Comp_Station& Station)
{
	out << "station's id: " << Station.id << "\n" << "station's name: " << Station.name << "\n" << "station's number of workshops: " << Station.number_of_workshops << "\n" << "station's performance: " << Station.performance << "\n" << "station's working workshops: " << Station.working_workshops << "\n" << "station's stopped workshops: " << (Station.number_of_workshops - Station.working_workshops) << "\n";

	return out;
}

istream& operator >> (istream& in, Comp_Station& Station)
{
	cout << "Print name:" << "\n";
	cin.ignore(1, '\n');
	getline(cin, Station.name);
	cout << "Print number of workshops:" << "\n";
	Station.number_of_workshops = Proverochka(0, 1000);
	cout << "Print working workshops:" << "\n";
	Station.working_workshops = Proverochka(0, Station.number_of_workshops);
	cout << "Print performance:" << "\n";
	Station.performance = Proverochka(0, 1000);

	return in;
}

ofstream& operator << (ofstream& fout, const Comp_Station& Station)
{
	fout << "station's id: " << Station.id << "\n" << "station's name: " << Station.name << "\n" << "station's number of workshops: " << Station.number_of_workshops << "\n" << "station's performance: " << Station.performance << "\n" << "station's working workshops: " << Station.working_workshops << "\n" << "station's stopped workshops: " << (Station.number_of_workshops - Station.working_workshops) << "\n";
	
	return fout;
}

ifstream& operator >> (ifstream& fin, Comp_Station& Station)
{
	fin >> Station.id;
	fin.ignore(1, '\n');
	getline(fin, Station.name);
	fin >> Station.number_of_workshops >> Station.working_workshops >> Station.performance;
	return fin;
}