#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include <cmath>

using namespace std;
double middle(const vector<double> &a)
{
	double k=0,n=0;
	size_t oursize = a.size();
	for (size_t i=0; i<oursize;i++)
	{ 
			k = k + a[i];
			n++;
	}
	return k / n;
}
double B1(const vector<double> &a, const vector<double> &b)
{
	double r = 0, m = 0,r1=0,m1=0,mida=middle(a),midb=middle(b);
	size_t oursizea;
	if (a.size() <= b.size())
	{
		oursizea = a.size();
	}
	else 
	{
		oursizea = b.size();
	}
	for (size_t i = 0; i < oursizea; i++)
	{
				m = (a[i] - mida)*(b[i]-midb);
				r = r + m;
				m1 = (a[i] - mida) * (a[i] - mida);
				r1 = r1 + m1;

		
	}
	return r / r1;

}
double B0(const vector<double> &a , const vector<double> &b)
{
	double b0 = middle(b) - B1(a, b) * middle(a);
	return b0;
}
double prognos(const double& a, const double& b, const double &x)
{
	return x * a + b;
}
double RMSE(const vector<double>& a, const vector<double>& b)
{
	double r = 0, m = 0, n = 0, b0= B0(a, b),b1= B1(a, b);
	size_t oursize=b.size();
	for (size_t i = 0; i < oursize; i++) 
	{
		m = (b[i] - prognos(b1, b0, a[i])) * (b[i] - prognos(b1, b0, a[i]));
		r = r + m;
		n++;

	}
	return sqrt(r / n);
}
double R_2(const vector<double>& a, const vector<double>& b)
{
	double r = 0, m = 0, n = 0,r1=0,m1=0,midl=middle(b), b0 = B0(a, b), b1 = B1(a, b);
	size_t oursize = b.size();
	for (size_t i = 0; i < oursize; i++)
	{
		m = (b[i] - prognos(b1, b0, a[i])) * (b[i] - prognos(b1, b0, a[i]));
		r = r + m;
		m1 = (b[i] - midl) * (b[i] - midl);
		r1 = r1 + m1;
	}
	return 1 - (r / r1);
}