/*
Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

SET x y: sets the value of the key x with value y
GET x: gets the key of x if present else returns -1.

The LRUCache class has two methods get() and set() which are defined as follows.

get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be initialized.
 

Example 1:

Input:
cap = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: 
Cache Size = 2

SET 1 2 GET 1
SET 1 2 : 1 -> 2

GET 1 : Print the value corresponding
to Key 1, ie 2.

Example 2:

Input:
cap = 2
Q = 8
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
Output: 5 -1
Explanation: 
Cache Size = 2
SET 1 2 : 1 -> 2

SET 2 3 : 1 -> 2, 2 -> 3 (the most recently 
used one is kept at the rightmost position) 

SET 1 5 : 2 -> 3, 1 -> 5

SET 4 5 : 1 -> 5, 4 -> 5 (Cache size is 2, hence 
we delete the least recently used key-value pair)

SET 6 7 : 4 -> 5, 6 -> 7 

GET 4 : Prints 5 (The cache now looks like
6 -> 7, 4->5)

SET 1 2 : 4 -> 5, 1 -> 2 
(Cache size is 2, hence we delete the least 
recently used key-value pair)

GET 3 : No key value pair having 
key = 3. Hence, -1 is printed.

Your Task:
You don't need to read input or print anything. Complete the constructor and get(), and set() methods of the class LRUcache. 


Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). 
(Although, you may use extra space for cache storage and implementation purposes).


Constraints:
1 <= cap <= 10^3
1 <= Q <= 10^5
1 <= x, y <= 10^4
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
        struct node {
            int key,val;
            node* prev;
            node* next;
            
            node(int k,int v) {
               key=k;
               val=v;
            }
        };
    
        node* head=new node(-1,-1);
        node* tail=new node(-1,-1);
        
        int capacity;
        unordered_map<int,node*> mp;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity=cap;
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
    }
    
    void insert(node* temp)
    {
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        
        mp[temp->key]=temp;
    }
    
    void rem(node* temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(mp.find(key)==mp.end())
        return -1;
        
        node* cur=mp[key];
        rem(cur);
        insert(cur);
        return cur->val;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            node* cur=mp[key];
            cur->val=value;
            
            rem(cur);
            insert(cur);
            
        }
        
        else if(mp.size()<capacity)
        {
            node* newnode=new node(key,value);
            insert(newnode);
        }
        
        else
        {
            //permanently remove the least used node
            node* cur=tail->prev;
            rem(cur);
            mp.erase(cur->key);
            delete cur;
            
            //insert the new node
            node* newnode=new node(key,value);
            insert(newnode);
            
            
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
