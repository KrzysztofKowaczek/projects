#pragma once

#include "Shape.hh"
#include <string>

/**
 * @file Objects.hh
 * 
 * Plik zawiera zbiór brył niestandardowych.
 */

/**
 * @brief Przestrzeń nazw Objects.
 * 
 * Służy jako kontener dla kliku brył, żeby nie robić osobnego pliku dla 
 * każdej klasy z osobna.
 */
namespace Objects
{
    /**
     * @brief Modeluje pojęcie płyty jako zbiór punktów w przestrzeni.
     * 
     * Dziedziczy z klasy Shape.
     */
    class Plate: public Shape
    {
    public:
        /**
         * @brief Zwraca nazwę obiektu.
         * 
         * @return std::string Nazwa obiektu.
         */
        virtual std::string getName() const override {return "plyta";}
        /**
         * @brief Construct a new Plate object
         * 
         * @param filename Nazwa pliku, z którego ma zczytać punkty.
         */
        Plate(std::string filename) 
        {
            Cuboid *shape = new Cuboid(filename);
            _points = shape->getPoints();
            delete shape;
        }
    };

    /**
     * @brief Modeluje pojęcie patyka jako zbiór punktów w przestrzeni.
     * 
     * Dziedziczy z klasy Shape.
     */
    class Stick: public Shape
    {
    public:
        /**
         * @brief Zwraca nazwę obiektu.
         * 
         * @return std::string Nazwa obiektu.
         */
        virtual std::string getName() const override {return "patyk";}
        /**
         * @brief Construct a new Stick object
         * 
         * @param filename Nazwa pliku, z którego ma zczytać punkty.
         */
        Stick(std::string filename) 
        {
            Cuboid *shape = new Cuboid(filename);
            _points = shape->getPoints();
            delete shape;
        }
    };

    /**
     * @brief Modeluje pojęcie powierzchni wody jako zbiór punktów w przestrzeni.
     * 
     * Dziedziczy z klasy Shape.
     */
    class Ceil: public Shape
    {
    public:
        /**
         * @brief Zwraca nazwę obiektu.
         * 
         * @return std::string Nazwa obiektu.
         */
        virtual std::string getName() const override {return "powierzchnia";}
        /**
         * @brief Construct a new Ceil object
         * 
         * @param filename Nazwa pliku, z którego ma zczytać punkty.
         */
        Ceil(std::string filename) 
        {
            Cuboid *shape = new Cuboid(filename);
            _points = shape->getPoints();
            delete shape;
        }
    };

    /**
     * @brief Modeluje pojęcie dna jako zbiór punktów w przestrzeni.
     * 
     * Dziedziczy z klasy Shape.
     */
    class Floor: public Shape
    {
    public:
        /**
         * @brief Zwraca nazwę obiektu.
         * 
         * @return std::string Nazwa obiektu.
         */
        virtual std::string getName() const override {return "dno";}
        /**
         * @brief Construct a new Floor object
         * 
         * @param filename Nazwa pliku, z którego ma zczytać punkty.
         */
        Floor(std::string filename) 
        {
            Cuboid *shape = new Cuboid(filename);
            _points = shape->getPoints();
            delete shape;
        }
    };

};