cmake_minimum_required(VERSION 3.27)
project(Zaephus_Engine)

set(CMAKE_CXX_STANDARD 23)

include_directories(${PROJECT_NAME} PUBLIC Core/..)

add_executable(Zaephus_Engine main.cpp
        Core/Graphics/Material.cpp
        Core/Graphics/Mesh.cpp
        Core/Graphics/MeshRenderer.cpp
        Core/Graphics/Shader.cpp
        Core/Buffer.cpp
        Core/Device.cpp
        Core/RenderDebug.cpp
        Core/RenderInstance.cpp
        Core/Window.cpp)

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(Include/glfw-3.3.8)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(Include/glm)
target_link_libraries(${PROJECT_NAME} glm)

target_include_directories(${PROJECT_NAME} PUBLIC Include/STB_Image)