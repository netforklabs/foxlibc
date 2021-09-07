#include <heap_min>

void init_heap_min(Heap_min *heap){
  if(*heap != NULL){
    (*heap)->size = 0;
    return;
  }
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
  ++heap->size;
  percolate_up_heap_min(heap,heap->size-1);
}

void percolate_up_heap_min(Heap_min heap,size_t pos){
  if((0 == pos) || pos >= heap->size) return;
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
  return delete_heap_min(heap,0);
}

int delete_heap_min(Heap_min heap,size_t pos){
  if((0 == heap->size) || pos >= heap->size) return INT_MIN;
  HEAP_MIN_TYPE del = heap->val[pos];
  heap->val[pos] = heap->val[heap->size-1]; // 将最后一个元素赋值给要删除的元素
  --heap->size;
  percolate_down_heap_min(heap,pos);
  return del;
}

void percolate_down_heap_min(Heap_min heap,size_t pos){
  if(0 == heap->size) return;
  HEAP_MIN_TYPE down = heap->val[pos]; // 要下降的元素
  size_t middle = pos; // 空穴的索引
  size_t temp = 0; // 子分支索引
  size_t up = 0; // 左右分支小的元素索引(可以删)
  while (true) {
    temp = (middle+1)*2; // 右分支,索引从0开始
    if(temp > heap->size){ // 左右分支都不存在
      break;
    }else if(temp == heap->size){ // 只有左分支
      up = temp - 1;
    }else{ // 左右分支都存在
      up = (heap->val[temp-1] < heap->val[temp])?(temp-1):temp;
    }
    if(down <= heap->val[up]) break; // 下降元素与子分支最小元素比较
    heap->val[middle] = heap->val[up]; // 将分支中小的赋给父空穴
    middle = up;
  }
  heap->val[middle] = down; // 将下降的值赋给最后得到的空穴
}

Heap_min build_heap_min(HEAP_MIN_TYPE *ele,int len){
  Heap_min heap = (Heap_min)malloc(sizeof(Heap_block));
  if(heap == NULL) return NULL;
  heap->capacity = HEAP_MIN_CAPACITY;
  heap->size = len;
  for (size_t i = 0; i < len; i++) { // 赋值
    heap->val[i] = ele[i];
  }
  for (int i = (len/2-1); i >= 0; i--) { // 下降
    percolate_down_heap_min(heap,i);
  }
}
