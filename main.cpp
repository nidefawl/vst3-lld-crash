#include <public.sdk/source/vst/hosting/module.h>

int main(int, char*[]) {
    VST3::Hosting::ClassInfo info;
    return info.classFlags();
}

