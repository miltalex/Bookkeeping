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

/*
 * LogTreeResponse.h
 *
 * Response containing a single log tree.
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_LogTreeResponse_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_LogTreeResponse_H_


#include "../ModelBase.h"

#include "LogTree.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {


/// <summary>
/// Response containing a single log tree.
/// </summary>
class  LogTreeResponse
    : public ModelBase
{
public:
    LogTreeResponse();
    virtual ~LogTreeResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// LogTreeResponse members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<LogTree> getData() const;
    bool dataIsSet() const;
    void unsetData();

    void setData(const std::shared_ptr<LogTree>& value);


protected:
    std::shared_ptr<LogTree> m_Data;
    bool m_DataIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_LogTreeResponse_H_ */