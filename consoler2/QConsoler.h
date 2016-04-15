#ifndef QCONSOLER_H
#define QCONSOLER_H

#include <QWidget>
#include <QGLWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QEvent>
#include <QKeyEvent>

#include "QConsolerControl.h"
#include "QConsolerTasks.h"
#include "QExplodeAnimation.h"
#include "QImplodeAnimation.h"

class QConsoler : public QWidget {
	Q_OBJECT

public:
	QConsoler( QWidget * = 0 );
	~QConsoler();

private:
	QGraphicsScene *qgraphicsscene;
	QGraphicsView *qgraphicsview;

	QGLWidget *qglwidget;
	QBoxLayout *qvboxlayout;

	QConsolerControl *qconsolercontrol;
	QConsolerTasks *qconsolertasks;

	QGraphicsProxyWidget *qconsolercontrolproxywidget;
	QGraphicsProxyWidget *qconsolertasksproxywidget;

	bool animationrunning = false;
	QAbstractAnimation *qabstractanimation;

	void keyPressedFilter( QKeyEvent * );

	bool isVisibleControl();
	bool isVisibleTasks();

	void setZOrder( QList<QPair<QGraphicsItem *, int>> _items );
	void raiseReset();
	void raiseControl();
	void raiseTasks();

	void showControl();
	void showTasks();
	void hideControl();
	void hideTasks();

	void hideControlShowTasksPretty();
	void hideTasksShowControlPretty();

protected:
	bool eventFilter( QObject *, QEvent * );
};

#endif /* QCONSOLER_H */
