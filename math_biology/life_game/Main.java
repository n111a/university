import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size n*m and type");
        Field field = new Field(sc.nextInt(), sc.nextInt(), sc.nextInt());
        System.out.println("Initial information received. Enter time period");
        int time = sc.nextInt();
        for (int i = 0; i <time; i++)
            field.play(i);





    }
}