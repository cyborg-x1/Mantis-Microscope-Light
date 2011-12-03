/*
 * MicroScopeConnector.h
 *
 *  Created on: 28.10.2011
 *      Author: cyborg-x1
 */

#ifndef MICROSCOPECONNECTOR_H_
#define MICROSCOPECONNECTOR_H_

#include <QThread>
#include <QString>
#include "qext/qextserialport.h"
#include "qext/qextserialport_global.h"
#include "qext/qextserialenumerator.h"
#include <ftdi.hpp>

class MicroScopeConnector : public QThread
{
	Q_OBJECT
public:
	MicroScopeConnector();
	virtual ~MicroScopeConnector();
};

#endif /* MICROSCOPECONNECTOR_H_ */
