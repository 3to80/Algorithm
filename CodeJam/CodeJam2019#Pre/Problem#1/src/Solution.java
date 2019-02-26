import java.util.Scanner;

public class Solution {
    public static void solve(Scanner input, int a, int b) {
        // 현재 턴에서, 예측한 숫자, 예측한 숫자를 답안 시스템에 보여준다.
        int q = (a + b) / 2;
        System.out.println(q);

        // judge system에 대답이 들어온다. n번의 대답을 한다는 거겠네
        String s = input.next(); //

        if (s.equals("WRONG_ANSWER")){
            return;
        }
        if (s.equals("CORRECT")) {
            return;
        } else if (s.equals("TOO_SMALL")) {
            solve(input, q + 1, b);
        } else {
            solve(input, a, q - 1);
        }
    }

    public static void main(String args[]) {
        // standard input stream으로 들어온.
        Scanner input = new Scanner(System.in);

        // 전체 Test Case를 입력받는다.
        int T = input.nextInt();

        for (int ts= 1; ts <= T; ts++) {
            // A, B를 입력받는다.
            int a = input.nextInt(); // lo inclusive
            int b = input.nextInt(); // hi exclusive
            int n = input.nextInt(); // n, maximum number of gessess i can make

            solve(input, a + 1, b);
        }
    }
}
