/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* t = head;
        unordered_map<Node*,Node*> mp;

        while(t){
            mp[t] = new Node(t->val);
            t=t->next;
        }

        t=head;
        while(t){
            mp[t]->next = mp[t->next];
            mp[t]->random = mp[t->random];

            t=t->next;
        }

        return mp[head];



    }
};
// Fix 1: Handle empty list edge case
        // Pass 1: Clone all nodes and map old nodes to new nodes
                // Pass 2: Connect the next and random pointers of the clones

