template<class T>
void exange(T &a, T&b)
{
  T temp;
  temp = a;
  a = b;
  b = temp;
}