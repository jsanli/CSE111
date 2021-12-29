#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(ReuleauxCircle)
{
};

// Uncomment when you're ready

TEST(ReuleauxCircle, Contained)
{
        //inner inside outer
  Circle outer = Circle(Point(0.0,0.0), 4.0);
        Point points[3] = (Point(3.0,3.0), Point(3.0, -7.0), Point(-17.0, -0.0));
        ReuleauxTriangle inner = ReuleauxTriangle(points);
  CHECK(inner.ContainedBy(outer));
}

