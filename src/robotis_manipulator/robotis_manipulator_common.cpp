/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Darby Lim, Hye-Jong KIM, Ryan Shim, Yong-Ho Na */

#include "../../include/robotis_manipulator/robotis_manipulator_common.h"

using namespace robotis_manipulator;


/*****************************************************************************
** Add Function
*****************************************************************************/
void Manipulator::addWorld(Name world_name,
                           Name child_name,
                           Eigen::Vector3d world_position,
                           Eigen::Matrix3d world_orientation)
{
  world_.name = world_name;
  world_.child = child_name;
  world_.pose.kinematic.position = world_position;
  world_.pose.kinematic.orientation = world_orientation;
  world_.pose.dynamic.linear.velocity = Eigen::Vector3d::Zero();
  world_.pose.dynamic.linear.acceleration = Eigen::Vector3d::Zero();
  world_.pose.dynamic.angular.velocity = Eigen::Vector3d::Zero();
  world_.pose.dynamic.angular.acceleration = Eigen::Vector3d::Zero();
}

void Manipulator::addJoint(Name my_name,
                           Name parent_name,
                           Name child_name,
                           Eigen::Vector3d relative_position,
                           Eigen::Matrix3d relative_orientation,
                           Eigen::Vector3d axis_of_rotation,
                           int8_t joint_actuator_id,
                           double max_position_limit,
                           double min_position_limit,
                           double coefficient,
                           double mass,
                           Eigen::Matrix3d inertia_tensor,
                           Eigen::Vector3d center_of_mass)
{
  Component temp_component;
  if (joint_actuator_id != -1)
  {
    dof_++;
    temp_component.component_type = ACTIVE_JOINT_COMPONENT;
  }
  else
  {
    temp_component.component_type = PASSIVE_JOINT_COMPONENT;
  }

  temp_component.name.parent = parent_name;
  temp_component.name.child.push_back(child_name);
  temp_component.relative.pose_from_parent.position = relative_position;
  temp_component.relative.pose_from_parent.orientation = relative_orientation;
  temp_component.relative.inertia.mass = mass;
  temp_component.relative.inertia.inertia_tensor = inertia_tensor;
  temp_component.relative.inertia.center_of_mass = center_of_mass;
  temp_component.joint_constant.id = joint_actuator_id;
  temp_component.joint_constant.coefficient = coefficient;
  temp_component.joint_constant.axis = axis_of_rotation;
  temp_component.joint_constant.position_limit.maximum = max_position_limit;
  temp_component.joint_constant.position_limit.minimum = min_position_limit;

  temp_component.pose_from_world.kinematic.position = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.kinematic.orientation = Eigen::Matrix3d::Identity();
  temp_component.pose_from_world.dynamic.linear.velocity = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.dynamic.linear.acceleration = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.dynamic.angular.velocity = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.dynamic.angular.acceleration = Eigen::Vector3d::Zero();

  temp_component.joint_value.position = 0.0;
  temp_component.joint_value.velocity = 0.0;
  temp_component.joint_value.effort = 0.0;

  component_.insert(std::make_pair(my_name, temp_component));
}

void Manipulator::addTool(Name my_name,
                          Name parent_name,
                          Eigen::Vector3d relative_position,
                          Eigen::Matrix3d relative_orientation,
                          int8_t tool_id,
                          double max_position_limit,
                          double min_position_limit,
                          double coefficient,
                          double mass,
                          Eigen::Matrix3d inertia_tensor,
                          Eigen::Vector3d center_of_mass)
{
  Component temp_component;

  temp_component.name.parent = parent_name;
  temp_component.name.child.resize(0);
  temp_component.component_type = TOOL_COMPONENT;
  temp_component.relative.pose_from_parent.position = relative_position;
  temp_component.relative.pose_from_parent.orientation = relative_orientation;
  temp_component.relative.inertia.mass = mass;
  temp_component.relative.inertia.inertia_tensor = inertia_tensor;
  temp_component.relative.inertia.center_of_mass = center_of_mass;
  temp_component.joint_constant.id = tool_id;
  temp_component.joint_constant.coefficient = coefficient;
  temp_component.joint_constant.axis = Eigen::Vector3d::Zero();
  temp_component.joint_constant.position_limit.maximum = max_position_limit;
  temp_component.joint_constant.position_limit.minimum = min_position_limit;

  temp_component.pose_from_world.kinematic.position = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.kinematic.orientation = Eigen::Matrix3d::Identity();
  temp_component.pose_from_world.dynamic.linear.velocity = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.dynamic.linear.acceleration = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.dynamic.angular.velocity = Eigen::Vector3d::Zero();
  temp_component.pose_from_world.dynamic.angular.acceleration = Eigen::Vector3d::Zero();

  temp_component.joint_value.position = 0.0;
  temp_component.joint_value.velocity = 0.0;
  temp_component.joint_value.effort = 0.0;

  component_.insert(std::make_pair(my_name, temp_component));
}

