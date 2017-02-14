#include <iostream>
#include <iomanip>
#include <cmath>
#include <quadmath.h>

using namespace std;

int main(){
    	float epsi = 1.0f;
	double d_epsi = 1.0;
	long double q_epsi = 1.0;
	float test = 1.0f + epsi;
	double d_test = 1.0 + d_epsi;
	long double q_test=1.0 + q_epsi;

	cout << "Float epsilon" << endl;
	while (test > 1.0f) {
		epsi /= 2;
		cout << setprecision(40) << epsi << endl;
		test = 1.0f + epsi;
	}

	cout << endl << "Double Epsilon" << endl;
	while (d_test > 1.0) {
		d_epsi /= 1.5;
		cout << setprecision(20) << d_epsi << endl;
		d_test = 1.0 + d_epsi;
	}

	cout << endl << "Quad Epsilon" << endl;
	while (q_test > 1.0) {
		q_epsi /= 1.5;
		cout << setprecision(20) << q_epsi << endl;
		q_test = 1.0 + q_epsi;
	}


    return 0;
}
