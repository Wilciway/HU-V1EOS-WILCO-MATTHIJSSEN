#include <string>
#include <iostream>
using namespace std;



void speak(string  zin){

        for (unsigned int i=0; i < zin.size(); i++ ){
                switch(zin[i]){
                        case 'e':       cout << '3';    break;
                        case 'l':       cout << '1';    break;
                        case 'o':       cout << '0';    break;
                        case 't':       cout << '7';    break;
                        case 'a' ... 'd':
                        case 'f' ... 'k':
                        case 'm' ... 'n':
                        case 'p' ... 's':
                        case 'u' ... 'z':
                        cout << char ( zin[i] - ('a'-'A'));     break;
                        default:        cout << char(zin[i]);
                }
        }
        cout << endl;
}
int main(int argc, char **argv) {
    string lineInput;
while (getline(cin,lineInput)) {

speak(lineInput);
}

    return 0;
}
