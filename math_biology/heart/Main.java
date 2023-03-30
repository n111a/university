import java.util.HashSet;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of cells");
        Heart heart = new Heart(sc.nextInt());
        System.out.println("Enter refractoriness");
        Cell.refractoriness = sc.nextInt();
        System.out.println("Enter number of neighbours for");
        for(int i=0; i<heart.nCells; i++)
            heart.cellsArray[i] = new Cell(sc.nextInt());
        System.out.println("Enter neighbours' IDs.");
        for(int i=0; i<heart.nCells; i++)
        {
            System.out.println("For " + i + " Cell");
            for(int j= heart.cellsArray[i].curPos; j < heart.cellsArray[i].nNeighbours; j++)
            {
                int neighbour = sc.nextInt();
                heart.addConnections(i, neighbour);
            }
        }
        System.out.println("Enter number of impulses");
        int nImpulse = sc.nextInt();
        HashSet<Integer> impulseTime = new HashSet<Integer>(nImpulse);
        int max = 0;
        for(int j:impulseTime)
            if(j>max)
                max = j;

        System.out.println("Enter time of impulse");
        for(int i=0; i<nImpulse; i++)
            impulseTime.add(sc.nextInt());
        int timeCounter = 0;
        int lastImpulse = 0;
        while(!heart.stop)
        {

            if(impulseTime.contains(timeCounter)) {
                lastImpulse = timeCounter;
                System.out.println("\nEnter index of impulse and power");
                heart.work(sc.nextInt(), sc.nextInt(), timeCounter, lastImpulse, max);
            }
            else
                heart.work(-1,-1, timeCounter, lastImpulse, max);

            timeCounter++;
        }
        System.out.println("work stopped");
    }

}
