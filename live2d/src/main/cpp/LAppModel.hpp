/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * Use of this source code is governed by the Live2D Open Software license
 * that can be found at https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html.
 */

#pragma once

#include <CubismFramework.hpp>
#include <Model/CubismUserModel.hpp>
#include <ICubismModelSetting.hpp>
#include <Type/csmRectF.hpp>
#include <Rendering/OpenGL/CubismOffscreenSurface_OpenGLES2.hpp>

/**
 * @brief 유저가 실제로 사용하는 모델의 구현 클래스<br>
 *         모델 생성, 기능 컴포넌트 생성, 업데이트 처리 및 렌더링 호출을 수행합니다.
 *
 */
class LAppModel : public Csm::CubismUserModel
{
public:
    /**
     * @brief 생성자
     */
    LAppModel();

    /**
     * @brief 소멸자
     *
     */
    virtual ~LAppModel();

    /**
     * @brief model3.json이 위치한 디렉토리와 파일 경로로부터 모델을 생성합니다.
     *
     */
    void LoadAssets(const Csm::csmChar* dir, const Csm::csmChar* fileName);

    /**
     * @brief 렌더러를 재구축합니다.
     *
     */
    void ReloadRenderer();

    /**
     * @brief 모델의 업데이트 처리. 모델의 파라미터로부터 렌더링 상태를 결정합니다.
     *
     */
    void Update();

    /**
     * @brief 모델을 렌더링하는 처리. 모델을 렌더링하는 공간의 View-Projection 행렬을 전달합니다.
     *
     * @param[in]  matrix  View-Projection 행렬
     */
    void Draw(Csm::CubismMatrix44& matrix);

    /**
     * @brief 지정된 모션의 재생을 시작합니다.
     *
     * @param[in]   group                       모션 그룹 이름
     * @param[in]   no                          그룹 내 번호
     * @param[in]   priority                    우선 순위
     * @param[in]   onFinishedMotionHandler     모션 재생 종료 시 호출되는 콜백 함수. NULL인 경우 호출되지 않습니다.
     * @return                                  시작한 모션의 식별 번호를 반환합니다. 개별 모션이 종료되었는지 여부를 판단하는 IsFinished()의 인수로 사용됩니다. 시작할 수 없는 경우에는 "-1"
     */
    Csm::CubismMotionQueueEntryHandle StartMotion(const Csm::csmChar* group, Csm::csmInt32 no, Csm::csmInt32 priority, Csm::ACubismMotion::FinishedMotionCallback onFinishedMotionHandler = NULL);

    /**
     * @brief 랜덤으로 선택된 모션의 재생을 시작합니다.
     *
     * @param[in]   group                       모션 그룹 이름
     * @param[in]   priority                    우선 순위
     * @param[in]   onFinishedMotionHandler     모션 재생 종료 시 호출되는 콜백 함수. NULL인 경우 호출되지 않습니다.
     * @return                                  시작한 모션의 식별 번호를 반환합니다. 개별 모션이 종료되었는지 여부를 판단하는 IsFinished()의 인수로 사용됩니다. 시작할 수 없는 경우에는 "-1"
     */
    Csm::CubismMotionQueueEntryHandle StartRandomMotion(const Csm::csmChar* group, Csm::csmInt32 priority, Csm::ACubismMotion::FinishedMotionCallback onFinishedMotionHandler = NULL);

    /**
     * @brief 지정된 표정 모션을 설정합니다.
     *
     * @param   expressionID    표정 모션의 ID
     */
    void SetExpression(const Csm::csmChar* expressionID);

    /**
     * @brief 랜덤으로 선택된 표정 모션을 설정합니다.
     *
     */
    void SetRandomExpression();

    /**
    * @brief 이벤트 발생을 수신합니다.
    *
    */
    virtual void MotionEventFired(const Live2D::Cubism::Framework::csmString& eventValue);

