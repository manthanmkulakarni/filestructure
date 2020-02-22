#include<iostream>

using namespace std;

class Pages{
public:
	int ar[100],pages[100],n,np;

	Pages(int n,int np){
		this->n=n;
		this->np=np;
	}
	void getData(){
		cout<<"Enter the data\n";
		for(int i=0;i<n;i++){
			cin>>ar[i];
		}
	}
	int check(int p){
		for(int i=0;i<n;i++){
			if(pages[i]==p)return 1;
		}
		return 0;
	}
	void LRU(){

		for(int p=0;p<np;p++)pages[p]=-1;
		int i=0,j=0,flg,target[np],cnt;
		while(i<np and j<n){
			flg=0;
			for(int k=0;k<i;k++){
				if(pages[k]==ar[j])flg=1;

			}

			if(flg!=1){
				pages[i++]=ar[j];
			}
			j++;
			for(int p=0;p<np;p++){
				cout<<pages[p]<<" ";
			}cout<<endl;
		}
		while(j<n){
			
			if(check(ar[j])){j++;}
		
			else{
				for(int p=0;p<np;p++)target[p]=0;
				cnt=0;
				for(int m=j-1;m>-1;m--){
					if (cnt==(np-1))break;
					for(int k=0;k<np;k++){
						if(pages[k]==ar[m]){
							cnt++;target[k]=1;
						}
					}
				}
				for(int m=0;m<np;m++){
					if(target[m]==0){
						pages[m]=ar[j];
						break;
					}
				}
		
			}
			j++;
			for(int p=0;p<np;p++){
				cout<<pages[p]<<" ";
			}cout<<endl;
		}

	}

	void FIFO(){
		for(int p=0;p<np;p++)pages[p]=-1;

		int i=0,j=0;
		while(j<n){
			if(check(ar[j])){j++;}

			else{
				pages[i]=ar[j];
				j++;
				i=(i+1)%np;

			}

			for(int p=0;p<np;p++){
				cout<<pages[p]<<" ";
			}cout<<endl;
		
		}



	}
	void clock(){
		for(int p=0;p<np;p++)pages[p]=-1;

		int i=0,j=0,chance[np];
		for(int p=0;p<np;p++)chance[p]=0;

		while(i<np and j<n){
			if(check(ar[j])){
				j++;
				chance[i]=1;
			}
			else{
				pages[i]=ar[j];
				i++;
				j++;
			}
			for(int p=0;p<np;p++){
				cout<<pages[p]<<" ";
			}cout<<endl;

		}
		i=0;
		while(j<n){
			if(check(ar[j])){
				for(int p=0;p<np;p++){
					if(pages[p]==ar[j]){
						chance[p]=1;
						break;
					}
				}
				j++;
			}

			else{
				int cnt=0;
				while(cnt<np){
					cnt++;
					if(chance[i]==0){
						pages[i]=ar[j];
						break;
					}
					i=(i+1)%np;
				} 
				if(cnt==np){
					pages[i]=ar[j];
					chance[i]=0;
				}
				i=(i+1)%np;
				j++;
			}
			for(int p=0;p<np;p++){
				cout<<pages[p]<<" ";
			}cout<<endl;
		}

	}

};

int main(){
Pages p(10,3);
p.getData();
cout<<"LRU\n";
p.LRU();
cout<<"FIFO\n";
p.FIFO();
cout<<"Clock\n";
p.clock();
return 0;
}

