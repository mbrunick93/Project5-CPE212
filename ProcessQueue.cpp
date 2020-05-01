#include "ProcessQueue.hpp"



/// TODO
void ProcessQueue::PushProcess(const std::string & output, Priority p)
{
    Process x(output, p, _nextPID);
    _nextPID++;
    for (int i =0; i < _data.size(); i++){
        if (p == _data.at(i).Prio())
        {
            _data.at(i).Push(x);
            return;
        }
    }
   
    PriorityList list(x,p);
    _data.push_front(list);
   
    ReheapUpList(_data.size() - 1);
}

/// TODO
void ProcessQueue::ExecuteNextProcess()
{
    _data.front().Pop().ExecuteProcess(std::cout);
    if(_data.front().IsEmpty()){
        _data.pop_front();
    }
    if(!_data.empty()){
        ReheapDownList(0);
    }
    
}

/// TODO
void ProcessQueue::ReheapUpList(int currentIndex)
{
   if (currentIndex == 0)
   {
       return;
   }
   for(int i = 0; i < _data.size()-1; i++){

       if (_data.at(i) < _data.at(currentIndex)){
           _data.at(i).SwapList(_data.at(currentIndex));
       }
   }   
    ReheapUpList(currentIndex -1);
}

/// TODO
void ProcessQueue::ReheapDownList(int currentIndex)
{
    if (currentIndex == _data.size())
   {
       return;
   }
   for(int i = 0; i < _data.size()-1; i++){

       if (_data.at(i) < _data.at(currentIndex)){
           _data.at(i).SwapList(_data.at(currentIndex)); 
       }
   }   
   ReheapDownList(currentIndex+1);
}

/// TODO
bool ProcessQueue::IsEmpty() const
{
  if (_nextPID == 0)
  {
      return true;
  }
  else {return false;}
}