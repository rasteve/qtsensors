/****************************************************************************
**
** Copyright (C) 2016 Research In Motion
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSensors module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QMLHOLSTERSENSOR_P_H
#define QMLHOLSTERSENSOR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qmlsensor_p.h"

QT_BEGIN_NAMESPACE

class QHolsterSensor;

class Q_SENSORSQUICK_PRIVATE_EXPORT QmlHolsterSensor : public QmlSensor
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HolsterSensor)
    QML_ADDED_IN_VERSION(5,1)
public:
    explicit QmlHolsterSensor(QObject *parent = 0);
    ~QmlHolsterSensor();

private:
    QSensor *sensor() const override;
    QmlSensorReading *createReading() const override;

    QHolsterSensor *m_sensor;
};

class Q_SENSORSQUICK_PRIVATE_EXPORT QmlHolsterReading : public QmlSensorReading
{
    Q_OBJECT
    Q_PROPERTY(bool holstered READ holstered NOTIFY holsteredChanged)
    QML_NAMED_ELEMENT(HolsterReading)
    QML_UNCREATABLE("Cannot create HolsterReading")
    QML_ADDED_IN_VERSION(5,1)
public:
    explicit QmlHolsterReading(QHolsterSensor *sensor);
    ~QmlHolsterReading();

    bool holstered() const;

Q_SIGNALS:
    void holsteredChanged();

private:
    QSensorReading *reading() const override;
    void readingUpdate() override;

    QHolsterSensor *m_sensor;
    bool m_holstered;
};

QT_END_NAMESPACE
#endif