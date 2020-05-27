#pragma once

#include <string>

#include "Shape.hh"
#include "Vector.hh"

/**
 * @brief Modeluje pojęcie wirnika jako zbiór punktów w przestrzeni.
 * 
 * Klasa ta jest zoptymalizowana pod kątem współpracy z klasą Drone.
 */
class Rotor: public Shape
{
private:
    double _angle;
    double _rotation;
    Vector3D _mountPoint;
public:
    /**
     * @brief Konstruktor klasy Rotor.
     * 
     * Wczytuje z pliku kRotorFile model wirnika.
     */
    Rotor();
    /**
     * @brief "Rysuje" wirnik, wpisując punkty do pliku.
     * 
     * Punkty wpisuje na końcu pliku, ta metoda zoptymalizowana jest do pracy
     * z obiektem Cuboid.
     * 
     * @param filename Plik, do którego ma wpisać punkty.
     */
    void draw(std::string filename) const;
    /**
     * @brief Ustawia kąt obrotu.
     * 
     * @param angle Kąt obrotu.
     */
    void setAngle(double angle);
    /**
     * @brief Zwraca ustawiony kąt obrotu.
     * 
     * @return double Kąt obrotu.
     */
    double getAngle() const {return _angle;}
    /**
     * @brief Ustawia kąt rotacji (obrót wokół osi X).
     * 
     * @param rotation Kąt rotacji.
     */
    void setRotation(double rotation);
    /**
     * @brief Zwraca kąt rotacji (obrót wokół osi X).
     * 
     * @return double Kąt rotacji.
     */
    double getRotation() const {return _rotation;}
    /**
     * @brief Ustawia wektor przesunięcia względem kadłubu Drona.
     * 
     * @param mountPoint Wektor przesunięcia.
     */
    void setMountPoint(const Vector3D &mountPoint) {_mountPoint = mountPoint;}
    /**
     * @brief Zwraca wektor przesunięcia względem kadłubu Drona.
     * 
     * @return Vector3D Wektor przesunięcia.
     */
    Vector3D getMountPoint() const {return _mountPoint;}
    /**
     * @brief Zwraca nazwę klasy Rotor.
     * 
     * @return std::string Nazwa klasy.
     */
    virtual std::string getName() const override {return "wirnik";}
};