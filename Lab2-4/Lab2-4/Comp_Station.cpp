#include "Comp_Station.h"
#include "Dops.h"
#include <string>
using namespace std;

Comp_Station::Comp_Station() {
	id = 0;
	name = "";
	number_of_workshops = 0;
	performance = 0;
	working_workshops = 0;
	MaxId = 0;
}

int Comp_Station::GetMaxId() {
	return MaxId;
}

int Comp_Station::GetId() {
	return id;
}

string Comp_Station::GetName() {
	return name;
}

int Comp_Station::GetNumber_of_workshops() {
	return number_of_workshops;
}

int Comp_Station::GetWorking_workshops() {
	return working_workshops;
}

int Comp_Station::GetPerformance() {
	return performance;
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