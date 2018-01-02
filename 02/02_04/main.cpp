#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return pow(x, 3) + x;
}

int main() {
    // Alustetaan muuttujat: max ja min-raja-arvot funktiolle, aloituskohta x, iteraatioasekel ja y:n arvo.
    double x_max = 1, x_min = -1, x = 0.1, step = 0.001, y = 0;

    // Silmukka toistuu, kunnes toinen raja-arvo on saavutettu.
    while(x < x_max && x > x_min)
    {
        // Lasketaan y:n uusi arvo.
        double fx_left = f(x - step);
        double fx_right = f(x + step);

        // Valitaan suuremman arvon perusteella suunta.
        if (fx_left > fx_right)
        {
            y = fx_left;
            x -= step;
        }
        else if (fx_right > fx_left)
        {
            y = fx_right;
            x += step;
        }

        // Tarkastaa y:n arvon jokaisella iteraatiolla.
        cout << "debug: x = " << x << ", y = " << y << endl;
    }

    cout << "Highest value: " << y << endl;

    return 0;
}
