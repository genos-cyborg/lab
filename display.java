import java.io.*;
class display
 {
public static void main(String args[]) throws Exception
   {
FileInputStream f=new FileInputStream("temp.txt");
 int n;
System.out.println("Total bytes available in file:" +f.available());
while((n=f.read())!=-1)
{
  System.out.print((char)n);
 
}
 f.close();
}}
