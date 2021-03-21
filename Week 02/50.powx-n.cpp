class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0)
            return 1;
        
        if(n < 0){
            n = -n; x = 1/x;
        }
        double temp = myPow(x, n/2);
        double square = temp * temp;
        return (n%2==1) ? square*x : square;  
    }
};