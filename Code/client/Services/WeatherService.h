#pragma once

struct World;
struct TransportService;
struct UpdateEvent;
struct DisconnectedEvent;
struct PartyJoinedEvent;
struct PartyLeftEvent;

/**
* @brief Responsible for weather changes, which is controlled on a party-per-party basis.
* 
*/
struct WeatherService
{
    WeatherService(World& aWorld, TransportService& aTransport, entt::dispatcher& aDispatcher);
    ~WeatherService() noexcept = default;

    TP_NOCOPYMOVE(WeatherService);

protected:
    void OnUpdate(const UpdateEvent& acEvent) noexcept;
    void OnDisconnected(const DisconnectedEvent& acEvent) noexcept;
    void OnPartyJoinedEvent(const PartyJoinedEvent& acEvent) noexcept;
    void OnPartyLeftEvent(const PartyLeftEvent& acEvent) noexcept;

    void RunWeatherUpdates(const double acDelta) noexcept;

    void RegainControlOfWeather() noexcept;

private:
    World& m_world;
    TransportService& m_transport;

    bool m_isInParty{};
    uint32_t m_cachedWeatherId{};

    entt::scoped_connection m_updateConnection;
    entt::scoped_connection m_disconnectConnection;
    entt::scoped_connection m_partyJoinedConnection;
    entt::scoped_connection m_partyLeftConnection;
};
