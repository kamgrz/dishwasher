#ifndef PROGRAM_H
#define PROGRAM_H

class Program
{
private:
	std::string p_name;
	double p_program_length;
	double p_temperature;
	double p_energy_consumption;
public:
	Program(std::string name, double program_length, double temperature, double energy_consumption);
	virtual ~Program();

	std::string get_name();
	double get_program_length();
	double get_temperature();
	double get_energy_consumption();
};

#endif // PROGRAM_H
