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
    property alias menuItemModel: menuItemModel
    property int iconSize: 26

    ButtonMenuItemModel {
        id: menuItemModel
    }

    MyButton {
        id: button
        display: menuItemModel.simplified ? AbstractButton.TextOnly :
                                            AbstractButton.TextBesideIcon
        icon.source: menuItemModel.image
        icon.width: iconSize
        icon.height: iconSize

        text: menuItemModel.text
        font.pixelSize: 20
        colorAnim.duration: 150
        defBackgroundColor: backgroundColor
        buttonRect.border.width: 0
    }
}
