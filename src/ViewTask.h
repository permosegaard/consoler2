#pragma once

#include "View.h"
#include "Task.h"
#include "TaskConsole.h"
#include "TaskBrowser.h"

#include <QGraphicsProxyWidget>

class ViewTask : public View {
	Q_OBJECT

private:
	Task *currenttask;
	QGraphicsProxyWidget *currentwidget;

public:
	ViewTask();
	~ViewTask();
	
	void animatedShow();
	void animatedHide();

	Task * getCurrentTask();
	QGraphicsProxyWidget * getCurrentWidget();

	void taskClear();

	void taskConsole();
	void taskBrowser();

private slots:
	void animatedShowFrame( int );
	void animatedShowPost();
	void animatedHideFrame( int );
	void animatedHidePost();
};
