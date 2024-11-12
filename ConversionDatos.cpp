#include "ConversionDatos.h"
char ConversionDatos::conversionChar(string s) {
	stringstream r(s);
	char v;
	r >> v;
	return v;
}
double ConversionDatos::conversionDouble(string s) {
	stringstream r(s);
	double v;
	r >> v;
	return v;
}
int ConversionDatos::conversionInt(string s) {
	stringstream r(s);
	int v;
	r >> v;
	return v;
}
bool ConversionDatos::conversionBool(string s) {
	stringstream r(s);
	bool v; 
	r >> v;
	return v; 
}