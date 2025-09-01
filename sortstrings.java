import java.util.*;
  
class sortstrings
{
    public static void main(String args[])
    {
        String temp;
        Scanner s = new Scanner(System.in);
         
        System.out.print("Enter the value of N: ");
        int n= s.nextInt();
             
        String names[] = new String[n];
             
        System.out.println("Enter names: ");
        for(int i=0; i<n; i++)
        {
	    System.out.println("Enter name [ " + (i+1) +" ]:");
	    names[i] = s.nextLine();
        }
             
        //sorting strings 
         
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(names[j-1].compareTo(names[j])>0)
                {
                    temp=names[j-1];
                    names[j-1]=names[j];
                    names[j]=temp;
                }
            }
        }
         
         
        System.out.println("\nSorted names are in Ascending Order: ");
        for(int i=0;i<n;i++)
        {
            System.out.println(names[i]);
        }
    }
}