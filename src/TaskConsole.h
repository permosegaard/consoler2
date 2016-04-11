#pragma once

#include "Task.h"

#include "qtermwidget.h"

class TaskConsole : public Task {
private:
	QTermWidget *console;

public:
	TaskConsole();
	~TaskConsole();
};
