# 🚀 Pipe Flow Analyzer – C++ Internal Flow Analysis Tool  

A lightweight C++ program for estimating **internal pipe flow behavior** using fundamental fluid dynamics principles.  

## 📌 About the Project  
This project was developed as part of a **Programming continuous assessment**, where my team and I explored the application of C++ in solving engineering problems. While full-scale **Computational Fluid Dynamics (CFD)** tools exist, our goal was to create a **simpler, faster** computational tool for quick estimations of flow properties.  

## 🔍 Key Features  
✔️ Calculates **velocity, Reynolds number, and pressure losses**  
✔️ Implements **Bernoulli’s and Darcy-Weisbach equations**  
✔️ Classifies flow as **laminar, transitional, or turbulent**  
✔️ Uses **modular programming** for easy expansion  
✔️ Simple **command-line interface** for user input  

## ⚙️ How It Works  
1. **User Inputs:** Pipe diameter, length, roughness, fluid properties, and flow conditions  
2. **Program Computes:**  
   - Flow velocity  
   - Reynolds number (to determine flow type)  
   - Head loss using Darcy-Weisbach equation  
3. **Outputs:** Flow classification and estimated pressure drop  

## 🛠️ Installation & Usage  
### **1️⃣ Clone the Repository**  
```bash
git clone https://github.com/yourusername/PipeFlowAnalyzer-Cpp.git
cd PipeFlowAnalyzer-Cpp
