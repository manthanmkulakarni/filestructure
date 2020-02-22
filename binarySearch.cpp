#include<iostream>
#include<bits/stdc++.h>
#include<cstring>

using namespace std;

class BSearch{
public:
	int ar[100],n,count;
	char fname[100];
	fstream fptr;
	char ename[100][100];
	char address[100][100];
	char gen[100][1];
	char depname[100][100];
	char ssn[100][100];
	char salary[100][100];
	BSearch(char *name){
		n=0;
		strcpy(fname,name);
	}
	void getData(){
		fptr.open(fname);
		char data[1000],*datat,*temp,t[100];
		int i=0;

	
		while(fptr>>data){
		datat=data;
		strcpy(ssn[i],strtok_r(datat,",",&datat));ar[i]=atoi(ssn[i]);
		strcpy(ename[i],strtok_r(datat,",",&datat));
		strcpy(address[i],strtok_r(datat,",",&datat));
		strcpy(gen[i],strtok_r(datat,",",&datat));
		strcpy(depname[i],strtok_r(datat,",",&datat));
		strcpy(salary[i],strtok_r(datat,",",&datat));
		i+=1;
		}
		fptr.close();
		n=count=i;
		for(int j=0;j<count;j++){
			cout<<"\nEmployee "<<j<<endl;
			cout<<ssn[j]<<"\n"<<ename[j]<<"\n"<<address[j]<<"\n"<<gen[j]<<"\n"<<depname[j]<<"\n"<<salary[j]<<"\n\n";
		}
	}

	void printData(){
		for(int i=0;i<n;i++)cout<<ar[i]<<" ";

		cout<<endl;
	}
	void sort(){
		std::sort(ar,ar+n);
	}

	void printRec(int key){
		for(int i=0;i<count;i++){
			if(atoi(ssn[i])==key){
				cout<<ssn[i]<<"\n"<<ename[i]<<"\n"<<address[i]<<"\n"<<gen[i]<<"\n"<<depname[i]<<"\n"<<salary[i]<<"\n\n";
				break;		
			}
		}
		
	}
	void search(){
		int key,l=0,u=n-1,mid;
		cout<<"Enter the key\n";
		cin>>key;
		while(l<=u){
			mid=(l+u)/2;
			if(ar[mid]==key){
				cout<<"Key found at : "<<mid<<endl;
				printRec(ar[mid]);
				return;
			}
			else if(ar[mid]>key){
				u=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		cout<<"Key not found\n";
		return;
		
	}



};

int main(){


BSearch b("bsearchrecord.csv");

b.getData();
b.printData();
b.sort();
b.printData();
b.search();

return 0;
}
