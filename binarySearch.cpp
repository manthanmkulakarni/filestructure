#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class BSearch{
public:
	int ar[100],n;
	BSearch(int i){
		n=i;
	}
	void getData(){
		cout<<"Enter the data\n";
		for(int i=0;i<n;i++)
			cin>>ar[i];
	}
	void printData(){
		for(int i=0;i<n;i++)cout<<ar[i]<<" ";

		cout<<endl;
	}
	void sort(){
		std::sort(ar,ar+n);
	}
	void search(){
		int key,l=0,u=n-1,mid;
		cout<<"Enter the key\n";
		cin>>key;
		while(l<=u){
			mid=(l+u)/2;
			if(ar[mid]==key){
				cout<<"Key found at : "<<mid<<endl;
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

int n;
cout<<"Enter the size of array\n";
cin>>n;

BSearch b(n);

b.getData();
b.printData();
b.sort();
b.printData();
b.search();

return 0;
}
