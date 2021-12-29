#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(ReuleauxReuleaux)
{
};

// Uncomment when you're ready

TEST(ReuleauxReuleaux, Contained)
{
        //inner inside outer
        Point first[3] = (Point(3.0,3.0), Point(3.0, -7.0), Point(-17.0, -0.0));
        ReuleauxTriangle inner = ReuleauxTriangle(first);
        Point points[3] = (Point(3.0,3.0), Point(3.0, -7.0), Point(-17.0, -0.0));
        ReuleauxTriangle outer = ReuleauxTriangle(points);
  CHECK(inner.ContainedBy(outer));
}

