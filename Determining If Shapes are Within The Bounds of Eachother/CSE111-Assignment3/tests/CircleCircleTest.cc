#include "CppUTest/TestHarness.h"

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

TEST_GROUP(CircleCircle)
{
};

// Uncomment when you're ready

TEST(CircleCircle, Contained)
{
  Circle inner = Circle(Point(0.0,0.0), 2.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  CHECK(inner.ContainedBy(outer));
	//inner and outer intersect
  inner = Circle(Point(0.0,6.0), 2.0);
  outer = Circle(Point(0.0,0.0), 4.0);
  CHECK(!(inner.ContainedBy(outer)));
	//inner is entirely outside outer
  inner = Circle(Point(0.0,9.0), 2.0);
  outer = Circle(Point(0.0,0.0), 4.0);
  CHECK(!(inner.ContainedBy(outer)));
	//inner surrounds outer
  inner = Circle(Point(0.0,0.0), 4.0);
  outer = Circle(Point(0.0,0.0), 2.0);
  CHECK(!(inner.ContainedBy(outer)));
	//inside perimeters touch
  inner = Circle(Point(0.0,2.0), 2.0);
  outer = Circle(Point(0.0,0.0), 4.0);
  CHECK(inner.ContainedBy(outer));
	//inner perimeter touches
  inner = Circle(Point(0.0,6.0), 2.0);
  outer = Circle(Point(0.0,0.0), 4.0);
  CHECK(!(inner.ContainedBy(outer)));
}


/* 
   You'll need to extend this by adding additional tests for:
    1. Inner and Outer intersect (not contained)
    2. Inner is entirely outside Outer (not contained)
    3. Inner surrounds Outer (not contained)
    4. Inner perimeter touches Outer perimeter, Inner is inside Outer (contained)
    5. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
*/
