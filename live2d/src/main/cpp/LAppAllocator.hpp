/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

#include <CubismFramework.hpp>
#include <ICubismAllocator.hpp>

/**
* @brief 메모리 할당을 구현하는 클래스.
*
* 메모리 할당 및 해제 처리의 인터페이스 구현.
* 프레임워크에서 호출됩니다.
*
*/
class LAppAllocator : public Csm::ICubismAllocator
{
    /**
    * @brief 메모리 영역을 할당합니다.
    *
    * @param[in]   size    할당하려는 크기.
    * @return  지정된 메모리 영역
    */
    void* Allocate(const Csm::csmSizeType size);

    /**
    * @brief 메모리 영역을 해제합니다.
    *
    * @param[in]   memory    해제할 메모리.
    */
    void Deallocate(void* memory);

    /**
    * @brief
    *
    * @param[in]   size         할당하려는 크기.
    * @param[in]   alignment    할당하려는 크기.
    * @return  alignedAddress
    */
    void* AllocateAligned(const Csm::csmSizeType size, const Csm::csmUint32 alignment);

    /**
    * @brief
    *
    * @param[in]   alignedMemory    해제할 메모리.
    */
    void DeallocateAligned(void* alignedMemory);
};

