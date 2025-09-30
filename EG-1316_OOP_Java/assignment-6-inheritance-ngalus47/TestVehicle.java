/**
 * The TestVehicle class demonstrates the creation and display of different types of vehicles:
 * a Car, a Truck, and a Tank.
 * It creates instances of each and prints their details.
 */
public class TestVehicle {

    /**
     * The main method instantiates and displays different vehicle types.
     *
     * @param args command line arguments (not used)
     */
    public static void main(String[] args) {
        Car honda = new Car(2006, 2100.56, "1RT245", "Honda", 5);
        Truck truck = new Truck(2009, 2500.45, "2TU123", "Dodge", 1200.0);
        Tank tank = new Tank(2011, 7000.56, 4.56);

        System.out.println(honda);
        System.out.println(truck);
        System.out.println(tank);
    }
}
