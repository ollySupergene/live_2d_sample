/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <Math/CubismMatrix44.hpp>
#include <Math/CubismViewMatrix.hpp>
#include "CubismFramework.hpp"
#include <Rendering/OpenGL/CubismOffscreenSurface_OpenGLES2.hpp>

class TouchManager;
class LAppSprite;
class LAppModel;

/**
* @brief 렌더링 클래스
*/
class LAppView
{
public:

    /**
     * @brief LAppModel의 렌더링 대상
     */
    enum SelectTarget
    {
        SelectTarget_None,                ///< 기본 프레임 버퍼에 렌더링
        SelectTarget_ModelFrameBuffer,    ///< LAppModel이 각자 가진 프레임 버퍼에 렌더링
        SelectTarget_ViewFrameBuffer,     ///< LAppView가 가진 프레임 버퍼에 렌더링
    };

    /**
    * @brief 생성자
    */
    LAppView();

    /**
    * @brief 소멸자
    */
    ~LAppView();

    /**
    * @brief 초기화합니다.
    */
    void Initialize();

    /**
    * @brief 렌더링합니다.
    */
    void Render();

    /**
    * @brief 셰이더를 초기화합니다.
    */
    void InitializeShader();

    /**
    * @brief 이미지를 초기화합니다.
    */
    void InitializeSprite();

    /**
    * @brief 터치가 시작될 때 호출됩니다.
    *
    * @param[in]       pointX            스크린 X 좌표
    * @param[in]       pointY            스크린 Y 좌표
    */
    void OnTouchesBegan(float pointX, float pointY) const;

    /**
    * @brief 터치 중에 포인터가 이동하면 호출됩니다.
    *
    * @param[in]       pointX            스크린 X 좌표
    * @param[in]       pointY            스크린 Y 좌표
    */
    void OnTouchesMoved(float pointX, float pointY) const;

    /**
    * @brief 터치가 종료되면 호출됩니다.
    *
    * @param[in]       pointX            스크린 X 좌표
    * @param[in]       pointY            스크린 Y 좌표
    */
    void OnTouchesEnded(float pointX, float pointY);

    /**
    * @brief X 좌표를 View 좌표로 변환합니다.
    *
    * @param[in]       deviceX            디바이스 X 좌표
    */
    float TransformViewX(float deviceX) const;

    /**
    * @brief Y 좌표를 View 좌표로 변환합니다.
    *
    * @param[in]       deviceY            디바이스 Y 좌표
    */
    float TransformViewY(float deviceY) const;

    /**
    * @brief X 좌표를 Screen 좌표로 변환합니다.
    *
    * @param[in]       deviceX            디바이스 X 좌표
    */
    float TransformScreenX(float deviceX) const;

    /**
    * @brief Y 좌표를 Screen 좌표로 변환합니다.
    *
    * @param[in]       deviceY            디바이스 Y 좌표
    */
    float TransformScreenY(float deviceY) const;

    /**
     * @brief   모델 하나를 렌더링하기 직전에 호출됩니다.
     */
    void PreModelDraw(LAppModel &refModel);

    /**
     * @brief   모델 하나를 렌더링한 직후에 호출됩니다.
     */
    void PostModelDraw(LAppModel &refModel);

    /**
     * @brief   다른 렌더링 타겟에 모델을 렌더링할 때 샘플로
     *           렌더링 시의 알파 값을 결정합니다.
     */
    float GetSpriteAlpha(int assign) const;

    /**
     * @brief 렌더링 대상을 전환합니다.
     */
    void SwitchRenderingTarget(SelectTarget targetType);

    /**
     * @brief 기본 외의 렌더링 대상으로 전환할 때의 배경 클리어 색상 설정
     * @param[in]   r   빨강(0.0~1.0)
     * @param[in]   g   초록(0.0~1.0)
     * @param[in]   b   파랑(0.0~1.0)
     */
    void SetRenderTargetClearColor(float r, float g, float b);

private:
    TouchManager* _touchManager;                 ///< 터치 매니저
    Csm::CubismMatrix44* _deviceToScreen;    ///< 디바이스에서 스크린으로의 행렬
    Csm::CubismViewMatrix* _viewMatrix;      ///< viewMatrix
    GLuint _programId;                       ///< 셰이더 ID
    LAppSprite* _back;                       ///< 배경 이미지
    LAppSprite* _gear;                       ///< 기어 이미지
    LAppSprite* _power;                      ///< 전원 이미지
    bool _changeModel;                       ///< 모델 전환 플래그

    // 렌더링 대상을 별도로 하는 방식에 사용
    LAppSprite* _renderSprite;                                      ///< 모드에 따라 _renderBuffer의 텍스처를 렌더링
    Csm::Rendering::CubismOffscreenSurface_OpenGLES2 _renderBuffer;   ///< 모드에 따라 Cubism 모델 결과를 여기로 렌더링
    SelectTarget _renderTarget;     ///< 렌더링 대상 선택지
    float _clearColor[4];           ///< 렌더링 대상의 클리어 컬러
};