void Manipulator::addComponentChild(Name my_name, Name child_name)
{
  component_.at(my_name).name.child.push_back(child_name);
}

void Manipulator::printManipulatorSetting()
{
  rm_log::println("----------<Manipulator Description>----------");
  rm_log::println("<Degree of Freedom>\n", dof_);
  rm_log::println("<Number of Components>\n", component_.size());
  rm_log::println("");
  rm_log::println("<World Configuration>");
  rm_log::println(" [Name]");
  rm_log::print(" -World Name : "); rm_log::println(STRING(world_.name));
  rm_log::print(" -Child Name : "); rm_log::println(STRING(world_.child));
  rm_log::println(" [Static Pose]");
  rm_log::println(" -Position : ");
  rm_log::print_vector(world_.pose.kinematic.position);
  rm_log::println(" -Orientation : ");
  rm_log::print_matrix(world_.pose.kinematic.orientation);
  rm_log::println(" [Dynamic Pose]");
  rm_log::println(" -Linear Velocity : ");
  rm_log::print_vector(world_.pose.dynamic.linear.velocity);
  rm_log::println(" -Linear acceleration : ");
  rm_log::print_vector(world_.pose.dynamic.linear.acceleration);
  rm_log::println(" -Angular Velocity : ");
  rm_log::print_vector(world_.pose.dynamic.angular.velocity);
  rm_log::println(" -Angular acceleration : ");
  rm_log::print_vector(world_.pose.dynamic.angular.acceleration);

  std::vector<double> result_vector;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    rm_log::println("");
    rm_log::println("<"); rm_log::print(STRING(it_component->first)); rm_log::print("Configuration>");
    if(component_.at(it_component->first).component_type == ACTIVE_JOINT_COMPONENT)
      rm_log::println(" [Component Type]\n  Active Joint");
    else if(component_.at(it_component->first).component_type == PASSIVE_JOINT_COMPONENT)
      rm_log::println(" [Component Type]\n  Passive Joint");
    else if(component_.at(it_component->first).component_type == TOOL_COMPONENT)
      rm_log::println(" [Component Type]\n  Tool");
    rm_log::println(" [Name]");
    rm_log::print(" -Parent Name : "); rm_log::println(STRING(component_.at(it_component->first).name.parent));
    for(uint32_t index = 0; index < component_.at(it_component->first).name.child.size(); index++)
    {
      rm_log::print(" -Child Name",index+1,0);
      rm_log::print(" : ");
      rm_log::println(STRING(component_.at(it_component->first).name.child.at(index)));
    }
    rm_log::println(" [Actuator]");
    rm_log::print(" -Actuator Name : ");
    rm_log::println(STRING(component_.at(it_component->first).actuator_name));
    rm_log::print(" -ID : ");
    rm_log::println("", component_.at(it_component->first).joint_constant.id,0);
    rm_log::println(" -Joint Axis : ");
    rm_log::print_vector(component_.at(it_component->first).joint_constant.axis);
    rm_log::print(" -Coefficient : ");
    rm_log::println("", component_.at(it_component->first).joint_constant.coefficient);
    rm_log::println(" -Position Limit : ");
    rm_log::print("    Maximum :", component_.at(it_component->first).joint_constant.position_limit.maximum);
    rm_log::println(", Minimum :", component_.at(it_component->first).joint_constant.position_limit.minimum);

    rm_log::println(" [Actuator Value]");
    rm_log::println(" -Position : ", component_.at(it_component->first).joint_value.position);
    rm_log::println(" -Velocity : ", component_.at(it_component->first).joint_value.velocity);
    rm_log::println(" -Acceleration : ", component_.at(it_component->first).joint_value.acceleration);
    rm_log::println(" -Effort : ", component_.at(it_component->first).joint_value.effort);

    rm_log::println(" [Constant]");
    rm_log::println(" -Relative Position from parent component : ");
    rm_log::print_vector(component_.at(it_component->first).relative.pose_from_parent.position);
    rm_log::println(" -Relative Orientation from parent component : ");
    rm_log::print_matrix(component_.at(it_component->first).relative.pose_from_parent.orientation);
    rm_log::print(" -Mass : ");
    rm_log::println("", component_.at(it_component->first).relative.inertia.mass);
    rm_log::println(" -Inertia Tensor : ");
    rm_log::print_matrix(component_.at(it_component->first).relative.inertia.inertia_tensor);
    rm_log::println(" -Center of Mass : ");
    rm_log::print_vector(component_.at(it_component->first).relative.inertia.center_of_mass);

    rm_log::println(" [Variable]");
    rm_log::println(" -Position : ");
    rm_log::print_vector(component_.at(it_component->first).pose_from_world.kinematic.position);
    rm_log::println(" -Orientation : ");
    rm_log::print_matrix(component_.at(it_component->first).pose_from_world.kinematic.orientation);
    rm_log::println(" -Linear Velocity : ");
    rm_log::print_vector(component_.at(it_component->first).pose_from_world.dynamic.linear.velocity);
    rm_log::println(" -Linear acceleration : ");
    rm_log::print_vector(component_.at(it_component->first).pose_from_world.dynamic.linear.acceleration);
    rm_log::println(" -Angular Velocity : ");
    rm_log::print_vector(component_.at(it_component->first).pose_from_world.dynamic.angular.velocity);
    rm_log::println(" -Angular acceleration : ");
    rm_log::print_vector(component_.at(it_component->first).pose_from_world.dynamic.angular.acceleration);
  }
  rm_log::println("---------------------------------------------");
}


