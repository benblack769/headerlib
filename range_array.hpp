/*
Two dimentional array with offset.

Allows one to access points efficiently in a  two dimentional space with
arbirary bounds.

So you can have a space like([-10,10],[-20,0]).

*/
#pragma once
#include <headerlib/point.hpp>
#include <headerlib/range_array.hpp>

template<typename ArrayType>
class RangeArray;

template<typename ArrayType>
class RA_Iterator{
public:
    PointIter Spot;
    using ArrIterator = typename vector<ArrayType>::iterator;
    ArrIterator ArrIt;
    RA_Iterator(RangeArray<ArrayType> * InArr){
        ArrIt = InArr->Arr.begin();

        int sx = InArr->Corner.X;
        int sy = InArr->Corner.Y;
        int xdis = InArr->XSize;
        int ydis = InArr->YSize;
        Spot = PointIter(sx, sy, sx + xdis, sy + ydis);
    }
    RA_Iterator(){
        Spot = PointIter();
    }
    bool operator != (RA_Iterator & Other){
        return Spot.NotEnd();
    }
    void operator ++ (){
        ++Spot;
        ++ArrIt;
    }
    PointInfo<ArrayType> operator *(){
        return PointInfo<ArrayType>(*Spot, &(*ArrIt));
    }
};
template<typename ArrayType>
class RangeArray
{
public:
    vector<ArrayType> Arr;
    using iterator = RA_Iterator<ArrayType>;
    Point Corner;
    int YSize, XSize;
    RangeArray(Point InCenP,int InRange){
        Corner.X = max(InCenP.X - InRange, 0);
        Corner.Y = max(InCenP.Y - InRange, 0);

        XSize = min(InCenP.X + InRange + 1, BoardSizeX) - Corner.X;
        YSize = min(InCenP.Y + InRange + 1, BoardSizeY) - Corner.Y;

        Arr.resize(XSize * YSize);
        Init(ArrayType());//zeros out data
    }
    RangeArray(ConstSquare Sq) :RangeArray(Sq.Cen, Sq.Range){}
    RangeArray(){
        Corner = CreatePoint(0, 0);
        YSize = 0;
        XSize = 0;
    }
    RangeArray(const RangeArray & other){
        (*this) = other;
    }
    RangeArray(RangeArray && other){
        (*this) = other;
    }

    void operator =(const RangeArray & val){
        _copy_scalars(val);
        Arr = val.Arr;
    }
    void operator =(RangeArray && val){
        _copy_scalars(val);
        Arr = move(val.Arr);
    }
    void Init(ArrayType InitVal){
        for (auto & Val : Arr)
            Val = InitVal;
    }
    int Size(){
        return Arr.size();
    }
    int PointToInt(Point P){
        return (P.Y - Corner.Y) * XSize + (P.X - Corner.X);
    }
    iterator begin(){
        return RA_Iterator<ArrayType>(this);
    }
    iterator end(){
        return RA_Iterator<ArrayType>();
    }
    bool IsInScope(Point P){
        int Xadj = P.X - Corner.X;
        int Yadj = P.Y - Corner.Y;
        return Xadj < XSize && Yadj < YSize && Xadj >= 0 && Yadj >= 0;
    }
    ArrayType & operator [](Point & P){
        return Arr[PointToInt(P)];
    }
protected:
    void _copy_scalars(const RangeArray & other){
        Corner = other.Corner;
        YSize = other.YSize;
        XSize = other.XSize;
    }
};
