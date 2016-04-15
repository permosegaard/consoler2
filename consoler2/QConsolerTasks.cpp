#include "QConsolerTasks.h"

QConsolerTasks::QConsolerTasks( QWidget *parent ) : QWidget( parent )  {
	qgraphicsscene = new QGraphicsScene();
	qgraphicsscene->installEventFilter( this );
	qgraphicsscene->setSceneRect( QRectF( 0, 0, 10000, 10000 ) );

	qgraphicsview = new QGraphicsView();
	qgraphicsview->centerOn( 5000, 5000 );
	qgraphicsview->setScene( qgraphicsscene );
	qgraphicsview->setStyleSheet( "QWidget { background-color: green }" );
	qgraphicsview->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	qgraphicsview->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

	qvboxlayout = new QVBoxLayout();
	qvboxlayout->addWidget( qgraphicsview );

	this->setLayout( qvboxlayout );
	this->setVisible( false );
}

QConsolerTasks::~QConsolerTasks() {}

bool QConsolerTasks::eventFilter( QObject *object, QEvent *event ) {
	if ( event->type() == QEvent::KeyPress ) {
		this->keyPressedFilter( static_cast<QKeyEvent *>( event ) );
	}
	return QObject::eventFilter( object, event );
}

void QConsolerTasks::keyPressedFilter( QKeyEvent *keyevent ) {}
