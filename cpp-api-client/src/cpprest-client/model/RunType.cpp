/**
 * ALICE Bookkeeping
 * No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
 *
 * The version of the OpenAPI document: 0.0.0
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 5.0.0-beta2.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "RunType.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



RunType::RunType()
{
}

RunType::~RunType()
{
}

void RunType::validate()
{
    // TODO: implement validation
}

web::json::value RunType::toJson() const
{
    web::json::value val = web::json::value::object();

    
    if (m_value == eRunType::RunType_PHYSICS) val = web::json::value::string(U("physics"));
    if (m_value == eRunType::RunType_COSMICS) val = web::json::value::string(U("cosmics"));
    if (m_value == eRunType::RunType_TECHNICAL) val = web::json::value::string(U("technical"));

    return val;
}

bool RunType::fromJson(const web::json::value& val)
{
    auto s = val.as_string();

    
    if (s == utility::conversions::to_string_t("physics")) m_value = eRunType::RunType_PHYSICS;
    if (s == utility::conversions::to_string_t("cosmics")) m_value = eRunType::RunType_COSMICS;
    if (s == utility::conversions::to_string_t("technical")) m_value = eRunType::RunType_TECHNICAL;
    return true;
}

void RunType::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    utility::string_t s;

    
    if (m_value == eRunType::RunType_PHYSICS) s = utility::conversions::to_string_t("physics");
    if (m_value == eRunType::RunType_COSMICS) s = utility::conversions::to_string_t("cosmics");
    if (m_value == eRunType::RunType_TECHNICAL) s = utility::conversions::to_string_t("technical");

    multipart->add(ModelBase::toHttpContent(namePrefix, s));
}

bool RunType::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }
    {
        utility::string_t s;
        ok = ModelBase::fromHttpContent(multipart->getContent(namePrefix), s);
        eRunType v;

        
        if (s == utility::conversions::to_string_t("physics")) v = eRunType::RunType_PHYSICS;
        if (s == utility::conversions::to_string_t("cosmics")) v = eRunType::RunType_COSMICS;
        if (s == utility::conversions::to_string_t("technical")) v = eRunType::RunType_TECHNICAL;

        setValue(v);
    }
    return ok;
}

RunType::eRunType RunType::getValue() const
{
   return m_value;
}

void RunType::setValue(RunType::eRunType const value)
{
   m_value = value;
}


}
}
}
}


