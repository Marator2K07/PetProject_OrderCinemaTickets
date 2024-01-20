import QtQuick
import QtQuick.Controls

Button {
    id: control
    implicitWidth: Math.max(
                       buttonBackground ? buttonBackground.implicitWidth : 0,
                       textItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(
                        buttonBackground ? buttonBackground.implicitHeight : 0,
                        textItem.implicitHeight + topPadding + bottomPadding)

    property color defBackgroundColor: "white";
    property color hoverBackgroundColor: "#e3c8eb";
    property color presBackgroundColor: "#5e2970";
    property color defBorderColor: "black";
    property color hoverBorderColor: "black";
    property color presBorderColor: "black";
    property color defTextColor: "black";
    property color hoverTextColor: "white";
    property color presTextColor: "#e3c8eb";

    property alias buttonRect: buttonBackground;
    property alias textItem: textItem;
    property alias colorAnim: colorAnim;

    background: buttonBackground
    Rectangle {
        id: buttonBackground        
        border.color: defBorderColor
    }

    contentItem: textItem
    Text {
        id: textItem
        text: control.text
        color: defTextColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    states: [
        State {
            name: "Default"
            when: !control.down && !control.hovered
            PropertyChanges {
                target: buttonBackground
                color: defBackgroundColor
                border.color: defBorderColor
            }
            PropertyChanges {
                target: textItem
                color: defTextColor
            }
        },
        State {
            name: "Pressed"
            when: control.down
            PropertyChanges {
                target: buttonBackground
                color: presBackgroundColor
                border.color: presBorderColor
            }
            PropertyChanges {
                target: textItem
                color: presTextColor
            }            
        },
        State {
            name: "Hovered"
            when: !control.down && control.hovered
            PropertyChanges {
                target: buttonBackground
                color: hoverBackgroundColor
                border.color: hoverBorderColor
            }
            PropertyChanges {
                target: textItem
                color: hoverTextColor
            }
        }
    ]

    transitions: Transition {
        ColorAnimation {
            id: colorAnim
        }
    }
}
