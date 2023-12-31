.import RequestTypes 1.0 as RequestTypesModule
.import RequestBodyTypes 1.0 as RequestBodyTypesModule

function initComboBoxModel(originalModel, customModel) {
    for (var i = 0; i < customModel.itemsCount(); i++) {
        var item = customModel.getEnumItem(i);
        originalModel.append({"info": item.text(),
                              "value": item.value()});
    }
}

function controlFormElements(controlValue,
                             dataTypeCombo,
                             multiLineText) {
    if (controlValue === RequestTypesModule.RequestTypes.GET) {
        dataTypeCombo.enabled = false;
        multiLineText.enabled = false;
        multiLineText.isActive = false;
    } else if (controlValue === RequestTypesModule.RequestTypes.POST) {
        dataTypeCombo.enabled = true;
        multiLineText.enabled = true;
        multiLineText.isActive = true;
    }
}

function selectContentType(model, controlValue) {
    if (controlValue === RequestBodyTypesModule.RequestBodyTypes.TEXT) {
        model.contentType = "text/plain";
    } else if (controlValue === RequestBodyTypesModule.RequestBodyTypes.JSON) {
        model.contentType = "application/json";
    }
}
