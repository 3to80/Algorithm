import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Integer;
import static java.lang.Integer.max;

public class Solution {


    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        // Test cases num
        int T = input.nextInt();
        for (int ts = 1; ts <= T; ts++) {
            int n = input.nextInt();
            int len = (n%2 == 0)?n/2: n/2+1;

            String s = input.next();

            int val = 0;
            for(int i = 0; i < len; ++i)
                val += (int)(s.charAt(i) - '0');

            int maxVal = val;
            for(int i = len; i < n; ++i){
                val += (int)(s.charAt(i) - s.charAt(i-len));
                maxVal = max(maxVal, val);
            }

            System.out.println("Case #" + ts + ": " + maxVal);



        }
    }
}
