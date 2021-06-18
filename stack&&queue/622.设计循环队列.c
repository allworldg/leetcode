typedef struct MyCircularQueue {
    int size;//数组当前长度
    int capacity;//数组容量
    int head;//数组下标
    int tail;//数组下标
    int* data;//数组
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    if(k<0){
        return NULL;
    }
    MyCircularQueue *queue = malloc(sizeof(MyCircularQueue));
    queue->capacity = k;
    queue->data = malloc(sizeof(int)*k);
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->capacity==obj->size){
        return false;
    }
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail+1)%obj->capacity;
    ++obj->size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size==0){
        return false;
    }
    obj->data[obj->head] = 0;
    obj->head = (obj->head+1)%obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->size==0){
        return -1;
    }
    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size==0){
        return -1;
    }
    int i = obj->tail==0?obj->capacity-1:obj->tail-1;
    return obj->data[i];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size==0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size==obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/