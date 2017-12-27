NIREUS_LIB=$(NIREUS_FRAMEWORK)

include $(NIREUS_LIB)/$(NIREUS_VERSION)/makefile/makefile_a

PROJECT_INCLUDES += -I$(SERVER_LIB_PATH) -I$(COMMON_LIB_PATH)/CommonLib -I$(COMMON_LIB_PATH)/CommonLib/third_party/include/oss_sdk/ -I$(COMMON_LIB_PATH)/CommonLib/third_party/apr/include/apr-1 -I$(COMMON_LIB_PATH)/CommonLib/third_party/apr-util/include/apr-1
LFLAGS += -L$(COMMON_LIB_PATH)/linux_lib -lCommonLib -loss_c_sdk -laprutil-1 -lapr-1 -lmxml -L$(SERVER_LIB_PATH)/lib -lServerLib