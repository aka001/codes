import java.io.*;
import java.math.*;
public class perfect
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int i,val,sqrtit,sum=0;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the given number");
		val=Integer.parseInt(br.readLine());
		sqrtit=(int)Math.sqrt(val);
		for(i=1;i<=sqrtit;i++)
		{
			if(val%i==0)
				sum+=i;
		}
		if(sum==val)
			System.out.println("Perfect Number");
		else
			System.out.println("Not a perfect number");
	}
}
