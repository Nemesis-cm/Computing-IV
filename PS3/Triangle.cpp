// copyright 2021 Thomas Freeman
#include "Triangle.hpp"

Triangle::Triangle(int side, int depth) : ftree(depth) {
  t = Vector2f(side / sqrt(3.0), 0);

  float height = .5 * sqrt(3.0) * side;

  l = Vector2f(0, height);
  r = Vector2f(side-1, height);

  p1 = Vector2f(((t.x + l.x) / 2), ((t.y + l.y) / 2) );
  p2 = Vector2f(((l.x + r.x) / 2), ((l.y + r.y) / 2) );
  p3 = Vector2f(((t.x + r.x) / 2), ((t.y + r.y) / 2) );

  if (ftree - 1 > 0) {
    t1 = new Triangle(p1, l, p2, depth - 1);
    t2 = new Triangle(t, p1, p3, depth - 1);
    t3 = new Triangle(p3, p2, r, depth - 1);
  } else {
    t1 = NULL;
    t2 = NULL;
    t3 = NULL;
  }
}


Triangle::Triangle(Vector2f top, Vector2f left,
Vector2f right, int depth) : ftree(depth) {
  if (depth <= 0) {
    t1 = NULL;
    t2 = NULL;
    t3 = NULL;

    return;
  }

  t = top;
  l = left;
  r = right;

  p1 = Vector2f(((top.x + left.x) / 2), ((top.y + left.y) / 2));
  p2 = Vector2f(((left.x + right.x) / 2), ((left.y + right.y) / 2));
  p3 = Vector2f(((top.x + right.x) / 2), ((top.y + right.y) / 2));

  t1 = new Triangle(p1, left, p2, depth - 1);
  t2 = new Triangle(top, p1, p3, depth - 1);
  t3 = new Triangle(p3, p2, right, depth - 1);
}

void Triangle::draw(RenderTarget& target, RenderStates states) const {
  ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, l);
  triangle.setPoint(1, r);
  triangle.setPoint(2, t);
  triangle.setFillColor(Color::Green);

  ConvexShape triangle1;
  triangle1.setPointCount(3);
  triangle1.setPoint(0, p1);
  triangle1.setPoint(1, p2);
  triangle1.setPoint(2, p3);
  triangle1.setFillColor(Color::Red);
  target.draw(triangle);
  if (ftree > 0)
    target.draw(triangle1);
  if (t1 != NULL) {
    t1->draw(target, states);
    t2->draw(target, states);
    t3->draw(target, states);
  }
}
