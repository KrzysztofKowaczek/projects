#pragma once

#include "Shape.hh"

#include <memory>
#include <vector>

/**
 * @brief Służy jako kontener wszystkich obiektów na scenie.
 * 
 */
class Scene
{
public:
    /**
     * @brief Lista wszystkich obiektów pochodnych Shape.
     * 
     * Są to obiekty dziedziczące z klasy Shape, lista je zbiera w jedno miejsce.
     */
    std::vector<std::shared_ptr<Shape>> objects;
    /**
     * @brief Konstruktor klasy Scene.
     * 
     * Inicjalizuje wszystkie obiekty sceny i ładuje je do listy.
     */
    Scene();
};