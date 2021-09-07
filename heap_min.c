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
  printf("�ѵ�Ԫ��Ϊ:");
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
  heap->val[pos] = heap->val[heap->size-1]; // �����һ��Ԫ�ظ�ֵ��Ҫɾ����Ԫ��
  --heap->size;
  percolate_down_heap_min(heap,pos);
  return del;
}

void percolate_down_heap_min(Heap_min heap,size_t pos){
  if(0 == heap->size) return;
  HEAP_MIN_TYPE down = heap->val[pos]; // Ҫ�½���Ԫ��
  size_t middle = pos; // ��Ѩ������
  size_t temp = 0; // �ӷ�֧����
  size_t up = 0; // ���ҷ�֧С��Ԫ������(����ɾ)
  while (true) {
    temp = (middle+1)*2; // �ҷ�֧,������0��ʼ
    if(temp > heap->size){ // ���ҷ�֧��������
      break;
    }else if(temp == heap->size){ // ֻ�����֧
      up = temp - 1;
    }else{ // ���ҷ�֧������
      up = (heap->val[temp-1] < heap->val[temp])?(temp-1):temp;
    }
    if(down <= heap->val[up]) break; // �½�Ԫ�����ӷ�֧��СԪ�رȽ�
    heap->val[middle] = heap->val[up]; // ����֧��С�ĸ�������Ѩ
    middle = up;
  }
  heap->val[middle] = down; // ���½���ֵ�������õ��Ŀ�Ѩ
}

Heap_min build_heap_min(HEAP_MIN_TYPE *ele,int len){
  Heap_min heap = (Heap_min)malloc(sizeof(Heap_block));
  if(heap == NULL) return NULL;
  heap->capacity = HEAP_MIN_CAPACITY;
  heap->size = len;
  for (size_t i = 0; i < len; i++) { // ��ֵ
    heap->val[i] = ele[i];
  }
  for (int i = (len/2-1); i >= 0; i--) { // �½�
    percolate_down_heap_min(heap,i);
  }
}
