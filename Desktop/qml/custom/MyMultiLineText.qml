import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainRect
    color: backgroundColor 
    Keys.onUpPressed: vbar.decrease()
    Keys.onDownPressed: vbar.increase()
    clip: true

    property color textColor: "#5e2970";
    property color textSelectionColor: "#5e2970";
    property color backgroundColor: "#ffffff";
    property color hoveredBackgroundColor: "#e3c8eb";

    property alias textItem: textEdit;
    property int vBarWidth;
    property bool hoverEnabled;
    property bool isActive;

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: mainRect.hoverEnabled
        onHoveredChanged: {
            if (containsMouse && isActive) {
                toHoveredColor.start()
                textEdit.forceActiveFocus();
            } else if (!containsMouse && isActive) {
                fromHoveredColor.start()
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
            height: contentHeight
            color: textColor
            width: mainRect.width - vbar.width - leftPadding
            y: -vbar.position * height
            wrapMode: TextEdit.Wrap
            selectionColor: textSelectionColor
            selectByKeyboard: true
            selectByMouse: true

            // адаптация vbar при изменении свойства contentHeight
            property int tempContentHeight: 0
            onContentHeightChanged: {
                if (contentHeight > tempContentHeight) {
                    vbar.increase();
                } else if (contentHeight < tempContentHeight) {
                    vbar.decrease();
                }
                tempContentHeight = contentHeight;
                vbar.stepSize = font.pixelSize * 1.35 / contentHeight;
            }
        }
    }

    ScrollBar {
        id: vbar
        hoverEnabled: true
        active: hovered || pressed
        orientation: Qt.Vertical
        size: mainRect.height / textEdit.contentHeight
        width: vBarWidth
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
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
