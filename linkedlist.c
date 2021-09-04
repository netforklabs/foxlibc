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

/*! ===> Creates on 2021/8/30. <=== */

/*!
 * @author 范特西
 */
#include <linkedlist>

void linkedlist_init(struct linkedlist* list)
{
        struct linkedlist_node* node;
        node = _malloc(sizeof(struct linkedlist_node));

        list->size = 0;
        list->last = node;
        list->node = node;
        list->free_func = NULL;
}

void linkedlist_init_freefunc(struct linkedlist* list, linked_val_free free_func)
{
        linkedlist_init(list);
        list->free_func = free_func;
}

void linkedlist_add(struct linkedlist* list, linked_t value)
{
        struct linkedlist_node* node;
        node = _malloc(sizeof(struct linkedlist_node));

        node->value = value;

        node->parent = list->last;
        list->last->next = node;
        list->last = node;

        ++list->size;
}

struct linkedlist_node* linkedlist_get_node(struct linkedlist* list, size_t index)
{
        size_t count;
        struct linkedlist_node* node;
        node = list->node->next;

        if(index > list->size || index < 0)
                return NULL;

        if(index == 0)
                return node;

        if(index == (list->size - 1))
                return list->last;

        count = 0;
        while(count != index) {
                node = node->next;
                if(node == NULL)
                        return NULL;
                ++count;
        }

        return node;
}

linked_t linkedlist_get_value(struct linkedlist* list, size_t index)
{
        struct linkedlist_node* node;
        node = linkedlist_get_node(list, index);

        if(node == NULL)
                return NULL;

        return node->value;
}


void linkedlist_remove(struct linkedlist* list, size_t index)
{
        struct linkedlist_node* node;
        struct linkedlist_node* parent;

        node = linkedlist_get_node(list, index);
        if(node == NULL)
                return;

        parent = node->parent;
        parent->next = node->next;

        if(list->free_func != NULL) {
                list->free_func(node->value);
                _free(node);
        } else {
                _free(node);
        }

        --list->size;
}

void linkedlist_insert(struct linkedlist* list, size_t index, linked_t value)
{
        struct linkedlist_node* node;
        struct linkedlist_node* curnode;

        curnode = linkedlist_get_node(list, index);
        if(curnode == NULL)
                return;

        node = _malloc(sizeof(struct linkedlist_node));
        node->value = value;
        node->parent = curnode;
        node->next = curnode->next;
        curnode->next = node;
}
