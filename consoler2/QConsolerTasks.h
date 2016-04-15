#ifndef QCONSOLERTASKS_H
#define QCONSOLERTASKS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QEvent>
#include <QKeyEvent>

class QConsolerTasks : public QWidget {
	Q_OBJECT

public:
	QConsolerTasks( QWidget * = 0 );
	~QConsolerTasks();

private:
	QBoxLayout *qvboxlayout;

	QGraphicsScene *qgraphicsscene;
	QGraphicsView *qgraphicsview;
	
	void keyPressedFilter( QKeyEvent * );

protected:
	bool eventFilter( QObject *, QEvent * );
};

#endif /* QCONSOLERTASKS_H */
