import time
from gpiozero import LED

# Define LED pins with descriptive names
led_red = LED(7)
led_yellow = LED(22)
led_green = LED(23)

# Turn all LEDs OFF initially (gpiozero LEDs are initially off)

print("Enter:")
print("r - Red light ON")
print("y - Yellow light ON")
print("g - Green light ON")
print("b - Green light BLINK")

# Main loop
while True:
    key = input("Enter character: ").lower()
    print("Received:", key)
    
    # Turn all LEDs off first
    led_red.off()
    led_yellow.off()
    led_green.off()
    
    if key == 'r':
        # Red light ON
        led_red.on()
    elif key == 'y':
        # Yellow light ON
        led_yellow.on()
    elif key == 'g':
        # Green light ON
        led_green.on()
    elif key == 'b':
        # Blink green light (5 times)
        print("Green LED blinking...")
        for i in range(5):
            led_green.on()
            time.sleep(0.5)
            led_green.off()
            time.sleep(0.5)
        print("Blinking finished")
    else:
        print("Try r, y, g, or b")