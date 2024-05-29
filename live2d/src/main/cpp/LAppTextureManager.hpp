/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

#include <string>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <Type/csmVector.hpp>

/**
* @brief 텍스처 관리 클래스
*
* 이미지 로드 및 관리를 수행하는 클래스.
*/
class LAppTextureManager
{
public:

    /**
    * @brief 이미지 정보 구조체
    */
    struct TextureInfo
    {
        GLuint id;              ///< 텍스처 ID
        int width;              ///< 너비
        int height;             ///< 높이
        std::string fileName;   ///< 파일 이름
    };

    /**
    * @brief 생성자
    */
    LAppTextureManager();

    /**
    * @brief 소멸자
    */
    ~LAppTextureManager();


    /**
    * @brief 프리멀티플라이 처리
    *
    * @param[in] red  이미지의 Red 값
    * @param[in] green  이미지의 Green 값
    * @param[in] blue  이미지의 Blue 값
    * @param[in] alpha  이미지의 Alpha 값
    *
    * @return 프리멀티플라이 처리 후의 컬러 값
    */
    inline unsigned int Premultiply(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    {
        return static_cast<unsigned>(\
            (red * (alpha + 1) >> 8) | \
            ((green * (alpha + 1) >> 8) << 8) | \
            ((blue * (alpha + 1) >> 8) << 16) | \
            (((alpha)) << 24)   \
            );
    }

    /**
    * @brief 이미지 로드
    *
    * @param[in] fileName  로드할 이미지 파일 경로명
    * @return 이미지 정보. 로드 실패 시 NULL 반환
    */
    TextureInfo* CreateTextureFromPngFile(std::string fileName);

    /**
    * @brief 이미지 해제
    *
    * 배열에 존재하는 모든 이미지를 해제
    */
    void ReleaseTextures();

    /**
     * @brief 이미지 해제
     *
     * 지정한 텍스처 ID의 이미지를 해제
     * @param[in] textureId  해제할 텍스처 ID
     **/
    void ReleaseTexture(Csm::csmUint32 textureId);

    /**
    * @brief 이미지 해제
    *
    * 지정한 이름의 이미지를 해제
    * @param[in] fileName  해제할 이미지 파일 경로명
    **/
    void ReleaseTexture(std::string fileName);

private:
    Csm::csmVector<TextureInfo*> _textures;
};
