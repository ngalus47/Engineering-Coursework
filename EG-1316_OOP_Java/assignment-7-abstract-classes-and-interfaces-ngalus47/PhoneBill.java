public abstract class PhoneBill {

	private double monthlyRate;
	private double callRate;

	public PhoneBill() {
		super();
	}

	public PhoneBill(double monthlyRate, double callRate) {
		this.monthlyRate = monthlyRate;
		this.callRate = callRate;
	}

	public double getMonthlyRate() {
		return monthlyRate;
	}
	
	public double getCallRate() {
		return callRate;
	}

	public abstract double calculateBill(int time);
}