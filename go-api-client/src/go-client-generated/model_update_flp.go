/*
 * ALICE Bookkeeping
 *
 * No description provided (generated by Swagger Codegen https://github.com/swagger-api/swagger-codegen)
 *
 * API version: 0.0.0
 * Generated by: Swagger Codegen (https://github.com/swagger-api/swagger-codegen.git)
 */
package swagger

// Describes an update to an flp
type UpdateFlp struct {
	NTimeframes int64 `json:"nTimeframes,omitempty"`
	BytesProcessed int64 `json:"bytesProcessed,omitempty"`
	BytesEquipmentReadOut int64 `json:"bytesEquipmentReadOut,omitempty"`
	BytesRecordingReadOut int64 `json:"bytesRecordingReadOut,omitempty"`
	BytesFairMQReadOut int64 `json:"bytesFairMQReadOut,omitempty"`
}