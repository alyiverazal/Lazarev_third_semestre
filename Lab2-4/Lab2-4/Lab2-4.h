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
    int stopped_workshops;
    int performance;
};
void OutputPipe(Pipe& My_Pipe);

void InputPipe(Pipe& My_Pipe);

void InputStation(Comp_Station& Station);

void OutputStation(Comp_Station& Station);
