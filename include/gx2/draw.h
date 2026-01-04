#pragma once
#include <wut.h>
#include "enum.h"

/**
 * \defgroup gx2_draw Draw
 * \ingroup gx2
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GX2DispatchComputeParam GX2DispatchComputeParam;

struct GX2DispatchComputeParam
{
   uint32_t worksizeX;
   uint32_t worksizeY;
   uint32_t worksizeZ;
};
WUT_CHECK_SIZE(GX2DispatchComputeParam, 0x0c);
WUT_CHECK_OFFSET(GX2DispatchComputeParam, 0x00, worksizeX);
WUT_CHECK_OFFSET(GX2DispatchComputeParam, 0x04, worksizeY);
WUT_CHECK_OFFSET(GX2DispatchComputeParam, 0x08, worksizeZ);

void
GX2SetAttribBuffer(uint32_t index,
                   uint32_t size,
                   uint32_t stride,
                   const void *buffer);

void
GX2DrawEx(GX2PrimitiveMode mode,
          uint32_t count,
          uint32_t offset,
          uint32_t numInstances);

void
GX2DrawEx2(GX2PrimitiveMode mode,
           uint32_t count,
           uint32_t offset,
           uint32_t numInstances,
           uint32_t baseInstance);

void
GX2DrawIndexedEx(GX2PrimitiveMode mode,
                 uint32_t count,
                 GX2IndexType indexType,
                 const void *indices,
                 uint32_t offset,
                 uint32_t numInstances);

void
GX2DrawIndexedEx2(GX2PrimitiveMode mode,
                  uint32_t count,
                  GX2IndexType indexType,
                  const void *indices,
                  uint32_t offset,
                  uint32_t numInstances,
                  uint32_t baseInstance);

void
GX2DrawIndexedImmediateEx(GX2PrimitiveMode mode,
                          uint32_t count,
                          GX2IndexType indexType,
                          const void *indices,
                          uint32_t offset,
                          uint32_t numInstances);

void
GX2SetPrimitiveRestartIndex(uint32_t index);

void
GX2DispatchCompute(const GX2DispatchComputeParam *params);

#ifdef __cplusplus
}
#endif

/** @} */
