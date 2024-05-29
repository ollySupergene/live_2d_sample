/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * 이 소스 코드의 사용은 Live2D 오픈 소프트웨어 라이선스에 의해 관리됩니다.
 * 라이선스는 https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html 에서 확인할 수 있습니다.
 */

#pragma once

#include <CubismFramework.hpp>
#include <Type/csmVector.hpp>

/**
 * @brief wav 파일 핸들러
 * @attention 16bit wav 파일 읽기만 구현됨
 */
class LAppWavFileHandler
{
public:
    /**
     * @brief 읽어들인 wav 파일의 정보
     */
    struct WavFileInfo
    {
        /**
         * @brief 생성자
         */
        WavFileInfo() : _fileName(""), _numberOfChannels(0),
                        _bitsPerSample(0), _samplingRate(0), _samplesPerChannel(0),
                        _avgBytesPerSec(0), _blockAlign(0)
        { }

        Csm::csmString _fileName; ///< 파일 이름
        Csm::csmUint32 _numberOfChannels; ///< 채널 수
        Csm::csmUint32 _bitsPerSample; ///< 샘플당 비트 수
        Csm::csmUint32 _samplingRate; ///< 샘플링 레이트
        Csm::csmUint32 _samplesPerChannel; ///< 1 채널당 총 샘플 수
        Csm::csmUint32 _avgBytesPerSec; ///< 평균 데이터 속도
        Csm::csmUint32 _blockAlign; ///< 블록 크기
    } _wavFileInfo;

    /**
     * @brief 생성자
     */
    LAppWavFileHandler();

    /**
     * @brief 소멸자
     */
    ~LAppWavFileHandler();

    /**
     * @brief wav 파일 핸들러의 내부 상태를 갱신
     *
     * @param[in]   deltaTimeSeconds    델타 시간[초]
     * @retval  true    갱신됨
     * @retval  false   갱신되지 않음
     */
    Csm::csmBool Update(Csm::csmFloat32 deltaTimeSeconds);

    /**
     * @brief 인수로 지정한 wav 파일의 읽기를 시작
     *
     * @param[in] filePath wav 파일의 경로
     */
    void Start(const Csm::csmString& filePath);

    /**
     * @brief 현재 RMS 값 가져오기
     *
     * @retval  csmFloat32 RMS 값
     */
    Csm::csmFloat32 GetRms() const;

    /**
     * @brief 파일 정보를 가져오기
     *
     * @retval  파일 정보
     */
    const WavFileInfo& GetWavFileInfo() const;

    /**
     * @brief 정규화 전의 데이터를 가져오기
     *
     * @retval  정규화 전의 데이터
     */
    const Csm::csmByte* GetRawData() const;

    /**
     * @brief 정규화 전의 데이터 크기를 가져오기
     *
     * @retval  정규화 전의 데이터 크기
     */
    Csm::csmUint64 GetRawDataSize() const;

    /**
     * @brief 정규화 데이터를 가져오기
     *
     * @retval 정규화 데이터
     */
    Csm::csmVector<Csm::csmFloat32> GetPcmData() const;

    /**
     * @brief 인수로 지정한 채널의 정규화 데이터를 가져오기
     *
     * @param[in] dst 저장소
     * @param[in] useChannel 사용할 채널
     */
    void GetPcmDataChannel(Csm::csmFloat32* dst, Csm::csmUint32 useChannel) const;

    /**
     * @brief -1 ~ 1 범위의 1 샘플 가져오기
     *
     * @param[in] bitsPerSample 비트 깊이
     * @param[in] data 정규화할 데이터
     * @param[in] dataSize 정규화할 데이터 크기
     *
     * @retval    csmFloat32    정규화된 샘플
     */
    static Csm::csmFloat32 NormalizePcmSample(Csm::csmUint32 bitsPerSample, Csm::csmByte* data, Csm::csmUint32 dataSize);

private:
    /**
     * @brief wav 파일 로드
     *
     * @param[in] filePath wav 파일의 경로
     * @retval  true    읽기 성공
     * @retval  false   읽기 실패
     */
    Csm::csmBool LoadWavFile(const Csm::csmString& filePath);

