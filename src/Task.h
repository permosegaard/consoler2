#pragma once

#include <QWidget>

class Task {
public:
	Task();
	~Task();
	
	QWidget * getWidget();

protected:
	QWidget *widget;
};
