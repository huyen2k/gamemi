#include <bits/stdc++.h>
#define int long long

using namespace std;
int a[100005], sum[100006];
int n;

int binary(const int a[], int i, int sum){
    int l = i, r = n, ans = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] <= a[i - 1] + sum){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int sum_1toi(int i){
    return (i + 1) * i / 2;
}

main()
{
    ifstream cin("test.inp");
    int numcase;
    cin >> numcase;
    while(numcase --){
        cin >> n;
        sum[0] = 0;
        for(int i = 1; i <= n; i ++){
             cin >> a[i];
             sum[i] = sum[i - 1] + a[i];
        }
        int q; cin >> q;
        while(q --){
            int i, u;
            cin >> i >> u;
            int j = binary(sum, i, u);
            int ans = j;
            if(j < n && u * (sum[j] - sum[i - 1]) - sum_1toi(sum[j] - sum[i - 1]) <
               u * (sum[j + 1] - sum[i - 1]) - sum_1toi(sum[j + 1] - sum[i - 1]) ) ans = j + 1;
            cout << ans << " ";
        }
        cout << '\n';
    }
}
