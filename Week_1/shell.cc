#include "shell.hh"
using namespace std;

int main(){
string input;

while(true){ 
getline(cin, input);

switch(input){
case "new_file": newfile(); break;
case "ls": list(); break;
case "find": find(); break;
case "quit": return 0; break;
case "error": return 1; break;
default: cout<<"COMMAND NOT FOUND"<<endl;}}}

void new_file(){ 
cout << "NEW F" << endl; }

void list(){ 
cout << "LS!" << endl; }

void find(){ 
cout << "VIND" << endl; }

void python(){ 
cout << "PITON" << endl; }