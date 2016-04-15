#include "QConsoler.h"

QConsoler::QConsoler( QWidget *parent ) : QWidget( parent )  {
	qgraphicsscene = new QGraphicsScene();
	qgraphicsscene->installEventFilter( this );
	qgraphicsscene->setSceneRect( QRectF( 0, 0, 20000, 20000 ) );

	qgraphicsview = new QGraphicsView();
	qgraphicsview->centerOn( 10000, 10000 );
	qgraphicsview->setScene( qgraphicsscene );
	qgraphicsview->setAlignment( Qt::AlignLeft | Qt::AlignTop );
	qgraphicsview->setResizeAnchor( QGraphicsView::AnchorViewCenter );
	qgraphicsview->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	qgraphicsview->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	qgraphicsview->setStyleSheet( "QWidget { background-color: red }" );
	//qgraphicsview->setViewportUpdateMode( QGraphicsView::BoundingRectViewportUpdate );

	qconsolercontrol = new QConsolerControl();
	qconsolercontrolproxywidget = qgraphicsscene->addWidget( qconsolercontrol );
	qconsolercontrolproxywidget->setGeometry( QRectF( 5000, 5000, 10000, 10000 ) );
	
	qconsolertasks = new QConsolerTasks();
	qconsolertasksproxywidget = qgraphicsscene->addWidget( qconsolertasks );
	qconsolertasksproxywidget->setGeometry( QRectF( 5000, 5000, 10000, 10000 ) );

	//qglwidget = new QGLWidget( /* QGLFormat( QGL::SampleBuffers | QGL::DirectRendering ) */ );
	//qgraphicsview->setViewport( qglwidget );

	qvboxlayout = new QVBoxLayout();
	qvboxlayout->addWidget( qgraphicsview );
	//qvboxlayout->addWidget( qglwidget );

	this->setLayout( qvboxlayout );

	this->showControl(); // DEBUG HERE
}

QConsoler::~QConsoler() {}

bool QConsoler::eventFilter( QObject *object, QEvent *event ) {
	if ( event->type() == QEvent::KeyPress ) {
		this->keyPressedFilter( static_cast<QKeyEvent *>( event ) );
	}
	return QObject::eventFilter( object, event );
}

void QConsoler::keyPressedFilter( QKeyEvent *keyevent ) {
	if ( keyevent->key() == 16777216 )  { // escape
		if ( ! this->animationrunning && this->isVisibleControl() ) {
			this->hideControlShowTasksPretty();
		}
	}
	else if ( keyevent->key() == 96 && keyevent->modifiers() == Qt::AltModifier ) { // alt+tilda
		if ( ! this->animationrunning && this->isVisibleTasks() ) {
			this->hideTasksShowControlPretty();
		}
	}
}

bool QConsoler::isVisibleControl() { return qconsolercontrol->isVisible(); }

bool QConsoler::isVisibleTasks() { return qconsolertasks->isVisible(); }

void QConsoler::setZOrder( QList<QPair<QGraphicsItem *, int>> _items ) {
	typedef QPair<QGraphicsItem *, int> pair; // commas, macros and templates make for sad times
	Q_FOREACH( pair item, _items) {
		item.first->setZValue( item.second );
	}
}

void QConsoler::raiseReset() {
	this->setZOrder(
		QList<QPair<QGraphicsItem *, int>>({
			QPair<QGraphicsItem *, int>( static_cast<QGraphicsItem *>( qconsolercontrolproxywidget ), 0 ),
			QPair<QGraphicsItem *, int>( static_cast<QGraphicsItem *>( qconsolertasksproxywidget ), 0 )
		})
	);
}

void QConsoler::raiseControl() {
	this->setZOrder(
		QList<QPair<QGraphicsItem *, int>>({
			QPair<QGraphicsItem *, int>( static_cast<QGraphicsItem *>( qconsolercontrolproxywidget ), 2 ),
			QPair<QGraphicsItem *, int>( static_cast<QGraphicsItem *>( qconsolertasksproxywidget ), 1 )
		})
	);
}

void QConsoler::raiseTasks() {
	this->setZOrder(
		QList<QPair<QGraphicsItem *, int>>({
			QPair<QGraphicsItem *, int>( static_cast<QGraphicsItem *>( qconsolertasksproxywidget ), 2 ),
			QPair<QGraphicsItem *, int>( static_cast<QGraphicsItem *>( qconsolercontrolproxywidget ), 1 )
		})
	);
}

void QConsoler::showControl() { qconsolercontrol->setVisible( true ); }

void QConsoler::showTasks() { qconsolertasks->setVisible( true ); }

void QConsoler::hideControl() { qconsolercontrol->setVisible( false ); }

void QConsoler::hideTasks() { qconsolertasks->setVisible( false ); }

void QConsoler::hideControlShowTasksPretty() {
	this->animationrunning = true;

	this->raiseControl();
	this->showTasks();

	QAbstractAnimation *qabstractanimation = new QExplodeAnimationOut();
	qabstractanimation->setQGraphicsView( qconsolercontrol->getGraphicsView() );
	qabstractanimation->run();
	qabstractanimation->blockingFinishedWithUpdates();
	
	this->hideControl();
	this->raiseReset();
	
	this->animationrunning = false;
}

void QConsoler::hideTasksShowControlPretty() {
	this->hideTasks();
	this->showControl();
}
