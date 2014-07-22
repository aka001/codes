import java.io.*;
public class matrix
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int i,j;
		int arr[][]=new int[3][3];
		int brr[][]=new int[3][3];
		int crr[][]=new int[3][3];
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter values of 1st array(2X2)");
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				arr[i][j]=Integer.parseInt(br.readLine());
		System.out.println("Enter values of 2nd array(2X2)");
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				brr[i][j]=Integer.parseInt(br.readLine());
		crr[0][0]=arr[0][0]*brr[0][0]+arr[0][1]*brr[1][0];
		crr[0][1]=arr[0][0]*brr[0][0]+arr[0][1]*brr[1][1];
		crr[1][0]=arr[1][0]*brr[0][0]+arr[1][1]*brr[1][0];
		crr[1][1]=arr[1][0]*brr[0][1]+arr[1][1]*brr[1][1];
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				System.out.print(crr[i][j]+" ");
			}
			System.out.println();
		}
	}
}
