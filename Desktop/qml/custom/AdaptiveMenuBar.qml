import QtQuick
import QtQuick.Layouts
// наш подгруженный модуль/плагин в папке qml
import Qml.Custom 1.0

Rectangle {
    id: mainRect
    color: "lightgray"
    anchors.top: parent.top
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
                item.anchors.centerIn = parent
            }
        }
    }

    ColumnLayout {
        anchors.fill: mainRect
        ListView {
            id: listViewMenu
            model: menuListModel
            delegate: menuItemDelegate
            orientation: ListView.Horizontal
            Layout.alignment: Qt.AlignCenter
            Layout.minimumWidth: contentWidth
            Layout.preferredHeight: mainRect.height

            spacing: 10
        }
    }
}
