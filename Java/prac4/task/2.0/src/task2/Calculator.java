package task2;

// 2 Вариант

public class Calculator implements Mathematicae{

    @Override
    public int add(int a, int b){
        return a + b;
    }

    @Override
    public int negative(int a){
        return a * (-1);
    }

    public int substract(int a, int b){
        return add(a, negative(b));
    }

    public int multiply(int a, int b){
        int result = 0;

        for (int i = 0; i < b; i++){
            result = add(result, a);
        }

        if (b < 0){
            result = negative(result);
        }

        return result;
    }

    public int divice(int a, int b){
        if (b == 0){
            return 0;
        }

        int result = 0;
        int absA = a;

        if (absA < 0){
            absA = negative(a);
        }

        int absB = b;

        if (absB < 0){
            absB = negative(b);
        }

        while (absA >= absB){
            absA = substract(absA, absB);
            result = add(result, 1);
        }

        if ((a < 0 && b > 0) || (a > 0 && b < 0)){
            result = negative(result);
        }

        return result;
    }

    public int ostat(int a, int b){
        if (b == 0){
            return 0;
        }

        int absA = a;

        if (absA < 0){
            absA = negative(a);
        }

        int absB = b;

        if (absB < 0){
            absB = negative(b);
        }

        while (absA >= absB){
            absA = substract(absA, absB);
        }

        if (a < 0){
            absA = negative(absA);
        }

        return absA;
    }




}
