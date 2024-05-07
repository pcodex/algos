#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class RecBinSrch
{

public:
	bool srch(vector<int> inp, int val)
	{
		if (inp.size() == 0)
			return false;

		sort(inp.begin(), inp.end());

		int st = 0;
		int end = inp.size() - 1;
		int mid = (st + end) / 2;

		if (st <= end) {
			if (val == inp[mid])
				return true;
			else if (val < inp[mid]) {
				end = mid - 1;
				if (st <= end) {
					inp = vector<int>(inp.begin(), inp.begin() + end + 1);
					return srch(inp, val);
				}
				else
					return false;
			}
			else if (val > inp[mid]) {
				st = mid + 1;
				if (st <= end) {
					inp = vector<int>(inp.begin() + st, inp.end());
					return srch(inp, val);
				}
				else
					return false;
			}
			mid = (st + end) / 2;
		}
		return false;
	}
};

int main()
{
	RecBinSrch rsbin;
	vector<int> inp = { 22,24,11,2,5,920,124,83,76,46,18,62,921,746,2 };
	bool ret = rsbin.srch(inp, 45);
	return 0;
}