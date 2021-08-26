#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct myCmp {
	constexpr bool operator()(const int& _Left, const int& _Right) const {
		return _Left > _Right;
	}
};

struct myCmpPair {
	constexpr bool operator()(const pair<int,int>& _Left, const pair<int, int>& _Right) const {
		if (_Left.first == _Right.first)
			return _Left.second > _Right.second;
		return _Left.first > _Right.first;
	}
};

struct Article
{
	int id, score;
	Article(int id_, int score_)
	{
		id = id_;
		score = score_;
	}
};

struct myArticleCmp {
	constexpr bool operator()(const Article& _Left, const Article& _Right) const {
		return _Left.score > _Right.score;
	}
};

int main()
{
	priority_queue<int> maxHeap; // default impl =  max_heap

	maxHeap.push(1);  // logn
	maxHeap.push(5);
	maxHeap.push(22);
	maxHeap.push(6);
	maxHeap.emplace(5);

	int tpEle = maxHeap.top(); // return 22 -> O(1)
	maxHeap.pop(); // removing the top element -> logn

	cout << maxHeap.size() << endl;


    priority_queue<int, vector<int>, myCmp> minHeap;
	minHeap.push(1);  // logn
	minHeap.push(5);
	minHeap.push(22);
	minHeap.push(6);
	minHeap.emplace(5);

	int tpEle = maxHeap.top(); // return 1 -> O(1)

	///

	vector<int> data = { 2,4,5,6,8,11 };
	// N = 10^6 -> logN = 20
	// 3N versus 20N
	priority_queue<int> maxHeapData(data.begin(), data.end()); // this


	// given N numbers, -> 
	// NlogN
	// O(3N) -> O(N) 

	cout << maxHeapData.top() << endl; // returns 11
	//priority_queue<int> maxHeapData = { 1,23,4 }; // why this doesnt work

	vector<int> data2 = { 1,2,3,4 };


	priority_queue<pair<int, int>> maxHeapPair;
	maxHeapPair.push({ 1,2 });
	maxHeapPair.emplace(2, 3);
	maxHeapPair.emplace(2, 4);

	priority_queue<pair<int, int>, vector<pair<int, int>>, myCmpPair> minHeapPair;

	//multiset<int> st; // BBST
	//// logn

	// below thing  list (DLL) -> removal takes O(N) so use below hash table
	//unordered_map<int, multiset<int>::iterator> hashHeapDs; 


	priority_queue<Article,vector<Article>, myArticleCmp> pqArticle;
	//priority_queue <Article> pqArticle;
	pqArticle.push(Article(1, 2));
	pqArticle.push(Article(4, 2));

	set<int> st;

	cout << pqArticle.top().id << " " << pqArticle.top().score << endl;

	return 0;
}
