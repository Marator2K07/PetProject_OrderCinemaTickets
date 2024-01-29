import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: mainItem
    height: button.height
    width: button.width

    property color backgroundColor: "lightgray"

    MyButton {
        id: button
        text: qsTr("Test")
        textItem.font.pixelSize: 18
        colorAnim.duration: 150
        defBackgroundColor: backgroundColor
        buttonRect.border.width: 0
    }
}
