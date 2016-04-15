#ifndef QCONSOLERCONTROL_H
#define QCONSOLERCONTROL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>

class QConsolerControl : public QWidget {
	Q_OBJECT

public:
	QConsolerControl( QWidget * = 0 );
	~QConsolerControl();

	QGraphicsView * getGraphicsView();

private:
	QBoxLayout *qvboxlayout;

	QGraphicsScene *qgraphicsscene;
	QGraphicsView *qgraphicsview;
};

#endif /* QCONSOLERCONTROL_H */
