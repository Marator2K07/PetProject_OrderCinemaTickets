import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    color: backgroundColor
    radius: borderRadius
    border.width: borderWidth
    anchors.centerIn: parent
    anchors.top: parent.bottom
    anchors.left: parent.left    
    Keys.onUpPressed: vbar.decrease()
    Keys.onDownPressed: vbar.increase()
    clip: true

    // основные свойства для текста
    property alias textData: textEdit.text
    property int textSize;
    property color textColor;
    property color textSelectionColor;
    property bool readOnly;
    property int vBarWidth;
    // основные свойства для mainRect
    property int borderWidth;
    property int borderRadius;
    property color backgroundColor;
    property color hoveredBackgroundColor;
    property bool hoverEnabled;
    property bool isActive;

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: mainRect.hoverEnabled
        onHoveredChanged: {
            if (containsMouse && isActive) {
                colorAnimation1.start()
                textEdit.forceActiveFocus();
            } else if (!containsMouse && isActive) {
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
            anchors.left: parent.left
            font.pixelSize: textSize
            height: contentHeight
            color: textColor
            width: mainRect.width - vbar.width - 7
            y: -vbar.position * textEdit.height
            wrapMode: TextEdit.Wrap
            anchors.leftMargin: 7
            selectionColor: textSelectionColor
            selectByKeyboard: true
            selectByMouse: true
        }
    }

    ScrollBar {
        id: vbar
        hoverEnabled: true
        active: hovered || pressed
        orientation: Qt.Vertical
        size: mainRect.height / textEdit.height
        width: vBarWidth
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    ColorAnimation {
        id: colorAnimation1
        target: mainRect
        property: "color"
        to: hoveredBackgroundColor
        from: backgroundColor
    }

    ColorAnimation {
        id: colorAnimation2
        target: mainRect
        property: "color"
        to: backgroundColor
        from: hoveredBackgroundColor
    }
}
