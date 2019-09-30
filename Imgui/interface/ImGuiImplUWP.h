/*     Copyright 2019 Diligent Graphics LLC
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

#include <memory>
#include "ImGuiImplDiligent.h"

namespace Diligent
{

class ImGuiImplUWP final : public ImGuiImplDiligent
{
public:
    ImGuiImplUWP(IRenderDevice*  pDevice,
                 TEXTURE_FORMAT  BackBufferFmt,
                 TEXTURE_FORMAT  DepthBufferFmt,
                 Uint32          InitialVertexBufferSize = ImGuiImplDiligent::DefaultInitialVBSize,
                 Uint32          InitialIndexBufferSize  = ImGuiImplDiligent::DefaultInitialIBSize);
    ~ImGuiImplUWP();

    ImGuiImplUWP             (const ImGuiImplUWP&)  = delete;
    ImGuiImplUWP             (      ImGuiImplUWP&&) = delete;
    ImGuiImplUWP& operator = (const ImGuiImplUWP&)  = delete;
    ImGuiImplUWP& operator = (      ImGuiImplUWP&&) = delete;

    virtual void NewFrame()override final;

    void SetDisplaySize(Uint32 DisplayWidth, Uint32 DisplayHeight)
    {
        m_DisplayWidth  = DisplayWidth;
        m_DisplayHeight = DisplayHeight;
    }

private:
    INT64 m_Time = 0;
    INT64 m_TicksPerSecond = 0;
    Uint32 m_DisplayWidth  = 0;
    Uint32 m_DisplayHeight = 0;
};

}