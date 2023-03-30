import java.util.Arrays;
import java.util.Scanner;

public class Field
{
    static Scanner sc = new Scanner(System.in);
    int n;
    int m;
    int type;
    int newLife;
    int loneliness;
    int overpopulation;
    int lifeTime;
    boolean neighbours;
    int [][]Array1;
    int [][]Array2;
    Field(int n, int m, int type)
    {
        this.n = n;
        this.m = m;
        this.type = type;
        this.Array1 = new int[n+2][m+2];
        this.Array2 = new int[n+2][m+2];
        for(int i = 0; i < n+2;i++)
        {
            Arrays.fill(this.Array1[i], -1);
            Arrays.fill(this.Array2[i], -1);
        }
        if (type == 3)
        {
            System.out.println("Enter rules: NewLife Loneliness Overpopulation LifeTime(0 if infinity) Neighbours(8 - 1; 4 - 0)");
            this.setParams(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
        }
        else
            this.setParams(3, 2, 3, 0, type);
        System.out.println("Enter number of Life Cells");
        this.setLifeCells(sc.nextInt());

    }
    public void setParams(int newLife,int loneliness, int overpopulation, int lifeTime, int neighbours)
    {
        this.newLife = newLife;
        this.loneliness = loneliness;
        this.overpopulation = overpopulation;
        this.lifeTime = lifeTime;
        this.neighbours = (neighbours == 1) ? true: false;
    }
    public void setLifeCells(int number)
    {
        System.out.println("Enter life coordnations");
        for(int i = 0; i < number; i++) {
            this.Array1[sc.nextInt() + 1][sc.nextInt() + 1] = 0;
        }
    }
    public void play(int time)
    {
        this.print(time);
        int cur;
        for(int i = 1; i < this.n+1; i++) {
            for (int j = 1; j < this.m + 1; j++) {


                if (this.neighbours)
                    cur = ((Array1[i + 1][j + 1] >= 0) ? 1 : 0) + ((Array1[i + 1][j] >= 0) ? 1 : 0) + ((Array1[i - 1][j + 1] >= 0) ? 1 : 0) + ((Array1[i][j + 1] >= 0) ? 1 : 0) + ((Array1[i + 1][j - 1] >= 0) ? 1 : 0) + ((Array1[i - 1][j - 1] >= 0) ? 1 : 0) + ((Array1[i][j - 1] >= 0) ? 1 : 0) + ((Array1[i - 1][j] >= 0) ? 1 : 0);
                else
                    cur = ((Array1[i + 1][j] >= 0) ? 1 : 0) + ((Array1[i - 1][j] >= 0) ? 1 : 0) + ((Array1[i][j+1] >= 0) ? 1 : 0) + ((Array1[i][j-1] >= 0) ? 1 : 0);
                if(this.Array1[i][j] == -1)
                {
                    if (cur == this.newLife)
                        this.Array2[i][j] = 0;
                    else
                        this.Array2[i][j] = -1;
                }
                else
                {
                    if ((cur > this.overpopulation || cur < this.loneliness) || (this.Array1[i][j]  + 1 >= this.lifeTime && this.lifeTime != 0))
                        this.Array2[i][j] = -1;
                    else
                        this.Array2[i][j] = this.Array1[i][j] + ((this.lifeTime == 0) ? 0 : 1);

                }
            }
        }
        for(int i = 0; i<this.n+1; i++)
            for(int j = 0; j<this.m+1; j++)
            {
                this.Array1[i][j] = this.Array2[i][j];
            }

    }
    public void print(int time)
    {
        System.out.println("Time:" + time);
        for(int i = 0; i<this.n+2; i++) {
            for (int j = 0; j < this.m + 2; j++)
            {
                if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                    System.out.print(" * ");
                else if (this.Array1[i][j] == -1)
                    System.out.print(" - ");
                else
                    System.out.print(" + ");
            }
            System.out.println();
        }
    }
}
