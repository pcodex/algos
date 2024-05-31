#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


class QuickSort
{

public:
	list<int> doSort(list<int> lin) {

		if (lin.size() <= 1)
			return lin;

		int pivot = *lin.begin();
		lin.pop_front();

		list<int> lleft, lright;
		list<int>::iterator liter = lin.begin();
		while(liter!=lin.end()){
			if (*liter <= pivot)
				lleft.push_back(*liter);
			else
				lright.push_back(*liter);
			liter++;
		}

		list<int> lsorted = doSort(lleft);
		list<int> rsorted = doSort(lright);
		lsorted.push_back(pivot);
		lsorted.splice(lsorted.end(), rsorted);

		return lsorted;

	}
};

int main()
{
	QuickSort qs;
	list<int> l1 = { 22,1,4,98,32,17,3 };
	list<int> sortedLst = qs.doSort(l1);
	return 0;
}