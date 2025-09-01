import java.text.SimpleDateFormat;
import java.util.*;
public class main2
{
public static void main(String[] args) 
{
Date date = new Date();
SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
String strDate1 = formatter.format(date);
System.out.println("Current date is : " + strDate1);
formatter = new SimpleDateFormat("MM-dd-yyyy");
String strDate2 = formatter.format(date);
System.out.println("Current date is : " + strDate2);
formatter = new SimpleDateFormat("EEEE MMMM dd yyyy");
String strDate3 = formatter.format(date);
System.out.println("Current date is : " + strDate3);
formatter = new SimpleDateFormat("E MMMM dd HH:mm:ss z yyyy");
String strDate4 = formatter.format(date);
System.out.println("Current date and time is : " + strDate4);
formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss a");
String strDate5 = formatter.format(date);
System.out.println("Current date and time is : " + strDate5);

}
}