#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once

class Application {
 public:
   API static void Init();
   API static void Clean();

 private:
   static Application& Instance() noexcept;
};

#endif