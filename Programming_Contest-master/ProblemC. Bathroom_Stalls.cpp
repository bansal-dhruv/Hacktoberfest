#include<bits/stdc++.h>
using namespace std;
// # define ll long long

long double num,den,val;
long long maxi,mini;

int main(){

	int t;
	cin>>t;
	int T=1;
	while(t--){
                // Intializing
		long long N,k,n;
		cin>>N>>k;
		n=log2(k)-1;
		num=N-(pow(2,n+1)-1);
		den=pow(2,n+1); 
		val=num/den;

		if(((long long)(val))<=0){
			cout<<"Case #"<<T<<": "<<"0 0"<<endl;
			T++;
			continue;
		}

		if(((long long)(val))%2==0){
			mini=((long long)(val))/2 -1;
			maxi=((long long)(val))/2;
		}else{
			mini=((long long)(val))/2;
			maxi=((long long)(val))/2;
		}
 
		long long left=(val-((long long)(val)))*pow(2,n+1);
		// cout<<"left "<<left<<endl;
		long long temp=k-(long long)(pow(2,n+1));
		if(temp<left){
			if(maxi>mini){
				mini++;
			}else{
				maxi++;
			}
		}

		cout<<"Case #"<<T<<": "<<maxi<<" "<<mini<<endl;
		T++;
	}	

	return 0;
}
