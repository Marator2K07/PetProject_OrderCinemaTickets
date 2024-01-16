import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    width: 400
    height: 30
    radius: 3
    border.width: 1
    clip: true

    // основные свойства для текста
    property string textData: qsTr("...")
    property int textSize: 22
    property color textColor: "#5e2970"
    property color textSelectionColor: "#5e2970"
    // основные свойства для mainRect
    property int borderWidth: 2
    property int borderRadius: 3
    property color backgroundColor: "#ffffff"
    property color hoveredBackgroundColor: "#e3c8eb"

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
        target: mainRect
        property: "color"
        to: "#e3c8eb"
        from: "#ffffff"
    }

    ColorAnimation {
        id: colorAnimation2
        target: mainRect
        property: "color"
        to: "#ffffff"
        from: "#e3c8eb"
    }
}
