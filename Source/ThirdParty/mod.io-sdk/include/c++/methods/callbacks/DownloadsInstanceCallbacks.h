#include "../../ModioUtility.h"
#include <map>
#include "../../schemas/Response.h"

namespace modio
{
struct SetDownloadListenerCall
{
  const std::function<void(u32 response_code, u32 mod_id)> callback;
};

struct SetUploadListenerCall
{
  const std::function<void(u32 response_code, u32 mod_id)> callback;
};

extern SetDownloadListenerCall *set_download_listener_call;
extern SetUploadListenerCall *set_upload_listener_call;
extern std::map<u32, GetBoolCall *> check_if_mods_are_updated_calls;

void onDownloadListener(u32 response_code, u32 mod_id);
void onUploadListener(u32 response_code, u32 mod_id);
void onCheckIfModsAreUpdated(void *object, ModioResponse modio_response, bool mods_are_updated);
} // namespace modio
