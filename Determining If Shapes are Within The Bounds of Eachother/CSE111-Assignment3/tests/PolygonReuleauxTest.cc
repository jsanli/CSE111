#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(PolygonReuleaux)
{
};

// Uncomment when you're ready

TEST(PolygonReuleaux, Contained)
{
        //inner inside outer
        std::vector<Point> pent = {Point(5.0,0.0), Point(5.0, 5.0), Point(0.0, 5.0), Point(-5.0, 3.0), Point(0.0, -30.0)};
  Polygon inner = Polygon(pent);
        Point points[3] = (Point(3.0,3.0), Point(3.0, -7.0), Point(-17.0, -0.0));
        ReuleauxTriangle outer = ReuleauxTriangle(points);
  CHECK(inner.ContainedBy(outer));
}



