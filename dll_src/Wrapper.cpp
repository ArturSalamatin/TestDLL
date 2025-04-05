#include <Wrapper.h>
#include <src/Manager.h>
#include <src/Operator.h>

Wrapper::Wrapper(){
  m_operator = new Operator();
  m_manager = new Manager();
}

Wrapper::~Wrapper(){
  delete m_operator;
  delete m_manager;
}

void Wrapper::useOperator(){
  m_operator->dummyFunction1();
  m_operator->dummyFunction2();
}

void Wrapper::useManager(){
  m_manager->dummyFunction1();
  m_manager->dummyFunction2();
}