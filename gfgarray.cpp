#include <bits/stdc++.h>
using namespace std;
// find largest...
// tc:o(n^2)
int maxi(int a[], int n)
{ // 1 5 3 6 2
    for (int i = 0; i < n; i++)
    {
        int flag = true;
        for (int j = i; j < n; j++)
        {
            if (a[i] < a[j])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            return i;
    }

    return -1;
}

// tc:o(n)
int maxi2(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
            res = i;
    }
    return res;
}

// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];

//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }

//     cout<<maxi2(a,n);
// }

// find second largest.....
int seclarg(int a[], int n)
{
    int r = maxi2(a, n);
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[r])
        {
            if (res == -1)
                res = i;
            else if (a[i] > a[res])
                res = i;
        }
    }
    return res;
}

int seclarg2(int a[], int n)
{
    int largest = 0;
    int res = -1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[largest])
        {
            res = largest;
            largest = i;
        }
        else if (a[i] != a[largest])
        {
            if (res == -1 || a[i] > a[res])
                res = i;
        }
    }
    return res;
}

// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];

//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }

//     cout<<a[seclarg(a,n)];
// }

// array is sorted or not....
//  tc:o(n^2)
bool sorted(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] > a[j])
                return false;
        }
    }
    return true;
}

// tc:o(n^2) sc:o(1)
bool sorted2(int a[], int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];

//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }

//     cout<<sorted2(a,n);
// }

// reverse an array
// tc:o(n)... sc:o(1)...
void rev(int a[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     rev(a, n);
// }



// dulicate method 1 without vector.....
// tc:o(n) sc:o(n)
 int remDups(int arr[], int n)
{
	int temp[n];

	temp[0] = arr[0];

	int res = 1;

	for(int i = 1; i < n; i++)
	{
		if(temp[res - 1] != arr[i])
		{
			temp[res] = arr[i];
			res++;
		}
	}

	for(int i = 0; i < res; i++)
	{
		arr[i] = temp[i];
	}

	return res;
}
    
// int main() {
	
//       int arr[] = {10, 20, 20, 30, 30, 30}, n = 6;
//        for(int i = 0; i < n; i++)
//        {
//        		cout<<arr[i]<<" ";
//        }
//        cout<<endl;
//        n = remDups(arr, n);
//        for(int i = 0; i < n; i++)
//        {
//        		cout<<arr[i]<<" ";
//        }
// }

// using vector(self)
// tc:o(n) sc:o(n)
void duplicate(int a[],int n)
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[i+1])
        {
            v.push_back(a[i]);
        }
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
}

// optimized 
// tc:o(n) sc:o(1)
void duplicate2(int a[],int n)
{
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[res-1])
        {
            a[res]=a[i];
            res++;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}


// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     duplicate2(a, n);
// }


// move zero at the end.....
// tc:o(n) sc:o(1)
 void moveZeroes(int a[],int n)
{
    int indx = 0;
    for(int i=0; i<n; i++) {
        if(a[i] != 0) {
            swap(a[i],a[indx]);
            indx++;
        }
    }

}

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     moveZeroes(a, n);

//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i];
//     }
// }



//left rotate by 1......
void rotate(int arr[],int n)
{
    int temp=arr[0];
    for(int i=1;i<n;i++)
    arr[i-1]=arr[i];
    arr[n-1]=temp;
}

