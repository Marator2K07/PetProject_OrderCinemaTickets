import QtQuick
import QtQuick.Layouts
// наши подгруженные модули/плагины в папке qml
import Qml.Custom 1.0
import Qml.Constants 1.0

Rectangle {
    id: mainRect
    color: ConstColors.defMinorBackground
    width: listViewMenu.orientation == ListView.Horizontal ? parent.width :
                                                             listViewMenu.contentWidth / menuListModel.count;
    height: listViewMenu.orientation == ListView.Horizontal ? listViewMenu.contentHeight / menuListModel.count :
                                                              listViewMenu.contentHeight;

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
                listViewMenu.contentHeight += item.height;
                listViewMenu.contentWidth += item.width;
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
            Layout.minimumHeight: listViewMenu.orientation == ListView.Horizontal ? mainRect.height :
                                                                                    contentHeight;
            spacing: 10
        }
    }
}
