#include "Polygon.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#define PI 3.14159265
using namespace std; 

Polygon::Polygon(unsigned int numOfVertices)
{
	num = numOfVertices;
	sizeX = sizeY = 0;
	verticeX = new Point[numOfVertices];
	verticeY = new Point[numOfVertices]; 
}

Polygon::Polygon() //Set the polygon to a single point by default 
{
	verticeX = new Point[1];
	verticeY = new Point[1];
	sizeX = sizeY = 0; 
}

Polygon::~Polygon()
{
	delete verticeX;
	delete verticeY;
	sizeX = sizeY = 0; 
}

void Polygon::insert(Point x, Point y)
{
	if (sizeX > num && sizeY > num)
		return;
	else 
	{
		verticeX[sizeX] = x; 
		verticeY[sizeY] = y; 
		sizeX++; 
		sizeY++;
	}
}

void Polygon::deletePoint()
{
	if (sizeX == sizeY <= 0)
		return;
	else 
	{
		sizeX--;
		sizeY--;
	}
}

void Polygon::replace(Point x, Point y, int index)
{
	if (index > sizeX || index > sizeY || index < 0)
		return; 
	else 
	{
		verticeX[index] = x; 
		verticeY[index] = y; 
	}
}

bool Polygon::empty()
{
	if (sizeX == sizeY == 0)
		return true;
	return false;
}

bool Polygon::full()
{
	if (sizeX == sizeY == num)
		return true; 
	return false; 
}

bool Polygon::pointInPolygon(Point x, Point y) //Function not complete due to time constraints
{
	int shortX, shortY, longX, longY; 
	for (int i = 0; i < sizeX; sizeX++)
	{
		if (verticeX[i] < shortX)
			shortX = verticeX[i];
		else if (verticeX[i] > longX)
			longX = verticeX[i];
		if (verticeY[i] < shortY)
			shortY = verticeY[i];
		else if (verticeY[i] > longY)
			longY = verticeY[i];
	}
	if ((x < shortX || x > longX) && (y < shortY || y > longY))
		return true;
	return false; 
}

Polygon::RegularOctagon::RegularOctagon()
{
	verticeX = new Point[num]; 
	verticeY = new Point[num];
	sizeX = sizeY = 0; 
}

Polygon::RegularOctagon::~RegularOctagon()
{
	delete verticeX; 
	delete verticeY; 
	sizeX = sizeY = 0; 
}

void Polygon::RegularOctagon::insert(Point x, Point y)
{
	if (sizeX > num && sizeY > num)
		return;
	else 
	{
		verticeX[sizeX] = x; 
		verticeY[sizeY] = y; 		
		sizeX++; 
		sizeY++;
	}
}

void Polygon::RegularOctagon::deletePoint()
{
	if (sizeX == sizeY <= 0)
		return;
	else 
	{
		sizeX--;
		sizeY--;
	}
}

void Polygon::RegularOctagon::replace(Point x, Point y, int index)
{
	if (index > sizeX || index > sizeY || index < 0)
		return; 
	else 
	{
		verticeX[index] = x; 
		verticeY[index] = y; 
	}
}

bool Polygon::RegularOctagon::empty()
{
	if (sizeX = sizeY == 0)
		return true; 
	return false; 
}

bool Polygon::RegularOctagon::full()
{
	if (sizeX = sizeY = num)
		return true; 
	return false; 
}

bool Polygon::RegularOctagon::pointInPolygon(Point x, Point y) //Function not complete due to time constraints
{
	int shortX, shortY, longX, longY; 
	for (int i = 0; i < sizeX; sizeX++)
	{
		if (verticeX[i] < shortX)
			shortX = verticeX[i];
		else if (verticeX[i] > longX)
			longX = verticeX[i];
		if (verticeY[i] < shortY)
			shortY = verticeY[i];
		else if (verticeY[i] > longY)
			longY = verticeY[i];
	}
	if ((x < shortX || x > longX) && (y < shortY || y > longY))
		return true;
	return false; 	
}

void Polygon::RegularOctagon::contract(double n) //Function assumes that the pointsn of the octagon are inserted in counterclockwise order
{
	if (n == 0)
	{
		for (int i = 0; i < num; i++)
			verticeX[i] = verticeY[0] = 0;
	}
	
	else 
	{
		int baseDist = verticeX[1] - verticeX[0]; 
		int nBaseDist = n*baseDist; 
		int nXDist = nBaseDist*cos(	PI/4);
		int nYDist = nBaseDist*sin(PI/4); 
		
		verticeX[1] = nBaseDist + verticeX[0];
		verticeX[2] = nBaseDist + verticeX[0] + nXDist; 
		verticeY[2] = verticeY[0] + nYDist; 
		verticeX[3] = verticeX[2]; 
		verticeY[3] = verticeY[2] + nYDist; 
		verticeX[4] = verticeX[1]; 
		verticeY[4] = verticeY[3] + nYDist; 
		verticeX[5] = verticeX[0]; 
		verticeY[5] = verticeY[4]; 
		verticeX[6] = verticeX[0] - nXDist; 
		verticeY[6] = verticeY[3]; 
		verticeX[7] = verticeX[6];
		verticeY[7] = verticeY[2]; 
	}
}
