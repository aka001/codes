import java.io.*;
class triangular_ranges
{
	public static void main(String args[]) throws java.lang.Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int i,val;
		long arr[]=new long[2000000];
		long val1,ans,calc,calc1,mid,low,high,l,r,q,sizeit,cnt=0,flagit;
		String input[],inputstring;

		val1=(long)1000000;
		val1=(long)val1*(long)val1;
		sizeit=0;
		arr[0]=1;
		for(i=2;i<2000000;i++)
		{
			arr[i-1]=(long)((long)i+arr[i-2]);
			if(arr[i]>=val1)
			{
				sizeit=i;
				break;
			}
		}
		sizeit=1500000;
		q=Integer.parseInt(br.readLine());
		for(i=0;i<q;i++)
		{
			ans=0;
			inputstring=br.readLine();
			input=inputstring.split(" ");
			l=Long.valueOf(input[0]);
			r=Long.valueOf(input[1]);
			assert(r-l<=1000000);
			val=0;
			while(val<=sizeit)
			{
				if(arr[val]>r)
					break;
				low=val;
				flagit=0;
				high=sizeit;
				mid=(low+high)/2;
				calc=arr[val];
				calc1=calc;
				while(low<=high)
				{
					mid=(low+high)/2;
					calc=arr[val]+arr[(int)mid];
					if(mid!=0)
						calc1=arr[val]+arr[(int)mid-1];
					if(calc==l || (calc>=l && calc1<l) || mid==0)
					{
						flagit=1;
						break;
					}
					else if(l>calc)
					{
						low=mid+1;
					}
					else
						high=mid-1;
					//if(val<=3)
					//System.out.println(mid + " " + calc + " " + calc1);
				}
				if(flagit==1)
				{
					//System.out.println(mid);
					calc=mid;
					calc1=arr[val]+arr[(int)calc];
					while(calc1<=r && calc1>=l)
					{
						ans++;
						calc++;
						//System.out.println(calc1);
						calc1=arr[val]+arr[(int)calc];

					}
				}
				val++;
			}
			System.out.println(ans);
		}
	}
}







