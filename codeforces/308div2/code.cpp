#include <stdio.h>

int main()
{
	int T;
	long int n;
   char c[1000000];
   int a[1000000]={0};
  long  int sum[1000000]={0};
   long int i=0,Max=0,Maxi=0,Maxs=0,Mnr=0;// Max value, start and last index and maximum number of r's
   scanf("%d",&T);
  
   while(T>0){
   		i=0;
   		scanf("%s",c);
   		n=strlen(c);
   	
   		while(i<n){
			if(c[i]=='R')
				a[i]=-1;
			else
				a[i]=1;
			
			i++;
   		}
   	
   	
   		Max=a[0];
  		sum[0]=a[0];
  		i=1;
  		
  		while(i<n){
	
   			if(a[i]>a[i]+sum[i-1]){
   				sum[i]=a[i];
   				printf("%ld",sum[i]);
   			
   			}
   			else{
   				sum[i]=a[i]+sum[i-1];
   			}
   			if(sum[i]>Max){
   				Max=sum[i];
   				Maxi=i;
 
   			}
   		
   			i++;
   		}

	T--;   		
}
    return 0;
}
