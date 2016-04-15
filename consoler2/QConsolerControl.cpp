#include "QConsolerControl.h"

#include <QPushButton>
#include <QGraphicsProxyWidget>

QConsolerControl::QConsolerControl( QWidget *parent ) : QWidget( parent )  {
	qgraphicsscene = new QGraphicsScene();
	qgraphicsscene->setSceneRect( QRectF( 0, 0, 10000, 10000 ) );

	qgraphicsview = new QGraphicsView();
	qgraphicsview->centerOn( 5000, 5000 );
	qgraphicsview->setScene( qgraphicsscene );
	qgraphicsview->setAlignment( Qt::AlignLeft | Qt::AlignTop );
	qgraphicsview->setResizeAnchor( QGraphicsView::AnchorViewCenter );
	qgraphicsview->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	qgraphicsview->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	qgraphicsview->setStyleSheet( "QWidget { background-color: yellow }" );
	//qgraphicsview->setViewportUpdateMode( QGraphicsView::BoundingRectViewportUpdate );

	qvboxlayout = new QVBoxLayout();
	qvboxlayout->addWidget( qgraphicsview );

	this->setLayout( qvboxlayout );
	this->setVisible( false );

	QPushButton *button = new QPushButton("My Button");
	QGraphicsProxyWidget *temp = qgraphicsscene->addWidget( button );
	temp->setGeometry( QRectF( 4950, 4950, 100, 100 ) );
}

QConsolerControl::~QConsolerControl() {}

QGraphicsView * QConsolerControl::getGraphicsView() { return qgraphicsview; }
