import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// своя модель данных для данного визуального элемента
import WindowLoggerModel

Rectangle {
    anchors.fill: parent
    color: "#151515"

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        spacing: 8

        // класс с моделью оконного логера
        WindowLoggerModel {
            id: loggerModel
        }

        Rectangle {
            id: rectangle
            color: "#ffffff"
            radius: 8
            anchors.left: parent.left
            anchors.right: parent.right
            Layout.fillHeight: true
            Keys.onUpPressed: vbar.decrease()
            Keys.onDownPressed: vbar.increase()

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true
                onWheel: function moveTextField(wheelEvent) {
                    if (wheelEvent.angleDelta.y > 0) {
                        vbar.decrease();
                    }
                    else {
                        vbar.increase();
                    }
                }
            }

            TextEdit {
                id: textEdit
                readOnly: true
                activeFocusOnPress: true
                text: loggerModel.messages
                anchors.left: parent.left
                font.pixelSize: 20
                color: "black"
                wrapMode: TextEdit.Wrap
                height: contentHeight
                width: rectangle.width - vbar.width - 7
                y: -vbar.position * textEdit.height
                anchors.rightMargin: 4
                anchors.leftMargin: 4
                selectionColor: "black"
                selectByKeyboard: true
                selectByMouse: true

                // при добавлении новой информации в логер
                // фокус движется за последней строкой в тексте
                property string lastText: textEdit.text
                onTextChanged: function moveTextField() {
                    if (textEdit.text > textEdit.lastText) {
                        vbar.increase();
                    } else {
                        vbar.decrease();
                    }
                    textEdit.lastText = textEdit.text;
                }
            }
        }
    }

    ScrollBar {
        id: vbar
        x: 390
        y: 0
        hoverEnabled: true
        active: hovered || pressed
        orientation: Qt.Vertical
        size: rectangle.height / textEdit.height
        width: 14
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.topMargin: 8
        anchors.rightMargin: 8
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
