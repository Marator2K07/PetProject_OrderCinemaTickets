import QtQuick 2.15
import QtQuick.Controls 2.15
import EnumItemsModel 1.0

ComboBox {
    id: control
    width: 120
    height: 40
    font.pixelSize: 20
    topInset: 0
    bottomInset: 0
    textRole: "key"
    valueRole: "value"

    property color fillColor: "#ffffff"
    property color fillDropColor: "#e3c8eb"
    property color selectFillColor: "#5e2970"
    property color borderColor: "#000000"
    readonly property var value: currentValue

    contentItem: Text {
        leftPadding: 10
        text: control.displayText
        font: control.font
        color: "black"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        anchors.fill: parent
    }

    background: Rectangle {
        implicitWidth: control.width
        implicitHeight: control.height
        color: fillColor
        border.color: borderColor
        border.width: 1
        anchors.fill: parent
        radius: 3
    }

    delegate: ItemDelegate {
        width: control.width
        contentItem: Rectangle
        {
            anchors.fill:parent
            color: hovered ? selectFillColor : fillDropColor
            height: 40

            Text {
                anchors.centerIn: parent
                text: key
                color: "white"
                font: control.font
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
            }
        }
    }   

    // тестовая реализация
    model: ListModel {
        id: originalModel
        Component.onCompleted: {
            originalModel.append({key: "GET", value: 1.0});
            originalModel.append({key: "POST", value: 2.0});
        }
    }

    EnumItemsModel {
        id: customModel        
    }    
}


