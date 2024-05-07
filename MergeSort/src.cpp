#include <vector>
#include <string>

using namespace std;

/*
divide : split the given list into 2 halves
conquer : sort each half and then combine the 2 sorted halves

base case : only 1 element or no element is present in the list

*/


class CMergeSort
{	

public:

	vector<int> mergeSort(vector<int> inpv)
	{
		if (inpv.size() <= 1)
			return inpv;

		size_t mid = inpv.size() / 2;

		//do the split
		vector<int> lft = vector<int>(inpv.begin(), inpv.begin() + mid);
		vector<int> rgt = vector<int>(inpv.begin() + mid, inpv.end());

		//call mergeSort recursively
		vector<int> res1 = mergeSort(lft);
		vector<int> res2 = mergeSort(rgt);

		//finally merge the sorted lists
		vector<int> opvec = doMerge(res1, res2);

		return opvec;
	}

	vector<int> doMerge(vector<int>& v1, vector<int>& v2)
	{
		vector<int> op;
		size_t lidx = 0, ridx = 0;

		while (lidx < v1.size() && ridx < v2.size()) {

			if (v1[lidx] < v2[ridx]) {
				op.push_back(v1[lidx]);
				lidx++;
			}
			else {
				op.push_back(v2[ridx]);
				ridx++;
			}
		}

		while (lidx < v1.size())		
			op.push_back(v1[lidx++]);
		
		while (ridx < v2.size())
			op.push_back(v2[ridx++]);

		return op;
	}
};


int main()
{
	CMergeSort cms;

	vector<int> vinp = { 23,11,18,774,1,45,8,99,123 };
	vector<int> opv  = cms.mergeSort(vinp);

	return 0;
}