
#include <iostream>
#include <unistd.h>  // syscall()
#include <syscall.h> // SysCall nummers
#include <fcntl.h>   // O_RDONLY
#include <fstream>
using namespace std;

void new_file()
{
        cout<<"This is the new_file command!"<<endl;

        //########## FILE CREATE ###############
        cout<<"File name?: ";
        string fileName;
        cin >> fileName;
        int fd= syscall(SYS_creat, fileName.c_str(),S_IRWXU );
        syscall(SYS_close,fd);
        cout<<endl;

        //########### FILE WRITE ##############
        cout<<"File contents?: "<<endl;
        string fileContent;
        fd= syscall(SYS_open, fileName.c_str(), O_WRONLY);
        while(getline(cin,fileContent))
        {
                fileContent+='\n';
                syscall(SYS_write,fd, fileContent.c_str(), fileContent.size());
        }
        syscall(SYS_close,fd);
        cin.clear();
}


void list()
{ std::cout << "LS" << std::endl; }

void find()
{ std::cout << "FIND" << std::endl; }

void python()
{ std::cout << "PYTHON" << std::endl; }

void src()
{ int fd = syscall(SYS_open, "shell.cc", O_RDONLY, 0755); // Gebruik de SYS_open call om een bestand te openen.
  char byte[1];                                           // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
  while(syscall(SYS_read, fd, byte, 1))                   // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte; }                                  //   zet de gelezen byte in "byte" zodat deze geschreven kan worden.



void configfile(){
string line;
ifstream myfile;
myfile.open ("confFile.txt");
getline(myfile,line);
cout<<line;
myfile.close();
}

int main(){
configfile();

std::string input;
  while(true)

  { std::getline(std::cin, input);
    if (input == "new_file") new_file();
    if (input == "ls") list();
    if (input == "src") src();
    if (input == "find") find();
    if (input == "python") python();
    if (input == "quit") return 0;
    if (input == "error") return 1;
    configfile();
}}
