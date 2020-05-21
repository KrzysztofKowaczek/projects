#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "Shape.hh"
#include "Vector.hh"
#include "Matrix.hh"

const std::string kModelCuboid("solid/model.dat");

/**
 * @brief Modeluje pojęcie prostopadłościanu jako zbiór punktów w przestrzeni.
 * 
 * Dziedziczy z klasy Shape, rozszerzając ją o pojęcie kątu obrotu.
 */
class Cuboid : public Shape
{
private:
    double _angle;
public:
    /**
     * @brief Konstruktor klasy Cuboid.
     * 
     * Inicjalizuje rostopadłościan wczytując model z pliku.
     * Model ten staje się wzorcem odniesienia do wszelkich operacji.
     */
    Cuboid();
    Cuboid(std::string filename);
    /**
     * @brief Ustawia kąt obrotu prostopadłościanu względem osi Z.
     * 
     * Ustawia kąt obrotu względem osi Z, którego wykorzystuje klasa Cuboid.
     * 
     * @param angle Kąt obrotu względem osi Z.
     */
    void setAngle(double angle) 
            {_angle = angle; while(_angle > 360) _angle -= 360;}
    /**
     * @brief Zwraca kąt obrotu prostopadłościanu względem osi Z.
     * 
     * @return double - kąt obrotu. 
     */
    double getAngle() const {return _angle;}
    /**
     * @brief Zapisuje współrzędne prostopadłościanu po obliczeniach do pliku.
     * 
     * Funkcja oblicza obrót każdego punktu względem osi Z oraz przesuwa każdą
     * współrzędną prostopadłościanu o wektor translacji.
     * 
     * @param filename Nazwa pliku, do którego mają zostać wpisane punkty.
     */
    virtual void draw(std::string filename) const override;
    virtual std::string getName() const override {return "prostopadloscian";}
};