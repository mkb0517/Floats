#include <iostream>

using namespace std;

template<typename T>
void input(T&);

int main(){
    double* f;
    long* i = new long;
    long s, c, m;
    int option=0;
    bool goOn = true;
    bool skip = false;

    while(goOn){
        skip = false;
        cout << endl << "Which number do you want to see reinterpreted?" << endl;
        cout << "1. 1" << endl << "2. 2" << endl << "3. 3" << endl << "4. -3.5" << endl;
        cout << "-> ";
        input(option);
        cout << endl;
        switch(option){
        case 1:
            s = 0;
            c = 1023;
            m = 0x0;
            break;
        case 2:
            s = 0;
            c = 1024;
            m = 0x0;
            break;
        case 3:
            s = 0;
            c = 1024;
            m = 0x1;
            m<<=51;
            break;
        case 4:
            s = 1;
            c = 1024;
            m = 0x3;
            m<<=50;
            break;
        default:
            cout << "That is not valid input. Please try again." << endl << endl;
            skip = true;
            break;
        }

        if(!skip){
            s<<=63;
            c<<=52;

            *i = (s|c|m);

            cout << "i = " << hex << *i << endl;
            f = reinterpret_cast<double*>(i);
            cout << "f = " << dec << *f << endl << endl;    
        }
        cout << "Would you like to go on? (type 0 or 1) ";
        input(goOn);
    }

    delete i;
    i = 0;
    f = 0;
    return 0;
}

template<typename T>
void input(T& var){
    bool goOn = true;
    while(goOn){
        cin >> var;
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Please input valid data" << endl;
        }
        else {
            goOn = false;
        }
    }
}
