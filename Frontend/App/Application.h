#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once

class Application {
 public:
   API static void Init();

 private:
   static Application& Instance() noexcept;
};

#endif