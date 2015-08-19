#include <unordered_map>
#include <list>
using namespace std;
class LRUCache{
private:
	struct Entry {
		int key;
		int value;
		Entry(int k, int v):key(k), value(v) {}
	};
	int limit;
	list<Entry> cache;
	unordered_map<int, decltype(end(cache))> m;
public:
	LRUCache(int capacity) : limit{capacity}, cache{}, m{} {}
	int get(int key) {
		if (m.find(key) == end(m)) return -1;
		cache.splice(begin(cache), cache, m[key]);
		m[key] = begin(cache);
		return begin(cache)->value;
	}
	void set(int key, int value) {
		if (m.find(key) == end(m)) {
			if ((int)cache.size() == limit) {
				m.erase(cache.back().key);
				cache.pop_back();
			}
			cache.emplace_front(key, value);
			m[key] = begin(cache);
		} else {
			cache.splice(begin(cache), cache, m[key]);
			m[key] = begin(cache);
			begin(cache)->value = value;
		}
	}
};
