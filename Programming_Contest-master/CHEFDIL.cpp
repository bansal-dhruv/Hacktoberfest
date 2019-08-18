#include<bits/stdc++.h>
using namespace std;
long long ans,xr,a[100005],sz,coeff,temp,sum[100005],diff;
long long j;
vector<long long >  v[1999999];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(long long i=2;i<=100001;i++){
		sum[i]=sum[i-1]+ (long long)(((i-1)*i)/2);
	}

	set<long long > st;
	set <long long > :: iterator itr; 

	int t;
	cin>>t;
	while(t--){

		st.clear();
		ans=0;
		diff=0;
		int n;
		cin>>n;
		
		for(long long i=0;i<n;i++){
			cin>>a[i];

			if(i==0){
				xr=a[0];
				// continue;
			}else if(i==1){
				xr=a[0]^a[1];
				v[a[0]].push_back(1);
				v[xr].push_back(2);
			}else if(i>1){
				xr=xr^a[i];
				if(v[xr].size()==0){
					v[xr].push_back(i+1);	
				}else{
					v[xr].push_back(i-v[xr][0]);
					v[xr][0]=i+1;
				}
			}
			// cout<<xr<<" ";
			if(xr==0){
				ans+=i;
			}

			st.insert(xr);
		}
		// cout<<"**"<<ans<<endl;
		for (itr = st.begin(); itr != st.end(); itr++){ 
			xr=*itr;	

			if(v[xr].size()<=1){
				v[xr].clear();
				continue;
			}

			// cout<<xr<<" -- ";
			// ans=0;

			if((v[xr].size()-1)%2==0){

				j=1;
				sz=(v[xr].size()-1);
				temp=(long long)sz/2;
				coeff=sz;
				diff=sz-2;
				while(temp--){
					ans+=coeff*v[xr][j];
					coeff+=diff;
					diff-=2;
					j++;
				}

				temp=(long long )sz/2;
				diff=2;
				while(temp--){
					ans+=coeff*v[xr][j];
					coeff-=diff;
					diff+=2;
					j++;
				}

			}else{
				j=1;
				sz=(v[xr].size()-1);
				temp=(long long )sz/2;
				coeff=sz;
				diff=sz-2;
				while(temp--){
					ans+=coeff*v[xr][j];
					coeff+=diff;
					diff-=2;
					j++;
				}

				ans+=coeff*v[xr][j];
				j++;
				coeff--;

				temp=(long long)sz/2;
				diff=3;
				while(temp--){
					ans+=coeff*v[xr][j];
					coeff-=diff;
					diff+=2;
					j++;
				}
			}	

			ans+=sum[v[xr].size()-1];	
			v[xr].clear();

		}
		st.clear();
		cout<<ans<<endl;
	}
	return 0;
}
