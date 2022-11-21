
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
            Sunil::Info("Login Succesful");
            Sunil::Info("***************");
            Sunil::Info("**Hello Admin**");
            Sunil::Info("***************");
        }
        else
        {
                        //Wrong Pin attemps 3
            Warning++;
            Sunil::Warn("Try Again");
        }
    }
        //Pass Code attempts Exceeded 3 times then Accout is Bloked
    while(Warning<=3 && Input_Pin!=Pin);
    {
        if(Warning>3)
        {
            Sunil::Warn("Your Account Is Blocked! ");
            exit(0);
        }
    }
}
