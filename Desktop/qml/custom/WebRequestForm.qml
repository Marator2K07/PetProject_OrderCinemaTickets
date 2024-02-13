import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// своя подключенная модель данных для комбобокс
import EnumListModel
// своя модель данных для данного визуального элемента
import RequestFormModel

import "web_request_form.js" as Script

Rectangle {
    id: rectangle
    width: 600
    height: 550
    anchors.fill: parent
    color: "#ffffff"

    // класс с моделью формы запроса
    RequestFormModel {
        id: requestModel
        identifier: RequestEnums.REQUESTFORM // идентификатор запроса
        url: urlTextInput.textItem.text
        data: requestDataTextInput.textItem.text
    }

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: 10

        Text {
            id: urlLabel
            text: qsTr("Url:")
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            Layout.leftMargin: 10
            Layout.topMargin: 5
        }

        RowLayout {
            id: rowUrlLayout
            width: mainLayout.width
            height: 40
            spacing: 10

            MyLineText {
                id: urlTextInput
                textItem.text: qsTr("...")
                textItem.readOnly: false
                textItem.font.pixelSize: 22
                hoverEnabled: true
                border.width: 1
                radius: 4
                height: rowUrlLayout.height
                Layout.fillWidth: true
                Layout.leftMargin: 10
            }

            // создаем свою модель данных для комбобокс
            EnumListModel {
                id: customTypeModel
            }

            MyComboBox {
                id: requestTypeComboBox
                font.pixelSize: 20
                rectItem.radius: 5
                rectItem.border.width: 1
                model: customTypeModel                
                implicitHeight: rowUrlLayout.height
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.rightMargin: 10
                leftPadding: 7

                Component.onCompleted: {
                    customTypeModel.initializeAsRequestTypes();
                    requestTypeComboBox.currentIndex = 0;
                    requestModel.type = 0;
                    // активировируем/деактивируем связанные элементы
                    Script.controlFormElements(requestTypeComboBox.currentValue,
                                               requestDataTypeComboBox,
                                               requestDataTextInput)
                }
                onActivated: {                    
                    requestModel.type = currentValue;
                    // активировируем/деактивируем связанные элементы
                    Script.controlFormElements(currentValue,
                                               requestDataTypeComboBox,
                                               requestDataTextInput)
                    // ставим заголовок типа контента
                    Script.selectContentType(requestModel,
                                             requestDataTypeComboBox.currentValue);
                }
            }
        }

        RowLayout {
            id: rowRequestLayout
            width: rectangle.width
            height: 40
            spacing: 10

            Text {
                id: requestLabel
                text: qsTr("Request:")
                font.pixelSize: 20
                Layout.fillWidth: true
                Layout.leftMargin: 10
            }

            // создаем свою модель данных для комбобокс
            EnumListModel {
                id: customDataTypeModel
            }

            MyComboBox {
                id: requestDataTypeComboBox
                font.pixelSize: 20
                rectItem.radius: 5                
                rectItem.border.width: 1
                model: customDataTypeModel
                implicitHeight: rowUrlLayout.height
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.rightMargin: 10
                leftPadding: 7

                Component.onCompleted: {
                    customDataTypeModel.initializeAsRequestBodyTypes();
                    requestDataTypeComboBox.currentIndex = 0;
                    requestModel.bodyType = 0;
                }
                onActivated: {
                    requestModel.bodyType = currentValue;
                    // ставим заголовок типа контента
                    Script.selectContentType(requestModel, currentValue);
                }
            }
        }

        MyMultiLineText {
            id: requestDataTextInput
            textItem.text: qsTr("...")
            textItem.readOnly: false
            textItem.font.pixelSize: 22
            textItem.leftPadding: 8
            hoverEnabled: true
            vBarWidth: 10
            isActive: false
            border.width: 1
            radius: 4
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 10
            Layout.rightMargin: 10
        }

        RowLayout {
            id: rowStatusLayout
            width: mainLayout.widths
            height: 40
            Layout.rightMargin: 10
            Layout.leftMargin: 10
            spacing: 10

            Text {
                id: statusLabel
                width: contentWidth
                text: qsTr("Status:")
                font.pixelSize: 20
            }

            Text {
                id: statusText
                width: mainLayout.width - statusLabel.width - 30
                text: qsTr("...")
                font.pixelSize: 20
                clip: true
            }
        }

        MyButton {
            id: sendRequestButton
            text: qsTr("Send request")
            padding: 5
            buttonRect.radius: 5
            font.pixelSize: 20
            colorAnim.duration: 150
            Layout.bottomMargin: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            // в случае удачной проверки посылаемых данных
            // вызывается сигнал RequestIsReady у requestModel
            onClicked: {
                requestModel.send(requestModel);
            }
        }
    }

    Connections {
        target: requestModel
        // связываем сигнал RequestIsReady у requestModel
        // и слот sendRequest у webContext
        function onRequestIsReady(requestModel) {
            webContext.sendRequest(requestModel);
        }
        // связываем сигнал updateInfo у requestModel
        // и слот log у logger
        function onUpdateInfo(message) {
            logger.log(message);
        }
    }
}