/*****************************************************************************
** Set Function
*****************************************************************************/
void Manipulator::setWorldPose(Pose world_pose)
{
  world_.pose = world_pose;
}

void Manipulator::setWorldKinematicPose(KinematicPose world_kinematic_pose)
{
  world_.pose.kinematic = world_kinematic_pose;
}

void Manipulator::setWorldPosition(Eigen::Vector3d world_position)
{
  world_.pose.kinematic.position = world_position;
}

void Manipulator::setWorldOrientation(Eigen::Matrix3d world_orientation)
{
  world_.pose.kinematic.orientation = world_orientation;
}

void Manipulator::setWorldDynamicPose(DynamicPose world_dynamic_pose)
{
  world_.pose.dynamic = world_dynamic_pose;
}

void Manipulator::setWorldLinearVelocity(Eigen::Vector3d world_linear_velocity)
{
  world_.pose.dynamic.linear.velocity = world_linear_velocity;
}

void Manipulator::setWorldAngularVelocity(Eigen::Vector3d world_angular_velocity)
{
  world_.pose.dynamic.angular.velocity = world_angular_velocity;
}

void Manipulator::setWorldLinearAcceleration(Eigen::Vector3d world_linear_acceleration)
{
  world_.pose.dynamic.linear.acceleration = world_linear_acceleration;
}

void Manipulator::setWorldAngularAcceleration(Eigen::Vector3d world_angular_acceleration)
{
  world_.pose.dynamic.angular.acceleration = world_angular_acceleration;
}

void Manipulator::setComponent(Name component_name, Component component)
{
  component_.at(component_name) = component;
}

void Manipulator::setComponentActuatorName(Name component_name, Name actuator_name)
{
  component_.at(component_name).actuator_name = actuator_name;
}

void Manipulator::setComponentPoseFromWorld(Name component_name, Pose pose_to_world)
{
  if (component_.find(component_name) != component_.end())
  {
    component_.at(component_name).pose_from_world = pose_to_world;
  }
  else
  {
    rm_log::error("[setComponentPoseFromWorld] Wrong name.");
  }
}

