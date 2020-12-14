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



#include "PaginationMeta.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {




PaginationMeta::PaginationMeta()
{
    m_PageCount = 0;
    m_PageCountIsSet = false;
    m_TotalCount = 0;
    m_TotalCountIsSet = false;
}

PaginationMeta::~PaginationMeta()
{
}

void PaginationMeta::validate()
{
    // TODO: implement validation
}

web::json::value PaginationMeta::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_PageCountIsSet)
    {
        val[utility::conversions::to_string_t("pageCount")] = ModelBase::toJson(m_PageCount);
    }
    if(m_TotalCountIsSet)
    {
        val[utility::conversions::to_string_t("totalCount")] = ModelBase::toJson(m_TotalCount);
    }

    return val;
}

bool PaginationMeta::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t("pageCount")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("pageCount"));
        if(!fieldValue.is_null())
        {
            int32_t refVal_pageCount;
            ok &= ModelBase::fromJson(fieldValue, refVal_pageCount);
            setPageCount(refVal_pageCount);
        }
    }
    if(val.has_field(utility::conversions::to_string_t("totalCount")))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("totalCount"));
        if(!fieldValue.is_null())
        {
            int32_t refVal_totalCount;
            ok &= ModelBase::fromJson(fieldValue, refVal_totalCount);
            setTotalCount(refVal_totalCount);
        }
    }
    return ok;
}

void PaginationMeta::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }
    if(m_PageCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("pageCount"), m_PageCount));
    }
    if(m_TotalCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("totalCount"), m_TotalCount));
    }
}

bool PaginationMeta::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("pageCount")))
    {
        int32_t refVal_pageCount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t("pageCount")), refVal_pageCount );
        setPageCount(refVal_pageCount);
    }
    if(multipart->hasContent(utility::conversions::to_string_t("totalCount")))
    {
        int32_t refVal_totalCount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t("totalCount")), refVal_totalCount );
        setTotalCount(refVal_totalCount);
    }
    return ok;
}

int32_t PaginationMeta::getPageCount() const
{
    return m_PageCount;
}

void PaginationMeta::setPageCount(int32_t value)
{
    m_PageCount = value;
    m_PageCountIsSet = true;
}

bool PaginationMeta::pageCountIsSet() const
{
    return m_PageCountIsSet;
}

void PaginationMeta::unsetPageCount()
{
    m_PageCountIsSet = false;
}
int32_t PaginationMeta::getTotalCount() const
{
    return m_TotalCount;
}

void PaginationMeta::setTotalCount(int32_t value)
{
    m_TotalCount = value;
    m_TotalCountIsSet = true;
}

bool PaginationMeta::totalCountIsSet() const
{
    return m_TotalCountIsSet;
}

void PaginationMeta::unsetTotalCount()
{
    m_TotalCountIsSet = false;
}
}
}
}
}


