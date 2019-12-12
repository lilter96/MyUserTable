#include <iostream>
#include <algorithm>
using namespace std;

int n;

int solve(int* a)
{
	int* b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
		for (int j = 0; j < n; j++) if (a[i] == a[j]) b[i]++;
	}
	int max = b[0];
	for (int i = 1; i < n; i++) max = std::max(max, b[i]);
	int min = a[0];
	for (int i = 0; i < n; i++) if (b[i] == max)
	{
		min = std::min(min, a[i]);
	}
	return min;
}

void main()
{
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = solve(arr), count = 0;
	for (int i = 0; i < n; i++) if (arr[i] == ans) count++;
	cout << "ans = " << ans << " count = " << count << endl;
}
