CXX 				:= g++
CXXFLAGS 			:= -Wall -Wextra -Wno-strict-aliasing -Wno-shift-count-overflow -O2 -g
LOCAL_PATH			:= $(PWD)
LOCAL_OUT_PATH 		:= $(PWD)/out/
LOCAL_LIB_INCLUDES 	:= -L$(LOCAL_OUT_PATH) -lpthread

LOCAL_SRC_FILES := \
	src/Session.cpp \
	src/NetworkManager.cpp \
	src/Packet.cpp \
	src/User.cpp \
	src/include/util/utils3/ysf_queue3.cpp \
	src/NLogic/Bag.cpp

LOCAL_TEST_FILE := \
	main_client.cpp

LOCAL_MAIN_FILE := \
	main.cpp

INCLUDES := \
	src/include \
	src/include/util \
	src/include/util/utils3 \
	src/ \
	src/util \
	src/NLogic

LOCAL_C_INCLUDES = $(addprefix -I, $(INCLUDES))


all: server

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