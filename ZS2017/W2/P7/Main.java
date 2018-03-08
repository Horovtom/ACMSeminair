package P7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * Created by lactosis on 12.10.17.
 */
public class Main {
    public static int[] counts = new int[80];
    public static int pos = 40, maxLeft = 40, maxRight = 40;
    public static StringTokenizer st;
    public static BufferedReader br;

    public static void recursive() {
        if (st.hasMoreTokens()) {
            int curr = Integer.parseInt(st.nextToken());
            if (curr == -1) return;

            maxLeft = Math.min(maxLeft, pos);
            maxRight = Math.max(maxRight, pos);
            counts[pos] += curr;
            pos--;
            recursive();
            pos += 2;
            recursive();
            pos -= 1;
        } else {
            try {
                st = new StringTokenizer(br.readLine(), " ");
            } catch (IOException e) {
                e.printStackTrace();
            }
            recursive();
        }
    }


    public static void main(String[] args) {
        int caseCounter = 1;
        br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        try {
            while ((line = br.readLine()) != null) {
                StringTokenizer st1 =new StringTokenizer(line, " ");
                if (st1.nextToken().equals("-1")) return;
                counts = new int[80];
                pos = 40;
                maxLeft = 40;
                maxRight = 40;
                st = new StringTokenizer(line," ");
                recursive();

                StringBuilder sb = new StringBuilder();
                //print
                for (int i = maxLeft; i <= maxRight; i++) {
                    sb.append(counts[i]);
                    if (i + 1 > maxRight) break;
                    else sb.append(" ");
                }

                if (sb.length() == 0) return;
                System.out.println("Case " + caseCounter++ + ":");
                System.out.println(sb.toString());
                System.out.println();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
