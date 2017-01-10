#include "MyArray.h"

typedef struct App App;
struct App
{
	MyArray *genres;
	int g_num;
};

App *App_newApp();
void App_Delete(App *app);
void App_Run(App *app);