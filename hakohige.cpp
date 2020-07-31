#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num = 0, q1_addr = 0, q2_addr = 0, q3_addr = 0;
	double tmp = 0.0, q1 = 0.0, q2 = 0.0, q3 = 0.0, ir = 0.0;
	vector<double> array;
	cout << "Calculator for Hakohige Figure Ver.1.0.0\n" << endl;
	cout << "Put Numbers of Elements. > ";
	cin >> num;

	cout << "Put Elements." << endl;
	for (int i=0; i<num; i++) {
		cout << "array[" << i << "] > ";
		cin >> tmp;
		array.push_back(tmp);
	}
	sort(array.begin(), array.end());


	q2_addr = num / 2;
	q1_addr = q2_addr / 2;
	q3_addr = q2_addr + q1_addr;
	if (num % 2 != 0) {
		q2 = array.at(q2_addr);
		if (q2_addr % 2 != 0) {
			q1 = array.at(q1_addr);
			q3 = array.at(q3_addr);
		}
		else {
			q1 = ( array.at(q1_addr) + array.at(q1_addr + 1) ) / 2.0;
			q3 = ( array.at(q3_addr) + array.at(q3_addr + 1) ) / 2.0;
		}
	}
	else {
		q2 = ( array.at(q2_addr) + array.at(q2_addr - 1) ) / 2.0;
		if (q2_addr % 2 != 0) {
			q1 = array.at(q1_addr);
			q3 = array.at(q3_addr);
		}
		else {
			q1 = ( array.at(q1_addr) + array.at(q1_addr - 1) ) / 2.0;
			q3 = ( array.at(q3_addr) + array.at(q3_addr - 1) ) / 2.0;
		}
	}
	ir = q3 - q1;

	cout << "Result:" << endl;
	cout << "Elements(sorted): ";
	for (int i=0;i<num;i++)
		cout << array.at(i) << " ";
	cout << endl;
	cout << "Interquartile Range: " << ir << endl;
	cout << "First Quartile: " << q1 << " at array[" << q1_addr << "]" << endl;
	cout << "Second Quartile: " << q2 << " at array[" << q2_addr << "]" << endl;
	cout << "Third Quartile: " << q3 << " at array[" << q3_addr << "]" << endl;
	cout << "Outlier:" << endl;
	for (int i=0;i<num;i++){
		if (i < q1_addr && array.at(i) < q1 - (ir * 1.5) )
			cout << array.at(i) << " at array[" << i << "]" << endl;
		if (i > q3_addr && array.at(i) > q3 + (ir * 1.5) )
			cout << array.at(i) << " at array[" << i << "]" << endl;
	}

	return 0;
}

