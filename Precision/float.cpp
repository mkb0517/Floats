#include <iostream>

using namespace std;

int main(){
    double* f;
    long* i = new long;
    long s, c, m;
    s = 1;
    c = 1016;
    m = 0x0;

    s<<=63;
    c<<=52;

    *i = (s|c|m);

    cout << "i = " << hex << *i << endl;
    f = reinterpret_cast<double*>(i);
    cout << "f = " << dec << *f << endl; 

    delete i;
    i = 0;
    f = 0;
    return 0;
}
