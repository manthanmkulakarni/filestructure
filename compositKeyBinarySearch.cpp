#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class MyBsearch{
public:
	char name[100][100],ssn[100][100],branch[100][100],address[100][100],fname[100];
	int count;
	fstream fptr;
	MyBsearch(char *name){
		count=0;
		strcpy(fname,name);
	}
	void getData(){
		fptr.open(fname);
		char data[200],*datat,*dtoken;
		int i=0;
		while(fptr>>data){
			datat=data;

			dtoken=strtok_r(datat,",",&datat);
			strcpy(name[i],dtoken);

			dtoken=strtok_r(datat,",",&datat);
			strcpy(branch[i],dtoken);

			dtoken=strtok_r(datat,",",&datat);
			strcpy(ssn[i],dtoken);

			dtoken=strtok_r(datat,",",&datat);
			strcpy(address[i++],dtoken);

		}
		count=i;
	}

	void printData(){
		for(int i=0;i<count;i++){

			cout<<"Employee "<<i<<endl;
			cout<<"Name "<<name[i]<<endl;
			cout<<"Branch "<<branch[i]<<endl;	
			cout<<"ssn "<<ssn[i]<<endl;
			cout<<"address "<<address[i]<<"\n"<<endl;


		}

	}
	void swapRec(int i,int k){
		char temp[100];

		strcpy(temp,name[i]);
		strcpy(name[i],name[k]);
		strcpy(name[k],temp);
	
		strcpy(temp,branch[i]);
		strcpy(branch[i],branch[k]);
		strcpy(branch[k],temp);

		strcpy(temp,ssn[i]);
		strcpy(ssn[i],ssn[k]);
		strcpy(ssn[k],temp);

		strcpy(temp,address[i]);
		strcpy(address[i],address[k]);
		strcpy(address[k],temp);

	}

	void sortRec(){

		char temp1[100],temp2[100];
		for(int i=0;i<count;i++){
			for(int j=0;j<count-i-1;j++){
				strcpy(temp1,name[j]);
				strcat(temp1,branch[j]);

				strcpy(temp2,name[j+1]);
				strcat(temp2,branch[j+1]);

				if(strcmp(temp1,temp2)>0){
					swapRec(j,j+1);
				}

			}

		}
	}

	void searchRec(){

		int l,h,m;
		char keyname[100],keybranch[100],temp[200],keycombined[200];

		strcpy(keycombined,keyname);
		strcat(keycombined,keybranch);

		cout<<"Enter the name"<<endl;
		cin>>keyname;
		cout<<"Enter the branch"<<endl;
		cin>>keybranch;

		strcpy(keycombined,keyname);
		strcat(keycombined,keybranch);

		l=0;
		h=count;
		while(l<=h){
			m=(l+h)/2;
				strcpy(temp,name[m]);
				strcat(temp,branch[m]);
			cout<<temp<<" "<<branch[m]<<" "<<name[m]<<endl;
			if(strcmp(keycombined,temp)==0){
				cout<<"\n\nRec found\n";
				cout<<"Employee "<<m<<endl;
				cout<<"Name "<<name[m]<<endl;
				cout<<"Branch "<<branch[m]<<endl;	
				cout<<"ssn "<<ssn[m]<<endl;
				cout<<"address "<<address[m]<<"\n"<<endl;
				return;
			}
			else if(strcmp(keycombined,temp)>0){
				l=m+1;
			}
			else{
				h=m-1;
			}

		}
		cout<<"Record not found"<<endl;

	}
	

};

int main(){

MyBsearch b("compoundbsearchdata.csv");
b.getData();
b.printData();
b.sortRec();
b.printData();
b.searchRec();

return 0;
}
