#include <iostream>
#include <cmath>

using namespace std;

int
main ()
{
  int n, max, min, onInterval, value, compare, count = 0, intervalCount = 0;
  float average;
  max = 0;
  min = 25;

  cout << "Dati numarul de trenuri" << endl;
  cin >> n;
  cout << "Dati valoarea de a compara valorile" << endl;
  cin >> compare;
  cout << "Dati ora de determinare a intervalului" << endl;
  cin >> onInterval;

  for (int i = 1; i <= n; i++)
    {
      cout << "Dati ora trenului " << i << ":" << endl;
      cin >> value;

      (value > max) ? max = value : 0;
      (value < min) ? min = value : 0;
      average += value;

      (value > compare) ? count++ : 0;
      (value == onInterval) ? intervalCount++ : 0;
    }
  average /= n;

  cout << "Valoarea maxima:" << max << endl;
  cout << "Valoarea minima:" << min << endl;
  cout << "Decalajul:" << max - min << endl;
  cout << "Media valorilor:" << roundf (average * 100) / 100 << endl;
  cout << "Numarul de valori mai mari decit valoarea indicata:" << count << endl;
  cout << "Numarul de trenuri in intervalul de timp "<<onInterval <<" este: " << intervalCount << endl;
  return 0;
}
