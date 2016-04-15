#include "QImplodeAnimation.h"

QImplodeAnimationIn::QImplodeAnimationIn( QObject *_parent ) : QObject( _parent ) {}

QImplodeAnimationIn::~QImplodeAnimationIn() {}

void QImplodeAnimationIn::start() {
	this->__start();

	// not moveable due to QObject subclassing, macros & abstract magic :(
	connect( qtimeline, SIGNAL( frameChanged( int ) ), this, SLOT( step( int ) ) );
	connect( qtimeline, SIGNAL( finished() ), this, SLOT( end() ) );
}

void QImplodeAnimationIn::step( int _frame ) {
	this->__step_start();

	float multiplier __attribute__((unused)) = float( _frame ) / this->frames;
	float inverse __attribute__((unused)) = float( this->frames - _frame ) / this->frames;
	
	this->__step_end();
}

void QImplodeAnimationIn::end() {
	this->__end();
}

QImplodeAnimationOut::QImplodeAnimationOut( QObject *_parent ) : QObject( _parent ) {}

QImplodeAnimationOut::~QImplodeAnimationOut() {}

void QImplodeAnimationOut::start() {
	this->__start();

	// not moveable due to QObject subclassing, macros & abstract magic :(
	connect( qtimeline, SIGNAL( frameChanged( int ) ), this, SLOT( step( int ) ) );
	connect( qtimeline, SIGNAL( finished() ), this, SLOT( end() ) );
}

void QImplodeAnimationOut::step( int _frame ) {
	this->__step_start();

	float multiplier __attribute__((unused)) = float( _frame ) / this->frames;
	float inverse __attribute__((unused)) = float( this->frames - _frame ) / this->frames;
	
	this->__step_end();
}

void QImplodeAnimationOut::end() {
	this->__end();
}
