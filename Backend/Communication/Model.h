#ifndef MODEL_H
#define MODEL_H
#pragma once
class SignalBase;

class Model {
 private:
   std::map<std::string, std::unique_ptr<SignalBase>> m_signals;

 public:
   API void AddSignal(const std::string& id);

   template<typename T>
   API void AddSignal(const std::string& id);

   API void Trigger(const std::string& id) const;

   template<typename T>
   API void Trigger(const std::string& id, const T& argument) const;

   template<typename F>
   API void Connect(const std::string& id, F fun);

   template<typename F, typename P>
   API void Connect(const std::string& id, F fun, P ptr);

   template<typename T, typename F>
   API void Connect(const std::string& id, F fun);

   template<typename T, typename F, typename P>
   API void Connect(const std::string& id, F fun, P ptr);
};

#include "Model.hpp"
#endif