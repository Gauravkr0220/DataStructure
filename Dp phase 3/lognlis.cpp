/* Logic */
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];


	vector <int> lis;
	int back[n];
	for(int i = 0; i < n; i++){
		if(!lis.size() or lis.back() < a[i]){
			lis.push_back(a[i]);
			back[i] = lis.size();
			continue;
		}
		auto it = upper_bound(all(lis), a[i]);
		lis[it - lis.begin()] = a[i];
		back[i] = (it - lis.begin()) + 1;
	}


	int len = lis.size();
	cout << len << "\n";


	int ans[len];


	for(int i = n - 1; i >=0 ; i--){
		if(back[i] == len){
			ans[len - 1] = a[i];
			len--;
		}
	}
	for(int i = 0; i < lis.size(); i++){
		cout << ans[i] <<" ";
	}
	cout << "\n";
}