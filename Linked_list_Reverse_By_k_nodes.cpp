// Complete the reverseKnodes function below.
/*
For your reference:
SinglyLinkedListNode {
int data;
SinglyLinkedListNode* next;
};
To create a new node use the below constructor
SinglyLinkedListNode(int node_data)
*/

SinglyLinkedListNode *reverseByK(SinglyLinkedListNode* &head,int k){

  
  if(head == NULL){
    return head;
  }  
  
  int count=0;
  
  SinglyLinkedListNode *prev = NULL;
  SinglyLinkedListNode *curr = head;
  SinglyLinkedListNode *forward = head;

  while(curr != NULL && count<k)
  {
    forward = curr->next;
    curr->next = prev;
    
    prev= curr;
    curr=forward;
    
    
    count++;
    
  }
  
  if(forward != NULL){
    head -> next = reverseByK(forward , k);   
  }
  
  
  
  
  return prev;
  
  
}

SinglyLinkedListNode *reverseKnodes(SinglyLinkedListNode *head,int k)
{
  
  
  if(head == NULL){
    return head;
  }
  
  SinglyLinkedListNode *ptr = reverseByK(head , k);
  
  return ptr;

}


