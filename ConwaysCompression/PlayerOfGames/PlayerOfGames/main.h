#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 *  This library trains a NN to search for the heuristic minimal 32x32- constantly expanding starting game of life, that in N-moves becomes a defined
 *  Outcome Game of 256x256  Dimension.
 * It provides a training function for the NN.
 * It provides a export function for the NN.
 * It provides a encoding function of data via the NN.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT SomeFunction(const LPCSTR sometext);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
