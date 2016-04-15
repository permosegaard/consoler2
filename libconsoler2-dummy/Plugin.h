#ifndef PLUGIN_H
#define PLUGIN_H

#include <functional>

#include <QMap>
#include <QList>
#include <QWidget>
#include <QPushButton>
#include <QMapIterator>

#include "../consoler2/QAbstractPlugin.h"


class TestWidgetBase {
public:
	TestWidgetBase( QString );
	~TestWidgetBase();
	QWidget * getWidget();
private:
	QWidget *widget;
};

class TestWidget1 : public TestWidgetBase {
public:
	TestWidget1( QString );
	~TestWidget1();
};

class TestWidget2 : public TestWidgetBase {
public:
	TestWidget2( QString );
	~TestWidget2();
};


class QDummyPlugin : public QObject, QAbstractPlugin {
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "k34jthkj3hkjth4j") // this needs to be unique per plugin
	Q_INTERFACES(QAbstractPlugin)

public:
	QDummyPlugin( QObject * = 0 );
	~QDummyPlugin();

	QWidget * newWidget( QString );
	QList<QString> * listTasks();

private:
	QMap<QString,std::function<QWidget *(QString)>> tasks; 
	QList<QWidget *> *widgets;

	QWidget * newTestWidget1( QString );
	QWidget * newTestWidget2( QString );
};

#endif /* PLUGIN_H */
