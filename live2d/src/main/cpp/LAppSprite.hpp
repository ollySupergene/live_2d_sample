/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

/**
* @brief 스프라이트를 구현하는 클래스.
*
* 텍스처 ID, Rect 관리.
*/
class LAppSprite
{
public:
    /**
    * @brief Rect 구조체.
    */
    struct Rect
    {
    public:
        float left;     ///< 왼쪽
        float right;    ///< 오른쪽
        float up;       ///< 위
        float down;     ///< 아래
    };

    /**
    * @brief 생성자
    *
    * @param[in]       x            x 좌표
    * @param[in]       y            y 좌표
    * @param[in]       width        가로
    * @param[in]       height       세로
    * @param[in]       textureId    텍스처 ID
    * @param[in]       programId    셰이더 ID
    */
    LAppSprite(float x, float y, float width, float height, GLuint textureId, GLuint programId);

    /**
    * @brief 소멸자
    */
    ~LAppSprite();

    /**
    * @brief 스프라이트 크기 조정
    *
    * @param[in]       x            x 좌표
    * @param[in]       y            y 좌표
    * @param[in]       width        가로
    * @param[in]       height       세로
    */
    void ReSize(float x, float y, float width, float height);

    /**
    * @brief Getter 텍스처 ID
    * @return 텍스처 ID 반환
    */
    GLuint GetTextureId() { return _textureId; }

    /**
    * @brief 그리기
    */
    void Render() const;

    /**
    * @brief 텍스처 ID 지정하여 그리기
    */
    void RenderImmidiate(GLuint textureId, const GLfloat uvVertex[8]) const;

    /**
    * @brief 생성자
    *
    * @param[in]       pointX    x 좌표
    * @param[in]       pointY    y 좌표
    */
    bool IsHit(float pointX, float pointY) const;

    /**
     * @brief 색상 설정
     *
     * @param[in]       r (0.0~1.0)
     * @param[in]       g (0.0~1.0)
     * @param[in]       b (0.0~1.0)
     * @param[in]       a (0.0~1.0)
     */
    void SetColor(float r, float g, float b, float a);

    /**
     * @brief 윈도우 크기 설정
     *
     * @param[in]       width        가로
     * @param[in]       height       세로
     */
    void SetWindowSize(int width, int height);

private:
    GLuint _textureId;   ///< 텍스처 ID
    Rect _rect;          ///< 사각형
    int _positionLocation;  ///< 위치 어트리뷰트
    int _uvLocation;        ///< UV 어트리뷰트
    int _textureLocation;   ///< 텍스처 어트리뷰트
    int _colorLocation;     ///< 컬러 어트리뷰트

    float _spriteColor[4];  ///< 표시 색상
    int _maxWidth;  ///< 윈도우 너비
    int _maxHeight;  ///< 윈도우 높이
};
