#include "Plugin.h"

TestWidgetBase::TestWidgetBase( QString _text ) {
	this->widget = new QPushButton( _text.toLatin1().constData() );
}

QWidget * TestWidgetBase::getWidget() { return this->widget; }

TestWidget1::TestWidget1( QString _text ) : TestWidgetBase( _text ) {}

TestWidget1::~TestWidget1() {}

TestWidget2::TestWidget2( QString _text ) : TestWidgetBase( _text ) {}

TestWidget2::~TestWidget2() {}

QDummyPlugin::QDummyPlugin( QObject *_parent ) : QObject( _parent ) {
	this->tasks = QMap<QString,std::function<QWidget *(QString)>>();
	this->tasks[ "test1" ] = std::bind( &QDummyPlugin::newTestWidget1, this, std::placeholders::_1 );
	this->tasks[ "test2" ] = std::bind( &QDummyPlugin::newTestWidget2, this, std::placeholders::_1 );

	this->widgets = new QList<QWidget *>();
}

QDummyPlugin::~QDummyPlugin() {}

QList<QString> * QDummyPlugin::listTasks() {
	typedef QMapIterator<QString,std::function<QWidget *(QString)>> iteratortype;
	auto *tasknames = new QList<QString>();
	iteratortype qmapiterator( this->tasks );
	while( qmapiterator.hasNext() && ( qmapiterator.next(), true ) ) { // NOTE THE COMMA
		tasknames->append( qmapiterator.key() );
	}
	return tasknames;
}

QWidget * QDummyPlugin::newWidget( QString _name ) {
	//if ( this->tasks.contains( _name ) ) {
		auto reference = this->tasks.value( _name );
		return reference( QString( "test" ) );
	//}
	// assert fail or throw exception, needs thought
}

QWidget * QDummyPlugin::newTestWidget1( QString _text ) {
	TestWidgetBase *testwidget1 = new TestWidget1( _text );
	return testwidget1->getWidget();
}

QWidget * QDummyPlugin::newTestWidget2( QString _text ) {
	TestWidgetBase *testwidget2 = new TestWidget2( _text );
	return testwidget2->getWidget();
}
