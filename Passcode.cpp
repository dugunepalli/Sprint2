
#include<iostream>
#include "Logger.h"
using namespace std;
    
    
int main(){
    
    int Pin=1234;
    int Input_Pin=0;
    int Warning=1;
    do
    {
                    //Checking Pass Code
        cout<<"Enter Pin: ";
        cin>>Input_Pin;
        if(Input_Pin==Pin)
        {
            Logger::Info("Login Succesful");
            Logger::Info("***************");
            Logger::Info("**Hello Admin**");
            Logger::Info("***************");
        }
        else
        {
                        //Wrong Pin attemps 3
            Warning++;
            Logger::Warn("Try Again");
        }
    }
        //Pass Code attempts Exceeded 3 times then Accout is Bloked
    while(Warning<=3 && Input_Pin!=Pin);
    {
        if(Warning>3)
        {
            Logger::Warn("Your Account Is Blocked! ");
            exit(0);
        }
    }
}