//left rotate by k .....
//naive approach calling rotate tc:o(nd) sc:o(1)
void leftRotate1(int a[],int n,int k)
{
    
    for(int i=0;i<k;i++)
    rotate(a, n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

//better soln
//tc:o(nd) sc:o(d)
void leftRotate2(int arr[], int d, int n)
{
	int temp[d];

	for(int i = 0; i  < d; i++)
	{
		temp[i] = arr[i];
	}

	for(int i = d; i  < n; i++)
	{
		arr[i - d] = arr[i];
	}

	for(int i = 0; i  < d; i++)
	{
		arr[n - d + i] = temp[i];
	}	
}

void reversal(int a[],int low,int high)
{
    while(low<high)
    {
        int temp=a[low];
        a[low]=a[high];
        a[high]=temp;
        low++;
        high--;
    }
}

//tc:o(n) sc:o(1)
void leftRotate3(int a[],int n,int k)
{
    reversal(a,0,k-1);
    reversal(a,k,n-1);
    reversal(a,0,n-1);
}

// int main()
// {
//     int n,k;
//     cin >> n>>k;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     leftRotate3(a,n,k);

//     for (int i = 0; i < n; i++)
//     {
//         cout<<a[i]<<" ";
//     }
// }



// leader problem
// navive --> tc:o(n^2) sc:o(1)...
// like max code...
void leaders(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		bool flag = false;

		for(int j = i + 1; j < n; j++)
		{
			if(arr[i] <= arr[j])
			{
				flag = true;
				break;
			}
		}

		if(flag == false)
		{
			cout<<arr[i]<<" ";
		}
	}
}



// efficient soln.....
// tc:o(n) sc:o(1)
void leaders2(int arr[], int n)
{
	int curr = arr[n - 1];

	cout<<curr<<" ";

	for(int i = n - 2; i >= 0; i--)
	{
		if(curr < arr[i])
		{
			curr = arr[i];

			cout<<curr<<" ";
		}
	}
}



// int main() {
	
//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     leaders(a, n);
    
// }


// Maximum Difference Problem with Order....
// naive soln
// tc:o(n^2) sc:o(1)
int maxdiff1(int arr[],int n)
{
    int res=arr[0];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res=max(res,arr[j]-arr[i]);
        }
    }
    return res;
}
// effiecent soln 
// tc:o(n) sc:o(1)
int maxdiff2(int a[],int n)
{
    int res=a[1]-a[0];
    int minval=a[0];
    for(int i=1;i<n;i++)
    {
        res=max(res,a[i]-minval);
        minval=min(minval,a[i]);
    }
    return res;
}

// int main() {
	
//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout<<maxdiff1(a, n);
// }



void frequency(int a[],int n)
{
    int freq=1,i=1;
    while(i<n)
    {
        while(i<n && a[i]==a[i-1])
        {
            freq++;
            i++;
        }
        cout<<a[i-1]<<" "<<freq<<" ";
        i++;
        freq=1;
    }
    if(n==1 || a[n-2]!=a[n-1])
    cout<<a[n-1]<<" "<<1;

}

// int main() {

// int n;
// cin >> n;
// int a[n];

// for (int i = 0; i < n; i++)
// {
//     cin >> a[i];
// }
// frequency(a, n);
// }


// navie method...
// tc:o(n^2) sc:o(1)
int stockmaxProfit1(int price[], int start, int end)
{
	if(end <= start)
		return 0;

	int profit = 0;

	for(int i = start; i < end; i++)
	{
		for(int j = i + 1; j <= end; j++)
		{
			if(price[j] > price[i])
			{
				int curr_profit = price[j] - price[i] 
								  +  stockmaxProfit1(price, start, i - 1)
								  +  stockmaxProfit1(price, j + 1, end);

				profit = max(profit, curr_profit);
			}
		}
	}

	return profit;
}

// efficient method....
// stock sell problem...
// tc:o(n) sc:o(1)
// if the price is going up sell the stock , if price is going down buy them 
// add the diff of price if they r going up , if down don't do anything
int  stockmaxProfit2(int a[],int n)
{
    int profit=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[i-1])
        profit+=a[i]-a[i-1];
    }
    return profit;
}


// int main() {

//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout<<stockmaxProfit1(a, 0,n-1);
//     // cout<<stockmaxProfit2(a, n);
// }



// tapping rain water problem....
// naive soln
// tc:o(n^2) sc:o(1)...
int tappingwater1(int arr[], int n)
{
	int res = 0;

	for(int i = 1; i < n - 1; i++)
	{
		int lMax = arr[i];

		for(int j = 0; j < i; j++)
			lMax = max(lMax, arr[j]);

		int rMax = arr[i];

		for(int j = i + 1; j < n; j++)
			rMax = max(rMax, arr[j]);

		res = res + (min(lMax, rMax) - arr[i]);
	}

	return res;
}

