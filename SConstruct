env = Environment(
        CPPPATH = ['.', './thirdparty/include'] ,
        LIBS = ['sofa-pbrpc', 'protobuf', 'snappy', 'gflags', 'glog', 'pthread', 'rt', 'z'],
        LIBPATH= ['./thirdparty/lib'] )

env.Program('resman', Glob('src/resman/*.cc') + ['src/protocol/resman.pb.cc', 'src/protocol/galaxy.pb.cc'])

env.Program('appmaster', Glob('src/appmaster/*.cc') + ['src/protocol/appmaster.pb.cc', 'src/protocol/galaxy.pb.cc'])

env.Program('appworker', Glob('src/appworker/*.cc'))

env.Program('agent', Glob('src/agent/*.cc') + ['src/protocol/agent.pb.cc', 'src/protocol/galaxy.pb.cc'])



