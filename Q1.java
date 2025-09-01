public class Q1
{
	public static void main(String args[])
	{
		System.out.println("First name:"+args[0]);
		System.out.println("Last name:"+args[1]);
		double weight=Double.parseDouble(args[2]);
		System.out.println(weight+"kg:");
		double height=Double.parseDouble(args[3]);
		System.out.println(height+"cm:");
		double BMI=weight/(height*height);
		System.out.println("The body mass Index is:"+BMI+"kg/m2");
	}
}