#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class BinSearch
{
public:

	int search(vector<int>& vin, int val) {

		if (vin.size() == 0)
			return -1;

		sort(vin.begin(), vin.end());

		int start = 0;
		int end = vin.size()-1;
		int mid = (start + end) / 2;

		while (start <= end) {			
			mid = (start + end) / 2;

			if (vin[mid] == val)
				return mid;
			else if (val > vin[mid])
				start = mid + 1;
			else if (val < vin[mid])
				end = mid - 1;

			
		}
		return -1;
	}
};

int main()
{
	
	vector<int> vals = { 29,11,34,95,99,102,1,35,54 };
	BinSearch bsrch;
	int idx = bsrch.search(vals, 34);
	if (idx != -1)
		cout << "The value can be found at " << idx<<endl;
	else
		cout << "The value cannot be found\n";

	return 0;
}