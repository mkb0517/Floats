#include <iostream>

using namespace std;

void userInput(long&,long&,long&);

int main(){
    double* f;
    long* i = new long;
    long s, c, m;
    s = 0ULL;
    c = 0ULL;
    m = 0ULL;

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
    double input;
    bool sign;
    long power, mantissa;
    cout << "Enter the number you would like to see: ";
    cin >> input;

    if (input < 0)
        s = 1ULL<<63;
    else
        s = 0L;
    c = log2(input);
    c = power<<52;
    m = mantissa;

    cout << hex << s << ' ' << hex << c << ' ' << hex << m << endl;
}
