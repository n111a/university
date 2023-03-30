public class Heart {
    int nCells;
    Cell []cellsArray;
    int calm;
    boolean stop = false;
    Heart(int nCells)
    {
        this.nCells = nCells;
        this.cellsArray = new Cell[nCells];
        this.calm = 0;
    }
    public void addConnections(int i, int neighbour)
    {
        this.cellsArray[i].neighboursIDs.add(neighbour);
        this.cellsArray[neighbour].neighboursIDs.add(i);
        this.cellsArray[i].curPos++;
        this.cellsArray[neighbour].curPos++;
    }
    public void work(int index, int impulse, int time, int last, int max)
    {
        System.out.println();
        System.out.println("Time: " +time);
        boolean isCalm = true;
        for(int i = 0; i<nCells;i++)
        {
            this.cellsArray[i].curImpulse = this.cellsArray[i].nextImpulse;
            this.cellsArray[i].nextImpulse = 0;
        }
        if(index!=-1 && this.cellsArray[index].curImpulse < impulse) {
            this.cellsArray[index].curImpulse = impulse;
        }
        for(int i=0; i<nCells; i++)
        {
            if(this.cellsArray[i].curState!=0) {
                isCalm = false;
            }
            if(this.cellsArray[i].checkImpulse())
                for(int j:this.cellsArray[i].neighboursIDs)
                    this.cellsArray[j].nextImpulse = (this.cellsArray[j].nextImpulse < 1) ? 1:this.cellsArray[j].nextImpulse;
            if(this.cellsArray[i].curState == 0 )
                System.out.print("0 ");
            else if(this.cellsArray[i].curState == Cell.refractoriness)
                System.out.print("1 ");
            else
                System.out.print("* ");
        }
        if(isCalm)
            calm++;
        else
            calm = 0;

        if(calm == 1 && time>max)
            this.stop = true;
        if(time-last >=100)
            this.stop = true;
    }

}
