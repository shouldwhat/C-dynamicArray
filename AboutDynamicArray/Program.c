#include <stdio.h>

#include "App.h"
#include "MyArray.h"

void main()
{
	App *app;

	app = App_newApp();
	App_Run(app);
}