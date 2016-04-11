#pragma once

#include "Task.h"

#include <QtWebEngineWidgets>

class TaskBrowser : public Task {
public:
	TaskBrowser();
	~TaskBrowser();

private:
	QWebEngineView *browser;
};
