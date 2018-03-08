package P11;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    //private ArrayList<int[]> inputs = new ArrayList<>();
    //private ArrayList<String> answers = new ArrayList<>();


    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //br = new BufferedReader(new InputStreamReader(new FileInputStream("/home/lactosis/Documents/School/ACM/ACMSeminair/W1/P11/Input-data.txt")));
        Main m = new Main(br);
        //m.doIt();
        //m.printAnswers();
    }

    private int[] input, tempResult;




    private void getAnswerForSample() {
        this.tempResult = new int[input.length];
        int result = mergeSort(0, input.length - 1);
        if (result % 2 == 0) System.out.println("Carlos");
        else System.out.println("Marcelo");
    }

    private int mergeSort(int lowerBound, int upperBound) {
        if (lowerBound == upperBound) return 0;

        int halfPoint = (lowerBound + upperBound) / 2;
        int result = mergeSort(lowerBound, halfPoint) + mergeSort(halfPoint + 1, upperBound);



        int currentLower = lowerBound;
        int currentUpper = halfPoint + 1;
        int currentPosition = 0;

        while (currentLower <= halfPoint && currentUpper <= upperBound) {
            if (input[currentLower] < input[currentUpper]) this.tempResult[currentPosition] = input[currentLower++];
            else {
                this.tempResult[currentPosition] = input[currentUpper++];
                result += halfPoint - currentLower + 1;
            }

            currentPosition++;
        }

        //if upper half is not written whole
        if(currentLower >halfPoint) {
            System.arraycopy(input, currentUpper, this.tempResult, currentPosition, upperBound - currentUpper + 1);
        }

        //if lower half is not written whole
        if (currentUpper > upperBound) {
            System.arraycopy(input, currentLower, this.tempResult, currentPosition, halfPoint - currentLower + 1);
        }

        currentPosition = upperBound-lowerBound+1;

        //Write the result back to input.
        System.arraycopy(this.tempResult, 0, input, lowerBound, currentPosition);

        return result;
    }


    public Main(BufferedReader br) {
        //loadData(br);
        loadLine(br);
    }

    private void loadLine(BufferedReader br) {
        String line;
        try {
            while (true) {
                line = br.readLine();
                if (line.equals("0")) return;
                StringTokenizer st = new StringTokenizer(line, " ");
                int[] lineArray = new int[st.countTokens() - 1];
                st.nextToken();

                for (int i = 0; i < lineArray.length; i++) {
                    lineArray[i] = Integer.parseInt(st.nextToken());
                }

                input = lineArray;
                getAnswerForSample();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void loadData(BufferedReader br) {
        String line;

        try {
            line = br.readLine();

            while (line != null) {
                StringTokenizer tokenizer = new StringTokenizer(line, " ");
                if (tokenizer.countTokens() == 1 && line.equals("0")) {
                    return;
                }
                int[] lineNumbers = new int[tokenizer.countTokens() - 1];
                tokenizer.nextToken();
                for (int i = 0; i < lineNumbers.length; i++) {
                    lineNumbers[i] = Integer.parseInt(tokenizer.nextToken());
                }
//                inputs.add(lineNumbers);

                line = br.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
