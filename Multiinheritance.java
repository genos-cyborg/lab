import java.util.*;
import java.io.*;
class continent
{
	protected String cont;
	void get()
	{
		cont="asia";
	}
}
class country extends continent
{
	protected String cname;
	void accept()
	{
		cname="India";
	}
}
class state extends country
{
	protected String sname;
	void accept1()
	{
		sname="Maharashtra";
	}
}
class place extends state
{
	protected String pname;
	void accept2()
	{
		pname="Nashik";
	}

	void show()
	{
		System.out.println("Continent is:"+cont);
		System.out.println("Country is:"+cname);
		System.out.println("State is:"+sname);
		System.out.println("Place is:"+pname);
	}
}
class Multiinheritance
{
	public static void main(String arg[])
	{
		place t=new place();
		t.get();
		t.accept();
		t.accept1();
		t.accept2();
		t.show();
	}
}

