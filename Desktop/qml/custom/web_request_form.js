.import RequestEnums 1.0 as RequestEnumsModule

function controlFormElements(controlValue,
                             dataTypeCombo,
                             multiLineText) {
    if (controlValue === RequestEnumsModule.RequestEnums.GET) {
        dataTypeCombo.enabled = false;
        dataTypeCombo.isActive = false;
        multiLineText.enabled = false;
        multiLineText.isActive = false;
    } else if (controlValue === RequestEnumsModule.RequestEnums.POST) {
        dataTypeCombo.enabled = true;
        dataTypeCombo.isActive = true;
        multiLineText.enabled = true;
        multiLineText.isActive = true;
    }
}

function selectContentType(model, controlValue) {
    if (controlValue === RequestEnumsModule.RequestEnums.TEXT) {
        model.contentType = "text/plain";
    } else if (controlValue === RequestEnumsModule.RequestEnums.JSON) {
        model.contentType = "application/json";
    }
}
