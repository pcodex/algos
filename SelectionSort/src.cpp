#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

class SelSort
{	
public:
	vector<int> doSort(vector<int> inp)
	{		
		vector<int> op;
		while(inp.size()>0)
		{
			int min = inp[0];
			int minidx = 0;
			//each time pick the minimum element and move it into an array
			for (int j = 0; j < inp.size(); ++j)
			{
				if (inp[j] < min) {
					min = inp[j];
					//keep track of the minimum element's index
					minidx = j;
				}
			}

			op.push_back(min);
			//remove the min element from the original array
			inp.erase(inp.begin() + minidx);
		}
		return op;		
	}
	friend ostream& operator<<(ostream& o, vector<int> v);
};

ostream& operator<<(ostream& op, vector<int>& vin)
{
	for (int i = 0; i < vin.size(); ++i)
		op << vin[i] << " ";
	op << "\n";

	return op;

}

int main()
{

	SelSort ssrt;
	vector<int> vinp = { 99,12,1,55,23,19 };

	vector<int> out = ssrt.doSort(vinp);
	cout << out;

	return 0;
}