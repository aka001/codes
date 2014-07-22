import java.io.*;
public class linear
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int n,i,val,flagit=0;
		int arr[]=new int[1000];
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the length of the array");
		n=Integer.parseInt(br.readLine());
		for(i=0;i<n;i++)
		{
			arr[i]=Integer.parseInt(br.readLine());
		}
		System.out.println("Enter the value to be searched");
		val=Integer.parseInt(br.readLine());
		for(i=0;i<n;i++)
		{
			if(arr[i]==val)
			{
				flagit=1;
				break;
			}
		}
		i++;
		if(flagit==1)
			System.out.println("Present at position "+i);
		else
			System.out.println("The number is not present in the array");
	}
}
