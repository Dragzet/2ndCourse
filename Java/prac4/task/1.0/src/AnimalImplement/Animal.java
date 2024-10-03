package AnimalImplement;

public abstract class Animal implements Movable {

    private int _age;
    private int  _size;

    Animal(int age, int size){
        this._age = age;
        this._size = size;
    }

    public int get_age() {
        return _age;
    }

    public void set_age(int _age) {
        this._age = _age;
    }

    public int get_size() {
        return _size;
    }

    public void set_size(int _size) {
        this._size = _size;
    }

    public abstract int toHumanAge();

    @Override
    public abstract void move();
}

