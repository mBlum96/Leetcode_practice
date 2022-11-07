#include <stdlib.h>
#include <string.h>

//with this implementation I may get fregmentation and waste of memeory

//globals
char *buff;
int buffSize;
int counter=0;

//the struct we will be working with (no pointers)
struct Node{
    void *data;
    int next;
};
typedef struct Node Nodetype;

//because we cannot use pointers in the node struct
//and  we need to be able to write to the buffer
//and also locate the different nodes in the buffer
//this is why we are going to have one pointer for the buffer so that we know
//where to write and read to/from

struct Node createLinkedList(void *data, char *buff){//we need a function to initialize the linked list
//we assume that we don't reach the end of the buffer
    Nodetype head;
    head.data = data;
    memcpy(buff,head.data,sizeof(head.data));
    buff+= sizeof(head.data);
    head.next = NULL;
    memcpy(buff,head.next,sizeof(head.next));
    buff+= sizeof(head.next);
    return head;
}

void addNode(char *buffPtr, Nodetype head, void *data){//this function adds an element to the end of the linked list
    char *localBuffPtr = &buffPtr;
    Nodetype localHead = head;
    while(localHead.next!=NULL){//next is the
        //"index" (how many shifts we need to do) of the next node in the buff
        localBuffPtr = buffPtr + (localHead.next * sizeof(Nodetype));
        memcpy(localHead.data,*localBuffPtr,sizeof(head.data));
        localBuffPtr += sizeof(localHead.data);
        memcpy(localHead.next,*localBuffPtr,sizeof(head.next));
    }
    //now we have reached the place in the buffer where we can allocate the new node
    localHead.next = counter++;
    memcpy(localBuffPtr,localHead.next,sizeof(head.next));
    localBuffPtr = buffPtr + localHead.next * sizeof(Nodetype);
    createLinkedList(data, localBuffPtr);
}

void deleteNode(char *buffPtr, Nodetype head, void *val){//val is the value
//of the node we want to delete. we assume the node's values are unique
    char *localBuffPtr = &buffPtr;
    char *lastLocation = &buffPtr;
    Nodetype localHead = head;
    while(localHead.data!=val){
        lastLocation = localBuffPtr;
        //next is the
        //"index" (how many shifts we need to do) of the next node in the buff
        localBuffPtr = buffPtr + (localHead.next * sizeof(Nodetype));
        memcpy(localHead.data,*localBuffPtr,sizeof(head.data));
        localBuffPtr += sizeof(localHead.data);
        memcpy(localHead.next,*localBuffPtr,sizeof(head.next));
    }
    memcpy(lastLocation,head.next,sizeof(head.next));
    //now we are at the node we want to delete and we have the buff location of the "next"
    //field of the node that is the privous node in the list
    //we need to make the privous node point to the next node
    //this way we get segmentation cause we are not going to use this buffer
    //space for something else but this is the mnost straight forward
    //approach I could think of
}

// int main(int argc, char *argv){
//     counter = 0;
//     char const *bufferPtr = &buff;
//     Nodetype const head = createLinkedList(argv[0],buff);

// }