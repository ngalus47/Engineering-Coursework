import java.util.Scanner;

public class TestPhoneBill {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("This program will calculate your phone bill for you");
		System.out.println("What is your call rate?");
		
		double callRate = Double.parseDouble(input.nextLine());
		
		System.out.println("What is your montly rate?");
		
		double monthlyRate = Double.parseDouble(input.nextLine());
		
		PhoneBill bill = new LongDistanceBill(monthlyRate, callRate);
		
		System.out.println("How many minutes did you talk?");
		
		int minutes = Integer.parseInt(input.nextLine());
		
		System.out.printf("Your monthly bill is $%.2f", bill.calculateBill(minutes));

		input.close();
	}
}
