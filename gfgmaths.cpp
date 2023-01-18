#include<bits/stdc++.h>
using namespace std;

//count number
// int main()
// {
//     int x;
//     cin>>x;
//     int count=0;
//     while(x>0)
//     {
//         x=x/10;
//         count++;
//     }
//     cout<<count;
// }


//plaindrome

// int main()
// {
//     int x;
//     cin>>x;
//     int y=x;
//     int res=0;
//     while(y>0)
//     {
//         res=res*10+y%10;
//         y=y/10;
//     }
//     cout<<res;
//     if(x==res)
//         cout<<"yes";
//     else
//         cout<<"no";
// }


// factorial

int fact1(int x)
{
    if(x==0)
        return 1;
    
    return x*fact1(x-1);
}

int fact2(int x)
{
    if(x==0 || x==1)
    return 1;
    int res=1;
    for(int i=2;i<=x;i++)
    {
        res=res*i;
    }
    return res;
}

// int main()
// {
//     int n;
//     cin>>n;
//     int r;
//     r=fact2(n);
//     cout<<r;

    //for trailing zero...
    // int count=0;
    // while(r%10==0)
    // {
    //     count++;
    //     r=r/10;
    // }
    
    // cout<<count;

// }

//for trailing zero...
int counttrailing0(int x)
{
    int fact=1;
    for(int i=2;i<=x;i++)
        fact=fact*i;
    int res=0;
    while(fact%10==0)
    {
        res++;
        fact=fact/10;
    }
    return res;
}

// int main()
// {
//     int n;
//     cin>>n;
//     cout<<counttrailing0(n);
// }

// efficient 
int trail(int n)
{   int count=0;
    for(int i=5;i<=n;i*=5)
    {
       count=count + (n/i);
    }
    return count;
}

// int main()
// {
//     int n;
//     cin>>n;

//     cout<<trail(n);

//     return 0;
// }

//hcm or gcd...
int gcd(int a,int b)
{
    int m=min(a,b);
    int x;
    for(int i=1;i<=m;i++)
    {
        if(a%i==0 && b%i==0)
            x=i;
    }
    return x;
}

int egcd(int a , int b)
{
    if(b==0)
        return a;
    else
        return egcd(b,a%b);
}


// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     cout<<egcd(a,b);
// }


//lcm 
int lcm1(int a,int b)
{
    int res=max(a,b);
    while(true)
    {
        if(res%a==0 && res%b==0)
        {
            return res;
        }
        res++;
    }
}

int lcm2(int a,int b)
{
    int l;
    l=(a*b)/egcd(a,b);

    return l;
}

// int main()
// {
//     int a,b;
//     cin>>a>>b;

//     cout<<lcm2(a,b);

//     return 0;
// }

//is prime...
int prime1(int n)
{
    if(n==1) return false;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int prime2(int n)
{
    if(n==1) return false;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int prime(int n)
{
    if(n==2 || n==3)
        return true;
    if(n==1)
        return false;
    if(n%2==0 || n%3==0)
        return false;
    for(int i=5;i*i<n;i=i+6)
    {
        if(n%i==0 || n%(i+2))
            return false;
    }
    return true;
    
}

// int main()
// {
//     int n;
//     cin>>n;

//     for(int i=2;i<=n;i++)
//     {
//         if(prime(i))
//         {   
//             if(n%i==0)
//             {
//                 cout<<i<<" ";
//             }
//         }
//     }
//     // cout<<prime(n);
// } 


//prime factors....

//naive soln...
//tc = o(n^2 logn)
void primefactor1(int n)
{
    for(int i=2;i<n;i++)
    {
        if(prime(i))
        {
            int x=i;
            while(n%x==0)
            {
                cout<<i<<" ";
                x=x*i; //because multiple power of x can also divide n so..
            }
        }
    }
}

//little optimize...
void primefactor2(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(prime(i))
        {
            int x=i;
            while(n%x==0)
            {
                cout<<i<<" ";
                x=x*i; //because multiple power of x can also divide n so..
            }
        }
    }
}

//multiplicataion of power of prime factor
void primefactor3(int n)
{
    if(n<1) return;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i;
            n=n/i;
        }
    }

    if(n>1)
    cout<<n;
}

//tc: theta(sqrt(n))
void primefactor4(int n)
{
    if(n<1) return;
    while(n%2==0)
    {
        cout<<2;
        n=n/2;
    }
    while(n%3==0)
    {
        cout<<3;
        n=n/3;
    }

    for(int i=5;i*i<=n;i=i+6)
    {
        while(n%i==0)
        {
            cout<<i;
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2;
            n=n/i;
        }
    }

    if(n>3)
    cout<<n;
}

// int main()
// {
//     int n;
//     cin>>n;
//     primefactor3(n);
// }


//print all the divisor of the number...
//tc:theta(n) sc:theta(1)
void printdivisior1(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        cout<<i<<" ";
    }
}

//tc:theta(sqrt(n)) sc:theta(1)
void printdivisior2(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)  //10%1 =0 10%2=0 //10%3=1 
        cout<<i<<" ";

        if(i!=n/i)// 1=10/1 2=10/2 3=10/3
        cout<<n/i<<" ";
    }
}

//for sorted order
//tc:theta(sqrt(n)) sc:theta(1)
void printdivisior3(int n)
{
    int i;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)  //10%1 =0 10%2=0 //10%3=1 
        cout<<i<<" ";
    }
    for(;i>=1;i--)
    {
        if(n%i==0)// 1=10/1 2=10/2 3=10/3
        cout<<n/i<<" ";
    }
}

// int main()
// {
//     int n;
//     cin>>n;
//     printdivisior2(n);
// }


//
//tc:o(n*sqrt(n))...
void printprime(int n)
{
    for(int i=2;i<=n;i++)
        if(prime1(i))
            cout<<i;
}

// sieve of erathosthenes....
// naive soln
//tc:o(n*sqrt(n))
bool sieve1(int n)
{
    vector<int>isprime(n,true); 
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=2*i;j<=n;j=j+i)
            isprime[j]=false;
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
            cout<<i<<" ";
    }
}

//optimized implementation...
// tc:o(n log log n)
bool sieve2(int n)
{
    vector<int>isprime(n,true); 
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=n;j=j+i)
            isprime[j]=false;
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
            cout<<i<<" ";
    }
}

//shorter implementation same complexity
// tc:o(n log log n)
void seive3(int n)
{
    vector<int>isprime(n,true); 
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
            cout<<i<<" ";
        for(int j=i*i;j<=n;j=j+i)
            isprime[j]=false;
    }
}

// int main()
// {
//     int n;
//     cin>>n;
//     sieve2(n);
// }


// computing power....
// navive soln
// tc : theta(n)
int powr1(int x,int n)
{
    int res=1;
    for(int i=0;i<n;i++)
    {
        res=x*res;
    }
    return res;
}

// effiecient soln
// tc : t(n/2)+theta(1)=theta(logn)
// sc : theta(logn)
int powr2(int x,int n)
{
    if(n==0)
    return 1;
    int temp=powr2(x,n/2);
    temp=temp*temp;
    if(n%2==0)
        return temp;
    else
        return temp*x;

}

//best optimized..
// tc:o(n) sc:o(1)
int powr3(int x,int n)
{
    
    int res=1;
    while(n>0)
    {
        if(n%2!=0)//if(n & 1) //101 1
        {
            res=res*x;
        }
        x=x*x;
        n=n/2;//n=n>>1
    }
    return res;
}

// int main()
// {
//     int n,x;
//     cin>>x>>n;
//     cout<<powr3(x,n);
// }


