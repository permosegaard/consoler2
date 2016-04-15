#include "Application.h"

MainWindow::MainWindow( QWidget *parent ) : QMainWindow( parent ) {
	qconsoler = new QConsoler();

	this->setCentralWidget( qconsoler );
	this->resize( 800, 600 );
	this->setWindowTitle( "consoler2" );

	this->show();
}

MainWindow::~MainWindow() {}

void MainWindow::resizeEvent( QResizeEvent *event ) {
	QMainWindow::resizeEvent( event );
}

Application::Application( int argc, char **argv ) {
	qapplication = new QApplication( argc, argv );
	mainwindow = new MainWindow();
}

int Application::run() {
	QTaskPlugins::Instance(); // scan and load plugins

	return qapplication->exec();
}

Application::~Application() {}

int main( int argc, char **argv ) {
	Application application( argc, argv );
	application.run();
	
	return 0;
}
