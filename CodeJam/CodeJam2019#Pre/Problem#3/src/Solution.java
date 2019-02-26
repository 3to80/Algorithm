
import java.math.BigDecimal;
        import java.util.*;
        import java.io.*;

import java.io.FileNotFoundException;
public class Solution {


    static long N;
    static long K;
    static long C;
    static long D;
    static long E1;
    static long E2;
    static long F;
    static long MOD = (long)Math.pow(10, 9) + 7;

//    static long fastPower(long base, long power){ //
//        if(power == 0) return 1;
//        if(power % 2 == 0) return fastPower((base * base), power/2);
//        else return base* (fastPower(base , power-1));
//    }
    static long fastPowerMOD(long base, long power ,long MOD){
        long rem = (base%MOD);
        if(power == 1) return rem;
        if(power % 2 == 0) return fastPowerMOD(rem * rem, power/2, MOD);
        long tmp = fastPowerMOD(rem, power-1, MOD);
        return (rem * tmp)%MOD;

    }



    static long powerSum(long base){
        if(base == 1) return K;
        long rem = base%MOD;
        return rem * (fastPowerMOD(rem , K, MOD)-1)%MOD * fastPowerMOD((rem -1)%MOD, MOD-2, MOD);
    }
    static long updateX(long x, long y){
        return ((C *x) + (D * y) + E1)%F;
    }
    static long updateY(long x, long y){
        return ((D *x) + (C * y) + E2)%F;
    }
    public static void main(String[] args) throws FileNotFoundException{



//        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        Scanner in = new Scanner(new BufferedReader(new FileReader("input")));

        long T = in.nextLong();
        for (long tt = 1; tt <= T; ++tt) {
            N = in.nextLong();
            K = in.nextLong();
            long x = in.nextLong();
            long y = in.nextLong();
            C = in.nextLong();
            D = in.nextLong();
            E1 = in.nextLong();
            E2 = in.nextLong();
            F = in.nextLong();

            long ret = 0;
            long coef = 0;


            for(long i = 1; i < N+1; ++i){
                long A = (x+y)%F;
                coef += (powerSum(i)%MOD);
                ret += (A *(N+1-i) * (coef%MOD));
                ret %= MOD;
                long prevx = x; long prevy = y;
                x = updateX(prevx, prevy);
                y = updateY(prevx, prevy);

            }
            System.out.flush();
            System.out.println("Case #" + tt + ": " + ret);
            System.out.flush();

        }
    }
}