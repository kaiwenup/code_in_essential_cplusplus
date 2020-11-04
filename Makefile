#把所有的目录做成变量，方便修改和移植 
BIN = .
SRC = ./src
INC = ./inc
OBJ = ./obj
 
#提前所有源文件(即：*.c文件)和所有中间文件(即：*.o)
 SOURCE = $(wildcard ${SRC}/*.cpp \
		$(wildcard ./*.cpp) )
 OBJECT = $(patsubst %.cpp,${OBJ}/%.o,$(notdir ${SOURCE}))
 


# 设置最后目标文件
 TARGET = test
 BIN_TARGET = $(BIN)/$(TARGET)
 
 CC = g++ 
 CFLAGS = -std=gnu++0x   -I$(INC)
 
# 生成最后的可执行文件
$(BIN_TARGET):$(OBJECT)
	$(CC)  -o $@ $(OBJECT)

# 各文件单独编译
$(OBJ)/%.o :$(SRC)/%.cpp  
	$(CC) $(CFLAGS)  -c $< -o $@ 
$(OBJ)/test.o: ./test.cpp 
	$(CC) $(CFLAGS) -o $@ -c test.cpp 

 
 .PHONY:clean
 clean:
	find $(OBJ) -name *.o -exec rm -rf {} \; 
	rm -rf $(BIN_TARGET)