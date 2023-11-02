// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "swerve/Drivetrain.h"
#include "swerve/SwerveModule.h"
#include "swerve/Odometry.h"
#include "swerve/Trajectory.h"
#include "swerve/ngr.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer
{
public:
  Drivetrain m_drivetrain;
  Odometry m_odometry{&m_drivetrain};
  Trajectory m_trajectory{&m_drivetrain, &m_odometry};
  RobotContainer();

  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};

  frc2::CommandPtr GetAutonomousCommand();

private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;

  void ConfigureBindings();
};
