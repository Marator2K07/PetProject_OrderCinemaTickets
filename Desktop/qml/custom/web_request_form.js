.import RequestTypes 1.0 as RequestTypesModul

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
    if (controlValue === RequestTypesModul.RequestTypes.GET) {
        dataTypeCombo.enabled = false;
        multiLineText.enabled = false;
        multiLineText.isActive = false;
    } else if (controlValue === RequestTypesModul.RequestTypes.POST) {
        dataTypeCombo.enabled = true;
        multiLineText.enabled = true;
        multiLineText.isActive = true;
    }
}
