#include <SocialInfo.h>

namespace NLogic {

SocialInfo::SocialInfo() {
	_data = new Data;
}

SocialInfo::~SocialInfo() {
	delete _data;
}

void
SocialInfo::Initialize()
{
	_data->Clear();
}

void
SocialInfo::Finalize()
{

}


} /* namespace NLogic */
