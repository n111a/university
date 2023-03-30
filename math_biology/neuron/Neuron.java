import java.util.Arrays;

public class Neuron
{
    static int number = 0;
    int threshold;
    int nExcited;
    int nBraking;
    int exitedArray[];
    int brakingArray[];
    int curExcited;
    int curBraking;
    int id;
    int outputID;
    Neuron(int threshold, int nExcited, int nBraking)
    {
        this.id = number;
        if(this.id == 0)
            outputID = 0;
        else
            outputID = -999;
        number += 1;
        setThreshold(threshold);
        setNExcited(nExcited);
        setNBraking(nBraking);
        exitedArray = new int[nExcited];
        brakingArray = new int[nBraking];
        curExcited = 0;
        curBraking = 0;
    }

    public void setThreshold(int threshold) {
        if(threshold > 0)
            this.threshold = threshold;
    }

    public void setNExcited(int nExcited) {
        if(nExcited > 0)
            this.nExcited = nExcited;
    }

    public void setNBraking(int nBraking) {
        if(nBraking >= 0)
            this.nBraking = nBraking;
    }

    public boolean calcOutput(boolean []setMeanings)
    {
        boolean []braking = new boolean[this.nBraking];
        boolean []excited = new boolean[this.nExcited];
        for(int i = 0; i<nBraking; i++)
            braking[i] = setMeanings[this.brakingArray[i]];
        for(int i = 0; i<nExcited; i++)
            excited[i] = setMeanings[this.exitedArray[i]];
        for(boolean i: braking)
            if (i)
                return false;

        int n = 0;
        for(boolean i: excited)
            if (i)
                n += 1;
        if (n < this.threshold)
            return false;
        return true;
    }
}
