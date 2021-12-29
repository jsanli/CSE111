#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(CircleReuleaux)
{
};

// Uncomment when you're ready

TEST(CircleReuleaux, Contained)
{
        //inner inside outer
  Circle inner = Circle(Point(0.0,0.0), 2.0);
        Point points[3] = (Point(3.0,3.0), Point(3.0, -7.0), Point(-17.0, -0.0));
	ReuleauxTriangle outer = ReuleauxTriangle(points);
  CHECK(inner.ContainedBy(outer));
}

