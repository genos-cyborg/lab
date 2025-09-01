interface PrintNumber
{
	public void print(int numl);
}
public class PrintSquare
{
	public static void main(String[] args)
	{
		PrintNumber p = n-> System.out.println("Square is: "+n*n); 
		p.print(25);
	}
}