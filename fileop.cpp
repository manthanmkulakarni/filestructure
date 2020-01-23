#include<iostream>
#include<string>
#include<fstream>


using namespace std;

class Employee{
    public:
    char name[20],dep[10];
    int age;
    static int count;
    Employee(){
        age=0;
    }

    Employee(char name[],char  dep[], int age){
        strcpy(this->name,name);
        strcpy(this->dep,dep);
        this->age=age;
    }
    void setData(char name[],char  dep[], int age){
        strcpy(this->name,name);
        strcpy(this->dep,dep);
        this->age=age;
    }
    void get(){
       
        cout<<"Name "<<name<<endl<<"Dep "<<dep<<endl<<"Age "<<age<<endl;
    }

    void writeToFile(fstream &f){
        f<<name<<"\n";
        f<<dep<<"\n";
        f<<age<<"\n";

        cout<<"Done writing\n";
    }

};
void readFile(){
    fstream fr;
    char name[10],dep[10];
    int age;
    fr.open("empdata.txt",ios::in);
      for(int i=0;!fr.eof();i++){
        fr>>name;
        fr>>dep;
        fr>>age;
        cout<<"Emp "<<i+1<<endl;
        cout<<"Name "<<name<<endl<<"Dep "<<dep<<endl<<"Age "<<age<<endl;

    }
}
void findEmp(){
    char key[20];
    char tempname[30],tempdep[10];
    int tempage;
    fstream fr;

    cout<<"Enter the key name to find\n";
    cin>>key;

    fr.open("empdata.txt",ios::in);

    for(int i=0;!fr.eof();i++){
        fr>>tempname;
        fr>>tempdep;
        fr>>tempage;
        if(strcmp(tempname,key)==0){
            cout<<"\n\n\nRecord Found\n";
            cout<<"Emp "<<i+1<<endl;
            cout<<"Name "<<tempname<<endl<<"Dep "<<tempdep<<endl<<"Age "<<tempage<<endl;
        }
        

    }

}
int Employee::count=0;

int main(){
    char name[10],dep[10];
    int age;
    fstream f;
    f.open("empdata.txt",ios::app);
    

    Employee e[2];

    Employee::count=2;

    for(int i=0;i<Employee::count;i++){
        cin>>name;
        cin>>dep;
        cin>>age;

        e[i].setData(name,dep,2);
        e[i].writeToFile(f);
    }
  
    readFile();
    findEmp();

    return 0;
}