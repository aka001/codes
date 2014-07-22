import java.io.*;
public class gcd
{
	public static void main(String args[]) throws java.lang.Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int a=Integer.parseInt(br.readLine());
		int b=Integer.parseInt(br.readLine());
		int temp,i,answer=1;
		if(b>a)
		{
			temp=a;
			a=b;
			b=temp;
		}
		for(i=1;i<=a;i++)
		{
			if(a%i==0 && b%i==0)
			{
				answer=i;
			}
		}
		System.out.println(answer);
	}
}
