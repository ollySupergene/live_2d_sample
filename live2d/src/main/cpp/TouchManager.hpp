/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

/**
* @brief 터치 매니저
*/
class TouchManager
{
public:
    /**
    * @brief 생성자
    */
    TouchManager();

    float GetCenterX() const { return _lastX; }
    float GetCenterY() const { return _lastY; }
    float GetDeltaX() const { return _deltaX; }
    float GetDeltaY() const { return _deltaY; }
    float GetStartX() const { return _startX; }
    float GetStartY() const { return _startY; }
    float GetScale() const { return _scale; }
    float GetX() const { return _lastX; }
    float GetY() const { return _lastY; }
    float GetX1() const { return _lastX1; }
    float GetY1() const { return _lastY1; }
    float GetX2() const { return _lastX2; }
    float GetY2() const { return _lastY2; }
    bool IsSingleTouch() const { return _touchSingle; }
    bool IsFlickAvailable() const { return _flipAvailable; }
    void DisableFlick() { _flipAvailable = false; }

    /*
    * @brief 터치 시작 시 이벤트
    *
    * @param[in] deviceX    터치한 화면의 x 좌표
    * @param[in] deviceY    터치한 화면의 y 좌표
    */
    void TouchesBegan(float deviceX, float deviceY);

    /*
    * @brief 드래그 시 이벤트
    *
    * @param[in] deviceX    터치한 화면의 x 좌표
    * @param[in] deviceY    터치한 화면의 y 좌표
    */
    void TouchesMoved(float deviceX, float deviceY);

    /*
    * @brief 드래그 시 이벤트
    *
    * @param[in] deviceX1   첫 번째 터치한 화면의 x 좌표
    * @param[in] deviceY1   첫 번째 터치한 화면의 y 좌표
    * @param[in] deviceX2   두 번째 터치한 화면의 x 좌표
    * @param[in] deviceY2   두 번째 터치한 화면의 y 좌표
    */
    void TouchesMoved(float deviceX1, float deviceY1, float deviceX2, float deviceY2);

    /*
    * @brief 플릭 거리 측정
    *
    * @return 플릭 거리
    */
    float GetFlickDistance() const;

private:
    /*
    * @brief 점1에서 점2까지의 거리를 계산
    *
    * @param[in] x1 첫 번째 터치한 화면의 x 좌표
    * @param[in] y1 첫 번째 터치한 화면의 y 좌표
    * @param[in] x2 두 번째 터치한 화면의 x 좌표
    * @param[in] y2 두 번째 터치한 화면의 y 좌표
    * @return   두 점 사이의 거리
    */
    float CalculateDistance(float x1, float y1, float x2, float y2) const;

    /*
    * 두 값에서 이동량을 계산.
    * 서로 다른 방향인 경우 이동량은 0. 같은 방향인 경우 절대값이 작은 값을 참조
    *
    * @param[in] v1    첫 번째 이동량
    * @param[in] v2    두 번째 이동량
    *
    * @return   작은 이동량
    */
    float CalculateMovingAmount(float v1, float v2);

    float _startY;              // 터치를 시작한 시점의 y 좌표
    float _startX;              // 터치를 시작한 시점의 x 좌표
    float _lastX;               // 싱글 터치 시의 x 좌표
    float _lastY;               // 싱글 터치 시의 y 좌표
    float _lastX1;              // 더블 터치 시 첫 번째 x 좌표
    float _lastY1;              // 더블 터치 시 첫 번째 y 좌표
    float _lastX2;              // 더블 터치 시 두 번째 x 좌표
    float _lastY2;              // 더블 터치 시 두 번째 y 좌표
    float _lastTouchDistance;   // 두 손가락으로 터치했을 때의 거리
    float _deltaX;              // 이전 값에서 현재 값까지의 x 이동 거리.
    float _deltaY;              // 이전 값에서 현재 값까지의 y 이동 거리.
    float _scale;               // 이 프레임에서 곱할 확대율. 확대 중이 아닐 때는 1.
    bool _touchSingle;          // 싱글 터치 시 true
    bool _flipAvailable;        // 플릭이 가능한지 여부

};
