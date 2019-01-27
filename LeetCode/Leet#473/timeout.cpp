class Solution {
public:
    /*
    @Input : Integer list
    @Output : bool
    @Problem
    - list를 4개의 disjoint set으로 나눌 때, sum이 일정하게 나눌 수 있는 지 없는지 
    @Condition
    - list len < 15
    - sum(list) < 10^9 <-> Taret V < 2.25 * 10^8
    @Logic
    
    - Bruteforce : 
     1) 합이 특정 값 K가 되게 list를 선택. 
     2) 위 과정을 4번 연속 할 수 있으면 True
     -> 4 ^ 15 가지 
     
    - Improvement :
    
    list에서 합이 K가 되는 부분집합을 반환하는 함수
    : 이 경우, 모든 걸 구하게 된다. 
    2^16 개 다 조회하며 합이 K인 것들을 찾는다. 
    여기서 이제 하나씩 다 조져나가면 된다. 

     
     
     @Draft 
     DP(bitmap, K) := 주어진 bitmap으로 K를 만들 수 있는지 없는지를 반환. 
     
     DP(bitmap) = bitmap이 1인 것들로 K를 만들 수 있는지 check 
     
    */
    bool func(vector<int>& nums, int T,  int subsum, int bitmap, int cnt){
        
        if(cnt == 4)return true;
        
        if(subsum == T) return func(nums, T, 0, bitmap, cnt+1);
        
        # bitmap이 1인 것 중에서 pick을 시작
        for(int i = 0; i < nums.size(); ++i){
            if(bitmap & (1 << i)){
                bitmap -= (1<<i);
                bool check = func(nums, T, subsum +nums[i], bitmap, cnt);
                if(check) return true;
                bitmap += (1<<i);
            }
            
        }
        return false;
        
    
    
    }
    
    // Time out이 걸림. 
    bool func2(int idx, int rem, int cnt, const vector<int> &aux){
        /*
        @Input:
            idx : [idx, ) 까지의 숫자들을 선택
            rem : 선택되어야 하는 것들은 rem에 속해야 한다. (1100 이면 100 이나 1000 이나 1100 )
            cnt : 만족을 몇번 했는지를 나타낸다.
        @Output:
            bool := 현재 idx, rem, cnt로 주어졌을 때 cnt == 0 을 만족할 수 있는지
        @Logic:
            pick : [idx, ) 인 aux[i]에 대해, aux[i]와 rem 의 xor 결과가 0 인 것에 대해 선택한다. 
            next : func2(idx, rem, cnt) = func2(idx+1, rem, cnt) || func2(idx+1, rem - nums[idx], cnt+1) 
            end : cnt == 4인 경우 true, 모든 경우가 안되면 false
        */
        
        if(cnt == 4) return true;
        
        for(int i = idx; i < aux.size(); ++i){
            // if(aux[i] ^ rem != 0) continue; // 이조건 잘못 넣음. xor시키면, 모두 다른 경우 11111이 나오게 해야지
            if((rem | aux[i]) != rem) continue; // 부분집합에 포함되는지 확인할 때 사용할 bit operation에 대한 고찰

            bool next = func2(i+1, rem - aux[i], cnt+1, aux) || func2(i+1, rem, cnt, aux);
            if(next) return true;
        }
        
        return false;
        
        
        
    }
    
    bool makesquare(vector<int>& nums) {
        
//         int n = nums.size();
//         if(n ==0) return false;
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum%4 != 0) return false;
//         int T = sum/4;
//         for(auto i : nums)if(i > T)return false;   
//         return func(nums, T, 0, (1 << n)-1, 0);

        int n = nums.size();
        if(n ==0) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%4 != 0) return false;
        int T = sum/4;
        for(auto i: nums) if(i > T) return false;
        
        
        vector<int> aux; 
        
        //@ (1<< nums.size() -1) 이랑 (1<<nums.size())- 1
        for(int i = 0 ; i < (1 << nums.size()) - 1; ++i){
            // i : 0101011
            int s = 0 ; 
            for(int j = 0; j < nums.size();  ++j)
                if(i & ( 1<< j) ) s+= nums[j]; // 이거 이러면 중복이 엄청 발생하는데, dp를 이용하면 더 빠르게 할 수 잇지 않을까
            if(s == T) aux.emplace_back(i);   // i들을 어디에 모아야 한다. i1 i2 i3 i4 가 disjoint하게 
        }
        
        if(aux.size() == 0) return false;
        // return true;
        return func2(0, (1<<nums.size())-1, 0, aux);        
            
            
        
    }
};
