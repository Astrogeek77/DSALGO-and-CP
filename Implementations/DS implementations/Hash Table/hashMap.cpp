#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

template <typename K, typename V>
class HashMap
{
private:
    struct HashNode
    {
        K key;
        V value;
        HashNode *next;
        HashNode(const K &k, const V &v) : key(k), value(v), next(nullptr) {}
    };

    vector<HashNode *> buckets;
    int size;

    int hashFunction(const K &key) const
    {
        int magic_num = 0, WEIRD_PRIME = 91;

        for (int i = 0; i < key.size(); i++)
        {
            char ch = key[i];
            int charCode = (int)ch - 96;
            magic_num = (magic_num * WEIRD_PRIME + charCode) % buckets.size();
        }
        return magic_num;
    }

    bool contains(const vector<V> &vec, const V &element) const
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[i] == element)
            {
                return true;
            }
        }
        return false;
    }

    vector<K> getKeys() const
    {
        vector<K> keys;

        for (int i = 0; i < buckets.size(); i++)
        {
            HashNode *current = buckets[i];
            while (current)
            {
                keys.push_back(current->key);
                current = current->next;
            }
        }

        return keys;
    }

    vector<V> getValues() const
    {
        vector<V> values;

        for (int i = 0; i < buckets.size(); i++)
        {
            HashNode *current = buckets[i];
            while (current)
            {
                values.push_back(current->value);
                current = current->next;
            }
        }

        return values;
    }

    vector<V> getUniqueValues2() const
    {
        unordered_set<V> uniqueValues;
        for (int i = 0; i < buckets.size(); i++)
        {
            HashNode *current = buckets[i];
            while (current)
            {
                uniqueValues.insert(current->value);
                current = current->next;
            }
        }

        vector<V> values(uniqueValues.begin(), uniqueValues.end());
        return values;
    }

    vector<V> getUniqueValues() const
    {
        vector<V> values;

        for (int i = 0; i < buckets.size(); i++)
        {
            HashNode *current = buckets[i];
            while (current)
            {
                if (!contains(values, current->value))
                {
                    values.push_back(current->value);
                }
                current = current->next;
            }
        }

        return values;
    }

public:
    HashMap(int capacity = 50) : buckets(capacity), size(0) {}

    void put(const K &key, const V &value)
    {
        int index = hashFunction(key);
        // cout << "index for " << key << ": " << index << endl;
        HashNode *current = buckets[index];

        while (current)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }

        HashNode *newNode = new HashNode(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
        ++size;
    }

    V get(const K &key) const
    {
        int index = hashFunction(key);
        HashNode *current = buckets[index];

        while (current)
        {
            if (current->key == key)
                return current->value;

            current = current->next;
        }

        throw out_of_range("Key not found");
    }

    void remove(const K &key)
    {
        int index = hashFunction(key);
        HashNode *current = buckets[index];
        HashNode *prev = nullptr;

        while (current)
        {
            if (current->key == key)
            {
                if (prev)
                    prev->next = current->next;
                else
                    buckets[index] = current->next;

                delete current;
                --size;
                return;
            }
            prev = current;
            current = current->next;
        }

        throw out_of_range("Key not found");
    }

    void printKeys()
    {
        cout << "Keys: ";
        for (K key : getKeys())
        {
            cout << key << " ";
        }
        cout << endl;
    }

    void printValues()
    {
        cout << "Values: ";
        for (V value : getValues())
        {
            cout << value << " ";
        }
        cout << endl;
    }

    void printUniqueValues()
    {
        cout << "Unique values: ";
        for (V value : getUniqueValues())
        {
            cout << value << " ";
        }
        cout << endl;
    }

    void printAllKeyValuePairs()
    {
        cout << "All Key->Value pairs:" << endl;
        for (int i = 0; i < buckets.size(); i++)
        {
            HashNode *curr = buckets[i];
            while (curr)
            {
                cout << curr->key << "->" << curr->value << endl;
                curr = curr->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    HashMap<string, string> hashMap;
    hashMap.put("blue", "#0000FF");
    hashMap.put("pink", "#FFC0CB");
    hashMap.put("magenta", "#FF00FF");
    hashMap.put("green", "#008000");
    hashMap.put("cyan", "#00FFFF");
    hashMap.put("yellow", "#FFFF00");
    hashMap.put("red", "#FF0000");
    hashMap.put("hi", "hello");
    hashMap.put("hey", "hello");
    hashMap.put("bonjour", "hello");
    hashMap.put("bye", "bye!!");
    hashMap.put("bye", "goodbye");
    hashMap.put("hi", "Hello");

    hashMap.printKeys();
    hashMap.printUniqueValues();
    hashMap.printValues();

    hashMap.printAllKeyValuePairs();

    // cout << hashMap.get("yellow") << endl;
    return 0;
}
