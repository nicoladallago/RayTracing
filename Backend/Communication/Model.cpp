#include "Model.h"
#include "Signal.h"

API void Model::AddSignal(const std::string& id) {
   m_signals.at(id).reset(new Signal<sigslot::signal<>>(sigslot::signal<>()));
}


API void Model::Trigger(const std::string& id) const {
   sigslot::signal<>& signal = dynamic_cast<Signal<sigslot::signal<>>&>(*m_signals.at(id)).Get();
   signal();
}
