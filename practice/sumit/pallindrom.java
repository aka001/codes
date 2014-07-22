import java.io.*;
public class pallindrom
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int i=100;
		for(i=100;i<=1000;i++)
		{
			if(i%10==i/100)
				System.out.println(i);
		}
	}
}
