import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    width: parent.width
    height: textSize * 1.5
    radius: borderRadius
    border.width: borderWidth
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
                toHoveredColor.start()
            } else {
                fromHoveredColor.start()
            }
        }
    }

    TextInput {
        id: textInput
        color: textColor
        text: textData
        anchors.fill: parent
        font.pixelSize: textSize
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        anchors.leftMargin: 7
        font.strikeout: false
        font.weight: Font.Medium
        selectionColor: textSelectionColor
        font.bold: false
        selectByMouse: true
    }

    ColorAnimation {
        id: toHoveredColor
        target: mainRect
        property: "color"
        to: "#e3c8eb"
        from: "#ffffff"
    }

    ColorAnimation {
        id: fromHoveredColor
        target: mainRect
        property: "color"
        to: "#ffffff"
        from: "#e3c8eb"
    }
}
