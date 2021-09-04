#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
public:
    static const int p = 1 << 14;
    int keys[p];
    int values[p];

    /** Initialize your data structure here. */
    MyHashMap() {
        for (auto &i : keys)
            i = -1;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = key % p, i = pos;
        for (i = pos; i < p; ++i) {
            if (keys[i] < 0 || keys[i] == key) {
                keys[i] = key;
                values[i] = value;
                return;
            }
        }
        if (i == p) {
            for (i = 0; i < pos; ++i) {
                if (keys[i] < 0 || keys[i] == key) {
                    keys[i] = key;
                    values[i] = value;
                    return;
                }
            }
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = key % p, i = pos;
        for (; i < p; ++i) {
            if (keys[i] == -1)
                return -1;
            if (keys[i] == key) {
                return values[i];
            }
        }
        if (i == p) {
            for (i = 0; i < pos; ++i) {
                if (keys[i] == -1)
                    return -1;
                if (keys[i] == key) {
                    return values[i];
                }
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = key % p, i = pos;
        for (; i < p; ++i) {
            if (keys[i] == -1)
                return;
            if (keys[i] == key) {
                keys[i] = -2;
                values[i] = -1;
                return;
            }
        }
        if (i == p) {
            for (i = 0; i < pos; ++i) {
                if (keys[i] == -1)
                    return;
                if (keys[i] == key) {
                    keys[i] = -2;
                    values[i] = -1;
                    return;
                }
            }
        }
    }
};

int main() {
    MyHashMap map;
    //map.put(15578, 10);
    //cout << map.get(15578) << endl;
    //return 0;
    //map.put(1, 1); // map 现在为 [[1,1]]
    //map.put(2, 2); // map 现在为 [[1,1], [2,2]]
    //cout << map.get(1) << endl;    // 返回 1 ，map 现在为 [[1,1], [2,2]]
    //cout << map.get(3) << endl;    // 返回 -1（未找到），map 现在为 [[1,1], [2,2]]
    //map.put(2, 1); // map 现在为 [[1,1], [2,1]]（更新已有的值）
    //cout << map.get(2) << endl;    // 返回 1 ，map 现在为 [[1,1], [2,1]]
    //map.remove(2); // 删除键为 2 的数据，map 现在为 [[1,1]]
    //cout << map.get(2) << endl;    // 返回 -1（未找到），map 现在为 [[1,1]]
    //map.put(22,83);
    //map.put(39,4);
    //map.put(34,88);
    //map.put(72,99);
    //map.remove(33);
    //map.put(58,77);
    //map.put(23,61);
    //map.remove(34);
    //map.remove(66);
    //map.remove(90);
    //map.put(72,83);
    //map.put(50,98);
    //map.put(93,97);
    //map.put(74,95);
    //map.remove(81);
    //map.put(56,1);
    //map.put(86,80);
    //map.put(93,91);
    //map.put(13,1);
    //map.remove(93);
    //map.put(63,11);
    //map.put(62,63);
    //map.get(63);
    //map.put(71,98);
    //map.put(97,96);
    //map.put(65,47);
    //map.remove(93);
    //map.put(30,78);
    //map.put(31,40);
    //map.put(67,86);
    //map.put(84,11);
    //map.put(3,19);
    //map.put(30,97);
    //map.put(3,36);
    //map.get(63);
    //map.put(92,43);
    //map.remove(71);
    //map.remove(86);
    //map.put(77,91);
    //map.put(18,29);
    //map.put(75,44);
    //map.get(59);
    //map.put(035,81);
    //map.remove(58);
    //map.put(12,69);
    //map.remove(58);
    //map.get(86);
    //map.put(84,9);
    //map.put(83,40);
    //map.remove(82);
    //map.get(82);
    //map.put(55,0);
    //map.remove(65);
    //map.put(88,83);
    //map.put(61,83);
    //map.put(18,68);
    //map.put(61,19);
    //map.put(92,74);
    //map.put(68,15);
    //map.put(7,99);
    //map.get(97);
    //map.remove(92);
    //map.put(17,96);
    //map.put(73,22);
    //map.put(7,16);
    //map.put(7,16);
    //map.remove(3);
    //map.put(0,16);
    //map.put(22,27);
    //map.put(74,26);
    //map.put(63,28);
    //map.put(84,70);
    //map.put(44,23);
    //map.put(51,38);
    //map.put(65,67);
    //map.put(75,85);
    //map.put(50,57);
    //map.put(75,55);
    //map.put(4,84);
    //map.put(9,16);
    //map.put(69,39);
    //map.put(40,34);
    //map.put(99,55);
    //map.get(74);
    //map.put(42,53);
    //map.put(17,9);
    //map.put(70,92);
    //map.put(89,11);
    //map.put(15,64);
    //map.put(75,22);
    //map.put(27,59);
    //map.put(14,84);
    //map.remove(9);
    //cout << map.get(40) << endl;
    //map.put(59,47);
    //map.remove(60);
    //map.put(33,32);
    //map.put(63,28);
    //map.remove(15);
    //map.remove(33);
    for (int i = 0; i < 20; ++i) {
        map.put(i, i);
    }
    for (int i = (1 << 14); i < (1 << 14) + 20; ++i) {
        map.put(i, i % 500);
    }
    for (int i = (1 << 14); i < (1 << 14) + 20; i += 3) {
        map.remove(i);
    }
    for (int i = (1 << 14); i < (1 << 14) + 20; ++i) {
        cout << i << "," << map.get(i) << " ";
        //map.get(i);
    }
    for (int i = 0; i < 100; ++i) {
        if (i == 20)
            i = 20;
        cout << i << "," << map.get(i) << " ";
    }
    cout << endl;
    cout << (1 << 14) << "," << map.get(1 << 14) << endl;
    cout << (1 << 14) + 2 << "," << map.get((1 << 14) + 2) << endl;
    for (int i = 0; i < 100; ++i) {
        cout << i << ":" << map.values[i] << " ";
    }
    return 0;
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */