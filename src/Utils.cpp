#include "Utils.h"

void Utils::recursiveKiller( int pid ) {
	QVector<int> pids = QVector<int>();
	QVector<int> tokill = QVector<int>();
	tokill.append( pid );
	while ( ! pids.isEmpty() ) {
		int current = pids.takeFirst();
		tokill.append( current );
		QString filepath = ( QString( "/proc/%1/tasks/%1/children" ) ).arg( current );
		QFileInfo fileinfo( filepath );
		if ( fileinfo.exists() ) {
			QFile file( filepath );
			QString contents = QTextStream( &file ).readAll();
			QStringList splits = contents.split( " " );
			for ( int i = 0; i < splits.size(); i++ ) { pids.append( splits.at( i ).toInt() ); }
			file.close();
		}
	}
	for ( int i = 0; i < tokill.size(); i++ ) { kill( tokill.at( i ), SIGTERM ); }
}
