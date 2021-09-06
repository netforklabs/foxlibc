#include <heap_min>

void init_heap_min(Heap_min *heap){
  if(*heap != NULL) free(*heap);
  *heap = (Heap_min)malloc(sizeof(Heap_block));
  if(*heap == NULL) return;
  (*heap)->capacity = HEAP_MIN_CAPACITY;
  (*heap)->size = 0;
}

void print_heap_min(Heap_min heap){
  printf("堆的元素为:");
  for (size_t i = 0; i < heap->size; i++) {
    printf("%d ", heap->val[i]);
  }
  printf("\n");
}

void insert_heap_min(Heap_min heap,HEAP_MIN_TYPE val){
  if(heap->size >= HEAP_MIN_CAPACITY) return;
  heap->val[heap->size] = val;
  percolate_up_heap_min(heap,heap->size);
  ++heap->size;
}

void percolate_up_heap_min(Heap_min heap,size_t pos){
  if(0 == pos) return;
  size_t middle = pos,insert = heap->val[pos],temp = 0;
  while (true) {
    temp = (middle+1)/2-1;
    if (0 == middle || insert >= heap->val[temp]) {
      heap->val[middle] = insert;
      return;
    }
    heap->val[middle] = heap->val[temp];
    middle = temp;
  }
}

int delete_min_heap_min(Heap_min heap){
  if(0 == heap->size) return INT_MIN;
  HEAP_MIN_TYPE min = heap->val[0];
  percolate_down_heap_min(heap);
  --heap->size;
  return min;
}

void percolate_down_heap_min(Heap_min heap){
  if(0 == heap->size) return;
  size_t middle = 0,temp = 0,up = 0;
  while (true) {
    temp = (middle+1)*2; // 右分支,索引从0开始
    if(temp > heap->size){ // 左右分支都不存在
      return;
    }else if(temp == heap->size){ // 只有左分支
      up = temp - 1;
    }else{ // 左右分支都存在
      up = (heap->val[temp-1] < heap->val[temp])?(temp-1):temp;
    }
    heap->val[middle] = heap->val[up];
    middle = up;
  }
  heap->val[up] = heap->val[heap->size-1];
}
