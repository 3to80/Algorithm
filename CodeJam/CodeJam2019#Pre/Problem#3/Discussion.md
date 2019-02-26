# Discussion

<div>
  <img src="https://user-images.githubusercontent.com/37773080/53422935-be26f000-3a23-11e9-98ce-a4ddbbad0a2b.png">
</div>

- 이 때, K가 엄청나게 커지면 long type 이어도 OF 발생할 수 있음.
- 근데 1000009(10^6 + 9) 는 소수이므로, 페르마 소정리를 이용하면 OF를  O(logK)으로 구현가능.


<pre><code>
    static long fastPowerMOD(long base, long power ,long MOD){
        long rem = (base%MOD);
        if(power == 1) return rem;
        if(power % 2 == 0) return fastPowerMOD(rem * rem, power/2, MOD);
        return (rem * fastPowerMOD(rem, power-1, MOD)%MOD)%MOD;
    }
</code></pre>

