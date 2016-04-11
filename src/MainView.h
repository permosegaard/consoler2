#pragma once

#include "ViewControl.h"
#include "ViewTask.h"

#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

class MainView : public QObject {
	Q_OBJECT

private:
	QGraphicsScene *mainscene;
	QGraphicsView *mainview;

	ViewControl *viewcontrol;
	QGraphicsProxyWidget *viewcontrol_proxy;
	ViewTask *viewtask;
	QGraphicsProxyWidget *viewtask_proxy;
	
	void keyPressedFilter( QKeyEvent * );

	void hideControlPretty();
	void hideControlSimple();
	void hideTaskPretty();
	void hideTaskSimple();
	void showControlPretty();
	void showControlSimple();
	void showTaskPretty();
	void showTaskSimple();

public:
	MainView();
	~MainView();
	
	QGraphicsView * getGraphicsView();
	ViewControl * getViewControl();
	ViewTask * getViewTask();

protected:
	bool eventFilter( QObject *, QEvent * );
};
