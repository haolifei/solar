import os
os.system('thirdparty/bin/protoc --proto_path=./src/protocol/ --cpp_out=./src/protocol/ src/protocol/*.proto')

env = Environment(
        CPPPATH = ['.', './thirdparty/include', 'src/utils'] ,
        LIBS = ['sofa-pbrpc', 'protobuf', 'snappy', 'gflags', 'glog', 'pthread', 'rt', 'z'],
        LIBPATH= ['./thirdparty/lib'] )

env.Program('resman', Glob('src/resman/*.cc') + Glob('src/utils/*.cc') 
            + ['src/protocol/resman.pb.cc', 'src/protocol/galaxy.pb.cc'])

env.Program('appmaster', Glob('src/appmaster/*.cc') + Glob('src/utils/*.cc')
            + ['src/protocol/appmaster.pb.cc', 'src/protocol/galaxy.pb.cc'])

env.Program('appworker', Glob('src/appworker/*.cc') + Glob('src/utils/*.cc'))

env.Program('agent', Glob('src/agent/*.cc') + Glob('src/utils/*.cc')
            + ['src/protocol/agent.pb.cc', 'src/protocol/galaxy.pb.cc'])



