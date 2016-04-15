#ifndef QIMPLODEANIMATION_H
#define QIMPLODEANIMATION_H

#include "QAbstractAnimation.h"

class QImplodeAnimationIn : public QObject, public QAbstractAnimation {
	Q_OBJECT
	Q_INTERFACES(QAbstractAnimation)

public:
	QImplodeAnimationIn( QObject * = 0 );
	~QImplodeAnimationIn();

private:
	void start();

private slots:
	void step( int );
	void end();
};

class QImplodeAnimationOut : public QObject, public QAbstractAnimation {
	Q_OBJECT
	Q_INTERFACES(QAbstractAnimation)

public:
	QImplodeAnimationOut( QObject * = 0 );
	~QImplodeAnimationOut();

private:
	void start();

private slots:
	void step( int );
	void end();
};

#endif /* QIMPLODEANIMATION_H */
