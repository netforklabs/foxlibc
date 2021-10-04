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
#include <hash_map>

void test(Hash_map map){
}

int main(void){
    Hash_map map;
    init_hash_map(&map);

    put_hash_map(map,"aaa","aaa1");
    put_hash_map(map,"bbb","aaa2");
    put_hash_map(map,"ccc","aaa3");
    put_hash_map(map,"ddd","aaa4");
    put_hash_map(map,"eee","aaa5");
    print_hash_map(map);

    printf("get:%s\n",get_hash_map(map,"ccc"));

    remove_hash_map(map,"zzz");
    remove_hash_map(map,"aaa");
    print_hash_map(map);

    printf("equal:%d\n",equal_hash_map("aaa","aaa"));
    printf("equal:%d\n",equal_hash_map("aaa","aa1"));

    printf("exist:%d\n",exists_hash_map(map,"bbb"));
    printf("exist:%d\n",exists_hash_map(map,"aaa"));

    makeEmpty_hash_map(map);
    print_hash_map(map);

    printf("input every char exit...\n");
    getchar();
    return 0;
}
