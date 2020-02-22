#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

struct Employee{
char ename[100];
char address[100];
char gen;
int depnum[100];
char ssn[100];
float salary;
};
typedef struct Employee Employee;


class FileOperations{
public:
char fname[100];
fstream fptr;

char ename[100][100];
char address[100][100];
char gen[100][1];
char depname[100][100];
char ssn[100][100];
char salary[100][100];

Employee e[100];

int count,ptr;

FileOperations(char * a){
	strcpy(fname,a);
	
	ptr=0;
}

void getData(int i){
	
	cin>>ename[i];
	
	
	cin>>gen[i];
	cin>>depname[i];
	cin>>ssn[i];
	cin>>salary[i];
	cin>>address[i];
	
}

void insertRec(){
	int n;
	cout<<"Enter the number of records to insert\n";
	cin>>n;
	cout<<"Enter Name\ngender\ndepnumber\nssn\nsalary\naddress\n";
	
	for(int i=0;i<n;i++){
		getData(i);
		ptr+=1; cout<<endl;
	}
	fptr.open(fname,ios::app);
	for(int i=0;i<n;i++){
		fptr<<ssn[i]<<","<<ename[i]<<","<<address[i]<<","<<gen[i]<<","<<depname[i]<<","<<salary[i]<<","<<endl;
	}
	fptr.close();
	ptr=0;
}

void readRec(){
	fptr.open(fname);
	char data[1000],*datat,*temp,t[100];
	int i=0;

	
	while(fptr>>data){
	datat=data;
	strcpy(ssn[i],strtok_r(datat,",",&datat));
	strcpy(ename[i],strtok_r(datat,",",&datat));
	strcpy(address[i],strtok_r(datat,",",&datat));
	strcpy(gen[i],strtok_r(datat,",",&datat));
	strcpy(depname[i],strtok_r(datat,",",&datat));
	strcpy(salary[i],strtok_r(datat,",",&datat));
	i+=1;
	}
	fptr.close();
	count=i;
	for(int j=0;j<count;j++){
		cout<<"\nEmployee "<<j<<endl;
		cout<<ssn[j]<<"\n"<<ename[j]<<"\n"<<address[j]<<"\n"<<gen[j]<<"\n"<<depname[j]<<"\n"<<salary[j]<<"\n\n";
	}
}

void find(){
	char fssn[100];
	cout<<"Enter the ssn to find\n";
	cin>>fssn;
	for(int j=0;j<count;j++){
		if(strcmp(fssn,ssn[j])==0){
			cout<<"\n\nFound !!!\n";
			cout<<ssn[j]<<"\n"<<ename[j]<<"\n"<<address[j]<<"\n"<<gen[j]<<"\n"<<depname[j]<<"\n"<<salary[j]<<"\n\n";
		}

	}

}

void disp(){
	for(int j=0;j<count;j++){
		cout<<"\nEmployee "<<j<<endl;
		cout<<ssn[j]<<"\n"<<ename[j]<<"\n"<<address[j]<<"\n"<<gen[j]<<"\n"<<depname[j]<<"\n"<<salary[j]<<"\n\n";
	}

}

void delRec(){
	char fssn[100];
	int i,flg=0;
	cout<<"Enter the ssn to delete\n";
	cin>>fssn;
	for(i=0;i<count;i++){
		if(strcmp(fssn,ssn[i])==0){
			flg=1;
			break;
		}

	}

	if(flg){
		if(count==1) count=0;

		else{
			if(i==(count-1)){
				count-=1;
			}
			else{
				strcpy(ssn[i],ssn[count-1]);
				strcpy(ename[i],ename[count-1]);
				strcpy(address[i],address[count-1]);
				strcpy(gen[i],gen[count-1]);
				strcpy(depname[i],depname[count-1]);
				strcpy(salary[i],salary[count-1]);
		
				count=1;

			
			}

		}
		disp();
	}
}

void resetRec(){
	char fssn[100];
	int choice,i,flg=0;
	cout<<"Enter the ssn to reset\n";
	cin>>fssn;
	cout<<"1-name 2-address 3-department 4-salary\n";
	cin>>choice;

	for(i=0;i<count;i++){
		if(strcmp(fssn,ssn[i])==0){
			flg=1;
			break;
		}

	}

	if(flg){
		switch(choice){
		case 1:strcpy(ename[i],"Null");break;
		case 2:strcpy(address[i],"Null");break;
		case 3:strcpy(depname[i],"Null");break;
		case 4:strcpy(salary[i],"Null");break;
		default:cout<<"Invalid choice"<<endl;break;

		}

	}
	disp();
}
void modifyRec(){
	char fssn[100],data[100];
	int choice,i,flg=0;
	cout<<"Enter the ssn to modify\n";
	cin>>fssn;
	cout<<"1-name 2-address 3-department 4-salary\n";
	cin>>choice;
	cout<<"Enter the new value"<<endl;
	cin>>data;
	for(i=0;i<count;i++){
		if(strcmp(fssn,ssn[i])==0){
			flg=1;
			break;
		}

	}

	if(flg){
		switch(choice){
		case 1:strcpy(ename[i],data);break;
		case 2:strcpy(address[i],data);break;
		case 3:strcpy(depname[i],data);break;
		case 4:strcpy(salary[i],data);break;
		default:cout<<"Invalid choice"<<endl;break;

		}

	}
	disp();

}

};

int main(){

	FileOperations f("employee.csv");
	f.insertRec();
	f.readRec();
	f.find();
	f.delRec();
	f.resetRec();
	f.modifyRec();

return 0;
}
