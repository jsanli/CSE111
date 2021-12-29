
#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(PolygonPolygon)
{
};

// Uncomment when you're ready

TEST(PolygonPolygon, Contained)
{
        //inner inside outer
        std::vector<Point> pent = {Point(5.0,0.0), Point(5.0, 5.0), Point(0.0, 5.0), Point(-5.0, 3.0), Point(0.0, -30.0)};
  Polygon outer = Polygon(pent);
        std::vector<Point> points = {Point(1.0,0.0), Point(0.0, 1.0), Point(-1.0, 0.0)};
  Polygon inner = Polygon(points);
  CHECK(inner.ContainedBy(outer));
        //inter 
       pent = {Point(6.09,5.8), Point(8.0, 2.83), Point(5.76,0.1), Point(2.48, 1.38), Point(2.68, 4.9)};
  outer = Polygon(pent);
        points = {Point(8.0,3.0), Point(7.0, 1.0), Point(9.0, 1.0)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inner is entirely outside outer
       pent = {Point(5.0,0.0), Point(5.0, 5.0), Point(0.0, 5.0), Point(-5.0, 3.0), Point(0.0, -30.0)};
  outer = Polygon(pent);
        points = {Point(100.0,11.0), Point(100.0, 3.0), Point(170.0, 0.0)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inner surrounds outer
        pent = {Point(-0.67,12.96), Point(1.99, 8.53), Point(-1.4, 4.62), Point(-6.16, 6.64), Point(-5.71, 11.8)};
  outer = Polygon(pent);
        points = {Point(-11.46,16.1), Point(8.07, 13.69), Point(-3.84, -1.98)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inside perimeters touch
       pent = {Point(1.0,2.0), Point(6.0, 12.0), Point(0.0, 18.0), Point(-20.0, 10.0), Point(0.0, -30.0)};
  outer = Polygon(pent);
        points = {Point(2.0,4.0), Point(3.0, 6.0), Point(-1.0, -1.0)};
  inner = Polygon(points);
  CHECK(inner.ContainedBy(outer));
        //inner perimeter touches
       pent = {Point(1.0,2.0), Point(6.0, 12.0), Point(113.0, 5.0), Point(115.0, 4.0), Point(70.0, 30.0)};
  outer = Polygon(pent);
        points = {Point(1.0,1.0), Point(0.0, 0.0), Point(-1.0, -1.0)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
}


