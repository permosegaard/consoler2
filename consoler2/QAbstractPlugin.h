#ifndef QABSTRACTPLUGIN_H
#define QABSTRACTPLUGIN_H

#include <QWidget>

#include "Utils.h"

INTERFACE_QT_START(QAbstractPlugin)
public:
	INTERFACE_FUNCTION(QList<QString> * listTasks())
	INTERFACE_FUNCTION(QWidget * newWidget( QString ))
INTERFACE_QT_END(QAbstractPlugin)

#endif /* QABSTRACTPLUGIN_H */
