#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include <algorithm>
using namespace std;
int LIS(vector<int>& s){
	int c=0;
	// 不得不判斷的特例
	if (s.size() == 0) return 0;
	// 先放入一個數字，免得稍後 v.back() 出錯。
	vector<int> v;
	v.push_back(s[0]);
	for (int i = 1; i < s.size(); i++){
		int n = s[i];
		if (n > v.back()) v.push_back(n);
		else {
			*lower_bound(v.begin(), v.end(), n) = n;
			//if (v.size() == 1) c++;
		}
	}
	return v.size();
}
int main() {
	int k,kase=0;
	cin >> k;
	while (k--) {
		int n, p, q;
		vector<int>b;
		cin >> n >> p >> q;
		int a[250 * 250];
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= p + 1; i++) {
			int w; cin >> w;
			a[w]=i;
		}
		for (int i = 0; i < q+1; i++) {
			int t; cin >> t;
			if (a[t]>0) b.push_back(a[t]);
			//cout << t << '|';
		}
		cout << "Case " << ++kase << ": " << LIS(b) << endl;
	}
	//system("PAUSE");
	return 0;
}