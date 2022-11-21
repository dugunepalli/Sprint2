#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;


void login();
void registr();
void forgot();
void AdminLogin();


void AdminLogin()    
{
    
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
            cout<<"Login Succesful"<<endl;
            cout<<"***************"<<endl;
            cout<<"**Hello Admin**"<<endl;
            cout<<"***************"<<endl;
        }
        else
        {
                        //Wrong Pin attemps 3
            Warning++;
            cout<<"Try Again"<<endl;
        }
    }
        //Pass Code attempts Exceeded 3 times then Accout is Bloked
    while(Warning<=3 && Input_Pin!=Pin);
    {
        if(Warning>3)
        {
            cout<<"Your Account Is Blocked! "<<endl;
            exit(0);
        }
    }
}


void Menu()
{
    int choice;
    cout<<"             ***********************************************************************"<<endl<<endl;
    cout<<"             ******************    Welcome to login page     ***********************"<<endl<<endl;
    cout<<"             ***********************************************************************"<<endl;
    cout<<endl;
    cout<<endl;
        
    cout<<"                 *******************        MENU        *******************************\n\n";
    cout<<"1.LOGIN"<<endl;
    cout<<"2.REGISTER"<<endl;
    cout<<"3.FORGOT PASSWORD (or) USERNAME"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"\nEnter your choice :";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"Thanks for using this program.\nThis program is created by GROUP-1 \n\n";
            break;
        default:
            cout<<"You've made a mistake , Try again..\n"<<endl;
            Menu();
        }

}

void login()
{
    int count;
    string user,pass,u,p;
        
    cout<<"Please enter the following details"<<endl;
    cout<<"USERNAME :";
    cin>>user;
    cout<<"PASSWORD :";
    cin>>pass;

    ifstream input("database.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)

        {
            count=1;
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\nHello   "<<user<<"\n<---LOGIN SUCCESSFUL--->\nThanks for logging in\n"<<endl;
        cin.get();
        cin.get();
        Menu();
    }
    else
    {
        cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
        Menu();
    }
}

void registr()
{

    string reguser,regpass,ru,rp;
        
    cout<<"Enter the username :";
    cin>>reguser;
    cout<<"\nEnter the password :";
    cin>>regpass;

    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
        
        
    cout<<"\nRegistration Sucessful\n";
    Menu();
}

void forgot()
{
    int ch;
        
    cout<<"Forgotten ? We're here for help\n";
    cout<<"1.Search your id by username"<<endl;
    cout<<"2.Search your id by password"<<endl;
    cout<<"3.Main menu"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int count=0;
            string searchuser,su,sp;
            cout<<"\nEnter your remembered username :";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp)
            {
                if(su==searchuser)
                {
                    count=1;
                }
            }
            searchu.close();
            if(count==1)
            {
                cout<<"\n\nHurray, account found\n";
                cout<<"\nYour password is "<<sp;
                cin.get();
                cin.get();
    
                Menu();
            }
            else
            {
                cout<<"\nSorry, Your userID is not found in our database\n";
                cout<<"\nPlease kindly contact your system administrator for more details \n";
                cin.get();
                cin.get();
                Menu();
            }
                break;
        }
        case 2:
        {
            int count=0;
            string searchpass,su2,sp2;
            cout<<"\nEnter the remembered password :";
            cin>>searchpass;

            ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2==searchpass)
                {
                    count=1;
                }
            }
            searchp.close();
            if(count==1)
            {
                cout<<"\nYour password is found in the database \n";
                cout<<"\nYour Id is : "<<su2;
                cin.get();
                cin.get();
                
                Menu();
            }
            else
            {
                cout<<"Sorry, We cannot found your password in our database \n";
                cout<<"\nkindly contact your administrator for more information\n";
                cin.get();
                cin.get();
                Menu();
            }

            break;
        }

        case 3:
        {
            cin.get();
            Menu();
        }
        default:
            cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
            forgot();
    }
}


int main()
{
    cout<<"----------------WELCOME TO THE ONLINE LMS------------------"<<endl;
    cout<<"//   1.Admin Login   //"<<endl;
    cout<<"//   2.User Login    //"<<endl;
    int Choice;
    cout<<"Enter Login Type ";
    cin>>Choice;
    
    switch(Choice)
    {
        case 1:
            AdminLogin();
            break;
        
        case 2:
            Menu();
            break;
        default:
            cout<<"Enter Correct Login Type"<<endl;
    }
}
