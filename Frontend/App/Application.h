#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once

class Application {
 private:
   static Application& Instance() noexcept;
};

#endif