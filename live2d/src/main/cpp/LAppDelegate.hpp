/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * Use of this source code is governed by the Live2D Open Software license
 * that can be found at https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html.
 */

#pragma once

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "LAppAllocator.hpp"

class LAppView;
class LAppTextureManager;

/**
* @brief   애플리케이션 클래스.
*   Cubism SDK의 관리를 담당합니다.
*/
class LAppDelegate
{
public:
    /**
    * @brief   클래스의 인스턴스(싱글톤)를 반환합니다.<br>
    *           인스턴스가 생성되지 않은 경우 내부에서 인스턴스를 생성합니다.
    *
    * @return  클래스의 인스턴스
    */
    static LAppDelegate* GetInstance();

    /**
    * @brief   클래스의 인스턴스(싱글톤)를 해제합니다.
    *
    */
    static void ReleaseInstance();

    /**
    * @brief Java의 Activity의 OnStart() 콜백 함수.
    */
    void OnStart();

    /**
    * @brief Java의 Activity의 OnPause() 콜백 함수.
    */
    void OnPause();

    /**
    * @brief Java의 Activity의 OnStop() 콜백 함수.
    */
    void OnStop();

    /**
    * @brief Java의 Activity의 OnDestroy() 콜백 함수.
    */
    void OnDestroy();

    /**
    * @brief   Java의 GLSurfaceview의 OnSurfaceCreate() 콜백 함수.
    */
    void OnSurfaceCreate();

    /**
     * @brief Java의 GLSurfaceview의 OnSurfaceChanged() 콜백 함수.
     * @param width
     * @param height
     */
    void OnSurfaceChanged(float width, float height);

    /**
    * @brief   실행 처리.
    */
    void Run();

    /**
    * @brief 터치 시작.
    *
    * @param[in] x x 좌표
    * @param[in] y y 좌표
    */
    void OnTouchBegan(double x, double y);

    /**
    * @brief 터치 종료.
    *
    * @param[in] x x 좌표
    * @param[in] y y 좌표
    */
    void OnTouchEnded(double x, double y);

    /**
    * @brief 터치 이동.
    *
    * @param[in] x x 좌표
    * @param[in] y y 좌표
    */
    void OnTouchMoved(double x, double y);

    /**
    * @brief 셰이더를 등록합니다.
    */
    GLuint CreateShader();

    /**
    * @brief 텍스처 매니저를 가져옵니다.
    */
    LAppTextureManager* GetTextureManager() { return _textureManager; }

    /**
    * @brief 창의 너비를 설정합니다.
    */
    int GetWindowWidth() { return _width; }

    /**
    * @brief 창의 높이를 가져옵니다.
    */
    int GetWindowHeight() { return _height; }

    /**
    * @brief   애플리케이션을 비활성화합니다.
    */
    void DeActivateApp() { _isActive = false; }

    /**
    * @brief   View 정보를 가져옵니다.
    */
    LAppView* GetView() { return _view; }

private:
    /**
    * @brief   생성자
    */
    LAppDelegate();

    /**
    * @brief   소멸자
    */
    ~LAppDelegate();

    /**
    * @brief   Cubism SDK 초기화
    */
    void InitializeCubism();

    LAppAllocator _cubismAllocator;              ///< Cubism SDK Allocator
    Csm::CubismFramework::Option _cubismOption;  ///< Cubism SDK Option
    LAppTextureManager* _textureManager;         ///< 텍스처 매니저
    LAppView* _view;                             ///< View 정보
    int _width;                                  ///< 창의 너비
    int _height;                                 ///< 창의 높이
    int _SceneIndex;                             ///< 모델 씬 인덱스
    bool _captured;                              ///< 클릭 중인지 여부
    bool _isActive;                              ///< 애플리케이션이 활성 상태인지 여부
    float _mouseY;                               ///< 마우스 Y 좌표
    float _mouseX;                               ///< 마우스 X 좌표
};
