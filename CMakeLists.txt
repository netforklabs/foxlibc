# =================================================================================
#
# Copyright (C) 2020 netforklabs All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# =================================================================================/

### ==============================================
### ===> Creates on 2021/07/20. <=== ###
### author 范特西
CMAKE_MINIMUM_REQUIRED(VERSION 3.13...3.19)
#CMAKE_MINIMUM_REQUIRED(VERSION 3.1...)
PROJECT(foxlibc C)

SET(CMAKE_C_STANDARD 99)

ADD_DEFINITIONS(-DBUILD_DLL)
ADD_DEFINITIONS(-fgnu89-inline)

INCLUDE_DIRECTORIES(${PROJECT_NAME} SYSTEM ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
        main.c
        string.c
<<<<<<< HEAD
        stack_link.c
)
=======
        linkedlist.c
)
>>>>>>> 3baa3435adc02db0edf46825a343ce772cddfbaa
