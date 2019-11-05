/**
	Thermocouple - interface describes a set of methods
	for working with a thermocouple sensor and reading
	a temperature in Celsius, Fahrenheit and Kelvin.

	v.2.0.0
	- created

	https://github.com/YuriiSalimov/MAX6675_Thermocouple

	Created by Yurii Salimov, May, 2019.
	Released into the public domain.
*/
#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

class Thermocouple {

	public:
		/**
			Reads a temperature in Celsius from the thermocouple.

			@return temperature in degree Celsius
		*/
		virtual double readCelsius() = 0;

		/**
			Reads a temperature in Kelvin from the thermocouple.

			@return temperature in degree Kelvin
		*/
		virtual double readKelvin() = 0;

		/**
			Reads a temperature in Fahrenheit from the thermocouple.

			@return temperature in degree Fahrenheit
		*/
		virtual double readFahrenheit() = 0;
};

#endif
