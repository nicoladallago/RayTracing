#ifndef EXPORT_H
#define EXPORT_H
#pragma once

#ifdef _WIN32
   #define API __declspec(dllexport)
#else
   #define API
#endif

#endif