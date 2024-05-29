/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * Use of this source code is governed by the Live2D Open Software license
 * that can be found at https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html.
 */

#pragma once

#include <CubismFramework.hpp>
#include <Math/CubismMatrix44.hpp>
#include <Type/csmVector.hpp>
#include <Type/csmString.hpp>

class LAppModel;

/**
* @brief 샘플 애플리케이션에서 CubismModel을 관리하는 클래스<br>
*         모델 생성 및 폐기, 탭 이벤트 처리, 모델 교체를 수행합니다.
*
*/
class LAppLive2DManager
{

public:
    /**
    * @brief   클래스의 인스턴스(싱글톤)를 반환합니다.<br>
    *           인스턴스가 생성되지 않은 경우 내부에서 인스턴스를 생성합니다.
    *
    * @return  클래스의 인스턴스
    */
    static LAppLive2DManager* GetInstance();

    /**
    * @brief   클래스의 인스턴스(싱글톤)를 해제합니다.
    *
    */
    static void ReleaseInstance();

    /**
    * @brief   Resources 폴더에 있는 모델 폴더 이름을 설정합니다.
    *
    */
    void SetUpModel();

    /**
    * @brief   현재 씬에서 유지하고 있는 모델을 반환합니다.
    *
    * @param[in]   no  모델 리스트의 인덱스 값
    * @return      모델의 인스턴스를 반환합니다. 인덱스 값이 범위를 벗어난 경우 NULL을 반환합니다.
    */
    LAppModel* GetModel(Csm::csmUint32 no) const;

    /**
    * @brief   현재 씬에서 유지하고 있는 모든 모델을 해제합니다.
    *
    */
    void ReleaseAllModel();

    /**
    * @brief   화면을 드래그할 때의 처리
    *
    * @param[in]   x   화면의 X 좌표
    * @param[in]   y   화면의 Y 좌표
    */
    void OnDrag(Csm::csmFloat32 x, Csm::csmFloat32 y) const;

    /**
    * @brief   화면을 탭할 때의 처리
    *
    * @param[in]   x   화면의 X 좌표
    * @param[in]   y   화면의 Y 좌표
    */
    void OnTap(Csm::csmFloat32 x, Csm::csmFloat32 y);

    /**
    * @brief   화면을 업데이트할 때의 처리
    *          모델의 업데이트 처리 및 렌더링 처리를 수행합니다.
    */
    void OnUpdate() const;

    /**
    * @brief   다음 씬으로 전환합니다.<br>
    *           샘플 애플리케이션에서는 모델 세트를 전환합니다.
    */
    void NextScene();

    /**
    * @brief   씬을 전환합니다.<br>
    *           샘플 애플리케이션에서는 모델 세트를 전환합니다.
    */
    void ChangeScene(Csm::csmInt32 index);

    /**
    * @brief   씬 인덱스를 가져옵니다.
    * @return  씬 인덱스를 반환합니다.
    */
    Csm::csmInt32 GetSceneIndex() { return _sceneIndex; }

    /**
     * @brief   모델 개수를 얻습니다.
     * @return  소유 모델 개수
     */
    Csm::csmUint32 GetModelNum() const;

    /**
     * @brief   viewMatrix를 설정합니다.
     */
    void SetViewMatrix(Live2D::Cubism::Framework::CubismMatrix44* m);

private:
    /**
    * @brief  생성자
    */
    LAppLive2DManager();

    /**
    * @brief  소멸자
    */
    virtual ~LAppLive2DManager();

    Csm::CubismMatrix44*        _viewMatrix; ///< 모델 렌더링에 사용하는 View 행렬
    Csm::csmVector<LAppModel*>  _models; ///< 모델 인스턴스의 컨테이너
    Csm::csmInt32               _sceneIndex; ///< 표시할 씬의 인덱스 값

    Csm::csmVector<Csm::csmString> _modelDir; ///< 모델 디렉토리 이름의 컨테이너
};
