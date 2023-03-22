
// Tower of hanoi
// total no of steps (2^n)-1;

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define ll long long

void towerofHanoi(int n, char from, char helper, char to){

    if(n==0) return;

    // cout<<n<<" "<<from<<" "<<helper<<" "<<to<<endl;
    towerofHanoi(n-1,from,to,helper);
    // reached here
    //nth rod to to
    cout<<from<<" -> "<<to<<endl;
    towerofHanoi(n-1,helper,from,to);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
    towerofHanoi(n,'A','B','C');

    return 0;
}