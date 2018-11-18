#include "Console.h"
#include <stdlib.h>
#include "Exception.h"
# pragma warning(disable:4996)
int main(){
	Console* console;
	try {
		 console= Console::creatConsole();
	}
	catch(MyException& ex){
		ex.show();
		system("pause");
		return 0;

	}
	try {
		console->run();
	}
	catch (MyException& ex) {
		ex.show();
	}
	if (console != nullptr) {
		delete console;
	}
	system("pause");
}