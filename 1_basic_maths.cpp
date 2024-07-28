#include<bits/stdc++.h>
using namespace std;

//Counting digits

//Brute force - O(log(10)n + 1 )
int countDigits(int n){
    int cnt = 0;
    while(n > 0){
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}

//optimal - O(1)
int count_digits(int n){
    int cnt = (int)(log10(n)+1);
    return cnt;
}

//reverse a no. 
int reverseNum(int n){
    int r, revNum = 0;
    while (n > 0){
        r = n % 10;
        revNum = revNum*10 + r;
        n = n/10;
    }
    return revNum;
}

//palindrome check
bool palindromeCheck(int x){
    // Handle negative numbers and multiples of 10 (which are not palindromes)
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int revNum = 0;
    int originalNum = x;

    while (x > revNum) {
        int digit = x % 10;
        revNum = revNum * 10 + digit;
        x /= 10;
    }
    /*
    Reversing Half: No risk of overflow, number of digits being reversed is halved - so within 
    Even-Length Numbers:after reversing half, the reversed part (revNum) should be equal to the remaining part (x).
    Odd-Length Numbers:middle digit doesn't affect the palindrome property, so after reversing half, 
    the remaining part (x) should equal the reversed part without its last digit (revNum / 10).
        */
        return x == revNum || x == revNum / 10;
    }


//armstrong no. = is a number that is equal to the sum of its own digits 
//each raised to the power of the number of digits.
void armstrong (int n){
    int num = n;
    int cnt_digits = count_digits(n);
    int sum = 0;
    while (n > 0){
        int d = n % 10;
        sum = sum + (int)(pow((double)d, (double)cnt_digits));
        n = n/10;
    }

    if (num == sum)
        cout << num << " is an Armstrong number";
    else
        cout << " Not an armstring no.";
}

//prime or not
//Brute force
bool checkPrime(int n){
    int cnt = 0;
    for (int  i = 0; i <= n; i++){
        if (n%i == 0){
            cnt++;
        }
    }

    if (cnt == 2) 
        return true;
    else 
        return false;
}

//Optimal solution
bool checkPrime(int n){
    int cnt = 0;
    for (int  i = 0; i <= sqrt(n); i++){
        if (n%i == 0){
            cnt++;
        
        if (n/i != i){
            cnt++;
        }
      }
    } 

    if (cnt == 2) 
        return true;
    else 
        return false;
}

//HCF - O(min(n1, n2))
//Brute force
int HCF(int n1, int n2){
    int hcf = 1;
    for (int i = 0; i <= min(n1, n2); i++){
        if(n1%i == 0 && n2%i == 0 ){
            hcf = i;
        }
    }
    return hcf;
}

//better approach
int findHCF(int n1, int n2){
    for (int i = min(n1, n2); i > 0; i--){
        if(n1%i == 0 && n2%i == 0 && i){
            return i;
        }
    }
    return 1;
}

//optimal - euclidean algorithm
int find_hcf(int n1, int n2){
    while (n1 > 0 && n2 > 0){
        if(n1 > n2){
            n1 = n1 % n2;
        }
        else{
            n2 = n2 % n1;
        }

        if (n1 == 0){
            return n2;
        }
        return n1;
    }
}

//factors of a no.
//Brute force 
vector<int> divisors(int n){
    vector <int> d;
    for (int  i = 0; i <= n; i++){
        if (n%i == 0){
            d.push_back(i);
        }
    }
    return d;
}

//optimal
vector<int> divisors_(int n){
    vector <int> d;
    for (int  i = 0; i <= sqrt(n); i++){
        if (n%i == 0){
            d.push_back(i);

            if(n/i != i){
                d.push_back(n/i);
            }
        }
    }
    return d;
}
