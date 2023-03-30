import java.util.Arrays;
import java.util.Scanner;

public class Net {
    Scanner sc = new Scanner(System.in);
    int nNeurons;
    int nInputs;
    int nConnections;
    boolean setMeanings[];
    Neuron [] neuronArray;
    public void setNNeurons(int nNeurons) {
        if (nNeurons > 0)
            this.nNeurons = nNeurons;
    }
    Net(int nNeurons, int nInputs)
    {
        System.out.println("Enter each neurons\nThreshold Excited Braking");
        nConnections = 1;
        setNNeurons(nNeurons);
        this.nInputs = nInputs;
        this.neuronArray = new Neuron[nNeurons];
        for(int i = 0; i < nNeurons;i++) {
            int threshold = sc.nextInt();
            int nExcited = sc.nextInt();
            int nBraking = sc.nextInt();
            nConnections += nExcited + nBraking;
            this.neuronArray[i] = new Neuron(threshold, nExcited, nBraking);
            System.out.println("id:" + neuronArray[i].id);
        }

        System.out.println("network create");
        System.out.println(nConnections);
        setMeanings = new boolean[nConnections];
        Arrays.fill(setMeanings, false);
        System.out.println("Eneter conections between neurons in format: OutputID InputID type(1 - Exictied, 0 - Breaking)");
        int i = 1;
        for(; i < nConnections - nInputs; i++)
        {
            int output = sc.nextInt();
            int input = sc.nextInt();
            int type = sc.nextInt();
            if(neuronArray[output].outputID == -999 ) {
                neuronArray[output].outputID = i;
                if (type == 1)
                {
                    if(neuronArray[input].curExcited < neuronArray[input].nExcited) {
                        neuronArray[input].exitedArray[neuronArray[input].curExcited] = output;
                        neuronArray[input].curExcited++;
                        System.out.println("Connection added");
                    }else {
                        System.out.println("Error! There is no awailable excited slots in this neuron. Try again");
                        i--;
                        continue;
                    }

                }
                else
                {
                    if(neuronArray[input].curBraking < neuronArray[input].nBraking) {
                        neuronArray[input].brakingArray[neuronArray[input].curBraking] = output;
                        neuronArray[input].curBraking++;
                        System.out.println("Connection added");
                    }else {
                        System.out.println("Error! There is no awailable braking slots in this neuron. Try again");
                        i--;
                        continue;
                    }
                }
            }
            else {
                System.out.println("Error! Output is incorrect. Try agan");
                i--;
                continue;
            }
        }
        System.out.println("Eneter connections between inputs and neurons");
        for(; i < nConnections; i++)
        {
            int output = sc.nextInt();
            int input = sc.nextInt();
            int type = sc.nextInt();
            if (type == 1)
            {
                if(neuronArray[input].curExcited < neuronArray[input].nExcited) {
                    neuronArray[input].exitedArray[neuronArray[input].curExcited] = output + nConnections - nInputs;
                    neuronArray[input].curExcited++;
                    System.out.println("Connection added");
                }else {
                    System.out.println("Error! There is no awailable excited slots in this neuron. Try again");
                    i--;
                    continue;
                }

            }
            else
            {
                if(neuronArray[input].curBraking < neuronArray[input].nBraking) {
                    neuronArray[input].brakingArray[neuronArray[input].curBraking] = output + nConnections - nInputs;
                    neuronArray[input].curBraking++;
                    System.out.println("Connection added");
                }else {
                    System.out.println("Error! There is no awailable braking slots in this neuron. Try again");
                    i--;
                    continue;
                }
            }
        }
        System.out.println("Network created completly");
    }

    public void work(String vec)
    {
        char[]array = vec.toCharArray();
        for(int i = 0; i<vec.length(); i++)
        {
            if(array[i] == '0')
                this.setMeanings[i + nConnections - nInputs] = false;
            else
                this.setMeanings[i + nConnections - nInputs] = true;
        }
        for(int i = 0; i < this.nNeurons;i++)
        {
            this.setMeanings[neuronArray[i].outputID] = neuronArray[i].calcOutput(this.setMeanings);
        }
    }
}
