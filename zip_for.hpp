/*template <typename IteratorB,typename IteratorE>
void advance_all (IteratorB & begin,IteratorE & end) {
	++begin;
}
template <typename IteratorB,typename IteratorE, typename ... Iterators>
void advance_all (IteratorB & begin,IteratorE & end, Iterators& ... iterators){
	++begin;
	advance_all(iterators...);
} 
template <typename IteratorB,typename IteratorE>
bool compare_all (IteratorB & begin,IteratorE & end) {
	begin != end;
}
template <typename IteratorB,typename IteratorE, typename ... Iterators>
bool compare_all (IteratorB & begin,IteratorE & end, Iterators& ... iterators){
	return begin != end && compare_all(iterators...);
}
template <typename Function, typename IteratorB,typename IteratorE, typename ... Iterators>
Function zip_for_each (Function func, IteratorB begin, IteratorE end, Iterators ... iterators){
	for(;begin != end && compare_all(iterators...); ++begin, advance_all(iterators...))
		func(*begin, *(iterators)... );
	
	return func;
}
template<typename Function,typename ContTy1,typename ContTy2>
Function zip_range(Function func, ContTy1 Cont1,ContTy2 Cont2){
	return zip_for_each(func,Cont1.begin(),Cont1.end(),Cont2.begin(),Cont2.end());
}*/
template <typename Function, typename ItTy1,typename ItTy2>
void for_each (ItTy1 begin1, ItTy1 end1, ItTy2 begin2, ItTy2 end2,Function func){
	for (;begin1 != end1 && begin2 != end2; ++begin1,++begin2){
		func(*begin1,*begin2):
	}
}
template <typename Function, typename ItTy1,typename ItTy2,typename ItTy2>
void for_each (ItTy1 begin1, ItTy1 end1, ItTy2 begin2, ItTy2 end2,Function func){
	for (;begin1 != end1 && begin2 != end2; ++begin1,++begin2){
		func(*begin1,*begin2):
	}
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
using namespace std;

int main(){
	/*unordered_set<int> a{0,1,2,3,4};
	vector<double> b{0.0,0.1,0.2,0.3,0.4,0.5,0.6};
	vector<char> c{'a','b','c','d','e','f','h'};
	zip_for_each([](int & a_val,float b_val,char c_val){
		cout << a_val << " " << b_val << " " << c_val << "\n";
	},a.begin(),a.end(),b.rbegin(),b.rend(),c.begin(),c.end());
	
	cout << "\n";
	
	zip_range([](int & a_val,float b_val){
		cout << a_val << " " << b_val << "\n";
	},a,b);*/
	int myint;
  char mychar;

  std::tuple<int,float,char> mytuple;

  mytuple = std::make_tuple (10, 2.6, 'a');          // packing values into tuple

  std::tie (myint, std::ignore, mychar) = mytuple;   // unpacking tuple into variables

  std::cout << "myint contains: " << myint << '\n';
  std::cout << "mychar contains: " << mychar << '\n';

	return 0;
}












