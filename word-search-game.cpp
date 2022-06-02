#include <iostream>
using namespace std;
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//#include<windows.h>

void display(); //to display about game rules and info about htis game
int gamefunction(); //main working of the game

int main()
{
    string name;
    cout<<"Enter User Name: "<<endl;
    getline(cin,name);  //This also take space as a input eg.cin will terminate when space is encountered


    int score=0;    //initial score 
    char input;

    do
    {
        //game code
        //system("cls");  //for clearing the screen before game begins
        
        display();
        score = score+gamefunction();
        cout<<"Would you like to play this game y/n:";
        cin>>input;
        cout<<endl;
        
    } while (input != 'n'); //while y is selected game will be played otherwise no


    cout<<name<<"YOUR SCORE IS:"<<score<<endl;
    cout<<endl<<endl<<endl<<endl;
    
    cout<<"************************************************************************************\n"<<endl;
    return 0;
}

void display()
{
    cout<<"\t\t\t\tWORD SEARCHING GAME"<<endl;
    cout<<"You try to find valid words from the given matrix"<<endl;
    cout<<"if your guss is correct then score will increase"<<endl;
}
int gamefunction()
{
    string arr[10] = {"android","macos","unix","linux","windows","soalris","ubuntu","msdos","chromeos","fedora"};   //matching words
    char matrix[10][10];    //10*10 matrix of random alphabet
    
    

    for (int i = 0; i < 10; i++)    //for creating row
    {
        for (int j = 0; j < 10; j++)    //for creating column
        {
            int r;
            int c;
            r = rand()%26;  //pick a random no between 0-26
            c = 97+r;  //adds thr picked no to ASCAII value of 'a' and stores in c
            matrix[i][j]=c;   
        }
        
    }
    
    int index = rand()%10;  //select a random no b/w 0-12    
    string output = arr[index];   //store the random

    if(arr[index].length()%2==0)
    {
        //horizontally add alphabets from already given array
        int row = rand()%10; //row 
        int col = rand()%2;  //start from col

        for(int i=0;arr[index][i] != '\0';i++,col++)    //add alphabet in only in coloumn horizontly until last of the word becomes NULL
        {
            matrix[row][col] = arr[index][i];
        }

    }
    else
    {
        //vertically add alphabet from already given array
        int row = rand()%2; //start from row 
        int col = rand()%10;  //col

        for(int i=0;arr[index][i] != '\0';i++,row++)    //add alphabet in only in row vertically until last of the word becomes NULL
        {
            matrix[row][col] = arr[index][i];
        }
    }
    cout<<"\t\t\tPUZZLE\n"<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<" "<<matrix[i][j];
           // sleep(100); //delay printing next value
        }

        cout<<endl;

    }
    
    string guess;
    int hint;

    cout<<"PRESS 1 : for writing your guess"<<endl;
    cout<<"PRESS 2 : for seeing hint as no of words and answering your guss"<<endl;

    back:

    cout<<"ENTER INPUT :"<<endl;
    cin>>hint;

    if(hint == 1)
    {
        //this is common in both if
        //this part do nothing
    }
    else if (hint == 2)
    {
        cout<<"The word size is :"<<output.length()<<endl;  //length() for lenth of the word
    }
    else
    {
        cout<<"ENTER A VALID OPTION!"<<endl;

        goto back;
    }
    
    cout<<"enter the word :"<<endl;
    cin>>guess;

    if (output == guess)    //comparing the answer 
    {
        cout<<"Congratulation! you gussed the right word"<<endl;
        cout<<"score +1"<<endl;
        return 1;
    }
    else
    {
        cout<<"sorry plese guess again"<<endl;
        return 0;
    }
}
