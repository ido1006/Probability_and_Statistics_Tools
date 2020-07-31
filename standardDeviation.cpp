#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int num = 0;
 	double tmp = 0.0, sum = 0.0, ave = 0.0, vx = 0.0, sx = 0.0;
	vector<double> array;
	cout << "Standard Deviation Calculator Ver.1.0.1\n" << endl;
	cout << "Put Numbers of Elements > ";
	cin >> num;

	cout << "Put Elements." << endl;
	for (int i=0; i<num; i++) {
		cout << "array[" << i << "] > ";
		cin >> tmp;
		sum += tmp;
		array.push_back(tmp);
	}

	ave = sum / double(num);
	for (int i=0; i<num; i++)
		vx += pow(array.at(i) - ave, 2.0);
	vx /= double(num);
	sx = sqrt(vx);

	cout << "Result:" << endl;
	cout << "Elements: ";
	for (int i=0;i<num;i++)
		cout << array.at(i) << " ";
	cout << endl;
	sort(array.begin(), array.end());
	cout << "Range: " << array.at(num-1) - array.at(0) << endl;
	cout << "Average: " << ave << endl;
	cout << "Variance Value: " << vx << endl;
	cout << "Standard Deviation Value: " << sx << endl;

	return 0;
}
