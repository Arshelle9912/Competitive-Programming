#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    long int n,t,j(-1),sum(0),ans(0);
    cin >> n >> t;
    long int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        if (sum+arr[i]<t){
            sum+=arr[i];
        }
        else{
            sum+=arr[i];
            while (sum>t){
                j++;
                sum-=arr[j];
            }
        }
        ans=max(ans,i-j);
    }
    cout << ans;
}