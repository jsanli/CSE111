
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "bounds.h"

/*
 * Determine if one shape is contained by another where "contained"
 * means entirely within the bounds of the containing shape.
 *
 * Return TRUE if INNER is contained within OUTER, FALSE otherwise.
 */

//Borrowed From Class
static double distance(Point *a, Point *b){
	return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

//https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
double tri_area(Point* one, Point* two, Point* three){
	return (abs((one->x * (two->y - three->x) + two->x * (three->y - one->y) + three->x * (one->y - two->y)) / 2.0));
}

//https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
static bool point_in_tri(Point* one, Point* two, Point* three, Point* center){
	double area = tri_area((Point*)one, (Point*)two, (Point*)three);
	double a1 = tri_area((Point*)center, (Point*)two, (Point*)three);
	double a2 = tri_area((Point*)one, (Point*)center, (Point*)three);
	double a3 = tri_area((Point*)one, (Point*)two, (Point*)center);
	return (area == a1 + a2 + a3);
}
	
//stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon 
static bool point_in_pent(Point points[], Point* vertex){
	for(int i = 0, j = 4; i < 5; j=i++){
		if(((points[i].y > vertex->y) != (points[j].y >vertex->y)) && (vertex->x < (points[j].x - points[i].x) * (vertex->y - points[i].y) / (points[j].y - points[i].y) + points[i].x)){
			return true;
		}	
	}
	return false;
}	 

//Borrowed From Class
static bool circle_contained_by_circle(Circle *inner, Circle *outer){
	return distance(&inner->center, &outer->center) <= (outer->radius - inner->radius);
}

static bool polygon_contained_by_circle(Polygon *inner, Circle *outer){
	for(int x = 0; x < inner->num_vertices; x++){
		if(distance(&inner->vertices[x], &outer->center) >= outer->radius ){
			return false;
		}
	}
	return true;
}

static bool polygon_contained_by_polygon(Polygon *inner, Polygon *outer){	
	for(int i = 0; i < inner->num_vertices; i++){
		if(point_in_pent(outer->vertices, &inner->vertices[i])){
			return true;
		}
	}
	return false;
}

static bool circle_contained_by_polygon(Circle *inner, Polygon *outer){
	for(int p = 0; p < outer->num_vertices; p++){
		if((distance(&outer->vertices[p], &inner->center)) <= inner->radius || !(point_in_tri(&outer->vertices[0], &outer->vertices[1], &outer->vertices[2], &inner->center))){
			return false;
		}
	}
	return true;
}

//Borrowed From Class
bool contained_by(Shape *inner, Shape *outer) {
	if(inner->type == CIRCLE && outer->type == CIRCLE){
		return circle_contained_by_circle((Circle*)inner, (Circle*)outer);
	}	
	else if(inner->type == POLYGON && outer->type == CIRCLE){
		return polygon_contained_by_circle((Polygon*)inner, (Circle*)outer);
	}	
	else if(inner->type == POLYGON && outer->type == POLYGON){
		return polygon_contained_by_polygon((Polygon*)inner, (Polygon*)outer);
	}	
	else/* if(inner->type == CIRCLE && outer->type == POLYGON)*/{
		return circle_contained_by_polygon((Circle*)inner, (Polygon*)outer);
	}
}



