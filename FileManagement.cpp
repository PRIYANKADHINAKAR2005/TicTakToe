/*****************************************************************************************************************************************
 ***********************************************Priyanka File Management ****************************************************************
*****************************************************************************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdio>
void manipulation(int x);
void createfile();
void deletefile();
void readfile();
void writefile();
void appendfile();
using namespace std;
void manipulation(int x)
{
switch(x)
    {
        case 1:
        {
            createfile();
            break;
        }
        case 2:
        {
            deletefile();
            break;
        }
        case 3:
        {
            readfile();
            break;
        }
        case 4:
        {
            writefile();
            break;
        }
        case 5:
        {
            appendfile();
            break;
        }
        
        default:
        {
            cout<<"Invalid number";
            break;
        }
    }

}

void createfile()
{
        string name;
            cout<<"Enter the name of the file :";
            cin>>name;
           fstream file;
            file.open(name,ios::out);
            cout<<"Your file "<<name<<" has been created"<<endl;
            file.close();

}
void deletefile()
{
    fstream file;
            cout<<"Enter the name of the file to be removed:";
            string filename;
            cin>>filename;
            if(remove(filename.c_str())==0)
            {
                cout<<"File has been deleted successfully"<<endl;
                
            }
            else
            {
                cout<<"File does not exists"<<endl;
            }
            file.close();

}
void readfile()
{
    string fileName;
    cout<<"Enter the name of the file to be read:";
    cin>>fileName;
    fstream file;
    file.open(fileName,ios::in);
    if(!file.is_open())
    {
        cout<<"Error opening a file!"<<endl;
    }
    char ch;
    while(file.get(ch))
    {
        cout<<ch;
    }
    file.close();
    
}
void writefile()
{
    cout<<"Enter the name of the file to be written:";
    string fileName;
    cin>>fileName;
    fstream file;
    file.open(fileName,ios::out);
    if(!file)
    {
        cout<<"File doesn’t exist."; 
    }
    else {
        
        cout << "Enter data to write to the file (type 'exit' to finish):" << endl;
        string data;
        while (true) {
            getline(cin, data);  
            if (data == "exit") {
                break;
            }
            file << data << endl;  
        }

        cout << "Data has been written to the file." << endl;
    }
    file.close();


}
void appendfile()
{
    cout<<"Enter the file to be appended:";
    string fileName;
    cin>>fileName;
    fstream file;
    file.open(fileName,ios::app);
    if(!file)
    {
        cout<<"Error in opening the file";

    }
    else{
        string str;
        cout<<"Enter the data (enter exit to exit):";
        while(true)
        {
            getline(cin,str);
            if(str=="exit")
            {
                break;
            }
            file<<str;
        }
        file.close();

    }

}
int main()
{
    while(true)
    {
    int number;
    cout<<"* Welcome to File Program *"<<endl;
    cout<<"Select one of the following file options"<<endl;
    cout<<"1.Create a new file"<<endl;
    cout<<"2.Delete a exiting file"<<endl;
    cout<<"3.Open a file in a read mode"<<endl;
    cout<<"4.Write data in the file"<<endl;
    cout<<"5.Append the data in the existing file"<<endl;
    cout<<"Press the number based the operation you wanted to perform:";
    cin>>number;
    manipulation(number);
    cout<<endl<<"If want to continue the process press yes:";
    string str;
    cin>>str;
    if(str=="yes")
    {
        continue;
    }
    else{
        break;
    }
    }   



}
