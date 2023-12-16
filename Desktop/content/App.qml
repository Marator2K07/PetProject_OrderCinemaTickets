// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import Desktop

Window {
    width: 600
    height: 550

    visible: true
    title: "Desktop"

    WebRequestForm {
        id: mainScreen
        anchors.fill: parent
    }

}

