package vehicle;

public class ElectricCar extends Car{
    private int batteryCapacity;

    public ElectricCar(String ownerName, String insuranceNumber, int batteryCapacity){
        super(ownerName, insuranceNumber, "Electric");
        this.batteryCapacity = batteryCapacity;
    }

    public int getBatteryCapacity() {
        return batteryCapacity;
    }

    public void setBatteryCapacity(int batteryCapacity) {
        this.batteryCapacity = batteryCapacity;
    }

    @Override
    public String toString() {
        return "Class: ElectricCar\n" +
                "Owner: " + this.getOwnerName() + "\n" +
                "Insurance Number: "+ this.getInsuranceNumber() + "\n" +
                "Engine Type: " + this.engineType + "\n" + //Можем обратиться к engineType без геттера, так как он protected и мы в пакете vehicle
                "Battery: " + this.batteryCapacity + "\n";
    }
}
