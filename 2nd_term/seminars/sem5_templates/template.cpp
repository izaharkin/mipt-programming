template <typename T, int N>
class Array
{
};

template <typename T>
class Array <T, 10> 
{
};
// partical specification
template <typename T>
class Array <T*>
{
};
