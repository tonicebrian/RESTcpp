#include <ShutdownManager.hpp>

ShutdownManager::ShutdownManager():m_shutdown_now(false){}
ShutdownManager::~ShutdownManager(){}

/// signal handlers that trigger the shutdown manager
void handle_signal(int sig)
{
	main_shutdown_manager.shutdown();
}

