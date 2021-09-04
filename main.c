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
 * @author 范特西
 */
#include <linkedlist>

int main(void)
{
        struct linkedlist list;
        linkedlist_init(&list);

        linkedlist_add(&list, "a");
        linkedlist_add(&list, "b");
        linkedlist_add(&list, "c");
        linkedlist_add(&list, "d");
        linkedlist_add(&list, "e");

        printf("%s\n", linkedlist_get_value(&list, 0));
        printf("%s\n", linkedlist_get_value(&list, 1));
        printf("%s\n", linkedlist_get_value(&list, 2));
        printf("%s\n", linkedlist_get_value(&list, 3));
        printf("%s\n", linkedlist_get_value(&list, 4));

        return 0;
}