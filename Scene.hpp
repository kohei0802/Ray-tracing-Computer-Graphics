#pragma once

#include <vector>
#include <memory>
#include "Vector.hpp"
#include "Object.hpp"
#include "Light.hpp"

class Scene
{
public:
    // setting up options
    int width = 1280;
    int height = 960;
    double fov = 90;
    Vector3f backgroundColor = Vector3f(0.235294, 0.67451, 0.843137);
    // max reflection / refraction, originally 5
    int maxDepth = 50;
    float epsilon = 0.00001;

    Scene(int w, int h) : width(w), height(h)
    {}

    // transferring objects' ownerships to Scene's vector
    void Add(std::unique_ptr<Object> object) { objects.push_back(std::move(object)); }
    // transferring light's ownerships to Scene's vector
    void Add(std::unique_ptr<Light> light) { lights.push_back(std::move(light)); }

    // copying the vector that has the unique_ptr to objects
    [[nodiscard]] const std::vector<std::unique_ptr<Object> >& get_objects() const { return objects; }
    [[nodiscard]] const std::vector<std::unique_ptr<Light> >&  get_lights() const { return lights; }

private:
    // creating the scene (adding objects and lights)
    std::vector<std::unique_ptr<Object> > objects;
    std::vector<std::unique_ptr<Light> > lights;
};