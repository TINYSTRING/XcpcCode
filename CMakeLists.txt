cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)
project(XcpcCode VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(XcpcCode main.cpp)

# add_executable(XcpcCode)
# file(GLOB sources *.cpp *.h)
# target_sources(XcpcCode PUBLIC ${sources})

# add_executable(XcpcCode main.cpp)
# target_sources(XcpcCode PUBLIC test.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# cmake_minimum_required(VERSION 3.10)
# cmake_policy(SET CMP0076 NEW)
# project(XcpcCode VERSION 0.1.0 LANGUAGES C CXX)

# include(CTest)
# enable_testing()

# add_executable(XcpcCode)  # 创建名为XcpcCode的可执行文件

# file(GLOB sources *.cpp *.h)  # 获取当前目录下的所有.cpp和.h文件
# target_sources(XcpcCode PUBLIC ${sources})  # 将这些文件作为XcpcCode可执行文件的公共源文件

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
