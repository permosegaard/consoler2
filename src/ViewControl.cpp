#include "ViewControl.h"

ViewControl::ViewControl() : View() {
	view->setStyleSheet( "QWidget { background-color: red }" );
}

ViewControl::~ViewControl() {}

void ViewControl::animatedShow() {}

void ViewControl::animatedHide() {
	qDebug( "test2" );
}
