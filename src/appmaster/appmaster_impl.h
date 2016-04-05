#ifndef _BAIDU_GALAXY_APPMASTER_IMPL_H_
#define _BAIDU_GALAXY_APPMASTER_IMPL_H_

#include <string>
#include <map>
#include <set>

#include "src/protocol/appmaster.pb.h"

namespace baidu {
namespace galaxy {

class AppMasterImpl : public AppMaster {
public:

void KeepAlive(::google::protobuf::RpcController* controller,
               const ::baidu::galaxy::KeepAliveRequest* request,
               ::baidu::galaxy::KeepAliveResponse* response,
               ::google::protobuf::Closure* done);

void ListTasks(::google::protobuf::RpcController* controller,
               const ::baidu::galaxy::ListTasksRequest* request,
               ::baidu::galaxy::ListTasksResponse* response,
               ::google::protobuf::Closure* done);

void StartTask(::google::protobuf::RpcController* controller,
               const ::baidu::galaxy::StartTaskRequest* request,
               ::baidu::galaxy::StartTaskResponse* response,
               ::google::protobuf::Closure* done);

void StopTask(::google::protobuf::RpcController* controller,
              const ::baidu::galaxy::StopTaskRequest* request,
              ::baidu::galaxy::StopTaskResponse* response,
              ::google::protobuf::Closure* done);

void UpdateTask(::google::protobuf::RpcController* controller,
                const ::baidu::galaxy::UpdateTaskRequest* request,
                ::baidu::galaxy::UpdateTaskResponse* response,
                ::google::protobuf::Closure* done);

void ExecuteCmd(::google::protobuf::RpcController* controller,
                const ::baidu::galaxy::ExecuteCmdRequest* request,
                ::baidu::galaxy::ExecuteCmdResponse* response,
                ::google::protobuf::Closure* done);

};

}
}

#endif
