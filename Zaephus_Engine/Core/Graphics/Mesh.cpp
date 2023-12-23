
#include "Mesh.h"

void Mesh::initialize() {

}

void Mesh::render() {

}

void Mesh::createVertexBuffer() {

    std::vector<Vertex> vertexList = getVertexList();

    VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();



}

void Mesh::createIndexBuffer() {

}

void Mesh::updateUniformBuffer() {

}

const std::vector<Vertex> Mesh::getVertexList() {
    return std::vector<Vertex> {};

}