#include <bits/stdc++.h>
using namespace std;


struct schedule {
	int start, finish;
};



bool scheduleCompare(schedule s1, schedule s2)
{
	return (s1.finish < s2.finish);
}

void printMaxschedule(schedule arr[], int n)
{
	
	sort(arr, arr + n, scheduleCompare);

	cout << "Following activities are selected :\n";

	
	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish
		<< ")";

	
	for (int j = 1; j < n; j++) {
		
		if (arr[i].finish <= arr[j].start) {
			cout << ", (" << arr[j].start << ", "
				<< arr[j].finish << ")";
			i = j;
		}
	}
}
int main()
{
	schedule arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },
						{ 0, 6 }, { 5, 7 }, { 8, 9 } };
	int n = sizeof(arr) / sizeof(arr[0]);


	printMaxschedule(arr, n);
	return 0;
}