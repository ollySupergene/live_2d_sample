/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once
#include <Type/csmVector.hpp>
#include <Type/csmString.hpp>

/**
* @brief Jni Bridge Class
*/
class JniBridgeC
{
public:
    /**
    * @brief Assets 가져오기
    */
    static Csm::csmVector<Csm::csmString> GetAssetList(const Csm::csmString& path);

    /**
    * @brief Java에서 파일 읽기
    */
    static char* LoadFileAsBytesFromJava(const char* filePath, unsigned int* outSize);

    /**
    * @brief 앱을 백그라운드로 이동
    */
    static void MoveTaskToBack();

};
