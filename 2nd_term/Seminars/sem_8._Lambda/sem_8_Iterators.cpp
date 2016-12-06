// Э. Гамма, .. - "Приёмы ООП"
// Итераторы
// Паттерны программирования
// Один из паттернов - итератор
template <typename T>
class Vector
{
public:
	typedef ector Iterator iterator;	
};

template <typename t>
class VectorIterator
{
private:
	T* pointer;
public:
	T& operator * ()
	{
		return *pointer;
	}
	
	T* operator ++ ()
	{
		return ++pointer;
	}
	
	operator = (const VectorIterator& it)
	{
		
	}
}
/*
	std::copy(InputIterator begin, InputIterator end, OutputIterator result);
*/
/* Иерархия итераторов:
        	CommonIterator (*, ++, =) 
             /                \             
            /                  \
InputIterator (==, !=)     OutputIterator (==)
   		   \                    /
   		    \                  /
             ForwardIterator () [single-linked list] [stack] [queue]
                    |
                    |
         BidirectionalIterator (--) [double-linked list] [set] [deque]
                    |
                    |
           RandomAccessIterator (+ <number>, - <number>, - <RandomAccessIterator>, <, <=, >, >=, += <число>, -= <число>, [<число>])  [vector] [map]
              
  		
  
