# Python program to find 
# last digit of a number  
# obtained by dividing 
# factorial of a number 
# with factorial of another number. 
  
# Function which computes 
# the last digit 
# of resultant of B!/A! 
def computeLastDigit(A,B): 
  
    variable = 1
    if (A == B): # If A = B, B! = A! and B!/A! = 1 
        return 1
   
    # If difference (B - A) >= 5, answer = 0 
    elif ((B - A) >= 5):  
        return 0
   
    else:  
   
        # If non of the conditions 
        # are true, we 
        # iterate from  A+1 to B 
        # and multiply them.  
        # We are only concerned 
        # for the last digit, 
        # thus we take modulus of 10 
        for i in range(A + 1, B + 1): 
            variable = (variable * (i % 10)) % 10
   
        return variable % 10
      
# driver function 
  
print(computeLastDigit(2632, 2634)) 


"""
#include <bits/stdc++.h>
using namespace std;
long long L,R;
int ans;
int main()
{
	scanf("%lld%lld",&L,&R);
	if (R-L>=10) printf("%d\n",0);
	else
	{
		ans=1;
		for (long long i=L+1;i<=R;i++)
			ans=(1LL*ans*(i%10))%10; # multipl with last digit of i and then take last digit of i*ans
		printf("%d\n",ans);
	}
	return 0;
}

"""


############################################################33
# Python program to find 
# last non-zero digit in n! 
  
# Initialize values of 
# last non-zero digit of 
# numbers from 0 to 9 
dig= [1, 1, 2, 6, 4, 2, 2, 4, 2, 8] 
# https://math.stackexchange.com/questions/130352/last-non-zero-digit-of-a-factorial
def lastNon0Digit(n): 
    if (n < 10): 
        return dig[n] 
   
     # Check whether tens (or second last) digit 
     # is odd or even 
     # If n = 375, So n/10 = 37 and (n/10)%10 = 7 
     # Applying formula for even and odd cases. 
    if (((n//10)%10)%2 == 0): 
        return (6*lastNon0Digit(n//5)*dig[n%10]) % 10
    else: 
        return (4*lastNon0Digit(n//5)*dig[n%10]) % 10
    return 0
  
# driver code 
n = 14
  
print(lastNon0Digit(n)) 
  