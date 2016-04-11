#include "MainView.h"

MainView::MainView() {
	mainscene = new QGraphicsScene();
	mainscene->installEventFilter( this );
	mainscene->setSceneRect( QRectF( 0, 0, 20000, 20000 ) );
	
	mainview = new QGraphicsView();
	mainview->setScene( mainscene );
	mainview->setVisible( true );
	mainview->centerOn( 10000, 10000 );
	//mainview->setAlignment( Qt::AlignCenter );
	mainview->setResizeAnchor( QGraphicsView::AnchorViewCenter );
	mainview->setAlignment( Qt::AlignLeft | Qt::AlignTop );
	mainview->setStyleSheet( "QWidget { background-color: yellow }" );
	mainview->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	mainview->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

	viewcontrol = new ViewControl();
	viewcontrol_proxy = mainscene->addWidget( viewcontrol->getGraphicsView() );
	viewcontrol_proxy->setGeometry( QRectF( 5000, 5000, 10000, 10000 ) );

	viewtask = new ViewTask();
	viewtask_proxy = mainscene->addWidget( viewtask->getGraphicsView() );
	viewtask_proxy->setGeometry( QRectF( 5000, 5000, 10000, 10000 ) );

	//this->showControlSimple() // default
	
	/*viewtask->taskConsole();
	viewtask->taskBrowser();
	viewtask->taskConsole();
	viewtask->taskBrowser();*/
	viewtask->taskConsole();
	viewtask->taskBrowser();
	viewtask->taskConsole();
	this->showTaskSimple();
}

MainView::~MainView() {}

QGraphicsView * MainView::getGraphicsView() { return mainview; }

ViewControl * MainView::getViewControl() { return viewcontrol; }

ViewTask * MainView::getViewTask() { return viewtask; }

bool MainView::eventFilter( QObject *object, QEvent *event ) {
	if ( event->type() == QEvent::KeyPress ) {
		this->keyPressedFilter( static_cast<QKeyEvent *>( event ) );
	}
	return QObject::eventFilter( object, event );
}

void MainView::keyPressedFilter( QKeyEvent *keyevent ) {
	if ( keyevent->key() == 16777216 )  { // escape
		if ( viewcontrol->getGraphicsView()->isVisible() ) {
			this->showTaskSimple();
		}
	}
	else if ( keyevent->key() == 96 && keyevent->modifiers() == Qt::AltModifier ) { // alt+tilda
		if ( viewtask->getGraphicsView()->isVisible() ) {
			this->showControlSimple();
		}
	}
}

void MainView::hideControlPretty() {
	viewcontrol->animatedHide();
	viewcontrol->getGraphicsView()->setVisible( false );
}

void MainView::hideControlSimple() {
	viewcontrol->getGraphicsView()->setVisible( false );
}

void MainView::hideTaskPretty() {
	viewtask->animatedHide();
	viewtask->getGraphicsView()->setVisible( false );
}

void MainView::hideTaskSimple() {
	viewtask->getGraphicsView()->setVisible( false );
}

void MainView::showControlPretty() {}

void MainView::showControlSimple() {
	this->hideTaskSimple();
	viewcontrol->getGraphicsView()->setVisible( true );
}

void MainView::showTaskPretty() {}

void MainView::showTaskSimple() {
	this->hideControlSimple();
	viewtask->getGraphicsView()->setVisible( true );
}
