#ifndef QABSTRACTANIMATION_H
#define QABSTRACTANIMATION_H

#include <functional>

#include <QThread>
#include <QSemaphore>
#include <QWidget>
#include <QTimeLine>
#include <QGraphicsView>
#include <QCoreApplication>

#include "Utils.h"

INTERFACE_QT_START(QAbstractAnimation)
public:
	bool isRunning() { return qtimeline->state() == QTimeLine::Running; }

	void setQGraphicsView( QGraphicsView *_qgraphicsview ) { this->qgraphicsview = _qgraphicsview; }

	void __start() {
		this->qtimeline = new QTimeLine();
		this->qtimeline->setFrameRange( 1, this->frames );
		this->qtimeline->setDuration( static_cast<int>( this->duration * 1000 ) );
	}

	void run() {
		if ( ! this->qgraphicsview ) { /* assert or exception, needs thought */ }
		else {
			this->qsemaphore = new QSemaphore( 1 );
			this->qsemaphore->acquire();
			this->start();
			this->qtimeline->start();
		}
	}
	
	void run( std::function<void()> _callback ) {
		this->callback = _callback;
		this->run();
	}

	void __step_start() {}
	void __step_end() {}

	void __end() {
		if ( callback ) { this->callback(); }
		this->qsemaphore->release();
	}

	bool testFinished() { return this->qsemaphore->tryAcquire( 1, 100 ); }
	void blockingFinished() { this->qsemaphore->acquire(); }
	void blockingFinishedWithUpdates() {
		while ( ! this->testFinished() ) {
			QCoreApplication::processEvents(); // QEventLoop::AllEvents && sendPostedEvents()
			QThread::msleep( 20 );
		}
	}

private:
	INTERFACE_FUNCTION(void start())

protected:
	QSemaphore *qsemaphore;
	QTimeLine *qtimeline;
	QGraphicsView *qgraphicsview;
	
	int frames = 50; // ticks per run
	float duration = 0.5; // animation length in seconds

	std::function<void()> callback;

private slots:
	INTERFACE_FUNCTION(void step( int ))
	INTERFACE_FUNCTION(void end())
INTERFACE_QT_END(QAbstractAnimation)

#endif /* QABSTRACTANIMATION_H */
