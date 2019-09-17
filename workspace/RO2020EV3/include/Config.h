///
/// @file Config.h
/// @brief ET���{�R���v���W�F�N�g�̐ݒ�
///
#pragma once
#include <RyujiEv3.h>
#include <SceneManager.h>

/// �ŏ��ɋN������V�[��
constexpr SceneID START_SCENE_ID = SceneID::LineTrace;

/// ���C���g���[�X�ǂ̎��ɌĂ΂��V�[��
constexpr SceneID LINETRACE_NEXT_SCENE = SceneID::Lookup;

/// EV3�̊e�Z���T�[,���[�^�[�̐ڑ��|�[�g
constexpr PortData ROBOCON_PORT = {
    // ColorSensor
    SensorPort::PORT_3,

    // TouchSensor
    SensorPort::PORT_1,

    // GyroSensor
    SensorPort::PORT_4,

    // SonarSensor
    SensorPort::PORT_2,

    // LeftMotor
    MotorPort::PORT_C,

    // RightMotor
    MotorPort::PORT_B,

    // TailMotor
    MotorPort::PORT_A};