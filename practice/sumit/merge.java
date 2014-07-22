import java.io.*;
public class merge
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int i,n1,n2;
		int arr[]=new int[1000];
		int brr[]=new int[1000];
		int crr[]=new int[1000];
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the length of 1st array");
		n1=Integer.parseInt(br.readLine());
		System.out.println("Enter values of 1st array");
		for(i=0;i<n1;i++)
		{
			arr[i]=Integer.parseInt(br.readLine());
		}
		System.out.println("Enter the length of 1st array");
		n2=Integer.parseInt(br.readLine());
		System.out.println("Enter values of 1st array");
		for(i=0;i<n2;i++)
		{
			brr[i]=Integer.parseInt(br.readLine());
		}
		for(i=0;i<n1;i++)
			crr[i]=arr[i];
		for(i=0;i<n2;i++)
			crr[n1+i]=brr[i];
		System.out.println("Values in final array");
		for(i=0;i<n1+n2;i++)
			System.out.println(crr[i]);
	}
}
