#include <mutex>
#include <condition_variable>

class ShutdownManager {
    private:
        // true if we need to shutdown
        bool m_shutdown_now;

        // used to protect the condition
        std::mutex m_shutdown_mutex;

        // Triggered when it is time to shutdown
        std::condition_variable m_shutdown_cond;

    public:
        ShutdownManager():m_shutdown_now(false){}
        ~ShutdownManager(){}

        inline void shutdown(){
            std::lock_guard<std::mutex> lck(m_shutdown_mutex);
            m_shutdown_now = true;
            m_shutdown_cond.notify_all();
        }

        inline void wait(){
            std::unique_lock<std::mutex> lck(m_shutdown_mutex);
            m_shutdown_cond.wait(lck,[this]{return m_shutdown_now;});
        }
};

static ShutdownManager main_shutdown_manager;


/// signal handlers that trigger the shutdown manager
#ifdef PION_WIN32
BOOL WINAPI console_ctrl_handler(DWORD ctrl_type)
{
	switch(ctrl_type) {
		case CTRL_C_EVENT:
		case CTRL_BREAK_EVENT:
		case CTRL_CLOSE_EVENT:
		case CTRL_SHUTDOWN_EVENT:
			main_shutdown_manager.shutdown();
			return TRUE;
		default:
			return FALSE;
	}
}
#else
void handle_signal(int sig)
{
	main_shutdown_manager.shutdown();
}
#endif


