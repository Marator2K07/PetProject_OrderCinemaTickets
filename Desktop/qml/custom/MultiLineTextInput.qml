import QtQuick
import QtQuick.Controls

Rectangle {
    id: rectangle
    width: 400
    height: 150
    radius: 3
    border.width: 1
    anchors.centerIn: parent
    anchors.top: parent.bottom
    anchors.left: parent.left
    clip: true
    Keys.onUpPressed: vbar.decrease()
    Keys.onDownPressed: vbar.increase()

    property alias body: textEdit.text

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onHoveredChanged: {
            if (containsMouse) {
                colorAnimation1.start()
                textEdit.forceActiveFocus();
            } else {
                colorAnimation2.start()
            }
        }
        onWheel: function moveTextField(wheelEvent) {
            if (wheelEvent.angleDelta.y > 0) {
                vbar.decrease();
            }
            else {
                vbar.increase();
            }
        }
        onClicked: {
            textEdit.forceActiveFocus();
        }

        TextEdit {
            id: textEdit
            activeFocusOnPress: true
            text: "..."
            anchors.left: parent.left
            font.pixelSize: 20
            height: contentHeight
            color: "#5e2970"
            width: rectangle.width - vbar.width - 7
            y: -vbar.position * textEdit.height
            wrapMode: TextEdit.Wrap
            anchors.leftMargin: 7
            selectionColor: "#5e2970"
            selectByKeyboard: true
            selectByMouse: true
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
        width: 10
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    ColorAnimation {
        id: colorAnimation1
        target: rectangle
        property: "color"
        to: "#e3c8eb"
        from: "#ffffff"
    }

    ColorAnimation {
        id: colorAnimation2
        target: rectangle
        property: "color"
        to: "#ffffff"
        from: "#e3c8eb"
    }
}
