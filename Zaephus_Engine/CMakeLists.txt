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
        Core/Window.cpp
        Core/Math/Matrices/Matrix4x4.h
        Core/Math/Vectors/Vector2.h
        Core/Math/Vectors/Vector2Int.h
        Core/Math/Vectors/Vector3.h
        Core/Math/Vectors/Vector3Int.h
        Core/Math/Vectors/Vector4.h
        Core/Math/Vectors/Vector4Int.h
        Core/Math/Math.h
        Core/Math/Matrices/Matrix3x3.h
        Core/Math/Quaternion.h
        Core/Math/Matrices/Matrix2x2.h
        Core/Math/MathHelper.h)

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