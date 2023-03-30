import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of neurons and number of inputs");
        int numberNeurons = sc.nextInt();
        int numberInputs = sc.nextInt();
        Net myNetwork = new Net(numberNeurons, numberInputs);
        System.out.println(myNetwork.neuronArray.length);
        String vector = sc.nextLine();
        while(!vector.equals("stop")) {
            if(vector.length() == myNetwork.nInputs) {
                myNetwork.work(vector);
                System.out.println(myNetwork.setMeanings[0]);
            }
            vector = sc.nextLine();
        }
    }
}
