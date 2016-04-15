#include "QTaskPlugins.h"

QTaskPlugins::QTaskPlugins() {
	QDir *qdir = new QDir( QCoreApplication::applicationDirPath() );
	qdir->cd( "plugins" );

	Q_FOREACH( QString fileName, qdir->entryList( QDir::Files ) ) {
		QPluginLoader *qpluginloader = new QPluginLoader( qdir->absoluteFilePath( fileName ) );
		QObject *plugin = qpluginloader->instance();
		if ( plugin ) {
			QAbstractPlugin *casted_plugin = qobject_cast<QAbstractPlugin *>( plugin );
			auto tasks = casted_plugin->listTasks();
			QListIterator<QString> qlistiterator( *tasks );
			while ( qlistiterator.hasNext() ) { qDebug( "%s", qlistiterator.next().toLatin1().constData() ); }
		}
		else { qDebug( "%s", qpluginloader->errorString().toLatin1().constData() ); }
	}
}

QTaskPlugins::~QTaskPlugins() {}
