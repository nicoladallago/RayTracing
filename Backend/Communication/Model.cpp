#include "Model.h"
#include "Signal.h"

API void Model::AddSignal(const std::string& key) {
   m_signals.at(key) = std::make_unique<Signal<sigslot::signal<>>>(sigslot::signal<>());
}


API void Model::Trigger(const std::string& key) const {
   sigslot::signal<>& signal = dynamic_cast<Signal<sigslot::signal<>>&>(*m_signals.at(key)).Get();
   signal();
}
