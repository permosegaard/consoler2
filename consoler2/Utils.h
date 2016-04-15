#ifndef UTILS_H
#define UTILS_H

#define INTERFACE_FUNCTION(DEFINITION) virtual DEFINITION = 0;

#define INTERFACE_START(CLASSNAME)\
class CLASSNAME {\
public:\
	virtual ~CLASSNAME() {}\
protected:\
	CLASSNAME() {}\
	CLASSNAME( const CLASSNAME & ) {}\
	CLASSNAME & operator = ( const CLASSNAME & ) { return *this ; }

#define INTERFACE_END(CLASSNAME)\
};

#define INTERFACE_QT_START(CLASSNAME)\
class CLASSNAME {\
public:\
	virtual ~CLASSNAME() {}\
protected:\
	CLASSNAME() {}\
	CLASSNAME( const CLASSNAME & ) {}\
	CLASSNAME & operator = ( const CLASSNAME & ) { return *this ; }

#define INTERFACE_QT_END(CLASSNAME)\
};\
Q_DECLARE_INTERFACE(CLASSNAME, "")

#endif /* UTILS_H */
