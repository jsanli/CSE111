#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(CirclePolygon)
{
};

// Uncomment when you're ready

TEST(CirclePolygon, Contained)
{
	//inner inside outer
  Circle inner = Circle(Point(0.0,0.0), 2.0);
	std::vector<Point> points{Point(3.0,3.0), Point(3.0, -7.0), Point(-17.0, -0.0)};
  Polygon outer = Polygon(points);
  CHECK(inner.ContainedBy(outer));
        //inner and outer intersect
  inner = Circle(Point(0.0,0.0), 3.0);
	points = {Point(3.0,1.0), Point(-3.0, 1.0), Point(0.0, 11.0)};
  outer = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inner is entirely outside outer
  inner = Circle(Point(54.0,9.0), 2.0);
	points = {Point(2.0,11.0), Point(1.0, -3.0), Point(-17.0, 0.0)};
  outer = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inner surrounds outer
  inner = Circle(Point(0.0,0.0), 9.0);
	points = {Point(1.0,0.0), Point(0.0, 1.0), Point(-1.0, 0.0)};
  outer = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
        //inside perimeters touch
  inner = Circle(Point(0.0,0.0), 2.0);
	points = {Point(2.0,11.0), Point(2.0, -7.0), Point(-17.0, -0.0)};
  outer = Polygon(points);
  CHECK(inner.ContainedBy(outer));
        //inner perimeter touches
  inner = Circle(Point(4.0,0.0), 2.0);
	points = {Point(2.0,11.0), Point(2.0, -7.0), Point(-17.0, -0.0)};
  outer = Polygon(points);
  CHECK(!(inner.ContainedBy(outer)));
}

