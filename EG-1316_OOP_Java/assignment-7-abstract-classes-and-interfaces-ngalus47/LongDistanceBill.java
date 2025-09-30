
public class LongDistanceBill extends PhoneBill {

	public LongDistanceBill(double monthlyRate, double callRate) {
		super(monthlyRate, callRate);
	}

	@Override
	public double calculateBill(int time) {
		// TODO Auto-generated method stub
		return super.getCallRate() * time + super.getMonthlyRate();
	}

}
