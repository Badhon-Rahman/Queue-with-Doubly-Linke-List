#include <iostream>

using namespace std;

typedef struct QueueNode{
      int data;
      struct QueueNode *nextNode;
      struct QueueNode *previousNode;
}*queuePtr;

queuePtr front = NULL, rear = NULL;

void EnQueueListData(int enQueue){
         queuePtr newNode = new QueueNode;
         newNode->data = enQueue;
         newNode->nextNode = NULL;
         if(rear == NULL && front == NULL){
            newNode->previousNode = NULL;
            rear = newNode;
            front = newNode;
         }
         else{
            newNode->previousNode = rear;
            rear->nextNode = newNode;
            rear = newNode;
         }
}

void DeQueueListData(){
          queuePtr dequeuePtr = front;
          if(front == NULL){
            cout << "Queue List is Empty!!!" << endl;
          }
          else if(front->nextNode == NULL){
            cout << "Data Dequeued: " << dequeuePtr->data << endl;
            front = NULL;
            rear = NULL;
            delete(dequeuePtr);
          }
          else{
            front = front->nextNode;
            front->previousNode = NULL;
            cout << "Data Dequeued: " << dequeuePtr->data << endl;
            delete(dequeuePtr);
          }
}

void TraverseQueueList(){
          queuePtr traversePtr = front;
          if(front == NULL){
            cout << "Queue List is Empty!!!" << endl;
          }
          else{
            cout << "Queue List Data: ";
            while(traversePtr != NULL){
               cout << traversePtr->data << " ";
               traversePtr = traversePtr->nextNode;
            }
            cout << endl;
          }
}


int main()
{
    int choice;

    do{
      cout << "Press 1 to Enqueue element in Queue List." << endl;
      cout << "Press 2 to Dequeue element from Queue List." << endl;
      cout << "Press 3 to display element of the Queue List." << endl;
      cout << "Press 4  Exit System." << endl;
      cout << "Select Your Choice: ";
      cin >> choice;
      switch(choice){
             case 1:{
                    int enQueue;
                    cout << "Enter the pushing element: ";
                    cin >> enQueue;
                    EnQueueListData(enQueue);
                    break;
             }
             case 2:{
                    DeQueueListData();
                    break;
             }
             case 3:{
                  TraverseQueueList();
                  break;
             }
             case 4:{
                    cout << "Exit System." << endl;
                    break;
             }
             default:{
                  cout << "You peek the WRONG choice. Select your choice again:";
             }
      }
    } while(choice != 4);
    return 0;
}
