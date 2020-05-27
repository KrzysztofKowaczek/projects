#pragma once

#include <string>

#include "Scene.hh"
#include "Vector.hh"
#include "Shape.hh"
#include "Cuboid.hh"
#include "Rotor.hh"
#include "filenames.hh"
#include "gnuplot_link.hh"


/**
 * @brief Przestrzeń nazw dla typu wyliczeniowego pickRotor
 * 
 */
namespace DroneOpt
{
    /**
     * @brief Typ wyliczeniowy pickRotor.
     * 
     * Służy do wyboru wirnika do obrotu.
     */
    enum pickRotor {kLeftRotor, kRightRotor};
};

/**
 * @brief Modeluje pojęcie drona jako kadłub oraz dwa wirniki.
 * 
 * Udostępnia interfejs do animowania ruchów oraz zmiany pozycji drona.
 */
class Drone
{
private:
    Vector3D _translation;
    Vector3D _outline;
    double _angle;
    Cuboid _body;
    Rotor _leftRotor;
    Rotor _rightRotor;
    Scene _scene;
    Vector3D calculateMove(double lenght, double angle) const;
    void setRotation(DroneOpt::pickRotor select, double rotation);
public:
    /**
     * @brief Konstruktor obiektu Drone.
     * 
     * Inicjalizuje wszystkie obiekty składowe odpowiednimi wartościami.
     */
    Drone();
    /**
     * @brief Metoda draw "rysuje" do pliku punkty drona.
     * 
     * @param filename Nazwa pliku do wypisania punktów drona.
     */
    void draw(std::string filename) const;
    /**
     * @brief Ustawia kąt obrotu wszystkich obiektów składowych.
     * 
     * @param angle Kąt obrotu.
     */
    void setAngle(double angle);
    /**
     * @brief Zwraca ustawiony kąt.
     * 
     * @return double Kąt, który ustawiono.
     */
    double getAngle() const {return _angle;}
    /**
     * @brief Ustawia wektor translacji drona.
     * 
     * @param translation Wektor translacji.
     */
    void translate(const Vector3D &translation);
    /**
     * @brief Zwraca wektor translacji.
     * 
     * @return Vector3D Wektor translacji, który ustawiono.
     */
    Vector3D getTranslation() const {return _translation;}
    /**
     * @brief Sprawdza, czy nie zderzy się z innym obiektem na scenie.
     * 
     * @return true Dron się zderzy z innym obiektem.
     * @return false Dron się nie zderzy z innym obiektem.
     */
    bool checkCollisions() const;
    /**
     * @brief Przesuwa dron we wskazanym kierunku o określoną długość.
     * 
     * @param link Link do GnuPlota.
     * @param angle Kąt unoszenia/opadania.
     * @param lenght Długość, na jaką ma przesunąć się dron.
     */
    void move(PzG::GnuplotLink &link, double angle, double lenght);
    /**
     * @brief Obraca dron o wskazany kąt.
     * 
     * @param link Link do GnuPlota.
     * @param angle Kąt obrotu.
     */
    void rotate(PzG::GnuplotLink &link, double angle);
};