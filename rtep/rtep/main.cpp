#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "button.h"
int main(void)
{
	while (1) {
		button();
		screen();
	}
}