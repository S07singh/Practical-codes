import socket
import os
import subprocess
import sys

SERVER_IP = "127.0.0.1"   # Change if server is on another machine
PORT = 5001
BUFFER_SIZE = 1024

# Create UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Files to send
files_to_send = {
    "text": "file.txt",
    "video": "video.mp4",
    "audio": "audio.mp3",
    "script": "script.py"
}

for label, file_path in files_to_send.items():
    if not os.path.exists(file_path):
        print(f"[CLIENT] File '{file_path}' does not exist. Skipping.")
        continue

    file_size = os.path.getsize(file_path)
    file_name = os.path.basename(file_path)

    print(f"[CLIENT] Sending {label} file: {file_name} ({file_size} bytes)")

    # Send file info
    file_info = f"{file_name}::{file_size}"
    sock.sendto(file_info.encode(), (SERVER_IP, PORT))

    # Send file content in chunks
    with open(file_path, "rb") as f:
        while True:
            data = f.read(BUFFER_SIZE)
            if not data:
                break
            sock.sendto(data, (SERVER_IP, PORT))

    print(f"[CLIENT] Finished sending: {file_name}")

    # Try opening the file locally (optional)
    try:
        if label in ["audio", "video"]:
            print(f"[CLIENT] Playing {label} file locally: {file_path}")
            if sys.platform.startswith("win"):
                os.startfile(file_path)
            elif sys.platform.startswith("darwin"):
                subprocess.run(["open", file_path])
            else:
                subprocess.run(["xdg-open", file_path])
        elif label == "text":
            print(f"[CLIENT] Opening text file locally: {file_path}")
            if sys.platform.startswith("win"):
                subprocess.run(["notepad.exe", file_path])
            else:
                print("[CLIENT] Text auto-open supported only on Windows.")
    except Exception as e:
        print(f"[CLIENT] Could not open/play file locally: {e}")

sock.close()
