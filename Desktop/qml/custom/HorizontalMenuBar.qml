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

    property alias menuModel: menuListModel

    ListModel {
        id: menuListModel
    }

    Component {
        id: menuItemDelegate
        Loader {
            id: itemsLoader
            asynchronous: true
            source: switch(type) {
                case "button": return "ButtonMenuItem.qml";
            }
            onLoaded: {
                item.menuItemModel.text = text;
                item.menuItemModel.simplified = simplified;
                item.menuItemModel.image = image;
            }
        }
    }

    ListView {
        anchors.fill: mainRect
        model: menuListModel
        delegate: menuItemDelegate
    }
}
