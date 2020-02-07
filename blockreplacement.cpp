#include<iostream>

using namespace std;

class Block{
    public:
    int ar[100],buf[10],n,l;
    Block(int n,int l){
        this->n=n;
        this->l=l;
        for(int i=0;i<n;i++){
            buf[i]=-1;
        }
    }
    void getData(){
        for(int i=0;i<l;i++)
            cin>>ar[i];
    }

    void fifo(){
        int ptr=0;
        for(int i=0;i<n;i++){
            buf[i]=-1;
        }
        for(int i=0;i<l;i++){
            buf[ptr]=ar[i];
            ptr=(ptr+1)%n;

            for(int j=0;j<n;j++){
                cout<<buf[j]<<" ";
            }
            cout<<"\n\n";
        }
    }
    void lru(){
        int ptr=0,cnt,flg[n];
        for(int i=0;i<n;i++){
            buf[i]=-1;
        }
        for(int i=0;i<l;i++){
            if(buf[ptr==-1]){
                buf[ptr]=ar[i];
                ptr=(ptr+1)%n;
            }
            else{
                cnt=0;

                for(int p=0;p<n;p++){
                    flg[p]=0;
                }

                for(int j=i;j>=0;j--){
                    if(cnt==(n-1))break;

                    for(int k=0;k<n;k++){
                        if(buf[k]==ar[i]){
                            flg[k]=1;
                            cnt++;
                        }
                    }
                }
                for(int j=0;j<n;j++){
                    if(flg[j]==0){
                        buf[j]=ar[i];
                    }
                }
            }

            //Display content
            for(int j=0;j<n;j++){
                cout<<buf[j]<<" ";
            }
            cout<<"\n\n";
            
        }
    }

    void mru(){
	int ptr=0,flg;
	for(int i=0;i<n;i++){
		buf[i]=-1;
	
	}
	for(int i=0;i<l;i++){
		if(buf[ptr]==-1){
			buf[ptr]=ar[i];
			ptr=(ptr+1)%n;
		}
		else{
			flg=ptr;

			for(int j=i;j>=0;j--){
				for(int p=0;p<n;p++){
					if(buf[p]==ar[j]){
						flg=p;
						goto replace;
					}
				}
			}replace:
			buf[flg]=ar[i];
			

		}

		for(int j=0;j<n;j++)cout<<buf[j]<<" ";

		cout<<endl;
		
	}


    }

};

int main(){

    Block b(3,10);
    b.getData();
    cout<<"LRU\n";
    b.lru();
    cout<<"FIFO\n";
    b.fifo();
    cout<<"MRU\n";
    b.mru();

    return 0;
}
