#include"headerStrategy.h"
/**
the comment of this class is written in header file*/
Context::Context(Strategy* strategy){
	this->strategy=strategy;
}

void Context::setStrategy(Strategy *strategy){
	this->strategy=strategy;
}
         
GetData Context::getResult(){
	return strategy->compute();
}
         		
