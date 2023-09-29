#ifndef APPLICATION
#define APPLICATION
#pragma once

class Application {
 public:
   API static void Init();
   API static void Clean();

 private:
   static Application& Instance() noexcept;
};

#endif