    /**
     * @brief    충돌 감지 테스트.<br>
     *            지정된 ID의 정점 리스트로부터 사각형을 계산하여 좌표가 사각형 범위 내에 있는지 판별합니다.
     *
     * @param[in]   hitAreaName     충돌 감지를 테스트할 대상의 ID
     * @param[in]   x               판별할 X 좌표
     * @param[in]   y               판별할 Y 좌표
     */
    virtual Csm::csmBool HitTest(const Csm::csmChar* hitAreaName, Csm::csmFloat32 x, Csm::csmFloat32 y);

    /**
     * @brief   다른 타겟에 렌더링할 때 사용하는 버퍼를 가져옵니다.
     */
    Csm::Rendering::CubismOffscreenSurface_OpenGLES2& GetRenderBuffer();

protected:
    /**
     *  @brief  모델을 렌더링하는 처리. 모델을 렌더링하는 공간의 View-Projection 행렬을 전달합니다.
     *
     */
    void DoDraw();

private:
    /**
     * @brief model3.json으로부터 모델을 생성합니다.<br>
     *         model3.json의 기술에 따라 모델 생성, 모션, 물리 연산 등의 컴포넌트 생성을 수행합니다.
     *
     * @param[in]   setting     ICubismModelSetting의 인스턴스
     *
     */
    void SetupModel(Csm::ICubismModelSetting* setting);

    /**
     * @brief OpenGL의 텍스처 유닛에 텍스처를 로드합니다.
     *
     */
    void SetupTextures();

    /**
     * @brief   모션 데이터를 그룹 이름으로 일괄 로드합니다.<br>
     *           모션 데이터의 이름은 내부에서 ModelSetting으로부터 가져옵니다.
     *
     * @param[in]   group  모션 데이터의 그룹 이름
     */
    void PreloadMotionGroup(const Csm::csmChar* group);

    /**
     * @brief   모션 데이터를 그룹 이름으로 일괄 해제합니다.<br>
     *           모션 데이터의 이름은 내부에서 ModelSetting으로부터 가져옵니다.
     *
     * @param[in]   group  모션 데이터의 그룹 이름
     */
    void ReleaseMotionGroup(const Csm::csmChar* group) const;

    /**
    * @brief 모든 모션 데이터를 해제합니다.
    *
    * 모든 모션 데이터를 해제합니다.
    */
    void ReleaseMotions();

    /**
    * @brief 모든 표정 데이터를 해제합니다.
    *
    * 모든 표정 데이터를 해제합니다.
    */
    void ReleaseExpressions();

    Csm::ICubismModelSetting* _modelSetting; ///< 모델 세팅 정보
    Csm::csmString _modelHomeDir; ///< 모델 세팅이 위치한 디렉토리
    Csm::csmFloat32 _userTimeSeconds; ///< 델타 시간의 합계 값 [초]
    Csm::csmVector<Csm::CubismIdHandle> _eyeBlinkIds; ///< 모델에 설정된 눈 깜박임 기능용 파라미터 ID
    Csm::csmVector<Csm::CubismIdHandle> _lipSyncIds; ///< 모델에 설정된 립 싱크 기능용 파라미터 ID
    Csm::csmMap<Csm::csmString, Csm::ACubismMotion*> _motions; ///< 로드된 모션 리스트
    Csm::csmMap<Csm::csmString, Csm::ACubismMotion*> _expressions; ///< 로드된 표정 리스트
    Csm::csmVector<Csm::csmRectF> _hitArea;
    Csm::csmVector<Csm::csmRectF> _userArea;
    const Csm::CubismId* _idParamAngleX; ///< 파라미터 ID: ParamAngleX
    const Csm::CubismId* _idParamAngleY; ///< 파라미터 ID: ParamAngleX
    const Csm::CubismId* _idParamAngleZ; ///< 파라미터 ID: ParamAngleX
    const Csm::CubismId* _idParamBodyAngleX; ///< 파라미터 ID: ParamBodyAngleX
    const Csm::CubismId* _idParamEyeBallX; ///< 파라미터 ID: ParamEyeBallX
    const Csm::CubismId* _idParamEyeBallY; ///< 파라미터 ID: ParamEyeBallXY

    Csm::Rendering::CubismOffscreenSurface_OpenGLES2 _renderBuffer; ///< 프레임 버퍼 외의 렌더링 대상
};
