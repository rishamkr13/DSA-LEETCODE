class Solution {
public:
    // int g(int a , int b){
    //     if(b==0){
    //         return a;
    //     }
    //     return gcd(b,a%b);

    // }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int N= n;
        while(n>0){
            sumOdd+=(2*n-1);
            n--;
        }
        int sumEven=N*(N+1);
        return __gcd(sumOdd,sumEven);
        
        

        
    }
};