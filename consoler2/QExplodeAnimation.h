#ifndef QEXPLODEANIMATION_H
#define QEXPLODEANIMATION_H

#include <QGraphicsOpacityEffect>

#include "QAbstractAnimation.h"

class QExplodeAnimationIn : public QObject, public QAbstractAnimation {
	Q_OBJECT
	Q_INTERFACES(QAbstractAnimation)

public:
	QExplodeAnimationIn( QObject * = 0 );
	~QExplodeAnimationIn();

private:
	void start();

private slots:
	void step( int );
	void end();
};

class QExplodeAnimationOut : public QObject, public QAbstractAnimation {
	Q_OBJECT
	Q_INTERFACES(QAbstractAnimation)

public:
	QExplodeAnimationOut( QObject * = 0 );
	~QExplodeAnimationOut();

private:
	float scalemultipler = 0.5; // cumulative enlargement factor per step

	QGraphicsOpacityEffect *qgraphicsopacityeffect;

	void start();

private slots:
	void step( int );
	void end();
};

#endif /* QEXPLODEANIMATION_H */
