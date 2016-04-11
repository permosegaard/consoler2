#pragma once

#include "MainView.h"

#include <QApplication>
#include <QMainWindow>

class Application : public QMainWindow {
	Q_OBJECT

private:
	MainView *mainview;

public:
	explicit Application( QWidget *parent = 0 );
	~Application();

private slots:
	void resizeEvent( QResizeEvent * );
	void resizedHandler();
};
