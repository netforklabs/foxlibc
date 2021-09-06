/*! ************************************************************************
 *
 * Copyright (C) 2020 netforklabs All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/8/28. <=== */

/*!
 * @author LAB
 */
#include <heap_min>

void test(Heap_min heap){
    printf("¶ÑµÄÈİÁ¿:%u\n", heap->capacity);
    printf("¶ÑµÄ´óĞ¡:%d\n", heap->size);
    print_heap_min(heap);
    printf("\n");
}

int main(void){
    Heap_min heap = NULL;
    init_heap_min(&heap);
    test(heap);

    insert_heap_min(heap,12);
    insert_heap_min(heap,10);
    insert_heap_min(heap,6);
    insert_heap_min(heap,100);
    insert_heap_min(heap,99);
    insert_heap_min(heap,200);
    insert_heap_min(heap,2);
    insert_heap_min(heap,1);
    test(heap);

    printf("É¾³ı:%d\n", delete_min_heap_min(heap));
    test(heap);
    printf("É¾³ı:%d\n", delete_min_heap_min(heap));
    test(heap);
    printf("É¾³ı:%d\n", delete_min_heap_min(heap));
    test(heap);
    printf("É¾³ı:%d\n", delete_min_heap_min(heap));
    test(heap);

    getchar();
    return 0;
}
