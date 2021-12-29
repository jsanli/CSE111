//I moved this weekend and therefor was too busy to have time to get the assignment done. I did what I could in the time I had free

#include <cmath>
#include <vector>

#include "Reuleaux.h"
#include "Circle.h"
#include "Polygon.h"

//Borrowed from class
ReuleauxTriangle::ReuleauxTriangle(const Point* vertices){
        //vertices_ = (Point *)(vertices);
}

/*Point* ReuleauxTriangle::Vertices(){
        return vertices_;
}*/

bool ReuleauxTriangle::ContainedBy(Circle &circle){
		return true;
}
	
bool ReuleauxTriangle::ContainedBy(Polygon &polygon){
	return true;
}

bool ReuleauxTriangle::ContainedBy(ReuleauxTriangle &rt){
	return true;
}
