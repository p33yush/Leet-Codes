/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/



class Solution {
  public:
  
    Node *solve(Node *currHead ){
      vector<int> res ;
      Node *newHead ;
      while(currHead != nullptr){
          res.push_back(currHead->data)  ;
          Node *b = currHead->bottom ;
          currHead = currHead->next ;
          while(b){
              res.push_back(b->data) ;
              b = b->bottom ;
          }
      }
      sort(res.begin() , res.end()) ;    
      Node * curr = nullptr ; 
      for(int i : res){
          int v = i ;
          if(!curr){
              curr = new Node(v) ;
              newHead = curr ;
          }
          else {
              curr->next = new Node(v) ;
              curr = curr->next ;
          }
      }
      return newHead ;
    }
  
    Node* flatten(Node* head) {
        //base case
        if(!head)return nullptr;
        
        // if(!head->next){
        //     Node *t ;
        //     Node *curr ;
        //     while(head->bottom){
        //         int v= head->data ;
        //         if(!curr){
        //             curr = new Node(v) ;
        //             t = curr ;
        //         }
        //         else{
        //           curr->next = new Node(v) ; 
        //           curr =curr->next ;
        //         }
        //     }
        //     return t ;
        // }

        // vector<int> res;
        /*
        Node x  ;
            ->previous bottom
            ->next head node 
            ->current bottom node 
            ->resolution of bottom linked list 
            -> global next point for next node from the current node 
        */
        
       vector<int> res ;
      Node *newHead = nullptr;
      Node *currHead = head ;
      while(currHead != nullptr){
          res.push_back(currHead->data)  ;
          Node *b = currHead->bottom ;
          currHead = currHead->next ;
          while(b){
              res.push_back(b->data) ;
              b = b->bottom ;
          }
      }
      sort(res.begin() , res.end()) ;    
      Node * curr = nullptr ; 
      for(int i : res){
          int v = i ;
          if(!curr){
              curr = new Node(v) ;
              newHead = curr ;
          }
          else {
              curr->bottom = new Node(v) ;
              curr = curr->bottom ;
          }
      }
      return newHead ;
        
        // return newHead ;
        
    }
};