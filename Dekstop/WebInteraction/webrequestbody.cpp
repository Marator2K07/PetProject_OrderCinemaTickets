#include "webrequestbody.h"

QJsonObject WebRequestBody::getJsonData() const
{
    return qvariant_cast<QJsonObject>(data);
}

void WebRequestBody::setJsonData(const QJsonObject &newJsonData)
{
    data = QVariant::fromValue(newJsonData);
}

WebRequestBody::WebRequestBody(QObject *parent)
    : QObject{parent}
{
}
