import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    radius: borderRadius
    border.width: borderWidth
    clip: true

    // основные свойства для текста
    property alias textData: textInput.text
    property int textSize;
    property color textColor;
    property color textSelectionColor;
    // основные свойства для mainRect
    property int borderWidth;
    property int borderRadius;
    property color backgroundColor;
    property color hoveredBackgroundColor;

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
