#ifndef QTASKPLUGINS_H
#define QTASKPLUGINS_H

#include <QDir>
#include <QPluginLoader>
#include <QCoreApplication>

#include "QAbstractPlugin.h"

class QTaskPlugins {
public:
	static QTaskPlugins & Instance() {
		static QTaskPlugins QTaskPluginsInstance;
		return QTaskPluginsInstance;
	}

	QTaskPlugins( QTaskPlugins const& ) = delete;
	QTaskPlugins( QTaskPlugins && ) = delete;
	QTaskPlugins & operator= ( QTaskPlugins const& ) = delete;
	QTaskPlugins & operator= ( QTaskPlugins && ) = delete;

protected:
	QTaskPlugins();
	~QTaskPlugins();
};

#endif /* QTASKPLUGINS_H */
