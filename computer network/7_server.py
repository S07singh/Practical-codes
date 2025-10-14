import socket
import os

# Server settings
SERVER_IP = "0.0.0.0"
SERVER_PORT = 5001
BUFFER_SIZE = 4096
SAVE_DIR = "received_files"

os.makedirs(SAVE_DIR, exist_ok=True)

# Create TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((SERVER_IP, SERVER_PORT))
server_socket.listen(1)

print(f"TCP Server listening on {SERVER_IP}:{SERVER_PORT}...")
conn, addr = server_socket.accept()
print(f"Connection from {addr}")

while True:
    # Receive filename
    filename_data = b""
    while b"<END>" not in filename_data:
        chunk = conn.recv(BUFFER_SIZE)
        if not chunk:
            conn.close()
            server_socket.close()
            exit()
        filename_data += chunk

    filename = filename_data.split(b"<END>")[0].decode()
    print(f"Receiving file: {filename}")

    # Open file for writing
    with open(os.path.join(SAVE_DIR, filename), "wb") as f:
        while True:
            data = conn.recv(BUFFER_SIZE)
            if b"<EOF>" in data:
                f.write(data.replace(b"<EOF>", b""))
                break
            f.write(data)

    print(f"File {filename} received successfully!\n")
