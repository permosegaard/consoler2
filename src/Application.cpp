#include "Application.h"

Application::Application( QWidget *parent ) : QMainWindow( parent ) {
	this->setWindowTitle( "this is totally not a test" );
	this->resize( 800, 600 );

	mainview = new MainView();
	this->setCentralWidget( mainview->getGraphicsView() );
	
	this->show();
}

Application::~Application() {}

void Application::resizeEvent( QResizeEvent *event ) {
	QMainWindow::resizeEvent( event );
	this->resizedHandler();
}

void Application::resizedHandler() {
	//if ( mainview->getViewTask()->getCurrentTask() ) {
	//	mainview->getViewTask()->getCurrentTask()->getWidget()->resize( this->width() * 0.98, this->height() * 0.98 );
	//}
	//mainview->getViewControl()->getGraphicsView()->resize( this->width() * 0.99, this->height() * 0.99 );
	//mainview->getViewTask()->getGraphicsView()->resize( this->width() * 0.99, this->height() * 0.99 );
	
	// above broken by fixed size canvas'
	
	if ( mainview->getViewTask()->getCurrentTask() ) {
		int width = this->width() * 0.98;
		int height = this->height() * 0.98;
		mainview->getViewTask()->getCurrentTask()->getWidget()->resize( width, height );
		mainview->getViewTask()->getCurrentWidget()->setGeometry(
			QRectF( ( ( 10000 / 2 ) - ( width / 2 ) ), ( ( 10000 / 2 ) - ( height / 2 ) ), width, height )
		);
	}
}

int main( int argc, char *argv[] ) {
	QApplication qapplication( argc, argv );
	new Application();
	return qapplication.exec();
}
