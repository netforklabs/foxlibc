#include <hash_map>

void print_hash_map(Hash_map map){
    Hash_node *temp;
    size_t i;
    for (i = 0; i < map->capacity; ++i) {
        if(map->hash_arr[i] != NULL){
            printf("address:%p,key:%s,value:%s,next:%p\n",map->hash_arr,map->hash_arr[i]->key,map->hash_arr[i]->value,map->hash_arr[i]->next);
            temp = map->hash_arr[i]->next;
            while (temp != NULL){
                printf("address:%p,key:%s,value:%s,next:%p\n",temp,temp->key,temp->value,temp->next);
                temp = temp->next;
            }
        }
    }
}

void init_hash_map(Hash_map* map){
  *map = (Hash_map)_malloc(sizeof(Hash_block));
  if((*map) == NULL) return;
  (*map)->size = 0;
  (*map)->capacity = MIN_HASHMAP_CAPACITY;
  (*map)->hash_arr = (Hash_node**)_malloc(sizeof(Hash_node)*MIN_HASHMAP_CAPACITY);
  memset((*map)->hash_arr,0,sizeof(Hash_node)*MIN_HASHMAP_CAPACITY);
  if((*map)->hash_arr == NULL) return;
}

size_t _hashCode_hash_map(const char *key, size_t len, size_t seed){
    static const size_t c1 = 0xcc9e2d51;
    static const size_t c2 = 0x1b873593;
    static const size_t r1 = 15;
    static const size_t r2 = 13;
    static const size_t m = 5;
    static const size_t n = 0xe6546b64;

    size_t hash = seed;

    const size_t n_blocks = len / 4;
    const size_t *blocks = (const size_t *)key;
    size_t i;
    for (i = 0; i < n_blocks; i++)
    {
        size_t k = blocks[i];
        k *= c1;
        k = (k << r1) | (k >> (32 - r1));
        k *= c2;

        hash ^= k;
        hash = ((hash << r2) | (hash >> (32 - r2))) * m + n;
    }

    const size_t *tail = (const size_t *)(key + n_blocks * 4);
    size_t k1 = 0;

    switch (len & 3){
        case 3:
            k1 ^= tail[2] << 16;
        case 2:
            k1 ^= tail[1] << 8;
        case 1:
            k1 ^= tail[0];

            k1 *= c1;
            k1 = (k1 << r1) | (k1 >> (32 - r1));
            k1 *= c2;
            hash ^= k1;
    }

    hash ^= len;
    hash ^= (hash >> 16);
    hash *= 0x85ebca6b;
    hash ^= (hash >> 13);
    hash *= 0xc2b2ae35;
    hash ^= (hash >> 16);

    return hash;
}

bool equal_hash_map(KEY_HASHMAP_TYPE key1,KEY_HASHMAP_TYPE key2){
  return hashCode_hash_map(key1,strlen(key1)) == hashCode_hash_map(key2, strlen(key2));
}

size_t getIndex_hash_map(size_t key,size_t capacity){
    return key & (capacity - 1); // 取余
}

void put_hash_map(Hash_map map,KEY_HASHMAP_TYPE key,VALUE_HASHMAP_TYPE value){
    if(map == NULL) return;
    Hash_node *node = (Hash_node*)_malloc(sizeof(Hash_node));
    if(node == NULL) return;
    node->key = (KEY_HASHMAP_TYPE)_malloc(strlen(key)+1);
    if(node->key == NULL) return;
    strcpy(node->key,key);
    node->value = (VALUE_HASHMAP_TYPE)_malloc(strlen(value)+1);
    if(node->value == NULL) return;
    strcpy(node->value,value);
    node->next = NULL;
    // =====未实现链表=====
    map->hash_arr[getIndex_hash_map(hashCode_hash_map(key,strlen(key)),map->capacity)] = node;
}

VALUE_HASHMAP_TYPE get_hash_map(Hash_map map,KEY_HASHMAP_TYPE key){
    // =====未实现链表=====
    return map->hash_arr[getIndex_hash_map(hashCode_hash_map(key,strlen(key)),map->capacity)]->value;
}

bool remove_hash_map(Hash_map map,KEY_HASHMAP_TYPE key){
    if(map == NULL) return false;
    // =====未实现链表=====
    if(map->hash_arr[getIndex_hash_map(hashCode_hash_map(key,strlen(key)),map->capacity)] == NULL) return false;
    _free(map->hash_arr[getIndex_hash_map(hashCode_hash_map(key,strlen(key)),map->capacity)]);
    map->hash_arr[getIndex_hash_map(hashCode_hash_map(key,strlen(key)),map->capacity)] = NULL;
    return true;
}

void makeEmpty_hash_map(Hash_map map){
    // =====未实现链表=====
    size_t i;
    for (i = 0; i < map->capacity; ++i) {
        if(map->hash_arr[i] != NULL){
            _free(map->hash_arr[i]);
            map->hash_arr[i] = NULL;
        }
    }
    map->size = 0;
    map->capacity = MIN_HASHMAP_CAPACITY;
}

bool exists_hash_map(Hash_map map,KEY_HASHMAP_TYPE key){
    // =====未实现链表=====
    return map->hash_arr[getIndex_hash_map(hashCode_hash_map(key,strlen(key)),map->capacity)] != NULL;
}
