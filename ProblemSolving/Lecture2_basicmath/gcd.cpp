unsigned int gcd(unsigned int a, unsigned int b){
    if (a<b) 
        return gcd(b,a);
    if (b==0) 
        return a;
    else  
        return gcd(b, a % b);
}