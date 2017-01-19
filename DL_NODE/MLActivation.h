#pragma once
#include<math.h>

double Logistic(double z) {
	return 1.0 / (1.0 + exp(-1 * z));
}