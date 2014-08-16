/**
* Created by Alejandro Bordallo
* \file   Environment.h
* \brief  Declares the Environment class.
*/

#include <vector>
#include <map>

#ifndef HRVO_SIMULATOR_H_
#include "Simulator.h"
#endif

#ifndef HRVO_AGENT_H_
#include "Agent.h"
#endif


namespace hrvo {
  class Simulator;
  class Agent;
  class Goal;
  class KdTree;

  class Environment
  {
  public:
    Environment(enum Actor actorID, const Vector2 startPos);
    ~Environment();

    enum Actor getActorID() {return nActorID_;}

    std::string getsActorID() {return sActorID_;}

    std::size_t addTracker();
    
    void setPlannerParam();

    std::size_t addVirtualAgent(std::string id, const Vector2 startPos, std::size_t goalNo);

    std::size_t addPlannerGoal(const Vector2 goalPosition);

    int setPlannerGoal(std::size_t goalNo);

    std::size_t addAndSetPlannerGoal(const Vector2 goalPosition);

    std::size_t setSimParam(std::size_t simID);

    float getGlobalPlannerTime() const { return planner_->getGlobalTime(); }

    std::size_t getNumPlannerGoals()  { return planner_->getNumGoals(); }

    Vector2 getGoalPlannerPosition(std::size_t goalNo) const { return planner_->getGoalPosition(goalNo); }

    bool getReachedPlannerGoal() const { return planner_->agents_[THIS_ROBOT]->reachedGoal_;}

    bool getVirtualAgentReachedGoal(std::size_t simID, std::size_t agentNo);
    // { simvect_[simID]->agents_[agentNo].reachedGoal_;  }

    void doPlannerStep();

    void doSimulatorStep(std::size_t simID);

    std::size_t addAndSetSimGoal(std::size_t simID, std::size_t agentNo, const Vector2 goalPosition);

    std::map<std::size_t, std::size_t> setupModel(std::size_t agentNo, std::map<size_t, Vector2> possGoals);

    std::size_t inferGoals(std::size_t agentNo, std::map<std::size_t, std::size_t> simIDs);

    void setupPlannerModel(std::size_t agentNo);

    std::map<std::size_t, float> inferAllGoals(std::size_t agentNo);

    // bool plannerReachedGoals();

    std::size_t getNumPlannerAgents() const { return planner_->agents_.size(); }

    Vector2 getAgentPlannerPosition(std::size_t agentNo) const { return planner_->agents_[agentNo]->position_; }

    std::size_t addSimulation();

    void deleteSimulation(std::size_t simID);

    void stopYoubot();

  /**
  * \brief    Sends to all agents an emergency stop command.
  */
    void emergencyStop();


    private:
      friend class Simulator;
      friend class Agent;
      friend class Goal;
      friend class KdTree;

      enum Actor nActorID_;
      std::string sActorID_; 
      Vector2 startPos_;
      size_t startGoal_;

      Simulator *planner_;

      std::map<std::size_t, Vector2> possGoals_;
      std::map<std::size_t, std::size_t> simIDs_;
      std::map<std::size_t, Simulator *> simvect_;
      std::map<std::size_t, float> inferredGoalsSum_;
      std::map<std::size_t, std::map<std::size_t, float> > inferredAgentGoalsSum_;




  };

}