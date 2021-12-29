#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(PolygonCircle)
{
};

// Uncomment when you're ready

TEST(PolygonCircle, Contained)
{
        //inner inside outer
  Circle outer = Circle(Point(0.0,0.0), 9.0);
        std::vector<Point> points = {Point(1.0,0.0), Point(0.0, 1.0), Point(-1.0, 0.0)};
  Polygon inner = Polygon(points);
  CHECK(inner.ContainedBy(outer));
        //inner and outer intersect
  outer = Circle(Point(0.0,0.0), 3.0);
        points = {Point(3.0,1.0), Point(-3.0, 1.0), Point(0.0, 11.0)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inner is entirely outside outer
  outer = Circle(Point(54.0,9.0), 2.0);
        points = {Point(2.0,11.0), Point(1.0, -3.0), Point(-17.0, 0.0)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inner surrounds outer
  outer = Circle(Point(0.0,0.0), 2.0);
        points = {Point(3.0,3.0), Point(3.0, -7.0), Point(-17.0, 0.0)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inside perimeters touch
  outer = Circle(Point(0.0,0.0), 6.0);
        points = {Point(1.0,1.0), Point(0.0, 6.0), Point(-1.0, -1.0)};
  inner = Polygon(points);
  CHECK(inner.ContainedBy(outer));
        //inner perimeter touches
  outer = Circle(Point(0.0,0.0), 2.0);
        points = {Point(2.0,11.0), Point(2.0, -7.0), Point(-17.0, 0.0)};
  inner = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
}


