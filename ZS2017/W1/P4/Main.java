package P4;

import java.util.*;
import java.lang.*;

class Main {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        boolean printing = true;

        while (sc.hasNext()) {
            int num = sc.nextInt();
            if (printing) {
                if (num == 42) {
                    printing = false;
                } else {
                    System.out.println(num);
                }
            }
        }

    }
}