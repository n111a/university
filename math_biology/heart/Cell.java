import java.util.HashSet;
public class Cell
{
    int curImpulse;
    int nextImpulse;
    int curState;
    static int refractoriness;
    int nNeighbours;
    int curPos;
    HashSet<Integer> neighboursIDs;
    Cell(int nNeighbours)
    {
        this.nNeighbours = nNeighbours;
        this.neighboursIDs = new HashSet<Integer>(nNeighbours);
        this.curState = 0;
        this.curImpulse = 0;
        this.nextImpulse = 0;
        this.curPos = 0;
    }
    public boolean checkImpulse()
    {
        if(this.curState < this.curImpulse) {
            this.curState = refractoriness;
            return true;
        }
        else
            if(this.curState > 0)
                this.curState--;
        return false;
    }
}