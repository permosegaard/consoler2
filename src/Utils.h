#pragma once

#include <signal.h> // KILL
#include <signal.h> // SIGTERM

#include <QVector>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

class Utils {
public:
	void recursiveKiller( int );
};
