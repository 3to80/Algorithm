# Input, Output 처리

## Interactive 형
- 아래 코드를 참조
<pre><code>
import java.util.Scanner;

public class Solution {
    public static void solve(Scanner input, int a, int b) {
        int q = (a + b) / 2;
        System.out.println(q);// judge system에 q 라는 값을 stdout으로 보낸다.  
        String s = input.next(); // judge system에 대답이 stdin으로 들어온다.
//* stdin으로 들어온 값에 따른 branch action
        if (s.equals("WRONG_ANSWER")) return;
        if (s.equals("CORRECT")) return;
        else if (s.equals("TOO_SMALL")) solve(input, q + 1, b);
        else solve(input, a, q - 1);
    }

    public static void main(String args[]) {
	// stdin 설정
	Scanner input = new Scanner(System.in);

        // 전체 Test Case를 입력받는다.
        int T = input.nextInt();
        for (int ts= 1; ts <= T; ts++) {
            // A, B를 입력받는다.
            int a = input.nextInt(); // lo inclusive
            int b = input.nextInt(); // hi exclusive
            int n = input.nextInt(); // n, maximum number of gessess i can make
            solve(input, a + 1, b); // judge system과 동작한다. 
        }
    }
}
</code></pre>

- 구글에서 testing_tool.py를 제공하면, 내 로컬 개발 환경에서 ../out/production/Problem#1 에 testing_tool.py를 넣는다.
  -.class 파일있는 곳에서 <pre><code>python testing_tool.py 클래스이름 </code></pre> 으로 사용하면 된다. 

## Non-interacitve 형

- 채점시스템은 stdin으로 input을 넣고 stdout으로 나온 string으로 답을 check 한다.

### In, out 하는 거
  - java 
  <pre><code>
import java.util.*;
import java.io.*;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Deque;

public class Solution {
    
    public static void main(String[] args) throws FileNotFoundException{
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
//        Scanner in = new Scanner(new BufferedReader(new FileReader("input")));

        long T = in.nextLong();
        for (long tt = 1; tt <= T; ++tt) {
            int ret = 0;
            System.out.flush();
            System.out.println("Case #" + tt + ": " + ret);

        }
    }
}
  </code></pre>
  - cpp
  <pre><code>
using namespace std;

int main(){
//	freopen("../input.txt","r",stdin);
    int T=0;

	cin >> T;
	for(int tt = 1; tt <=T ; ++tt){
		int ans = 0;
        	printf("Case #%d: %d\n",tt,ans);
    	}
	return 0;
}
  </code></pre>




