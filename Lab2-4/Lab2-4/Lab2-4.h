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

void AddLength(Pipe& My_Pipe);

void AddWidth(Pipe& My_Pipe);

void OutputPipe(const Pipe& My_Pipe);

void NameStation(Comp_Station& Station);

void AllWorkshops(Comp_Station& Station);

void WorkingWorkshops(Comp_Station& Station);

void Performance(Comp_Station& Station);

void OutputStation(const Comp_Station& Station);

void menu(std::string& InputW);

void Upload();

void Save(const Comp_Station& Station, Pipe& My_Pipe);

void StopWorkstation(Comp_Station& Station, int& StopW);

void StartWorkstation(Comp_Station& Station, int& StartW);

void ChangePipeCond(Pipe& My_Pipe);
