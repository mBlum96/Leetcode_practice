class MyHashSet {
private:
    using listVector = vector<list<int>>;

    int prime;
    listVector table;
    
    int hashFunc(int key){
        return key%prime;
    }
    
    list<int>::iterator search(int key){
        int hashedKey = hashFunc(key);
        return find(table[hashedKey].begin(),table[hashedKey].end(), key);
    }
    
public:
    /** Initialize your data structure here. */
    MyHashSet() : prime(10000), table(prime){

    }

    void add(int key) {
        int hashedKey = hashFunc(key);
        if(!contains(key)){
            table[hashedKey].push_back(key);
        }
    }
    
    void remove(int key) {
        int hashedKey = hashFunc(key);
        if(contains(key) /*&& table[hashedKey].search(key)!=
            table[hashedKey].end()*/){
            table[hashedKey].erase(search(key));
        }

    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashedKey = hashFunc(key);
        return search(key) != table[hashedKey].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
