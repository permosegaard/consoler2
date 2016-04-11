#pragma once

#include <QTimeLine>
#include <QGraphicsView>
#include <QGraphicsScene>

class View : public QObject {
	Q_OBJECT

public:
	View();
	~View();

	QGraphicsView * getGraphicsView();
	
	virtual void animatedShow() = 0;
	virtual void animatedHide() = 0;

protected:
	QGraphicsScene *scene;
	QGraphicsView *view;

	QTimeLine *timeline;
};
