#include <stdio.h>

typedef struct point{
	double x;
	double y;
}point_t;

typedef struct circle{
	point_t center;
	double radius;
}circle_t;

int in_circle(point_t a, circle_t c)
{
	double d, r;

	d = (a.x - c.center.x) * (a.x -  c.center.x) + (a.y - c.center.y) * (a.y - c.center.y);
	r = c.radius;

	if(d > r)
		return 0;
	else
		return 1;
}

int main()
{
	point_t a;
	circle_t c;

	printf("Enter x: ");
	scanf("%lf", &a.x);

	printf("Enter y: ");
	scanf("%lf", &a.y);

	printf("Circle:\n*Center x: ");
	scanf("%lf", &c.center.x);

	printf("*Center y: ");
	scanf("%lf", &c.center.y);

	printf("*Radius: ");
	scanf("%lf", &c.radius);

	printf("This point is %s the circle!\n", in_circle(a, c)? "in":"not in");

	return 0;
}