void Manipulator::setComponentKinematicPoseFromWorld(Name component_name, KinematicPose pose_to_world)
{
  if (component_.find(component_name) != component_.end())
  {
    component_.at(component_name).pose_from_world.kinematic = pose_to_world;
  }
  else
  {
    rm_log::error("[setComponentKinematicPoseFromWorld] Wrong name.");
  }
}

void Manipulator::setComponentPositionFromWorld(Name component_name, Eigen::Vector3d position_to_world)
{
  if (component_.find(component_name) != component_.end())
  {
    component_.at(component_name).pose_from_world.kinematic.position = position_to_world;
  }
  else
  {
    rm_log::error("[setComponentPositionFromWorld] Wrong name.");
  }
}

void Manipulator::setComponentOrientationFromWorld(Name component_name, Eigen::Matrix3d orientation_to_wolrd)
{
  if (component_.find(component_name) != component_.end())
  {
    component_.at(component_name).pose_from_world.kinematic.orientation = orientation_to_wolrd;
  }
  else
  {
    rm_log::error("[setComponentOrientationFromWorld] Wrong name.");
  }
}

void Manipulator::setComponentDynamicPoseFromWorld(Name component_name, DynamicPose dynamic_pose)
{
  if (component_.find(component_name) != component_.end())
  {
    component_.at(component_name).pose_from_world.dynamic = dynamic_pose;
  }
  else
  {
    rm_log::error("[setComponentDynamicPoseFromWorld] Wrong name.");
  }
}

void Manipulator::setJointPosition(Name component_name, double position)
{
  component_.at(component_name).joint_value.position = position;
}

void Manipulator::setJointVelocity(Name component_name, double velocity)
{
  component_.at(component_name).joint_value.velocity = velocity;
}

void Manipulator::setJointAcceleration(Name component_name, double acceleration)
{
  component_.at(component_name).joint_value.acceleration = acceleration;
}

void Manipulator::setJointEffort(Name component_name, double effort)
{
  component_.at(component_name).joint_value.effort = effort;
}

void Manipulator::setJointValue(Name component_name, JointValue joint_value)
{
  component_.at(component_name).joint_value = joint_value;
}

void Manipulator::setAllActiveJointPosition(std::vector<double> joint_position_vector)
{
  int8_t index = 0;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (component_.at(it_component->first).component_type == ACTIVE_JOINT_COMPONENT)
    {
      component_.at(it_component->first).joint_value.position = joint_position_vector.at(index);
      index++;
    }
  }
}

void Manipulator::setAllActiveJointValue(std::vector<JointValue> joint_value_vector)
{
  int8_t index = 0;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (component_.at(it_component->first).component_type == ACTIVE_JOINT_COMPONENT)
    {
      component_.at(it_component->first).joint_value.position = joint_value_vector.at(index).position;
      component_.at(it_component->first).joint_value.velocity = joint_value_vector.at(index).velocity;
      component_.at(it_component->first).joint_value.acceleration = joint_value_vector.at(index).acceleration;
      component_.at(it_component->first).joint_value.effort = joint_value_vector.at(index).effort;
      index++;
    }
  }
}

void Manipulator::setAllJointPosition(std::vector<double> joint_position_vector)
{
  int8_t index = 0;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (component_.at(it_component->first).component_type == ACTIVE_JOINT_COMPONENT || component_.at(it_component->first).component_type == PASSIVE_JOINT_COMPONENT)
    {
      component_.at(it_component->first).joint_value.position = joint_position_vector.at(index);
      index++;
    }
  }
}

void Manipulator::setAllJointValue(std::vector<JointValue> joint_value_vector)
{
  int8_t index = 0;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (component_.at(it_component->first).component_type == ACTIVE_JOINT_COMPONENT || component_.at(it_component->first).component_type == PASSIVE_JOINT_COMPONENT)
    {
      component_.at(it_component->first).joint_value = joint_value_vector.at(index);
      index++;
    }
  }
}

void Manipulator::setAllToolPosition(std::vector<double> tool_position_vector)
{
  int8_t index = 0;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (component_.at(it_component->first).component_type == TOOL_COMPONENT)
    {
      component_.at(it_component->first).joint_value.position = tool_position_vector.at(index);
      index++;
    }
  }
}

