#把所有的目录做成变量，方便修改和移植 
BIN = .
SRC = ./src
INC = ./inc
OBJ = ./obj
 
#提前所有源文件(即：*.c文件)和所有中间文件(即：*.o)
 SOURCE = $(wildcard ${SRC}/*.cpp \
		$(wildcard ./*.cpp) )
 OBJECT = $(patsubst %.cpp,${OBJ}/%.o,$(notdir ${SOURCE}))
 


#设置最后目标文件
 TARGET = test
 BIN_TARGET = $(BIN)/$(TARGET)
 
 CC = g++ 
 CFLAGS = -std=gnu++0x   -I$(INC)
 
#用所有中间文件生成目的文件，规则中可以用 $^替换掉 ${OBJECT}
$(BIN_TARGET):$(OBJECT)
	$(CC)  -o $@ $(OBJECT)
 
#生成各个中间文件
 #${OBJ}/%.o:${SRC}/%.c 
#$(OBJ)/%.o:$(SRC)/%.cpp
#$(OBJ)/%.o:$(SOURCE) 
#	$(CC) $(CFLAGS) -o $@ -c $<
#$(OBJ)/stack.o:$(SRC)/stack.cpp
#	$(CC) $(CFLAGS) -o $@ -c $(SRC)/stack.cpp
#$(OBJ)/con.o:$(SRC)/con.cpp
#	$(CC) $(CFLAGS) -o $@ -c $(SRC)/con.cpp
$(OBJ)/chapter6.o:$(SRC)/chapter6.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC)/chapter6.cpp
$(OBJ)/function.o:$(SRC)/function.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC)/function.cpp
$(OBJ)/con.o:$(SRC)/con.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC)/con.cpp	
$(OBJ)/stack.o:$(SRC)/stack.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC)/stack.cpp
$(OBJ)/demo.o:$(SRC)/demo.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC)/demo.cpp
$(OBJ)/chapter5.o:$(SRC)/chapter5.cpp
	$(CC) $(CFLAGS) -o $@ -c $(SRC)/chapter5.cpp

$(OBJ)/test.o: ./test.cpp 
	$(CC) $(CFLAGS) -o $@ -c test.cpp 

 
 
 .PHONY:clean
 clean:
	find $(OBJ) -name *.o -exec rm -rf {} \; 
	rm -rf $(BIN_TARGET)