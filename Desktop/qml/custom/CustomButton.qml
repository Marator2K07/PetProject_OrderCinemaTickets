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

    // свойства для всех трех состояний
    property color defBackgroundColor;
    property color hoverBackgroundColor;
    property color presBackgroundColor;
    property color defBorderColor;
    property color hoverBorderColor;
    property color presBorderColor;
    property color defTextColor;
    property color hoverTextColor;
    property color presTextColor;
    // ссылки свойств на основные элементы кнопки
    property alias buttonRect: buttonBackground;
    property alias textItem: textItem;

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
            duration: 222
        }
    }
}
