import QtQuick 2.15
import QtQuick.Controls 2.15
import Desktop 1.0

Rectangle {
    id: rectangle
    width: 400
    height: 30
    radius: 3
    border.width: 1
    clip: true

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onHoveredChanged: {
            if (containsMouse) {
                colorAnimation1.start()
            } else {
                colorAnimation2.start()
            }
        }
    }

    TextInput {
        id: textInput
        color: "#5e2970"
        text: qsTr("...")
        anchors.fill: parent
        font.pixelSize: 20
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        anchors.leftMargin: 7
        font.strikeout: false
        font.weight: Font.Medium
        selectionColor: "#5e2970"
        font.bold: false
        selectByMouse: true
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
