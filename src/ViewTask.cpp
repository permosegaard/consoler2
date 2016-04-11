#include "ViewTask.h"

ViewTask::ViewTask() : View() {
	view->setStyleSheet( "QWidget { background-color: green }" );
}

ViewTask::~ViewTask() {}

Task * ViewTask::getCurrentTask() { return currenttask; } 

void ViewTask::animatedShow() {}

void ViewTask::animatedShowFrame( int frame )  {
	qDebug( "frame" );
}

void ViewTask::animatedShowPost() {
	qDebug( "post" );
}

void ViewTask::animatedHide() {
	qDebug( "hide" );
	timeline = new QTimeLine( 5000 );
	timeline->setFrameRange( 0, 100 );
	connect( timeline, SIGNAL( frameChanged( int ) ), this, SLOT( animatedHideFrame( int ) ) );
	connect( timeline, SIGNAL( finished() ), this, SLOT( animatedHidePost() ) );
	timeline->start();
	/*QPropertyAnimation *zoomUpAnimation = new QPropertyAnimation( view, "scale" );
	zoomUpAnimation->setDuration(500);
	zoomUpAnimation->setStartValue(1,1);
	zoomUpAnimation->setEndValue(2,2);
	QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect();
	view->setGraphicsEffect( effect );
	QPropertyAnimation *animation = new QPropertyAnimation( effect,"opacity" );
	animation->setDuration(200);
	animation->setStartValue(1);
	animation->setEndValue(0);
	//animation->setEasingCurve(QEasingCurve::OutBack);
	animation->start( QPropertyAnimation::DeleteWhenStopped );
	QParallelAnimationGroup *group = new QParallelAnimationGroup;
	group->addAnimation(animation);
	group->addAnimation(zoomUpAnimation);
	group->start(QAbstractAnimation::DeleteWhenStopped);*/
	//connect(group,SIGNAL(finished()),this,SLOT(hideTaskPretty_post()));
}

void ViewTask::animatedHideFrame( int frame )  {
	qDebug( "frame" );
	int frames = 100; // copied from above
	//float multiplier = float( frame ) / frames;
	float inverse = float( frames - frame ) / frames;
	qDebug( "%f", inverse );
	view->scale( 1 * ( inverse ), 1 * ( inverse ) );
	/*int width = parent->parent->width() * 0.98;
	int height = Application::height() * 0.98;
	mainview->getViewTask()->getCurrentWidget()->setGeometry(
		QRectF( ( ( 10000 / 2 ) - ( width / 2 ) ), ( ( 10000 / 2 ) - ( height / 2 ) ), width, height )
	);*/
}

void ViewTask::animatedHidePost() {
	qDebug( "post" );
	view->scale( 1, 1 );
}

QGraphicsProxyWidget * ViewTask::getCurrentWidget() { return currentwidget; } 

void ViewTask::taskClear() {
	if ( currenttask ) {
		QList<QGraphicsItem *> items = scene->items();
		while ( ! items.isEmpty() ) { scene->removeItem( items.takeFirst() ); }
		//delete currentwidget;
		//delete currenttask; // this needs lots of testing
		//currentwidget = 0;  // seems to be bugs in qtermwidget :(
		//currenttask = 0;
	}
}

void ViewTask::taskConsole() {
	this->taskClear();
	currenttask = new TaskConsole();
	currentwidget = scene->addWidget( currenttask->getWidget() );
}

void ViewTask::taskBrowser() {
	this->taskClear();
	currenttask = new TaskBrowser();
	currentwidget = scene->addWidget( currenttask->getWidget() );
}
