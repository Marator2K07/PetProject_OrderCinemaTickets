import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// своя модель данных для данного визуального элемента
import ButtonMenuItemModel

Item {
    id: mainItem
    height: button.height
    width: button.width

    property color backgroundColor: "lightgray"

    ButtonMenuItemModel {
        id: menuItemModel
    }

    RowLayout {
        id: rowUrlLayout
        height: button.height
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        MyButton {
            id: button
            text: menuItemModel.text
            textItem.font.pixelSize: 18
            colorAnim.duration: 150
            defBackgroundColor: backgroundColor
            buttonRect.border.width: 0
        }
    }
}
