#include <set>
#include <iostream>

using namespace std;

int main()
{
	set<int> st{ 2,2,2,2,3,3,3 };
	cout << st.size() << endl;
	
	st.insert(1);
	st.erase(2);
	
	for (auto& it : st)
		cout << it << " ";
	cout << endl;

	set<int> st2{ 1,2,2,3,3,4 };

	for (auto& it : st2)
		cout << it << " ";
	cout << endl;

	// https://www.cplusplus.com/reference/algorithm/lower_bound/
	auto lbIter = st2.lower_bound(2); // Returns an iterator pointitng to 1st element which is not less than 2 {2,3,4...}
	// {proper index or the end iterator}
	if (lbIter != st2.end())
	{
		cout << "lb = " << *lbIter << endl;
	}
	else
	{
		cout << "Element is bigger than the greatest element in the set\n";
	}

	auto ubIter = st2.upper_bound(2); // 1st element which is bigger than 2 {3,4...}
	// {proper index or the end iterator}
	if (ubIter != st2.end())
	{
		cout << "ub = " << *ubIter << endl;
	}
	else
	{
		cout << "Element is bigger than the greatest element in the set\n";
	}

	cin.get();
	return 0;
}
