import QtQuick
import QtQuick.Controls

ComboBox {
    id: control
    textRole: "info"
    valueRole: "value"

    property color defTextColor: "#000000"
    property color hovTextColor: "#ffffff"
    property color defBackgroundColor: "#ffffff"
    property color hovBackgroundColor: "#5e2970"
    property color dropDefBackgroundColor: "#e3c8eb"
    property color dropHovBackgroundColor: "#5e2970"

    property alias rectItem: comboRect
    property bool isActive: true

    contentItem: Text {
        leftPadding: control.leftPadding
        height: control.height
        text: control.displayText
        font: control.font
        color: hovered && isActive ? hovTextColor :
                                     defTextColor
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        anchors.fill: parent
    }

    background: Rectangle {
        id: comboRect
        color: hovered && isActive ? hovBackgroundColor :
                                     defBackgroundColor
        anchors.fill: parent
    }

    delegate: ItemDelegate {
        width: control.width
        contentItem: Rectangle
        {
            anchors.fill:parent
            color: hovered && isActive ? dropHovBackgroundColor :
                                         dropDefBackgroundColor

            Text {                
                text: info
                anchors.centerIn: parent
                color: hovered && isActive ? hovTextColor :
                                             defTextColor
                font: control.font
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}


