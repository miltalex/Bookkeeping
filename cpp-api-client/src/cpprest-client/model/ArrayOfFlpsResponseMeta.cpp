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



#include "ArrayOfFlpsResponseMeta.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {




ArrayOfFlpsResponseMeta::ArrayOfFlpsResponseMeta()
{
    m_PageIsSet = false;
}

ArrayOfFlpsResponseMeta::~ArrayOfFlpsResponseMeta()
{
}

void ArrayOfFlpsResponseMeta::validate()
{
    // TODO: implement validation
}

web::json::value ArrayOfFlpsResponseMeta::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_PageIsSet)
    {
        val[utility::conversions::to_string_t("page")] = ModelBase::toJson(m_Page);
    }

    return val;
}

bool ArrayOfFlpsResponseMeta::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t("page")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("page"));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<PaginationMeta> refVal_page;
            ok &= ModelBase::fromJson(fieldValue, refVal_page);
            setPage(refVal_page);
        }
    }
    return ok;
}

void ArrayOfFlpsResponseMeta::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }
    if(m_PageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("page"), m_Page));
    }
}

bool ArrayOfFlpsResponseMeta::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("page")))
    {
        std::shared_ptr<PaginationMeta> refVal_page;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t("page")), refVal_page );
        setPage(refVal_page);
    }
    return ok;
}

std::shared_ptr<PaginationMeta> ArrayOfFlpsResponseMeta::getPage() const
{
    return m_Page;
}

void ArrayOfFlpsResponseMeta::setPage(const std::shared_ptr<PaginationMeta>& value)
{
    m_Page = value;
    m_PageIsSet = true;
}

bool ArrayOfFlpsResponseMeta::pageIsSet() const
{
    return m_PageIsSet;
}

void ArrayOfFlpsResponseMeta::unsetPage()
{
    m_PageIsSet = false;
}
}
}
}
}

