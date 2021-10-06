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
void OutputPipe(Pipe My_Pipe);

void InputPipe(Pipe& My_Pipe);

void InputStation(Comp_Station& Station);

void OutputStation(Comp_Station& Station);

void f(std::string& InputW);

void f8();

void f7(Comp_Station& Station, Pipe& My_Pipe);

void f6(Comp_Station& Station, int& StopW);

void f5(Comp_Station& Station, int& StartW);

void f4(Pipe& My_Pipe, std::string& s);
