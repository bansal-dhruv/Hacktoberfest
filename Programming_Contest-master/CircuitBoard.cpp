#include<bits/stdc++.h>
using namespace std;
# define ll long long

long long W,H,I,maxi,val[400][400],x[400][400],r,c,k,T=1,J,larg,small;
int main(){

	int t;
	cin>>t;
	while(t--){
		cin>>r>>c>>k;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>val[i][j];
			}
		}		

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){				
				x[i][j]=0;
				J=j;
				larg=val[i][J];
				small=val[i][J];
				while(J>=0){
					larg=max(larg,val[i][J]);
					small=min(small,val[i][J]);

					if(abs(larg-small)<=k){
						x[i][j]++;
					}else{
						break;
					}

						J--;
				}

				// cout<<x[i][j]<<" ";
			}
// 			cout<<endl;
		}

		maxi=r;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				I=i;
				H=1;
				W=x[i][j];
				while(I>=0){
					W=min(W,x[I][j]);
					maxi=max(maxi,H*W);
					I--;
					H++;
				}
			}
		}


		cout<<"Case #"<<T<<": "<<maxi<<endl;
		T++;

	}	

	return 0;
