package Student;
public class studentPer
{
int S1M,S2M,S3M,S4M,S5M,S6M,total;
float per;//S1M-subject 1 marks and so on
public studentPer(int s1,int s2,int s3,int s4,int s5,int s6)
{
S1M=s1;
S2M=s2;
S3M=s3;
S4M=s4;
S5M=s5;
S6M=s6;
total=S1M+S2M+S3M+S4M+S5M+S6M;
per=total/12;
}
public float getPer()
{
return per;
}
}

import Student.*;
import java.util.*;

class studentInfo
{
int rno;
String Sname,Sclass;
//float per;
studentPer p;
studentInfo(int rno,String Sname,String Sclass,int s1,int s2,int s3,int s4,int s5,int s6)
{
this.rno=rno;
this.Sname=Sname;
this.Sclass=Sclass;
p=new studentPer(s1,s2,s3,s4,s5,s6);
//per=p.getPer();
}
public void display()
{
System.out.println("Roll no="+rno);
System.out.println("Name="+Sname);
System.out.println("Class="+Sclass);
System.out.println("Percentage="+p.getPer());
}
}

public class Slip10_2
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter Student Roll NO.=");
int r=sc.nextInt();
System.out.println("Enter Student Name=");
String n=sc.next();
System.out.println("Enter Student class=");
String c=sc.next();
System.out.println("Enter Student Marks of 6 subject=");
int s1=sc.nextInt();
int s2=sc.nextInt();
int s3=sc.nextInt();
int s4=sc.nextInt();
int s5=sc.nextInt();
int s6=sc.nextInt();
studentInfo s=new studentInfo(r,n,c,s1,s2,s3,s4,s5,s6);
s.display();
}
}