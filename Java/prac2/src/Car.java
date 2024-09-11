public class Car {

    final int CURRENT_YEAR = 2024;

    private String model;
    private String license;
    private String color;
    private int year;


    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getLicense() {
        return license;
    }

    public void setLicense(String license) {
        this.license = license;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }


    public Car() {
        this.model = null;
        this.license = null;
        this.color = null;
        this.year = -1;
    }

    public Car(String model, String license, String color, int year) {
        this.model = model;
        this.license = license;
        this.color = color;
        this.year = year;
    }

    public Car(String model, int year) {
        this.model = model;
        this.license = null;
        this.color = null;
        this.year = year;
    }

    public String getCarAge() {
        if (this.year == -1)
            return "No data about age";
        return "Car age is " + (CURRENT_YEAR - this.year);
    }

    @Override
    public String toString() {
        return "MODEL: " + model + "\n" +
                "LICENSE: " + license + "\n" +
                "COLOR: " + color + "\n" +
                "YEAR: " + year;
    }
}
