####Problem
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')



#####Note

- - -
####Solution
- 유사한 글자, 


 

- - - 
####Analysis
Time complexity

Space complexity
- - -
####Discussion


        E1 = [[0] * len(word1)] * len(word2)
        E1[0][0] = 2
        E2 = [[0] * len(word1) for i in range(len(word2))]
        print(E1, E1[0] == E1[1])
        E2[0][0] = 2

[[2, 0, 0, 0], [2, 0, 0, 0]] True
[[2, 0, 0, 0], [0, 0, 0, 0]] False


위는 *로 하면, 레퍼런스 복제가 되서 저런 원치 않는 결과가 나옴 
그래서 for로 해줘야됨 
- - -
####Reference