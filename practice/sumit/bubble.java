import java.io.*;
public class bubble
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int i,n,flagit=1,temp;
		int arr[]=new int[1000];
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the length of the array");
		n=Integer.parseInt(br.readLine());
		for(i=0;i<n;i++)
			arr[i]=Integer.parseInt(br.readLine());
		while(true)
		{
			flagit=1;
			for(i=0;i<n-1;i++)
			{
				if(arr[i]>arr[i+1])
				{
					flagit=0;
					temp=arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=temp;
				}
			}
			if(flagit==1)
				break;
		}
		for(i=0;i<n;i++)
			System.out.println(arr[i]);
	}
}
