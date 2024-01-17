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
            name: "normal"
            when: !control.down

            PropertyChanges {
                target: buttonBackground
                color: "#d307ff"
                font.pixelSize: 22
                border.color: "#047eff"
            }

            PropertyChanges {
                target: textItem
                color: "#047eff"
                font.pixelSize: 22
            }
        },
        State {
            name: "down"
            when: control.down
            PropertyChanges {
                target: textItem
                color: "#ffffff"
                font.pixelSize: 22
            }

            PropertyChanges {
                target: buttonBackground
                color: "#047eff"
                border.color: "#00000000"
            }
        }
    ]

    transitions: Transition {
        ColorAnimation {
            duration: 222
        }
    }
}
