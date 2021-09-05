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
    if(isEmpty_stack_link(stack)) return;
    Node_link *temp = stack->top;
    printf("Õ»µÄÔªËØÎª:");
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void init_stack_link(Stack_link *stack){
  if((*stack)->top != NULL) makeEmpty_stack_link(*stack);
  if(*stack != NULL) return;
	*stack = (Stack_link)malloc(sizeof(Stack_head));
	if(*stack == NULL) return;
  (*stack)->size = 0;
	(*stack)->top = NULL;
}

bool isEmpty_stack_link(Stack_link stack){
	return (bool)(stack->size == 0);
}

bool makeEmpty_stack_link(Stack_link stack){
	while (stack->size) {
    if (!pop_stack_link(stack)) {
      return false;
    }
  }
  return true;
}

bool push_stack_link(Stack_link stack,STACK_LINK_TYPE val){
	Node_link *push_ = (Node_link*)malloc(sizeof(Node_link));
  if(push_ == NULL) return false;
	push_->val = val;
	push_->next = stack->top;
	stack->top = push_;
  ++stack->size;
  return true;
}

STACK_LINK_TYPE pop_stack_link(Stack_link stack){
	if(isEmpty_stack_link(stack)) return INT_MIN;
    Node_link *pop_ = stack->top;
    STACK_LINK_TYPE res = pop_->val;
    stack->top = pop_->next;
    free(pop_);
    pop_ = NULL;
    --stack->size;
    return res;
}

STACK_LINK_TYPE top_stack_link(Stack_link stack){
	if(isEmpty_stack_link(stack)) return INT_MIN;
    return stack->top->val;
}
