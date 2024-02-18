import QtQuick
import QtQuick.Layouts
// наши подгруженные модули/плагины в папке qml
import Qml.Custom 1.0
import Qml.Constants 1.0

Rectangle {
    id: mainRect
    color: ConstColors.defMinorBackground
    anchors.top: parent.top
    width: parent.width

    property alias menuModel: menuListModel
    property alias menuOrientation: listViewMenu.orientation

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
                mainRect.height = itemsLoader.childrenRect.height;
            }
        }
    }

    ColumnLayout {
        anchors.fill: mainRect
        ListView {
            id: listViewMenu
            model: menuListModel
            delegate: menuItemDelegate
            Layout.alignment: Qt.AlignCenter
            Layout.minimumWidth: contentWidth
            Layout.preferredHeight: mainRect.height

            spacing: 10
        }
    }
}
