/*
 * QLinuxFtdiSerialAutoConnector.h
 *
 *  Created on: 03.12.2011
 *      Author: cyborg-x1
 */

#ifndef QLINUXFTDISERIALAUTOCONNECTOR_H_
#define QLINUXFTDISERIALAUTOCONNECTOR_H_

#include <QThread>
#include "qlinuxftdiserialautoconnectorgui.h"

namespace qFtdi
{

class QLinuxFtdiSerialAutoConnector: public QThread
{
	Q_OBJECT

public:
	QLinuxFtdiSerialAutoConnector();
	virtual ~QLinuxFtdiSerialAutoConnector();
};

} /* namespace qFtdi */
#endif /* QLINUXFTDISERIALAUTOCONNECTOR_H_ */
