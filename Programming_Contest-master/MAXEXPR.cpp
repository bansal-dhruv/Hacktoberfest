#include<bits/stdc++.h>
using namespace std;

# define ld long double


int main(){

	int t;
	cin>>t;
	while(t--){

		int n;
		cin>>n;
		int flag=0;
		ld ans=0,ff=0,f4=0,kk=0;
		ld k[100005],c[100005];

		for(int i=0;i<n;i++){
			cin>>k[i];
		}
		for(int i=0;i<n;i++){
			cin>>c[i];
		}

		ff=0;
		kk=0;
		f4=0;
		ans=0;

		for(int i=0;i<n;i++){
			ff+=k[i]*c[i];
			kk+=(1/k[i]);
		}

		f4=ff/kk;

		for(int i=0;i<n;i++){
			ld temp=f4/(k[i]*k[i]);

			if(temp<0){
				cout<<"-1"<<endl;
				flag=1;
				break;
			}

			ans+=sqrt(temp);
		}

		if(flag!=1)
		{		cout<<ans<<" ";		
				for(int i=0;i<n;i++){
		
					ld temp=f4/(k[i]*k[i]);
					temp-=c[i];
					cout<<temp<<" ";
		
					k[i]=0;
					c[i]=0;
				}
				cout<<endl;
		}
	}
	return 0;
}
