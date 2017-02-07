#include <iostream>

using namespace std;

void userInput(long&,long&,long&);

int main(){
    double* f;
    long* i = new long;
    long s, c, m;
    s = 0L;
    c = 0L;
    m = 0L;

    userInput(s,c,m);

    *i = (s|c|m);

    cout << "i = " << hex << *i << endl;
    f = reinterpret_cast<double*>(i);
    cout << "f = " << dec << *f << endl; 

    delete i;
    i = 0;
    f = 0;
    return 0;
}

void userInput(long &s, long &c, long &m){
    bool sign;
    long power, mantissa;
    cout << "Is your number positive or negative?" << endl;
    cout << "(Type 0 for positive or 1 for negative): ";
    cin >> sign;
    cout << "What is your float power (c=1023+bin_exp)? ";
    cin >> power;
    cout << "What is your mantissa? ";
    cin >> mantissa;

    if (sign)
        s = 1ULL<<63;
    else
        s = 0L;
    c = power<<52;
    m = mantissa;

    cout << hex << s << ' ' << hex << c << ' ' << hex << m << endl;
} 
