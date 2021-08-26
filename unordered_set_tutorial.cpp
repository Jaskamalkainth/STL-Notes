#include <unordered_set>
#include <iostream>

using namespace std;


int main()
{

	unordered_set<int> ust;
	
	ust.reserve(1 << 15);
	ust.max_load_factor(0.25);
	// The load factor is the ratio between the number of elements in the container (its size) and the number of buckets (bucket_count).
	// loadFactor = #Elements/#buckets
	// with 100 buckets we can store atmost 25 elements

	ust.insert(1);
	ust.insert(2);
	ust.insert(1); // wont be inserted since elements in unordered set are unique
	ust.insert(3);
	ust.emplace(5);

	for (auto& it : ust)
		cout << it << " ";
	cout << endl;

	if (ust.find(1) != ust.end())
		cout << "1 is present in the unordered set\n";
// key -> value mapping : u_map
	// list of keys -> u_set


	cin.get();
	return 0;
}