void Manipulator::setAllToolValue(std::vector<JointValue> tool_value_vector)
{
  int8_t index = 0;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (component_.at(it_component->first).component_type == TOOL_COMPONENT)
    {
      component_.at(it_component->first).joint_value = tool_value_vector.at(index);
      index++;
    }
  }
}


/*****************************************************************************
** Get Function
*****************************************************************************/
int8_t Manipulator::getDOF()
{
  return dof_;
}

Name Manipulator::getWorldName()
{
  return world_.name;
}

Name Manipulator::getWorldChildName()
{
  return world_.child;
}

Pose Manipulator::getWorldPose()
{
  return world_.pose;
}

KinematicPose Manipulator::getWorldKinematicPose()
{
  return world_.pose.kinematic;
}

Eigen::Vector3d Manipulator::getWorldPosition()
{
  return world_.pose.kinematic.position;
}

Eigen::Matrix3d Manipulator::getWorldOrientation()
{
  return world_.pose.kinematic.orientation;
}

DynamicPose Manipulator::getWorldDynamicPose()
{
  return world_.pose.dynamic;
}

int8_t Manipulator::getComponentSize()
{
  return component_.size();
}

std::map<Name, Component> Manipulator::getAllComponent()
{
  return component_;
}

std::map<Name, Component>::iterator Manipulator::getIteratorBegin()
{
  return component_.begin();
}

std::map<Name, Component>::iterator Manipulator::getIteratorEnd()
{
  return component_.end();;
}

Component Manipulator::getComponent(Name component_name)
{
  return component_.at(component_name);
}

Name Manipulator::getComponentActuatorName(Name component_name)
{
  return component_.at(component_name).actuator_name;
}

Name Manipulator::getComponentParentName(Name component_name)
{
  return component_.at(component_name).name.parent;
}

std::vector<Name> Manipulator::getComponentChildName(Name component_name)
{
  return component_.at(component_name).name.child;
}

Pose Manipulator::getComponentPoseFromWorld(Name component_name)
{
  return component_.at(component_name).pose_from_world;
}

KinematicPose Manipulator::getComponentKinematicPoseFromWorld(Name component_name)
{
  return component_.at(component_name).pose_from_world.kinematic;
}

Eigen::Vector3d Manipulator::getComponentPositionFromWorld(Name component_name)
{
  return component_.at(component_name).pose_from_world.kinematic.position;
}

Eigen::Matrix3d Manipulator::getComponentOrientationFromWorld(Name component_name)
{
  return component_.at(component_name).pose_from_world.kinematic.orientation;
}

DynamicPose Manipulator::getComponentDynamicPoseFromWorld(Name component_name)
{
  return component_.at(component_name).pose_from_world.dynamic;
}

KinematicPose Manipulator::getComponentRelativePoseFromParent(Name component_name)
{
  return component_.at(component_name).relative.pose_from_parent;
}

Eigen::Vector3d Manipulator::getComponentRelativePositionFromParent(Name component_name)
{
  return component_.at(component_name).relative.pose_from_parent.position;
}

Eigen::Matrix3d Manipulator::getComponentRelativeOrientationFromParent(Name component_name)
{
  return component_.at(component_name).relative.pose_from_parent.orientation;
}

int8_t Manipulator::getId(Name component_name)
{
  return component_.at(component_name).joint_constant.id;
}

double Manipulator::getCoefficient(Name component_name)
{
  return component_.at(component_name).joint_constant.coefficient;
}

Eigen::Vector3d Manipulator::getAxis(Name component_name)
{
  return component_.at(component_name).joint_constant.axis;
}

double Manipulator::getJointPosition(Name component_name)
{
  return component_.at(component_name).joint_value.position;
}

double Manipulator::getJointVelocity(Name component_name)
{
  return component_.at(component_name).joint_value.velocity;
}

double Manipulator::getJointAcceleration(Name component_name)
{
  return component_.at(component_name).joint_value.acceleration;
}

double Manipulator::getJointEffort(Name component_name)
{
  return component_.at(component_name).joint_value.effort;
}

JointValue Manipulator::getJointValue(Name component_name)
{
  return component_.at(component_name).joint_value;
}

double Manipulator::getComponentMass(Name component_name)
{
  return component_.at(component_name).relative.inertia.mass;
}

