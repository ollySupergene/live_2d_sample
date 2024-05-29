/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

#include <CubismFramework.hpp>
#include <string>

/**
* @brief Cubism Platform Abstraction Layer로 플랫폼 종속 기능을 추상화하는 클래스.
*
* 파일 로딩 및 시간 획득과 같은 플랫폼 종속 기능을 포함합니다.
*
*/
class LAppPal
{
public:
    /**
    * @brief 파일을 바이트 데이터로 로드합니다.
    *
    * @param[in]   filePath    로드할 파일 경로
    * @param[out]  outSize     파일 크기
    * @return                  바이트 데이터
    */
    static Csm::csmByte* LoadFileAsBytes(const std::string filePath, Csm::csmSizeInt* outSize);


    /**
    * @brief 바이트 데이터를 해제합니다.
    *
    * @param[in]   byteData    해제할 바이트 데이터
    */
    static void ReleaseBytes(Csm::csmByte* byteData);

    /**
    * @brief 델타 시간(이전 프레임과의 차이)을 가져옵니다.
    *
    * @return  델타 시간[ms]
    *
    */
    static Csm::csmFloat32 GetDeltaTime();

    /**
    * @brief 델타 시간을 업데이트합니다.
    *
    */
    static void UpdateTime();

    /**
    * @brief 로그를 출력하고 마지막에 줄 바꿈합니다.
    *
    * @param[in]   format  형식 지정된 문자열
    * @param[in]   ...     가변 인수 문자열
    *
    */
    static void PrintLogLn(const Csm::csmChar* format, ...);

    /**
    * @brief 메시지를 출력하고 마지막에 줄 바꿈합니다.
    *
    * @param[in]   message  문자열
    *
    */
    static void PrintMessageLn(const Csm::csmChar* message);

private:
    /**
    * @brief 시스템 시간을 가져옵니다.
    */
    static double GetSystemTime();

    static double s_currentFrame;
    static double s_lastFrame;
    static double s_deltaTime;
};
