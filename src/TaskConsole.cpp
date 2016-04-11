#include "TaskConsole.h"

TaskConsole::TaskConsole() : Task() {
	console = new QTermWidget();
	console->setColorScheme( "Linux" );
	widget = static_cast<QWidget *>( console );
}

TaskConsole::~TaskConsole() {}
