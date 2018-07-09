cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_CXX_STANDARD 11)

find_library(sfml-window sfml-window)
find_library(sfml-system sfml-system)
find_library(sfml-graphics sfml-graphics)

set(SOURCE_FILES SFMLGraphVisualizer.cpp DiGraph.cpp DiGraph.h Node.cpp Node.h Edge.cpp Edge.h List.hpp main.cpp SFMLGraphVisualizer.h GraphVisualizer.cpp GraphVisualizer.h Navigator.hpp PriorityQueue.hpp PriorityQueueEntry.hpp QueueException.cpp QueueException.h tokenizer.hpp tokenizer.cpp)
add_executable(project ${SOURCE_FILES})
target_link_libraries(project sfml-window sfml-system sfml-graphics)