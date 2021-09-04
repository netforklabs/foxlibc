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
 * @author LAB
 */

#include <stack_link>

void print_stack_link(Stack_link stack){
    if(stack == NULL) return;
    Node_link *temp = stack->next;
    while(temp != NULL){
        printf("%d\n",temp->val);
        temp = temp->next;
    }
}

Stack_link create_stack_link(){
	Stack_link stack = (Stack_link)malloc(sizeof(Node_link));
	if(stack == NULL) return stack;
	stack->next = NULL;
	stack->val = -1;
	return stack;
}

bool isEmpty_stack_link(Stack_link stack){
	return (bool)(stack->next == NULL);
}

void makeEmpty_stack_link(Stack_link stack){
	Node_link *temp = stack->next,*del;
	stack->next = NULL;
    while(temp != NULL){
        del = temp->next;
        free(temp);
        temp = del;
    }
}

void push_stack_link(Stack_link stack,STACK_LINK_TYPE val){
	Node_link *push_ = (Node_link*)malloc(sizeof(Node_link));
    if(push_ == NULL) return;
	push_->val = val;
	push_->next = stack->next;
	stack->next = push_;
}

STACK_LINK_TYPE pop_stack_link(Stack_link stack){
	if(isEmpty_stack_link(stack)) return INT_MIN;
    Node_link *pop_ = stack->next;
    STACK_LINK_TYPE res = pop_->val;
    stack->next = pop_->next;
    free(pop_);
    return res;
}

STACK_LINK_TYPE top(Stack_link stack){
	if(isEmpty_stack_link(stack)) return INT_MIN;
    return stack->next->val;
}

