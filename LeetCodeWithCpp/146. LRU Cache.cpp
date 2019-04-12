//// Easy, Medium or Hard
//// Hard
//#include"ListNode.h"
//#include"TreeNode.h"
//#include"Interval.h"
//#include<unordered_map>
//
//// WRONG
//class cache {
//public:
//	int _time;
//	int _key;
//	//int _index;
//	int _value;
//	bool operator() (const cache &cache2) {
//		return  _time < cache2._time;
//	}
//	cache() {}
//	cache(int key, int value, int time) :_key(key), _value(value), _time(time) {}
//};
//class LRUCache {
//public:
//	unordered_map<int, int> key2Index;
//	vector<cache> caches;
//	//unordered_map<int, int> key2Index;
//	//vector<int> containValues;
//	int size;
//	int capacity;
//	//priority_queue<cache*> pq;
//	long long curr_time;
//
//
//	LRUCache(int capacity) :capacity(capacity), size(0), curr_time(0) {
//		caches = vector<cache>(capacity);
//	}
//	int get(int key) {
//		try {
//			cache &c = caches[key2Index.at(key)];
//			c._time = curr_time++;
//			pq.emplace(&c);
//			//pq.emplace(key);
//			//pq.push(&c);
//			return c._value;
//		}
//		catch (out_of_range) {
//			return -1;
//		}
//	}
//
//	void put(int key, int value) {
//		try {
//			int index = key2Index.at(key);
//			cache &c = caches[index];
//			c._value = value;
//			c._time = curr_time++;
//			pq.emplace(key);
//			pq.push(c);
//		}
//		catch (out_of_range) {
//			if (size < capacity) {
//				key2Index[key] = size;
//				caches[size] = cache(key, value, curr_time++);
//				pq.push(caches[size]);
//				size++;
//			}
//			else {
//				auto leastCache = pq.top();
//			}
//		}
//	}
//
//
//int main() {
//	int capacity = 10;
//	LRUCache *LRUC = new LRUCache(capacity);
//	LRUC->put(1, 2);
//
//	return 0;
//}