package Operation;
public class addition
{
public int add(int a,int b)
{
return a+b;
}
public double subtract(double c,double d)
{
return c-d;
}
}

package Operation;
public class maximum
{
public int max(int a,int b)
{
if(a>b)
return a;
else
return b;
}
}

import java.util.*;
import Operation.*;
public class Slip20_2
{
public static void main(String args[])
{
addition OB=new addition();
maximum m=new maximum();
int addition=OB.add(4,5);
double sub=OB.subtract(5.7,3.4);
int maxx=m.max(7,9);
System.out.println("Addition of two integer is:"+addition);
System.out.println("Subtraction of two number is"+sub);
System.out.println("The maximum number is="+maxx);
}
}