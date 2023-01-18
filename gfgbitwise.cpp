#include<iostream>
using namespace std;

//check if kth bit is set or not...
//method 1(naive approach)
bool bit1(int n , int k)
{
    int x=1;
    for(int i=0;i<(k-1);i++) 
    x=x*2;

    if(n&x!=0)
    return true;
    else
    return false;
}

//dividing n/2^k-1 
bool bit2(int n , int k)
{
    for(int i=0;i<(k-1);i++) //k=3  n=5/2=2/2=1 101
    n=n/2;

    if(n&1!=0)
    return true;
    else
    return false;
}

//left shift is equivalent to power...
bool bit3(int n , int k)
{
    int x=(1<<(k-1));//2^(k-1) 010 100
    if(n&x!=0)
    return true;
    else
    return false;
}


// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     cout<<bit1(n,k);
// }


// count the set bits....
// tc: theta(d) d=no. of bits from last to msb...
int count_set1(int n)
{
    int count=0;
    // while(n>0)
    // {
    //     if(n&1==1) //n%2==1   
    //     count++;
    //     n=n/2;
    // }
    //can also be done like below
    while(n>0)
    {
        count+=(n&1);
        n=n/2;
    }
    return count;
}



// when we subtract all trailing zeros becomes 1 and last 1 becomes 0 eg: 40=101000 
//                   39=100111
//unsetting the rightmost setbit
//brian kerningam's algorithm....
//tc: theta(set bits)....
int count_set2(int n)
{
    int count=0;
    while(n>0)
    {
        count++;
        n=n & (n-1); 
    }
    return count;
}


//optimized approach...
//lookup table method..
//tc:o(1)
int tbl[256];
void initialize()
{
    tbl[0]=0;
    for(int i=1;i<256;i++)
        tbl[i]=tbl[i & (i-1)]+1; 
}

int count_set3(int n)
{
    return  tbl[n & 255] + 
            tbl[n>>8 & 255] + 
            tbl[n>>16 & 255] + 
            tbl[n>>24];
}

// int main()
// {
//     int n;
//     cin>>n;
//     initialize();
//     cout<<count_set3(n);
// }


// is power of 2 or not...

int power1(int n)
{
    if(n==0) return false;
    while(n!=1)
    {
        if(n%2!=0)
        return false;
        n=n/2;
    }
    return true;
}

int power2(int n)
{
    if(n==0) return 0;
    return ((n&(n-1))==0);//brian kerningam's algorithm....

    //to combine both conditions
    return (n&&((n&(n-1))==0));

}

// int main()
// {
//     int n;
//     cin>>n;
//     cout<<power2(n);
// }


//one odd occurence of number
// naive approach
//tc:o(n^2)
int odd1(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            count++;
        }
        if(count%2!=0)
        return arr[i];
    }
    return 0;
}

//optimized...
//tc:o(n) sc:o(1)
//can be done using hashing with o(n) tc & sc but this is best approach...
int odd2(int arr[],int n)
{
    int x=arr[0];  
    for(int i=1;i<n;i++)
    {
        x=x^arr[i];
    }
    return x;
}

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     cout<<odd2(arr,n);
// }


//two or more odd occurence of number
// naive approach
//tc:o(n^2)
void two_odd(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            count++;
        }
        if(count%2!=0)
        cout<<arr[i]<<" ";
    }
}


//optimized...
//tc:o(n) sc:o(1)
//can be done using hashing with o(n) tc & sc but this is best approach...
//exact 2 occurings only...

void two_odd2(int arr[], int n)
{
    int xors = 0, res1 = 0, res2 = 0; 
    
    for (int i = 0; i < n; i++) 
    xors = xors ^ arr[i]; 

    int sn = xors & (~(xors - 1)); 

    for (int i = 0; i < n; i++) 
    { 
        if ((arr[i] & sn) != 0) 
            res1 = res1 ^ arr[i]; 
        else
            res2 = res2 ^ arr[i]; 
    } 
    cout <<  res1 << " " << res2;
}

// find the missing number.....
 int missingNumber(int nums[],int N) {
    int sum1=N*(N+1)/2,sum2=0;
    for(int i=0;i<N;i++)
    {
        sum2+=nums[i];       
    }
    return sum1-sum2;

    //method 2... 
    // int miss = 0;
    // for(int i=1; i<=N; i++) {
    //     miss = miss ^ i;
    //     miss = miss ^ nums[i];
    // }
   
    }

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     two_odd2(arr,n);
//     // missingNumber(arr,n);
// }


//power set
//tc:theta(2^n*n)...
#include <iostream>
#include <cmath>
using namespace std;

void printPowerSet(string str)
{
	int n = str.length();

	int powSize = pow(2, n);

	for(int counter = 0; counter < powSize; counter++)
	{
		for(int j = 0; j < n; j++)
		{
			if((counter & (1 << j)) != 0)
                cout<<str[j];
		}
		
		cout<<endl;
	}
}
    

    
int main() {
	
	string s = "abc";

    printPowerSet(s);  
    
}