// efficient soln 
// tc:o(n) sc:o(n)
int tappingwater2(int a[],int n)
{
    int res=0;
    int lmax[n],rmax[n];
    lmax[0]=a[0];
    rmax[n-1]=a[n-1];
    for(int i=1;i<n;i++)
    {
        lmax[i]=max(lmax[i-1],a[i]);
    }

    for(int i=n-2;i>=0;i--)
    {
        rmax[i]=max(rmax[i+1],a[i]);
    }

    for(int i=1;i<n-1;i++)
    {
        res=res+((min(lmax[i],rmax[i]))-a[i]);
    }
    return res;
}


// int main() {

//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     // find amount of water between given containers...
//     cout<<tappingwater1(a, n);
// }


// find the maximum consecutive ones count....
// tc:o(n^2) sc:o(1)
int consecutive_ones(int arr[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==1)
            {
                count++;
            }
            else
            break; 
        }
        res=max(res,count);
    }
    return res;
}

// tc:o(n) sc:o(1)
int consecutive_ones1(int arr[],int n)
{
    int res=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        count=0;
        else
        {
            count++;
            res=max(res,count);
        }
    }
    return res;
}

// int main() {

//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout<<consecutive_ones1(a, n)<<" ";
// }



// maximum sum subarray....
// tc:o(n^2) sc:o(1)
int maxsubarray1(int a[],int n)
{
    int res=a[0];
    for (int i = 0; i <n; i++)
    {
        int curr=0;
        for(int j=i;j<n;j++)
        {
            curr+=a[j];
            res=max(res,curr);
        }
    }
    return res;
}


//tc:o(n) sc:o(1)
int maxsubarray2(int arr[],int n) {
    int maxEnding=arr[0];
    if(n==1)
    return arr[n-1];
    int res=arr[0];
    
    for(int i=0;i<n;i++)
    {
        maxEnding=max(maxEnding+arr[i],arr[i]);
        res=max(res,maxEnding);
    }
    
    return res;
}


// int main() {

//     int n;
//     cin >> n;
//     int a[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout<<maxsubarray2(a, n)<<" ";
// }


// 989. Add to Array-Form of Integer.....
// vector<int> addToArrayForm(vector<int>& A, int K) 
// {
//         vector<int> vReturn;
//         int i =A.size()-1;
//         cout<<i;
//         while (i >= 0 || K > 0) {
//             if (i >= 0)
//                 K += A[i];
//             vReturn.push_back(K % 10);
//             K /= 10;
//             i--;
//         }
//         reverse(vReturn.begin(), vReturn.end());
//         return vReturn;
// }




// maximum longest odd even occurance....
// eg:1 2 3 4 5 6
// tc:o(n^2) sc:o(1)
int long_odd_even1(int arr[],int n)
{
    int res=1;
    for(int i=1;i<n;i++)
    {
        int curr=1;
        for(int j=i;j<n;j++)
        {
            if((arr[j]%2==0 && arr[j-1]%2!=0)||(arr[j]%2!=0 && arr[j-1]%2==0))
            {
                curr++;
            }
            else
            break;
        }
        res=max(res,curr);
    }
    return res;
}

//kadane's algorithm....
//like kadane's algo start with 2nd element ...2 conditions either u beign new subarray or u extend the previous subarray.
// tc:o(n) sc:o(n)
int long_odd_even2(int arr[],int n) 
{
    int res=1,curr=1;
    for(int i=1;i<n;i++)
    {
        if((arr[i]%2==0 && arr[i-1]%2!=0)||(arr[i]%2!=0 && arr[i-1]%2==0))
        {
            curr++;
            res=max(res,curr);
        }
        else
        curr=1;

    }
    return res;
}

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     cout<<long_odd_even1(arr,n);
// }


