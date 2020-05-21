#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "Matrix.hh"

/**
 * @brief Modeluje pojęcie bryły jako zbiór punktów w przestrzeni.
 * 
 * Klasa ta służy do przechowywania punktów składowych bryły oraz ich 
 * przesunięcia względem środka bezwzględnego układu współrzędnych.
 */
class Shape
{
protected:
    std::vector<Vector3D> _points;
    Vector3D _translation;
public:
    //void generate(std::string filename) const;
    /**
     * @brief Metoda ta ustawia wektor translacji bryły.
     * 
     * @param trans Wektor translacji bryły.
     */
    void translate(const Vector3D &trans) {_translation = trans;}
    /**
     * @brief Zwraca wektor translacji bryły.
     * 
     * @return Vector3D - wektor translacji.
     */
    Vector3D getTranslation() const {return _translation;}
    /**
     * @brief Konstruktor klasy Shape.
     * 
     * Wczytuje z pliku współrzędne bryły.
     * 
     * @param filename Nazwa pliku ze współrzędnymi.
     */
    Shape(std::string filename);
    /**
     * @brief Konstruktor bezparametryczny klasy Shape.
     * 
     * Nic nie inicjalizuje, po prostu sobie jest.
     */
    Shape() {}

    virtual void draw(std::string filename) const = 0;
};