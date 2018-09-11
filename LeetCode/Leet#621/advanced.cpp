class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int arr[26];
        memset(arr, 0, sizeof(int) * 26);
        for(auto i: tasks) arr[i-'A']++;
        int maxCnt = -987654321;
        for(auto i: tasks)maxCnt = max(maxCnt, arr[i-'A']);
        int maxSpecies = 0;
        for(int i = 0; i < 26; ++i) if(arr[i] == maxCnt) maxSpecies++; 
        

        //******** 전체 = tasks.size() + idle의 개수 *******
	// 제일 개수 많은 문자는 서로 n의 거리를 가져야 한다. 최소 거리를 만들려는 것이므로 
	// 만약 개수 제일 큰 문자들이 여러개이면 걔들이 하나의 set으로 묶여서 들어가는거라고 생각하면 된다. 

        // idle의 개수 = (maxCnt-1) * (n+1 - maxSpecies) - 들어가는 남은 것들
	// set 당 거리는 가장 많은 것들을 넣을 때 거리가 n으로 벌려져있으므로 남은 것들은 idle을 제거.
        
        // cout << maxCnt << " " << maxSpecies << " " << endl;
        int remainder = tasks.size() - maxCnt * maxSpecies;
        int numIdle = (maxCnt-1) * (n+1 - maxSpecies) - remainder;
        return tasks.size() + max(numIdle, 0);
        
        

        

    }
};
