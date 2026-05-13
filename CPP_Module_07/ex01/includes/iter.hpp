
#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T* arr, const int len, F f)
{
  if (!arr)
    return;
  for (int i = 0; i < len; i++)
    f(arr[i]);
}

/*
template <typename T>
void iter(T* arr, const int len, void (*f)(const T&))
{
  if (!arr)
    return;
  for (int i = 0; i < len; i++)
    f(arr[i]);
}*/

#endif
