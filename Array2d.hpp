#pragma once
#include <array>
struct Point{
	int X;
	int Y;
	Point operator + (Point p){
		return Point{X+p.X,Y+p.Y};
	}
	
	Point operator - (Point p){
		return Point{X-p.X,Y-p.Y};
	}
	
	Point & operator += (Point p){
		*this = Point{X+p.X,Y+p.Y};
		return *this;
	}
	
	Point & operator -= (Point p){
		*this =  Point{X-p.X,Y-p.Y};
		return *this;
	}
	
	Point operator * (int scalar){
		return Point{X*scalar,Y*scalar};
	}
	
	Point operator / (int scalar){
		return Point{X/scalar,Y/scalar};
	}
	
	Point & operator *= (int scalar){
		*this = Point{X*scalar,Y*scalar};
		return *this;
	}
	
	Point & operator /= (int scalar){
		*this = Point{X/scalar,Y/scalar};
		return *this;
	}
};
template<typename ArrayType,size_t XSize,size_t YSize>
class Array2d
{
public:
	static constexpr size_t ArrSize = XSize*YSize;
	std::array<ArrayType,ArrSize> Arr;
	typedef Arr::iterator iterator;
	//static version
	Array2d(ArrayType InitVal){
		Assign(InitVal);
	}
	Array2d() = default;
	Array2d(void) = default;
	int size(){
		return Arr.size();
	}
	void assign(ArrayType Val){
		fill(begin(), end(), InitVal);
	}
	iterator begin(){
		return Arr.begin();
	}
	iterator end(){
		return Arr.end();
	}
	ArrayType & operator [](Point & P){
		return Arr[P.Y*YSize + P.X];
	}
	ArrayType * operator[](int Y){
		return &Arr[Y*YSize];
	}
};