    /**
     * @brief PCM 데이터 해제
     */
    void ReleasePcmData();

    /**
     * @brief -1 ~ 1 범위의 1 샘플 가져오기
     * @retval    csmFloat32    정규화된 샘플
     */
    Csm::csmFloat32 GetPcmSample();

    /**
     * @brief 바이트 리더
     */
    struct ByteReader {
        /**
         * @brief 생성자
         */
        ByteReader() : _fileByte(NULL), _fileSize(0), _readOffset(0)
        { }

        /**
         * @brief 8비트 읽기
         * @return Csm::csmUint8 읽은 8비트 값
         */
        Csm::csmUint8 Get8()
        {
            const Csm::csmUint8 ret = _fileByte[_readOffset];
            _readOffset++;
            return ret;
        }

        /**
         * @brief 16비트 읽기 (리틀 엔디안)
         * @return Csm::csmUint16 읽은 16비트 값
         */
        Csm::csmUint16 Get16LittleEndian()
        {
            const Csm::csmUint16 ret = (_fileByte[_readOffset + 1] << 8) | _fileByte[_readOffset];
            _readOffset += 2;
            return ret;
        }

        /**
         * @brief 24비트 읽기 (리틀 엔디안)
         * @return Csm::csmUint32 읽은 24비트 값 (하위 24비트에 설정)
         */
        Csm::csmUint32 Get24LittleEndian()
        {
            const Csm::csmUint32 ret =
                    (_fileByte[_readOffset + 2] << 16) | (_fileByte[_readOffset + 1] << 8)
                    | _fileByte[_readOffset];
            _readOffset += 3;
            return ret;
        }

        /**
         * @brief 32비트 읽기 (리틀 엔디안)
         * @return Csm::csmUint32 읽은 32비트 값
         */
        Csm::csmUint32 Get32LittleEndian()
        {
            const Csm::csmUint32 ret =
                    (_fileByte[_readOffset + 3] << 24) | (_fileByte[_readOffset + 2] << 16)
                    | (_fileByte[_readOffset + 1] << 8) | _fileByte[_readOffset];
            _readOffset += 4;
            return ret;
        }

        /**
         * @brief 시그니처를 가져와 참조 문자열과 일치하는지 확인
         * @param[in] reference 검사 대상 시그니처 문자열
         * @retval  true    일치함
         * @retval  false   일치하지 않음
         */
        Csm::csmBool GetCheckSignature(const Csm::csmString& reference)
        {
            Csm::csmChar getSignature[4] = { 0, 0, 0, 0 };
            const Csm::csmChar* referenceString = reference.GetRawString();
            if (reference.GetLength() != 4)
            {
                return false;
            }
            for (Csm::csmUint32 signatureOffset = 0; signatureOffset < 4; signatureOffset++)
            {
                getSignature[signatureOffset] = static_cast<Csm::csmChar>(Get8());
            }
            return (getSignature[0] == referenceString[0]) && (getSignature[1] == referenceString[1])
                   && (getSignature[2] == referenceString[2]) && (getSignature[3] == referenceString[3]);
        }

        Csm::csmByte* _fileByte; ///< 로드된 파일의 바이트 열
        Csm::csmSizeInt _fileSize; ///< 파일 크기
        Csm::csmUint32 _readOffset; ///< 파일 참조 위치
    } _byteReader;

    Csm::csmByte* _rawData; ///< 정규화되기 전의 바이트 열
    Csm::csmUint64 _rawDataSize; ///< 정규화되기 전의 바이트 열 크기
    Csm::csmFloat32** _pcmData; ///< -1에서 1 범위로 표현된 음성 데이터 배열
    Csm::csmUint32 _sampleOffset; ///< 샘플 참조 위치
    Csm::csmFloat32 _lastRms; ///< 마지막으로 측정된 RMS 값
    Csm::csmFloat32 _userTimeSeconds; ///< 델타 시간의 누적 값[초]
};
