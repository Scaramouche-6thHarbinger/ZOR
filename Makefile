CXX 				:= g++
CXXFLAGS 			:= -Wall -Wextra -O2 -g
LOCAL_PATH			:= $(PWD)
LOCAL_OUT_PATH 		:= $(PWD)/out/
LOCAL_LIB_INCLUDES 	:= -L$(LOCAL_OUT_PATH) -lpthread

LOCAL_SRC_FILES := \
	src/Session/Session.cpp \
	src/Network/NetworkManager.cpp \
	src/include/util/utils3/ysf_queue3.cpp

LOCAL_TEST_FILE := \
	main_client.cpp

LOCAL_MAIN_FILE := \
	main.cpp

INCLUDES := \
	src/include \
	src/include/util \
	src/include/util/utils3 \
	src/Network \
	src/Session

LOCAL_C_INCLUDES = $(addprefix -I, $(INCLUDES))


all: client server

client:
	mkdir -p $(LOCAL_OUT_PATH)
	$(CXX) $(CXXFLAGS) $(LOCAL_C_INCLUDES) $(LOCAL_SRC_FILES) $(LOCAL_TEST_FILE) -o $(LOCAL_OUT_PATH)client $(LOCAL_LIB_INCLUDES)

server:
	mkdir -p $(LOCAL_OUT_PATH)
	$(CXX) $(CXXFLAGS) $(LOCAL_C_INCLUDES) $(LOCAL_SRC_FILES) $(LOCAL_MAIN_FILE) -o $(LOCAL_OUT_PATH)server $(LOCAL_LIB_INCLUDES)

clean:
	rm -rf $(LOCAL_OUT_PATH)

run: all
	$(LOCAL_OUT_PATH)server