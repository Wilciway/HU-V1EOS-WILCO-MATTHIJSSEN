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
{
        pid_t childPIDorZero= syscall(SYS_fork);
        if(childPIDorZero <0){
                perror("fork() error");
        }
        else if(childPIDorZero !=0){
                wait(NULL);
        }
        else{
                execl("/bin/ls","ls","-la",NULL);
        }
}

void find(){
        cout<<"This is the find command!"<<endl;
        cout<<"search: ";
        string findQuery;
        getline(cin,findQuery);

        int fd[2];
        pipe(fd);
        pid_t pid=fork();

        if(pid==0){
                syscall(SYS_close,fd[0]);
                dup2(fd[1],1);
                //syscall(SYS_close,fd[1]);
                execlp("/usr/bin/find","find",".",NULL);
        }
        else{
                pid_t gpid= fork();

                if(gpid==0){
                        syscall(SYS_close,fd[1]);
                        dup2(fd[0],0);
                //      syscall(SYS_close,fd[0]);
                        execlp("/bin/grep","grep",findQuery.c_str(),NULL);
                }
                else{
                        syscall(SYS_close, fd[1]);
                        syscall(SYS_close, fd[0]);
                        syscall(SYS_wait4, pid, NULL, NULL, NULL);
                        syscall(SYS_wait4, gpid, NULL, NULL, NULL);
                }
        }
}



void python()
{
  pid_t childPIDorZero= syscall(SYS_fork);
        if(childPIDorZero <0){
                perror("fork() error");
        }
        else if(childPIDorZero !=0){
                wait(NULL);
        }
        else{
                execl("/usr/bin/python","python",NULL);
        }

// std::cout << "PYTHON" << std::endl; }
}


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