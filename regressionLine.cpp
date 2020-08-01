#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {
	double x;
	double y;
} two_d;

int main(void) {
	int num = 0;
 	two_d tmp = {0.0, 0.0}, sum = {0.0, 0.0}, ave = {0.0, 0.0}, sd = {0.0, 0.0};
	double sxy = 0.0, r = 0.0, a = 0.0, b = 0.0;
	vector<two_d> array;
	cout << "Regression Line Calculator Ver.1.0.0\n" << endl;
	cout << "Put Numbers of Elements > ";
	cin >> num;

	cout << "Put Elements." << endl;
	for (int i=0; i<num; i++) {
		cout << "array[" << i << "] x > ";
		cin >> tmp.x;
		sum.x += tmp.x;
		cout << "array[" << i << "] y > ";
		cin >> tmp.y;
		sum.y += tmp.y;
		array.push_back(tmp);
	}

	ave.x = sum.x / double(num);
	ave.y = sum.y / double(num);
	for (int i=0; i<num; i++) {
		sd.x += pow(array.at(i).x - ave.x, 2.0);
		sd.y += pow(array.at(i).y - ave.y, 2.0);
		sxy += (array.at(i).x - ave.x) * (array.at(i).y - ave.y);
	}
	sd.x = sqrt(sd.x / double(num));
	sd.y = sqrt(sd.y / double(num));
	sxy /= double(num);
	r = sxy / (sd.x * sd.y);
	a = sxy / pow(sd.x,2);
	b = ave.y - (a * ave.x);

	cout << "Result:" << endl;
	cout << "Elements: ";
	for (int i=0;i<num;i++)
		cout << "(" << array.at(i).x  << "," << array.at(i).y << ") ";
	cout << endl;
	cout << "Average: x: " << ave.x << " y: " << ave.y << endl;
	cout << "Standard Deviation Value: sx: " << sd.x << " sy: " << sd.y << " sxy: " << sxy << endl;
	cout << "Correlation coefficient: " << r << endl;
	cout << "Regression Line Equation: " << "y = " << a << "x + " << b << endl;

	return 0;
}
