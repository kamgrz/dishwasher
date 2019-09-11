#include <iostream>
#include <string>
#include "Program.h"
#include <list>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Dishwasher.h"

using namespace std;

vector<Program> read_file(){
    vector<Program> programs;
    string name;
    double length, temperature, power_consumption;
    int iter = 0;
    ifstream settings_file;
    settings_file.open("settings.txt");

    if (settings_file){
        while(!settings_file.eof()){
            iter ++;
            string data;
            if (iter == 0){
                getline(settings_file, name);
            }else if(iter == 1){
                getline(settings_file, data);
                length = atof(data.c_str());
            }else if(iter == 2){
                getline(settings_file, data);
                temperature = atof(data.c_str());
            }else if(iter == 3){
                getline(settings_file, data);
                power_consumption = atof(data.c_str());
                Program p = Program(name, length, temperature, power_consumption);
                programs.push_back(p);
                iter = 0;
            }
        }
    }else{
        cout<<"Cannot read settings file."<<endl;
    }
    settings_file.close();

    return programs;
}

void menu(vector<Program> programs){
    cout << "Virtual Dishwasher" <<endl;
    cout << "Choose program: " <<endl;
    cout << "1.\t" << programs[0].get_name() << "\n\tProgram length " <<programs[0].get_program_length() << "min\n\tTemperature: " << programs[0].get_temperature() << "*C\n\tPower Consumption " << programs[0].get_energy_consumption()<<"W"<<endl<<endl;
    cout << "2.\t" << programs[1].get_name() << "\n\tProgram length " <<programs[1].get_program_length() << "min\n\tTemperature: " << programs[1].get_temperature() << "*C\n\tPower Consumption " << programs[1].get_energy_consumption()<<"W"<<endl<<endl;
    cout << "3.\t" << programs[2].get_name() << "\n\tProgram length " <<programs[2].get_program_length() << "min\n\tTemperature: " << programs[2].get_temperature() << "*C\n\tPower Consumption " << programs[2].get_energy_consumption()<<"W"<<endl<<endl;
    cout << "4.\t" << programs[3].get_name() << "\n\tProgram length " <<programs[3].get_program_length() << "min\n\tTemperature: " << programs[3].get_temperature() << "*C\n\tPower Consumption " << programs[3].get_energy_consumption()<<"W"<<endl<<endl;
}

void manager(bool i){
    cout << "1. Stop" <<endl;
    if (!i){
        cout << "2. Pause" <<endl;
    }
    if (i){
      cout << "3. Start" <<endl;
    }
}

int main()
{
    vector<Program> programs = read_file();

    int program;
    Dishwasher dishwasher = Dishwasher();
    while(true){
        cout << "Program: ";
        menu(programs);
        cout << "Program: ";
        cin >> program;
        system("CLS");
        dishwasher.start();
        bool stop = false;
        int option;
        manager(false);
        cin >> option;
        while (!stop){
            system("CLS");
            if (option == 1 ){
                system("CLS");
                stop = dishwasher.stop();
            }else if (option == 2){
                system("CLS");
                dishwasher.pause();
                manager(true);
                cin >> option;
            }else if (option == 3){
                system("CLS");
                dishwasher.start();
                manager(false);
                cin >> option;
            }
        }
    }

	getchar();
}


