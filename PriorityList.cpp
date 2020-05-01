#include "PriorityList.hpp"

PriorityList::PriorityList(const Process &process, Priority priority) : 
        _priority(priority)
{
    _tasks.push_back(process);
    
}


/// TODO
void PriorityList::SwapList(PriorityList &otherList)
{

    _tasks.swap(otherList._tasks);
    Priority temp = otherList.Prio();
    otherList._priority = this->_priority;
    this->_priority = temp;
}


/// TODO
Process PriorityList::Pop()
{
  if(!_tasks.empty()){
    Process x = _tasks.front();
  _tasks.pop_front();
  return x;
  }  
  
}


/// TODO
void PriorityList::Push(const Process & process)
{

    _tasks.push_back(process);

}

Priority PriorityList::Prio() const
{
    return _priority;
}

bool PriorityList::IsEmpty() const
{
    return _tasks.size() == 0;
}

bool operator==(const Process &process, const PriorityList &list)
{
    return process.Prio() == list.Prio();
}

bool operator!=(const Process &process, const PriorityList &list)
{
    return process.Prio() != list.Prio();
}

bool operator>(const Process &process, const PriorityList &list)
{
    return process.Prio() > list.Prio();
}

bool operator<(const Process &process, const PriorityList &list)
{
    return process.Prio() < list.Prio();
}

bool operator==(const PriorityList &list, const Process &process)
{
    return list.Prio() == process.Prio();
}

bool operator!=(const PriorityList &list, const Process &process)
{
    return list.Prio() != process.Prio();
}

bool operator>(const PriorityList &list, const Process &process)
{
    return list.Prio() > process.Prio();
}

bool operator<(const PriorityList &list, const Process &process)
{
    return list.Prio() < process.Prio();
}


bool operator==(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() == listb.Prio();
}

bool operator!=(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() != listb.Prio();
}

bool operator>(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() > listb.Prio();
}

bool operator<(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() < listb.Prio();
}



