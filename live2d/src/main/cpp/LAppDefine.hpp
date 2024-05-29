/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

#include <CubismFramework.hpp>

/**
* @brief Sample App에서 사용하는 상수
*
*/
namespace LAppDefine {

    using namespace Csm;

    extern const csmFloat32 ViewScale;              ///< 확대 축소 비율
    extern const csmFloat32 ViewMaxScale;           ///< 확대 축소 비율 최대 값
    extern const csmFloat32 ViewMinScale;           ///< 확대 축소 비율 최소 값

    extern const csmFloat32 ViewLogicalLeft;        ///< 논리적 뷰 좌표 체계의 왼쪽 끝 값
    extern const csmFloat32 ViewLogicalRight;       ///< 논리적 뷰 좌표 체계의 오른쪽 끝 값
    extern const csmFloat32 ViewLogicalBottom;      ///< 논리적 뷰 좌표 체계의 아래쪽 끝 값
    extern const csmFloat32 ViewLogicalTop;         ///< 논리적 뷰 좌표 체계의 위쪽 끝 값

    extern const csmFloat32 ViewLogicalMaxLeft;     ///< 논리적 뷰 좌표 체계의 최대 왼쪽 끝 값
    extern const csmFloat32 ViewLogicalMaxRight;    ///< 논리적 뷰 좌표 체계의 최대 오른쪽 끝 값
    extern const csmFloat32 ViewLogicalMaxBottom;   ///< 논리적 뷰 좌표 체계의 최대 아래쪽 끝 값
    extern const csmFloat32 ViewLogicalMaxTop;      ///< 논리적 뷰 좌표 체계의 최대 위쪽 끝 값

    extern const csmChar* ResourcesPath;            ///< 자원 경로
    extern const csmChar* BackImageName;         ///< 배경 이미지 파일
    extern const csmChar* GearImageName;         ///< 톱니바퀴 이미지 파일
    extern const csmChar* PowerImageName;        ///< 종료 버튼 이미지 파일

    // 모델 정의--------------------------------------------
    // 외부 정의 파일(json)과 일치
    extern const csmChar* MotionGroupIdle;          ///< 아이들링 중에 재생되는 모션 목록
    extern const csmChar* MotionGroupTapBody;       ///< 몸을 탭했을 때 재생되는 모션 목록

    // 외부 정의 파일(json)과 일치
    extern const csmChar* HitAreaNameHead;          ///< 충돌 판정의 [Head] 태그
    extern const csmChar* HitAreaNameBody;          ///< 충돌 판정의 [Body] 태그

    // 모션 우선 순위 상수
    extern const csmInt32 PriorityNone;             ///< 모션 우선 순위 상수: 0
    extern const csmInt32 PriorityIdle;             ///< 모션 우선 순위 상수: 1
    extern const csmInt32 PriorityNormal;           ///< 모션 우선 순위 상수: 2
    extern const csmInt32 PriorityForce;            ///< 모션 우선 순위 상수: 3

    // 디버그용 로그 표시
    extern const csmBool DebugLogEnable;            ///< 디버그용 로그 표시 활성화 여부
    extern const csmBool DebugTouchLogEnable;       ///< 터치 처리의 디버그용 로그 표시 활성화 여부

    // Framework에서 출력하는 로그의 레벨 설정
    extern const CubismFramework::Option::LogLevel CubismLoggingLevel;
}

