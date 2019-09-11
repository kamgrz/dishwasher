#include <string>
#include <cstdlib>
#include "Program.h"

using namespace std;

Program::Program(string name, double program_length, double temperature, double energy_consumption)
{
	this->p_name = name;
	this->p_program_length = program_length;
	this->p_temperature = temperature;
	this->p_energy_consumption = energy_consumption;
}


Program::~Program()
{
}

string Program::get_name() {
	return this->p_name;
}

double Program::get_program_length() {
	return this->p_program_length;
}

double Program::get_temperature() {
	return this->p_temperature;
}

double Program::get_energy_consumption() {
	return this->p_energy_consumption;
}
