#include "QExplodeAnimation.h"

QExplodeAnimationIn::QExplodeAnimationIn( QObject *_parent ) : QObject( _parent ) {}

QExplodeAnimationIn::~QExplodeAnimationIn() {}

void QExplodeAnimationIn::start() {
	this->__start();

	// not moveable due to QObject subclassing, macros & abstract magic :(
	connect( qtimeline, SIGNAL( frameChanged( int ) ), this, SLOT( step( int ) ) );
	connect( qtimeline, SIGNAL( finished() ), this, SLOT( end() ) );
}

void QExplodeAnimationIn::step( int _frame ) {
	this->__step_start();

	float multiplier __attribute__((unused)) = float( _frame ) / this->frames;
	float inverse __attribute__((unused)) = float( this->frames - _frame ) / this->frames;
	
	this->__step_end();
}

void QExplodeAnimationIn::end() {
	this->__end();
}

QExplodeAnimationOut::QExplodeAnimationOut( QObject *_parent ) : QObject( _parent ) {}

QExplodeAnimationOut::~QExplodeAnimationOut() {}

void QExplodeAnimationOut::start() {
	this->__start();

	this->qgraphicsopacityeffect = new QGraphicsOpacityEffect( this->qgraphicsview );
	this->qgraphicsview->setGraphicsEffect( this->qgraphicsopacityeffect );
	
	// not moveable due to QObject subclassing, macros & abstract magic :(
	connect( qtimeline, SIGNAL( frameChanged( int ) ), this, SLOT( step( int ) ) );
	connect( qtimeline, SIGNAL( finished() ), this, SLOT( end() ) );
}

void QExplodeAnimationOut::step( int _frame ) {
	this->__step_start();

	float multiplier __attribute__((unused)) = float( _frame ) / this->frames;
	float inverse __attribute__((unused)) = float( this->frames - _frame ) / this->frames;
	
	this->qgraphicsview->scale(
		1 + ( multiplier * this->scalemultipler ),
		1 + ( multiplier * this->scalemultipler )
	);
	this->qgraphicsopacityeffect->setOpacity( inverse );

	this->__step_end();
}

void QExplodeAnimationOut::end() {
	this->qgraphicsview->resetMatrix();
	this->qgraphicsview->resetTransform();
	
	this->qgraphicsview->scale( 1, 1 );
	this->qgraphicsopacityeffect->setOpacity( 1 );

	this->__end();
}
