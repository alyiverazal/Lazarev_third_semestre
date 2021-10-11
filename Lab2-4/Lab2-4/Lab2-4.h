#pragma once

struct Pipe {
    int id;
    int length;
    double width;
    bool under_repair;
};
struct Comp_Station {
    int id;
    std::string name;
    int number_of_workshops;
    int working_workshops;
    int performance;
};

int AddLength(Pipe& My_Pipe);

double AddWidth(Pipe& My_Pipe);

void OutputPipe(const Pipe& My_Pipe);

void NameStation(Comp_Station& Station);

int AllWorkshops(Comp_Station& Station);

int WorkingWorkshops(Comp_Station& Station);

int Performance(Comp_Station& Station);

void OutputStation(const Comp_Station& Station);

int menu1(int& InputW);

int menu2(int& InputW);

int StopWorkstation(Comp_Station& Station, int& StopW);

int StartWorkstation(Comp_Station& Station, int& StartW);

void ChangePipeCond(Pipe& My_Pipe);

void Save(const Comp_Station& Station, Pipe& My_Pipe);

void Upload();