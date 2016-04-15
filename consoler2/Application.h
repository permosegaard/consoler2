#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QMainWindow>

#include "QConsoler.h"
#include "QTaskPlugins.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow( QWidget * = 0 );
    ~MainWindow();

private:
	QConsoler *qconsoler;

private slots:
	void resizeEvent( QResizeEvent * );
};

class Application {
public:
	Application( int, char ** );
	~Application();
	
	int run();

private:
	QApplication *qapplication;
	MainWindow *mainwindow;
};

#endif /* APPLICATION_H */
