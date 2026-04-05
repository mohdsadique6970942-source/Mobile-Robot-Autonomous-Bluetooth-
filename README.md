# 🤖 Multi-Mode Smart Mobile Robot (Autonomous + Bluetooth)

A versatile mobile robot built using Arduino Uno capable of performing multiple intelligent behaviors including line following, object following, obstacle avoidance, maze solving, cliff detection, and Bluetooth-controlled operation.

---
 
## 🚀 Features
- Line Following  
- Object Following  
- Obstacle Avoidance  
- Maze Solving  
- Cliff / Edge Detection  
- Bluetooth Manual Control (HC-05)  
- Multi-mode switching  

---

## 🧰 Components Used
- Arduino Uno  
- Ultrasonic Sensor (HC-SR04)  
- IR Sensors (for line & cliff detection)  
- Servo Motor  
- Motor Driver (L298N / TB6612)  
- DC Motors + Chassis  
- HC-05 Bluetooth Module  
- Battery Pack  

---

# 🔌 Pin Configuration

## 🔹 Motor Driver (L298N)
| Function | Arduino Pin |
|--------|------------|
| ENA | 9 |
| IN1 | 4 |
| IN2 | 5 |
| ENB | 10 |
| IN3 | 7 |
| IN4 | 8 |

---

## 🔹 Ultrasonic Sensor (HC-SR04)
| Function | Arduino Pin |
|--------|------------|
| Trig | 11 |
| Echo | 12 |

---

## 🔹 IR Sensors (Line / Cliff)
| Sensor | Arduino Pin |
|-------|------------|
| Left IR | A0 |
| Right IR | A1 |

---

## 🔹 Servo Motor
| Function | Arduino Pin |
|--------|------------|
| Signal | 6 |

---

## 🔹 Bluetooth Module (HC-05)
| Function | Arduino Pin |
|--------|------------|
| TX | RX (0) |
| RX | TX (1) |

## 📷 Circuit Diagram
<img width="1536" height="1024" alt="ChatGPT Image Apr 5, 2026, 11_40_05 PM" src="https://github.com/user-attachments/assets/595915d6-36e7-435d-ae0c-106a4ed910c1" />


---

# ⚙️ Modes & Working

## 🟢 1. Line Following
- Uses IR sensors to detect black/white path  
- Adjusts motor speed to stay on track  

---

## 🔵 2. Object Following
- Ultrasonic sensor detects distance  
- Robot follows object at fixed range  

---

## 🔴 3. Obstacle Avoidance
- Detects obstacles using ultrasonic  
- Changes direction automatically  

---

## 🟡 4. Maze Solving
- Uses logic (left/right priority)  
- Navigates through unknown paths  

---

## ⚫ 5. Cliff / Edge Detection
- IR sensors detect edges  
- Stops or turns to avoid falling  

---

## 📱 6. Bluetooth Control
Control robot using mobile commands:

| Command | Action |
|--------|--------|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |

---

# 💻 Code Structure
Each functionality is implemented in separate Arduino files:
- `line_following.ino`
- `object_following.ino`
- `obstacle_avoidance.ino`
- `maze_solver.ino`
- `cliff_avoidance.ino`
- `bluetooth_control.ino`

---

# 🔄 Flow Logic
Start → Select Mode → Read Sensors/Bluetooth → Process → Move Motors → Loop


---

# 🎯 Applications
- Autonomous navigation robots  
- Smart vehicles  
- Robotics competitions  
- Educational projects  

---

# 📚 Learning Outcomes
- Sensor fusion  
- Embedded systems  
- Motor control  
- Autonomous decision making  
- Wireless communication  

---

# 📄 License
Open-source and free for educational use.


