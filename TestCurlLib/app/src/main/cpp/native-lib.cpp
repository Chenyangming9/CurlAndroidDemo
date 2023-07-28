#include <jni.h>
#include <string>
#include <unistd.h>
#include "web_task.h"
#include <android/log.h>
#define TAG "dc_tag"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG ,  TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO  ,  TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN  ,  TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , TAG, __VA_ARGS__)


using namespace std;

//http://www.weather.com.cn/data/sk/101110101.html
//{"weatherinfo":{"city":"深圳","cityid":"101280601","temp":"21","WD":"南风","WS":"1级","SD":"31%","WSE":"1","time":"17:05","isRadar":"1","Radar":"JC_RADAR_AZ9755_JB","njd":"暂无实况","qy":"1014","rain":"0"}}
/**
curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, web_write_mem); //指定由 web_write_mem 处理网络数据和本地内存数据
curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &m_web_buf); //指定数据 和 &m_web_buf 对接，具体对接细节在 web_write_mem 中实现
static size_t web_write_mem(void *ptr, size_t size, size_t nmemb, void *data)
    ptr：存储来自网络的数据   size：每个单元字节大小   nmemb：总单元数量  data：本地的数据，这里是 &m_web_buf，用于完整保存网络数据
*/


extern "C"
jstring
test(JNIEnv *env, jobject /* this */) {
    //GET请求
    string url = "https://www.baidu.com";//"https://dlnbsqbjuo509.cloudfront.net/Teen_Patti_Start_v8.zip";
    WebTask task;
    task.SetUrl(url.c_str());
    task.SetConnectTimeout(10*60); //10 分钟内搞定吧
    task.DoGetString();
    if (task.WaitTaskDone() == 0) {
        //请求服务器成功
        string jsonResult = task.GetResultString();
        LOGI("返回的json数据是：%s\n", jsonResult.c_str());
    } else {
        LOGI("网络连接失败\n");
        return env->NewStringUTF("网络连接失败！");
    }
    return NULL;
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_example_testcurllib_MainActivity_downloadUrl(JNIEnv *env, jobject thiz, jstring url) {
    test(env, nullptr);
    return nullptr;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_testcurllib_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

