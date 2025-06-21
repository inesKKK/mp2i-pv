//https://www.tutorialspoint.com/c-program-to-change-rgb-color-model-to-hsv-color-model
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double max(double a, double b, double c) {
   return ((a > b)? (a > c ? a : c) : (b > c ? b : c));
}
double min(double a, double b, double c) {
   return ((a < b)? (a < c ? a : c) : (b < c ? b : c));
}
void rgb_to_hsv(double r, double g, double b, double *h, double *s, double *v) {
   // R, G, B values are divided by 255
   // to change the range from 0..255 to 0..1:
   r /= 255.0;
   g /= 255.0;
   b /= 255.0;
   double cmax = max(r, g, b);
   double cmin = min(r, g, b);
   double diff = cmax-cmin;
   if (cmax == cmin)
      *h = 0;
   else if (cmax == r)
      *h = fmod((60 * ((g - b) / diff) + 360), 360.0);
   else if (cmax == g)
     *h = fmod((60 * ((b - r) / diff) + 120), 360.0);
   else if (cmax == b)
     *h = fmod((60 * ((r - g) / diff) + 240), 360.0);
   if (cmax == 0)
     *s = 0;
   else
     *s = (diff / cmax) * 100;
   *v = cmax * 100;
}
//main function
int main(int argc, char const *argv[]) {
  int r = atoi(argv[1]), g = atoi(argv[2]), b = atoi(argv[3]);
   double h, s, v;
   rgb_to_hsv(r, g, b, &h, &s, &v);
   printf("h = %f\ts = %f\tv = %f\n", h, s, v);
   return 0;
}