// maximum circular sum subarray...
// eg: arr={5,-2,3,4}
// ans : res=12
// steps:
// i=0: c_m=10 , res=10
// i=1: c_m=10
// i=2: c_m=12,res=12
// i=3: c_m=10
//tc:o(n^2) sc:o(1)
int circular_sum_subarray1(int a[],int n)
{
    int res=a[0];
    for(int i=0;i<n;i++)
    {
        int curr_max=a[i];
        int curr_sum=a[i];
        for(int j=1;j<n;j++)
        {
            int indx=(i+j)%n;
            curr_sum+=a[indx];
            curr_max=max(curr_max,curr_sum);
        }
        res=max(res,curr_max);
    }
    return res;
}

// effiecient soln
// tc:o(n) sc:o(1)
//to find the max sum of normal subarray 
int normalMaxSum(int arr[], int n)
{
	int res = arr[0];

	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}
	
	return res;
}

// to find the overall sum and subtract it from normal sum
int overallMaxSum(int arr[], int n)
{
	int max_normal = normalMaxSum(arr, n);

	if(max_normal < 0)
		return max_normal;

	int arr_sum = 0;

	for(int i = 0; i < n; i++)
	{
		arr_sum += arr[i];

		arr[i] = -arr[i];
	}

	int max_circular = arr_sum + normalMaxSum(arr, n);

	return max(max_circular, max_normal);
}


// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     // cout<<circular_sum_subarray1(arr,n);
//     cout<<overallMaxSum(arr,n);
// }


// majority element
// an element is in majority if it is occuring more then n/2 times
// 2 3 4 5 4 4 4 
// tc:o(n^2) sc:o(1)
int majority_element1(int a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            count++;
        }
        if(count>n/2)
        return i;
    }
    return -1;
}

// Moore's voting algorithm.....
// tc:o(n) sc:o(1)
// doubt....
int majority_element2(int arr[], int n)
{
	int res = 0, count = 1;

    	for(int i = 1; i < n; i++)
    	{
    		if(arr[res] == arr[i])
    			count++;
    		else 
    			count --;

    		if(count == 0)
    		{
    			res = i; count = 1;
    		}
    	}

    	count = 0;

    	for(int i = 0; i < n; i++)
    		if(arr[res] == arr[i])
    			count++;

    	if(count <= n /2)
    		res = -1;

    	return res; 
}

// int main()
// {
//      int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     cin>>a[i];
//     cout<<majority_element2(a,n);
// }


// minimum consecutive flips....
// efficient soln : tc->o(n) sc->o(1)
// eg: n=7 a={1 1 0 0 0 1 0} ans:from 2 to 4
                            //   from 6 to 6
void min_consecutive_flips(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            if(a[i]!=a[0])
            {
                cout<<" from "<<i<<" to ";
            }
            else
            cout<<(i-1)<<endl;
        }
    }
    if(a[n-1]!=a[0])
    cout<<n-1;

}

// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     cin>>a[i];
//     min_consecutive_flips(a,n);

// }


// maximum sum of k consecuitive elements....
// navie soln 
// tc:o(n^2) sc:o(1)
// eg:n=6 k=4
//    a={1,8,30,-5,20,7} ans : 53 
int maxSum(int arr[], int n, int k)
{
	int max_sum = INT_MIN;
	for(int i = 0; i + k - 1 < n; i++)
	{
		int sum = 0;

		for(int j = 0; j < k; j++)
		{
			sum += arr[i + j];
		}

		max_sum = max(max_sum, sum);
	}

	return max_sum;

}

// sliding window concept
// tc:o(n) sc:o(1)
int consecutive_sum(int a[],int n,int k)
{
    int curr=0;
    for(int i=0;i<k;i++)
    {
        curr+=a[i];
    }
    int res=curr;
    for(int i=k;i<n;i++)
    {
        curr=curr+a[i]-a[i-k];
        res=max(res,curr);
    }
    return res;

}

// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     int a[n];
//     for(int i=0;i<n;i++)
//     cin>>a[i];
//     cout<<consecutive_sum(a,n,k);    
// }


// subarray with given sum...
// navive solution
// tc:o(n^2) sc:o(1)
/* Returns true if the there is a subarray
of arr[] with sum equal to 'sum' otherwise
returns false. Also, prints the result */

