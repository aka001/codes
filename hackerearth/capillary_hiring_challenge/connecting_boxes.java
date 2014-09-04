/*******************
  Akash Agrawall
  IIIT HYDERABAD
  akash.agrawall094@gmail.com
 ***********************/
import java.io.*;
import java.text.*;
class connecting_boxes
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int arr[]=new int[1000006];
		int brr[]=new int[1000006];
		int n,a,b,i,n1,n2,j,q,sizeit,x,y,flagit,temp,cnt=0;
		String inputstring;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		inputstring=br.readLine();
		String[] input=inputstring.split(" ");
		n=Integer.valueOf(input[0]);
		q=Integer.valueOf(input[1]);
		//	printf("q=%d\n",q);
		for(i=0;i<q;i++)
		{
			flagit=1;
			sizeit=i;
			inputstring=br.readLine();
			input=inputstring.split(" ");
			a=Integer.valueOf(input[0]);
			b=Integer.valueOf(input[1]);
			//System.out.println(a+" "+b);
			if(a==b)
			{
				System.out.println("NO");
				continue;
			}
			for(j=0;j<cnt;j++)
			{
				x=arr[j];
				y=brr[j];
				if(x>y)
				{
					temp=x;
					x=y;
					y=temp;
				}
				if(y!=n)
					n1=n+1;
				else
					n1=n;
				if(x!=1)
					n2=0;
				else
					n2=n;
				/*if(!((a>x && a<y && b>x && b<y)))
				  printf("NO1 x=%d y=%d\n",x,y);
				  if(!(  ((a<x && a>n2) || (a>y && a<n1)) && ((b<x && b>n2) || (b>y && b<n1))  ))
				  printf("NO2 x=%d y=%d\n",x,y);*/
				if(!((a>x && a<y && b>x && b<y) || (  ((a<x && a>n2) || (a>y && a<n1)) && ((b<x && b>n2) || (b>y && b<n1))  )))
				{
					flagit=0;
					break;
				}
			}
			//printf("i=%d q=%d\n",i,q);
			if(flagit==0)
			{
				System.out.println("NO");
			}
			else
			{
				System.out.println("YES");
				arr[cnt]=a;
				brr[cnt]=b;
				cnt++;
			}
		}
	}
}





