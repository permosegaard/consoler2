#include "View.h"

View::View() {
	scene = new QGraphicsScene();
	scene->setSceneRect( QRectF( 0, 0, 10000, 10000 ) );

	view = new QGraphicsView();
	view->setScene( scene );
	view->setVisible( false );
	view->centerOn( 5000, 5000 );
	//view->setAlignment( Qt::AlignCenter );
	view->setResizeAnchor( QGraphicsView::AnchorViewCenter );
	view->setAlignment( Qt::AlignLeft | Qt::AlignTop );
	view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
}

View::~View() {}

QGraphicsView * View::getGraphicsView() { return view; }
