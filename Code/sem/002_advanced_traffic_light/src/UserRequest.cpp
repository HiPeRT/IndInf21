#include "../inc/UserRequest.hpp"


UserRequest::UserRequest(InImage *inImage)
{
    _inImage = inImage;
    _retainedRequest = false;
}

bool UserRequest::getUserButton()
{
    return _inImage->getUserButton();
}

bool UserRequest::getRetainedRequest()
{
    if(getUserButton()) {
        _retainedRequest = true;
    }
    return _retainedRequest;
}

void UserRequest::setRetainedRequest(bool retainedRequest)
{
    _retainedRequest = retainedRequest;
}
