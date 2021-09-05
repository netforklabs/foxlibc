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
  ++heap->size;
  // 小的向上渗透
}
