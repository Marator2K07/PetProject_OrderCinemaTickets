import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// своя подключенная модель данных для комбобокс
import EnumItemsModel
// своя модель данных для данного визуального элемента
import RequestFormModel
// подключение перечислений для идентификаторов запроса
import RequestEnums

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
        url: urlTextInput.textData
        data: requestDataTextInput.textData
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
                textData: qsTr("...")
                readOnly: false
                hoverEnabled: true
                textSize: 22
                textColor: "#5e2970"
                textSelectionColor: "#5e2970"
                borderWidth: 1
                borderRadius: 4
                backgroundColor: "#ffffff"
                hoveredBackgroundColor: "#e3c8eb"
                height: rowUrlLayout.height
                Layout.fillWidth: true
                Layout.leftMargin: 10
                Layout.rightMargin: 0
            }

            CustomComboBox {
                id: requestTypeComboBox
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.rightMargin: 10

                // сначала создаем и ицициализируем свою модель данных
                EnumItemsModel {
                    id: customTypeModel
                    Component.onCompleted: {
                        customTypeModel.initializeAsRequestTypes();
                    }
                }
                // и после инициализируем оригинальную модель данными из своей
                model: ListModel {
                    id: originalTypeModel
                    Component.onCompleted: {
                        Script.initComboBoxModel(originalTypeModel,
                                                 customTypeModel);
                        requestTypeComboBox.currentIndex = 0;
                        requestModel.type = 0;
                        // активировируем/деактивируем связанные элементы
                        Script.controlFormElements(requestTypeComboBox.currentValue,
                                                   requestDataTypeComboBox,
                                                   requestDataTextInput)
                    }
                }
                onActivated: {                    
                    requestModel.type = currentValue;
                    // активировируем/деактивируем связанные элементы
                    Script.controlFormElements(currentValue,
                                               requestDataTypeComboBox,
                                               requestDataTextInput)
                    // ставим заголовок типа контента
                    Script.selectContentType(requestModel, requestDataTypeComboBox.currentValue);
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

            CustomComboBox {
                id: requestDataTypeComboBox
                Layout.rightMargin: 10
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

                // сначала создаем и ицициализируем свою модель данных
                EnumItemsModel {
                    id: customDataTypeModel
                    Component.onCompleted: {
                        customDataTypeModel.initializeAsRequestBodyTypes();
                    }
                }
                // и после инициализируем оригинальную модель данными из своей
                model: ListModel {
                    id: originalDataTypeModel
                    Component.onCompleted: {
                        Script.initComboBoxModel(originalDataTypeModel,
                                                 customDataTypeModel);
                        requestDataTypeComboBox.currentIndex = 0;
                        requestModel.bodyType = 0;
                    }
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
            textData: qsTr("...")
            readOnly: false
            hoverEnabled: true
            vBarWidth: 10
            isActive: false
            textSize: 22
            textColor: "#5e2970"
            textSelectionColor: "#5e2970"
            borderWidth: 1
            borderRadius: 4
            backgroundColor: "#ffffff"
            hoveredBackgroundColor: "#e3c8eb"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.topMargin: 40
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
            textItem.font.pixelSize: 20
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

