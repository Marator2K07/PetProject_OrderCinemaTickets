import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    color: backgroundColor
    clip: true

    // основные свойства для текста
    property alias textItem: textInput
    property color textColor: "#5e2970";
    property color textSelectionColor: "#5e2970";
    // основные свойства для mainRect
    property color backgroundColor: "#ffffff";
    property color hoveredBackgroundColor: "#e3c8eb";
    property bool hoverEnabled;

    MouseArea {
        anchors.fill: parent
        hoverEnabled: mainRect.hoverEnabled
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
        readOnly: mainRect.readOnly
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
        to: hoveredBackgroundColor
        from: backgroundColor
    }

    ColorAnimation {
        id: fromHoveredColor
        target: mainRect
        property: "color"
        to: backgroundColor
        from: hoveredBackgroundColor
    }
}
