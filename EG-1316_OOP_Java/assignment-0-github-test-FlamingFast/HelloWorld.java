public class HelloWorld 
{
    public static void main(String[] args)
    {
        String message = "Hello World";
        String name = "Nick Galus"; //type your name
        System.out.println(message + ", my name is " + name);
        
        System.out.println("Objects I use in my daily life:");
        
        // Add your answers as comments below:
        /* 
        1. List three objects you use in your daily life:
        
        2. For one of these objects, list:
           - Three properties (characteristics) of this object
           - Three actions you can do with this object
        
        3. What was the most interesting program you wrote in your C programming course?
        */
        String[] daily = {"Phone", "Computer", "Toothbrush"};
        
        for(int i = 0; i < 3; i++)
        {
        	System.out.print("\t*\t" + daily[i]);
        	
        	if(daily[i] == "Computer")
        	{
        		System.out.println("\n\t\t\tCharacteristics:");
        		
        		String[] characterisitcs = {"Green", "Lenovo", "I9"};
        		
        		for(int j = 0; j < 3; j++)
                {
        			System.out.println("\t\t\t-\t" + characterisitcs[j]);
                }
        		
        		System.out.println("\n\t\t\tActions:");
        		
        		String[] actions = {"Internet", "Homework", "Programming"};
        		
        		for(int j = 0; j < 3; j++)
                {
        			System.out.println("\t\t\t-\t" + actions[j]);
                }
        		
        		System.out.println();
        	}
        	else
        		System.out.println();
        }
        
        System.out.println("\nMost intersting C program was our year long project of programming a car that was controlled remotely through a Raspberry PI 400.");
    }
}