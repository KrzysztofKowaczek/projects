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
     * @brief Zwraca przechowywane punkty.
     * 
     * @return std::vector<Vector3D> Lista punktów.
     */
    std::vector<Vector3D> getPoints() const {return _points;}
    /**
     * @brief Metoda wirtualna do zwracania nazwy obiektu.
     * 
     * @return std::string Nazwa obiektu.
     */
    virtual std::string getName() const = 0;
};