bool subarray_sum(int a[],int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        int curr=0;
        for(int j=i;j<n;j++)
        {
            curr+=a[i];

            if(curr==sum)
            return true;
        }
    }
    return false;
}


// better readable code....
void subArray_sum(int arr[], int n, int sum)
{

	// Pick a starting point
	for (int i = 0; i < n; i++) {
		int currentSum = arr[i];

		if (currentSum == sum) {
			cout << "Sum found at indexes " << i << endl;
			return;
		}
		else {
			// Try all subarrays starting with 'i'
			for (int j = i + 1; j < n; j++) {
				currentSum += arr[j];

				if (currentSum == sum) {
					cout << "Sum found between indexes "
						<< i << " and " << j << endl;
					return;
				}
			}
		}
	}
	cout << "No subarray found";
	return;
}

//efficient code doubt.... 

// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     int a[n];
//     for(int i=0;i<n;i++)
//     cin>>a[i];
//     cout<<subarray_sum(a,n,k);    
// }



// prefixsum....
// naive soln -> tc:o(n) sc:o(1)

int prefixsum1(int a[],int l,int r)
{
    int sum=0;
    for(int i=l;i<r;i++)
    {
        sum+=a[i];
    }
    return sum;
}

// effiecient solution....
// tc->o(1) sc->o(1)



int getSum(int ps[], int l, int r)
{
    if(l==0)
        return ps[r];
    return ps[r]-ps[l-1];
}

// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     cin>>a[i];
//     int pre[n];
//     pre[0]=a[0];
//     for(int i=1;i<n;i++)
//     {
//         pre[i]=pre[i-1]+a[i];
//     }
//     int from_pos,to_pos;
//     cin>>from_pos>>to_pos;
//     cout<<getSum(pre,from_pos,to_pos);    
// }



// eqlibrium point.... OR pivot....(gfg approach)
// tc:o(n) sc:o(1)

int epoint(int a[],int n)
{
    int sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    int l=0;
    for(int i=0;i<n;i++)
    {
        sum-=a[i];
        if(l==sum)
        return true;
        l+=a[i];
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<epoint(a,n);
}



//pivot element...
// OR 
// 1991. Find the Middle Index in Array

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// tc:o(n)
// int findMiddleIndex(vector<int>& nums) 
// {
//     int n=nums.size();
//     vector<int>prefixsum(n+1);
//     prefixsum[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         prefixsum[i]=prefixsum[i-1]+nums[i-1];
//     }

//     int ans=-1;
//     for(int i=0;i<n;i++)
//     {
//         int leftsum=prefixsum[i] , rightsum=prefixsum[n]-prefixsum[i+1];

//         if(leftsum==rightsum)
//         {
//             ans=i;
//             break;
//         }
//     }
//     return ans;
// } 




// C++ program to find maximum occurred element in
// given N ranges.
#define MAX 1000000

// Return the maximum occurred element in all ranges.
int maximumOccurredElement(int L[], int R[], int n)
{
	// Initialising all element of array to 0.
	int arr[MAX];
	memset(arr, 0, sizeof arr);

	// Adding +1 at Li index and subtracting 1
	// at Ri index.
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		arr[L[i]] += 1;
		arr[R[i] + 1] -= 1;
		if (R[i] > maxi) {
			maxi = R[i];
		}
	}

	// Finding prefix sum and index having maximum
	// prefix sum.
	int msum = arr[0], ind;
	for (int i = 1; i < maxi + 1; i++) {
		arr[i] += arr[i - 1];
		if (msum < arr[i]) {
			msum = arr[i];
			ind = i;
		}
	}

	return ind;
}

// Driven code
// int main()
// {
// 	int L[] = { 1, 4, 9, 13, 21 };
// 	int R[] = { 15, 8, 12, 20, 30 };
// 	int n = sizeof(L) / sizeof(L[0]);

// 	cout << maximumOccurredElement(L, R, n) << endl;
// 	return 0;
// }