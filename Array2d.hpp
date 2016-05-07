#pragma once
template<typename ArrayType>
struct Point{
	int X;
	int Y;
};
class Array2d
{
public:
	vector<ArrayType> Arr;
	typedef Arr::iterator iterator;
	int XSize;
	//static version
	Array2d(int InXSize,int InYSize,ArrayType InitVal){
		XSize = InXSize;
		Arr.resize(InXSize * InYSize);
		Init(InitVal);
	}
	Array2d(Array2d & InArr){
		*this = InArr;
	}
	Array2d(void) = default;
	int Size(){
		return Arr.size();
	}
	void Init(ArrayType InitVal){
		fill(begin(), end(), InitVal);
	}
	iterator begin(){
		return Arr.begin();
	}
	iterator end(){
		return Arr.end();
	}
	void operator = (Array2d & InArr){
		Arr = InArr.Arr;
		XSize = InArr.XSize;
	}
	ArrayType & operator [](Point & P){
		return Arr[P.X * XSize + P.Y];
	}
	ArrayType * operator[](int X){
		return &Arr[X*XSize];
	}
};