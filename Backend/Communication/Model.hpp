#include "Signal.h"

template<typename T>
API void Model::AddSignal(const std::string& key) {
   m_signals.at(key).reset(new Signal<sigslot::signal<T>>(sigslot::signal<T>()));
}


template<typename T>
API void Model::Trigger(const std::string& key, const T& argument) const {
   sigslot::signal<T>& signal = dynamic_cast<Signal<sigslot::signal<T>>&>(*m_signals.at(key)).Get();
   signal(argument);
}


template<typename F>
API void Model::Connect(const std::string& key, F fun) {
   sigslot::signal<>& signal = dynamic_cast<Signal<sigslot::signal<>>&>(*m_signals.at(key)).Get();
   signal.connect(fun);
}


template<typename F, typename P>
API void Model::Connect(const std::string& key, F fun, P ptr) {
   sigslot::signal<>& signal = dynamic_cast<Signal<sigslot::signal<>>&>(*m_signals.at(key)).Get();
   signal.connect(fun, ptr);
}


template<typename T, typename F>
API void Model::Connect(const std::string& key, F fun) {
   sigslot::signal<T>& signal = dynamic_cast<Signal<sigslot::signal<T>>&>(*m_signals.at(key)).Get();
   signal.connect(fun);
}


template<typename T, typename F, typename P>
API void Model::Connect(const std::string& key, F fun, P ptr) {
   sigslot::signal<T>& signal = dynamic_cast<Signal<sigslot::signal<T>>&>(*m_signals.at(key)).Get();
   signal.connect(fun, ptr);
}