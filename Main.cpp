#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"ourfunctions.h"
using namespace std;
int main() 
{
	ifstream file("C:\\Users\\s29mi\\Downloads\\saveecobot_20131.csv");
	ofstream outfile("C:\\Users\\s29mi\\Downloads\\filtered.csv");
	string line, id, type, data_time, next, text;
	int indefer10=0,indefer25=0, last=1;
	double value, hour;
	vector<double> pm10, pm25, time10, time25;
	while (getline(file, line)) 
	{
		if (line.find("pm10") != string::npos||line.find("pm25")!=string::npos)
		{
			istringstream f(line);
			getline(f, id, ',');
			getline(f, type, ',');
			f >> value;
			getline(f, next, ',');
			getline(f, data_time, ',');
			istringstream f1(data_time);
			getline(f1, next, '-');
			getline(f1, next, '-');
			getline(f1, next, ' ');
			f1 >> hour;
			getline(f, text, ',');
			if (value < 100)
			{
				if (last == 1 && type == "pm10") 
				{
					outfile << line << endl;
					last = 0;
					pm10.push_back(value);
					time10.push_back(hour);
					indefer10++;
				}
				else if (last == 0 && type == "pm25")
				{
					outfile << line << endl;
					last = 1;
					pm25.push_back(value);
					time25.push_back(hour);
					indefer25++;
				}

				
			}
		}
		
	}
	cout << hour<<' '<<data_time<<'\n';
	cout << middle(pm10) << ' ' << middle(pm25)<<'\n';
	cout << "pm10 = " << B1(pm25, pm10) << "*pm25 + " << B0(pm25, pm10) <<'\n';
	cout << "RMSE = " << RMSE(pm25, pm10) << "; R^2 = " << R_2(pm25, pm10)<<'\n';
	cout << "pm25 = " << B1(pm10, pm25) << "*pm10 + " << B0(pm10, pm25) <<'\n';
	cout << "RMSE = " << RMSE(pm10, pm25) << "; R^2 = " << R_2(pm10, pm25) << '\n';
	cout << "pm10 = " << B1(time10, pm10) << "*time_of_day(hour) + " << B0(time10, pm10) << '\n';
	cout << "RMSE = " << RMSE(time10, pm10) << "; R^2 = " << R_2(time10, pm10) << '\n';
	cout << "pm25 = " << B1(time25, pm25) << "*time_of_day(hour) + " << B0(time25, pm25) << '\n';
	cout << "RMSE = " << RMSE(time25, pm25) << "; R^2 = " << R_2(time25, pm25) << '\n';
}