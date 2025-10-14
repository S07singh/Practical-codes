import socket
import os

# Server details
SERVER_IP = "127.0.0.1"   # Change to server machine IP if needed
SERVER_PORT = 5001
BUFFER_SIZE = 4096

# Create TCP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((SERVER_IP, SERVER_PORT))

# Files to send
files = [
    "files_to_send/script.py",
    "files_to_send/notes.txt",
    "files_to_send/video.mkv"
]

for filepath in files:
    filename = os.path.basename(filepath)

    # Send filename first
    client_socket.sendall(filename.encode() + b"<END>")

    # Send file content
    with open(filepath, "rb") as f:
        while chunk := f.read(BUFFER_SIZE):
            client_socket.sendall(chunk)

    # Send end-of-file marker
    client_socket.sendall(b"<EOF>")

    print(f"File {filename} sent successfully!\n")

client_socket.close()
