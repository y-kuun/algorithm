#include <list>
#include <unordered_map>
using namespace std;

// LRUCache 使用了list 以及 unordered_map

class LRUCache {
   public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = _cmap.find(key);
        if (it != _cmap.end()) {
            auto value = it->second->second;
            _cache.erase(it->second);
            _cache.push_front(pair<int, int>{key, value});
            it->second = _cache.begin();
            return value;
        }
        return -1;
    }

    void set(int key, int value) {
        auto it = _cmap.find(key);
        if (it != _cmap.end()) {
            _cache.erase(it->second);
            _cache.push_front(pair<int, int>{key, value});
            it->second = _cache.begin();
            return;
        }

        if (_cache.size() == _capacity) {
            auto k = _cache.back().first;
            _cache.pop_back();
            _cmap.erase(k);
        }
        _cache.push_front(pair<int, int>{key, value});
        _cmap.insert(
            pair<int, list<pair<int, int>>::iterator>{key, _cache.begin()});
    }

   private:
    int _capacity;
    list<pair<int, int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _cmap;
};