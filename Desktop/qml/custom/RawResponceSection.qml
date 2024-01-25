import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// своя модель необработанного ответа
import RawResponceModel
// подключение перечислений для идентификаторов запроса
import RequestEnums

Item {
    anchors.fill: parent

    property alias isLoading: loadingScreen.isLoading
    property bool withError: false

    RawResponceModel {
        id: responceModel
    }

    MyMultiLineText {
        anchors.fill: parent
        id: requestDataTextInput
        textItem.text: responceModel.data
        textItem.readOnly: true
        textItem.font.pixelSize: 22
        textItem.leftPadding: 8
        hoverEnabled: false
        vBarWidth: 10
        isActive: false
        border.width: 1
        radius: 4
        Layout.fillWidth: true
        Layout.fillHeight: true
    }

    Label {
        id: errorMessage
        font.pixelSize: loadingScreen.loadedStateFontSize
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.centerIn: parent
        text: responceModel.error
    }

    LoadingScreen {
        id: loadingScreen
        rotateAnim.duration: 650
        loadingSpinLabel.height: 39
    }

    Component.onCompleted: {
        responceModel.subscribe(responceHandler, RequestEnums.REQUESTFORM);
    }
}
