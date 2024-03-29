import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// своя модель данных для данного визуального элемента
import FullViewLoggerModel

Item {
    anchors.fill: parent

    FullViewLoggerModel {
        id: loggerModel
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        MyMultiLineText {
            id: requestDataTextInput
            textItem.text: loggerModel.messages
            textItem.readOnly: true
            textItem.font.pixelSize: 22
            textItem.leftPadding: 8
            hoverEnabled: false
            vBarWidth: 10
            isActive: false
            border.width: 1
            radius: 4
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }

    Connections {
        // связываем сигнал messageReady у logger
        // и слот acceptMessage у loggerModel
        target: logger
        function onMessageReady(message) {
            loggerModel.acceptMessage(message);
        }
    }
}
