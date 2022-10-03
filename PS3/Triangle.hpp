// copyright 2021 Thomas Freeman

#ifndef TRIANGLE_HPP  //NOLINT
#define TRIANGLE_HPP  //NOLINT

#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>



using std::cout;
using std::endl;
using sf::Color;
using sf::Vector2f;
using sf::RenderTarget;
using sf::RenderWindow;
using sf::RenderStates;
using sf::VideoMode;
using sf::Event;
using sf::ConvexShape;
using sf::Drawable;



class Triangle :  public Drawable {
 public:
  Triangle(int, int);
  Triangle(Vector2f, Vector2f, Vector2f, int);
  void virtual draw(RenderTarget&, RenderStates) const;

 private:
  int ftree;
  Vector2f t, l, r;
  Vector2f p1, p2, p3;
  Triangle *t1, *t2, *t3;
};
#endif //NOLINT
