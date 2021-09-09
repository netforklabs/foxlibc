#include <hash_map>

void print_hash_map(Hash_map map){

}

void init_hash_map(Hash_map* map){
  *map = (Hash_map)malloc(sizeof(Hash_block));
  if((*map) == NULL) return;
  (*map)->size = 0;
  (*map)->capacity = MIN_HASHMAP_CAPACITY;
  (*map)->hash_arr = (Hash_node**)malloc(sizeof(Hash_node)*MIN_HASHMAP_CAPACITY);
  if((*map)->hash_arr == NULL) return;
}

int HashCode_hash_map(Hash_map map,void* key){
  return 0;
}

bool equal_hash_map(KEY_HASHMAP_TYPE key1,KEY_HASHMAP_TYPE key2){
  return true;
}

void put_hash_map(Hash_map map,KEY_HASHMAP_TYPE key,VALUE_HASHMAP_TYPE value){

}

VALUE_HASHMAP_TYPE get_hash_map(Hash_map map,KEY_HASHMAP_TYPE key){
  return "";
}

bool remove_hash_map(Hash_map map,KEY_HASHMAP_TYPE key){
  return true;
}

void makeEmpty_hash_map(Hash_map map){

}

bool exists_hash_map(Hash_map map,KEY_HASHMAP_TYPE key){
  return true;
}
