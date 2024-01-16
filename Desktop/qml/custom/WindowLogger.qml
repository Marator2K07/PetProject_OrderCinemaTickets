import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// своя модель данных для данного визуального элемента
import WindowLoggerModel

Rectangle {
    id: mainRect
    anchors.fill: parent
    color: "#151515"


    // класс с моделью оконного логера
    WindowLoggerModel {
        id: loggerModel
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5

        MyMultiLineText {
            id: requestDataTextInput
            textData: loggerModel.messages
            readOnly: true
            hoverEnabled: false
            vBarWidth: 10
            isActive: false
            textSize: 22
            textColor: "#5e2970"
            textSelectionColor: "#5e2970"
            borderWidth: 1
            borderRadius: 4
            backgroundColor: "#ffffff"
            hoveredBackgroundColor: "#e3c8eb"
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
