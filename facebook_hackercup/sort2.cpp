#include<iostream>
using namespace std;
int main(){

	int testcases,n,m=0,u=0,d=0,k=0,a[10],b[10],c[50],q=0,r=0,v=0,i=0,z=0,p=0,j=0,small=0,large=0,l=0,x=0,y=0,s=0,mx=0,temp=0;
	cin>>testcases;
	
	
	for(u=0;u<testcases;u++)
	{
	m=0,d=0,k=0,q=0,r=0,v=0,i=0,p=0,j=0,small=0,large=0,l=0,x=0,y=0,s=0,mx=0,temp=0;
		cin>>n;m=n;mx++;
		
		while(m!=0){
			d=m%10;
			m/=10;
			a[j]=d;
			j++;
		}
			for(l=0;l<j;l++){
			b[l]=a[j-1-l];
			}
	l=0;
	
			for(i=0;i<j;i++){
				for(k=0;k<j;k++){
			temp=b[k];
			b[k]=b[i];
			b[i]=temp;
			
					for(l=0;l<j;l++){
						s=(s*10)+b[l];
					
					}
					q=s;
					while(q!=0){
						r=q%10;
						q=q/10;
						p++;
					}
				if(p==j){
				
				c[v]=s;v++;
				}
				for(l=0;l<j;l++){
			b[l]=a[j-1-l];	
				}
						
		s=0;l=0;
			for(l=0;l<j;l++){
			b[l]=a[j-1-l];
			}
			p=0;
			}

	}	
	small=c[0];
	for(l=0;l<v;l++){
		if(c[l]<small)
		small=c[l];
	}
	cout<<endl<<"case #"<<(u+1)<<" "<<small;
	
	large=c[0];
		for(z=0;z<v;z++){
			if(c[z]>large)
			large=c[z];
			}
	cout<<" "<<large<<endl;
	
	for(z=0;z<50;z++){
		c[z]=0;
	}
	for(z=0;z<10;z++){
		b[z]=a[z]=0;
	}
}
}


