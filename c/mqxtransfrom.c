#include <math.h>

enum transformation {
  MQ5_CO,
  MQ5_Alcholo,
  MQ5_H2,
  MQ5_CH4,
  MQ5_LPG,
  MQ9_CH4,
  MQ9_LPG,
  MQ9_CO,
  MQ131_NOx,
}



double isReadingInRange(t transformation, double rs, double r0) int {
  double max = 0, min = 0, x = rs/r0;

  switch (t) {
    case MQ5_CO:      min = 2.28,  max = 3.85;  break;
    case MQ5_Alcholo: min = 1.44,  max = 3.46;  break;
    case MQ5_H2:      min = 0.657, max = 1.75;  break;
    case MQ5_CH4:     min = 0.204, max = 0.949; break;
    case MQ5_LPG:     min = 0.15,  max = 0.705; break;
    case MQ9_CH4:     min = 0.681, max = 3.06;  break;
    case MQ9_LPG:     min = 0.321, max = 2.05;  break;
    case MQ9_CO:      min = 0.783, max = 1.6;   break;
    case MQ131_NOx:   min = 2.05,  max = 7.87;  break;
  }

  return (x > min && x < max)
}


double transformReading(t transformation, double rs, double r0) double {
  double a = 0, b = 0, c = 0, x = rs/r0;
  switch (t) {
    case MQ5_CO:       c = 10,   b = -23.5, a = 17.7, break;
    case MQ5_Alcholo:  c = 4.81, b = -4.5,            break;
    case MQ5_H2:       c = 3.07, b = -3.83,           break;
    case MQ5_CH4:      c = 2.25, b = -2.55,           break;
    case MQ5_LPG:      c = 1.9,  b = -2.48,           break;
    case MQ9_CH4:      c = 3.59, b = -2.59,           break;
    case MQ9_LPG:      c = 2.97, b = -2.11,           break;
    case MQ9_CO:       c = 2.74, b = -2.22,           break;
    case MQ131_NOx:    c = 2.7,  b = -2.26,           break;
  }
  double logx = log10(x);

  return a*pow(logx, 2) + b*logx + c
}
