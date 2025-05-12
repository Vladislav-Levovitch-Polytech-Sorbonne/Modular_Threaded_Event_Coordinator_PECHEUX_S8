# Paths
SRC_DIR := Example_Application/Game_Educative_Application
BUILD_DIR := .

# Files
SERVER_SRC := $(SRC_DIR)/server.c
CLIENT_SRC := $(SRC_DIR)/client.c
SERVER_OBJ := server.o
CLIENT_OBJ := client.o

SERVER_EXE := $(BUILD_DIR)/1_server_begin_0.exe
CLIENT_EXE := $(BUILD_DIR)/2_client_begin_1_2_3.exe

CC := gcc
#CFLAGS := -Wall # 🤫 Better without flags : )
CFLAGS :=

.PHONY: all clean

all: $(SERVER_EXE) $(CLIENT_EXE)

$(SERVER_EXE): $(SERVER_SRC)
	@echo "[🔧] Compiling server..."
	$(CC) $(CFLAGS) -o $@ $<
	@echo "[✅] Server ready : $(notdir $@)"

$(CLIENT_EXE): $(CLIENT_SRC)
	@echo "[🔧] Compiling client..."
	$(CC) $(CFLAGS) -o $@ $< -lSDL2 -lSDL2_image -lSDL2_ttf
	@echo "[✅] Client ready : $(notdir $@)"

clean:
	@echo "[🧹] Cleaning build artifacts..."
	rm -f $(BUILD_DIR)/*.exe
	rm -f *.o
	@echo "[✔️ ] Cleanup complete."

# With ChatGPT's help 