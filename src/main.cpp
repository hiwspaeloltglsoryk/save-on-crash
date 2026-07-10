#include <Geode/Geode.hpp>
#include <windows.h>
#include <filesystem>

using namespace geode::prelude;

void emergencyBackupData() {
    try {
        auto gdDir = geode::Mod::get()->getSaveDir().parent_path(); 
        auto backupDir = gdDir / "Crash_Backups";
        std::filesystem::create_directories(backupDir);
        std::filesystem::copy_file(gdDir / "CCGameManager.dat", backupDir / "CCGameManager_CrashBackup.dat", std::filesystem::copy_options::overwrite_existing);
        std::filesystem::copy_file(gdDir / "CCLocalLevels.dat", backupDir / "CCLocalLevels_CrashBackup.dat", std::filesystem::copy_options::overwrite_existing);
    } catch (...) {}
}

LONG WINAPI OurCrashHandler(EXCEPTION_POINTERS* ExceptionInfo) {
    emergencyBackupData();
    return EXCEPTION_CONTINUE_SEARCH; 
}

$on_mod(Loaded) {
    SetUnhandledExceptionFilter(OurCrashHandler);
}
