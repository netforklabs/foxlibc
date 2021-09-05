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
#include <stack_link>

void test(Stack_link stack){
    printf("栈的大小:%u\n", stack->size);
    printf("是否为空:%d\n", isEmpty_stack_link(stack));
    printf("获取栈顶元素:%d\n", top_stack_link(stack));
    print_stack_link(stack);
}

int main(void){
    Stack_link stack;
    init_stack_link(stack);
    test(stack);

    push_stack_link(stack,10);
    push_stack_link(stack,5);
    push_stack_link(stack,9);
    push_stack_link(stack,19);
    push_stack_link(stack,15);
    test(stack);

    pop_stack_link(stack);
    pop_stack_link(stack);
    pop_stack_link(stack);
    test(stack);

    makeEmpty_stack_link(stack);
    test(stack);

    getchar();
    return 0;
}
