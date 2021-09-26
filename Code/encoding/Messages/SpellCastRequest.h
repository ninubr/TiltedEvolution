#pragma once

#include "Message.h"

struct SpellCastRequest final : ClientMessage
{
    static constexpr ClientOpcode Opcode = kSpellCastRequest;

    SpellCastRequest() : ClientMessage(Opcode)
    {
    }

    void SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept override;
    void DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept override;

    bool operator==(const SpellCastRequest& acRhs) const noexcept
    {
        return CasterId == acRhs.CasterId &&
               GetOpcode() == acRhs.GetOpcode();
    }

    uint32_t CasterId;
};
