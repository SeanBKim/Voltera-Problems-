#ifndef POLYGON_H
#define POLYGON_H
class Polygon 
{
	public: 
		typedef double Point;
	private:
		unsigned int num, sizeX, sizeY; 
		Point* verticeX; 
		Point* verticeY; 
	public: 
		Polygon(); 
		Polygon(unsigned int num); 
		~Polygon();
		
		void insert(Point x, Point y); 
		void deletePoint();
		void replace(Point x, Point y, int index);
		
		bool empty(); 
		bool full();
		bool pointInPolygon(Point x, Point y); 
		
		class RegularOctagon
		{
			private: 
				unsigned int num = 8; 
				unsigned int sizeX, sizeY; 
				Point* verticeX;
				Point* verticeY;  	
			public: 
				RegularOctagon(); 
				~RegularOctagon(); 
				
				void insert(Point x, Point y); 
				void deletePoint(); 
				void replace(Point x, Point y, int index); 
				
				bool empty(); 
				bool full(); 
				bool pointInPolygon(Point x, Point y); 
				void contract(double n); 
		};
};
#endif
