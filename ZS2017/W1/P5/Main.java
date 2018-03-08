package P5;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Created by lactosis on 6.10.17.
 */
public class Main {
    ArrayList<String> output = new ArrayList<String>();
    BufferedReader br;

    public Main(BufferedReader br) {
        this.br = br;
    }

    public void doIt() throws IOException {
        //Read line by line (Tokenize into 2 strings)
        String line;
        while ((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            String first = st.nextToken();
            String second = st.nextToken();

            //Suppose i have first and second number:
            //2,A - they will never be equal
            //9,C - C is from base that certainly has C, so base 13 minimum, 9 is from base that certainly has 9, so 9 at minimum.
            //9,C - they will never be the same number.

            //SOLUTION: If it is a single digit, if two digits are not equal, they will never be equal
            /*
            If one of them is not a single digit, start iterating combinations, for each base of first number,
            for each base of second number, if the second number is already larger than the first number, break first loop
             */


        }
    }

    public static void main(String[] args) throws IOException {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            br = new BufferedReader(new InputStreamReader(new FileInputStream("/home/lactosis/Documents/School/ACM/ACMSeminair/W1/P5/Input-data.txt")));
            Main m = new Main(br);
            m.doIt();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }
}
