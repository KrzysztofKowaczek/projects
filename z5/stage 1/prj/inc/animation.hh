#pragma once

#include "gnuplot_link.hh"
#include "Vector.hh"
#include "Cuboid.hh"

/**
 * @brief Funkcja służąca do animowania ruchów.
 * 
 * Funkcja ta pozwala na płynne przeniesienie prostopadłościanu z jednego
 * miejsca w drugie. W tym celu dzieli cały ruch na 200 mniejszych ruchów
 * i wyświetla każdy po kolei w odstępach ok. 20ms, generując 50 klatek
 * na sekundę, a cały ruch trwa (w założeniu) ok. 4 sekund.
 * 
 * @param link Link do Gnuplota.
 * @param cuboid Prostopadłościan, na którym wykonana zostanie animacja.
 * @param translation Wektor translacji/przeniesienia prostopadłoscianu.
 * @param angle Kąt unoszenia/opadania podczas animacji.
 */
void animate(PzG::GnuplotLink &link, Cuboid &cuboid, 
            const Vector3D &translation, double angle);