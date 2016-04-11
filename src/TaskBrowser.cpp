#include "TaskBrowser.h"

TaskBrowser::TaskBrowser() : Task() {
	browser = new QWebEngineView();
	//browser->load( QUrl( url ) );
	browser->load( QUrl( "http://icanhazip.com/" ) );
	widget = static_cast<QWidget *>( browser );
}

TaskBrowser::~TaskBrowser() {}