Eigen::Matrix3d Manipulator::getComponentInertiaTensor(Name component_name)
{
  return component_.at(component_name).relative.inertia.inertia_tensor;
}

Eigen::Vector3d Manipulator::getComponentCenterOfMass(Name component_name)
{
  return component_.at(component_name).relative.inertia.center_of_mass;
}

std::vector<double> Manipulator::getAllJointPosition()
{
  std::vector<double> result_vector;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, ACTIVE_JOINT_COMPONENT) || checkComponentType(it_component->first, PASSIVE_JOINT_COMPONENT))
    {
      result_vector.push_back(component_.at(it_component->first).joint_value.position);
    }
  }
  return result_vector;
}

std::vector<JointValue> Manipulator::getAllJointValue()
{
  std::vector<JointValue> result_vector;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, ACTIVE_JOINT_COMPONENT) || checkComponentType(it_component->first, PASSIVE_JOINT_COMPONENT))
    {
      result_vector.push_back(component_.at(it_component->first).joint_value);
    }
  }
  return result_vector;
}

std::vector<double> Manipulator::getAllActiveJointPosition()
{
  std::vector<double> result_vector;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, ACTIVE_JOINT_COMPONENT))
    {
      result_vector.push_back(component_.at(it_component->first).joint_value.position);
    }
  }
  return result_vector;
}

std::vector<JointValue> Manipulator::getAllActiveJointValue()
{
  std::vector<JointValue> result_vector;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, ACTIVE_JOINT_COMPONENT))
    {
      result_vector.push_back(component_.at(it_component->first).joint_value);
    }
  }
  return result_vector;
}

std::vector<double> Manipulator::getAllToolPosition()
{
  std::vector<double> result_vector;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, TOOL_COMPONENT))
    {
      result_vector.push_back(component_.at(it_component->first).joint_value.position);
    }
  }
  return result_vector;
}


std::vector<JointValue> Manipulator::getAllToolValue()
{
  std::vector<JointValue> result_vector;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, TOOL_COMPONENT))
    {
      result_vector.push_back(component_.at(it_component->first).joint_value);
    }
  }
  return result_vector;
}

std::vector<uint8_t> Manipulator::getAllJointID()
{
  std::vector<uint8_t> joint_id;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, ACTIVE_JOINT_COMPONENT) || checkComponentType(it_component->first, PASSIVE_JOINT_COMPONENT))
    {
      joint_id.push_back(component_.at(it_component->first).joint_constant.id);
    }
  }
  return joint_id;
}

std::vector<uint8_t> Manipulator::getAllActiveJointID()
{
  std::vector<uint8_t> active_joint_id;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, ACTIVE_JOINT_COMPONENT))
    {
      active_joint_id.push_back(component_.at(it_component->first).joint_constant.id);
    }
  }
  return active_joint_id;
}


std::vector<Name> Manipulator::getAllToolComponentName()
{
  std::vector<Name> tool_name;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, TOOL_COMPONENT))
    {
      tool_name.push_back(it_component->first);
    }
  }
  return tool_name;
}

std::vector<Name> Manipulator::getAllActiveJointComponentName()
{
  std::vector<Name> active_joint_name;
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (checkComponentType(it_component->first, ACTIVE_JOINT_COMPONENT))
    {
      active_joint_name.push_back(it_component->first);
    }
  }
  return active_joint_name;
}


/*****************************************************************************
** Check Function
*****************************************************************************/
bool Manipulator::checkJointLimit(Name component_name, double value)
{
  if(component_.at(component_name).joint_constant.position_limit.maximum < value)
    return false;
  else if(component_.at(component_name).joint_constant.position_limit.minimum > value)
    return false;
  else
    return true;
}

bool Manipulator::checkComponentType(Name component_name, ComponentType component_type)
{
  if(component_.at(component_name).component_type == component_type)
    return true;
  else
    return false;
}


/*****************************************************************************
** Find Function
*****************************************************************************/
Name Manipulator::findComponentNameUsingId(int8_t id)
{
  std::map<Name, Component>::iterator it_component;

  for (it_component = component_.begin(); it_component != component_.end(); it_component++)
  {
    if (component_.at(it_component->first).joint_constant.id == id)
    {
      return it_component->first;
    }
  }
  return {};
}
