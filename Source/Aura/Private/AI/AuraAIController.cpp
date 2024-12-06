// Guided project nr 2


#include "AI/AuraAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AAuraAIController::AAuraAIController()
{

	Blackboard = CreateDefaultSubobject<UBlackboardComponent>("Blackboard Component");
	check(Blackboard);
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("Behavior Tree");
	check(BehaviorTreeComponent);
	
}
