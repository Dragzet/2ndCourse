package AnimalImplement;

public class Sheep extends Animal{

    Sheep(int age, int size){
        super(age, size);
    }

    @Override
    public int toHumanAge(){
        return super.get_age() * 7;
    }

    @Override
    public void move(){
        System.out.println("Move the sheep.");
    }

}
