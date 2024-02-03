import QtQuick
import QtQuick.Layouts
// наш подгруженный модуль/плагин в папке qml
import Qml.Custom 1.0

Rectangle {
    id: mainRect
    color: "lightgray"
    anchors.top: parent.top
    anchors.topMargin: 0
    width: parent.width
    height: 75

    RowLayout {
        id: rowLayout
        height: mainRect.height
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        ButtonMenuItem {
            menuItemModel.text: qsTr("Test text")
            menuItemModel.simplified: true
            menuItemModel.image: "qrc:/icons/test_icon"
        }
        ButtonMenuItem {
            menuItemModel.text: qsTr("Test text")
            menuItemModel.simplified: true
        }
        ButtonMenuItem {
            menuItemModel.text: qsTr("Test text")
            menuItemModel.simplified: false
            menuItemModel.image: "qrc:/icons/test_icon"
        }
    }
}
