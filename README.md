# KISAN - Agriculture Management Tool

KISAN is a console-based application that helps farmers with **crop recommendations**, information on **government agricultural schemes**, and **profit estimation** for their crops.


## Features

1. **Crop Recommendation** — Select your state and city to get suitable crop suggestions along with soil pH, season, and NPK (Nitrogen, Phosphorus, Potassium) values.
2. **Government Schemes** — View a list of government schemes available for farmers.
3. **Profit Calculation** — Estimate your profit based on land area, chosen crop, and associated costs.


## How to Run

### Requirements

- **Windows PC** (the `.exe` is built for Windows)
- No installation or compiler needed

### Steps

**Download and Setup:**
1. Go to the **Releases** section on the right side of this repository page.
2. Download the latest project `.zip` file from the **Assets** dropdown.
3. Extract the downloaded `.zip` file to a folder on your computer. This folder contains the executable (`kisan.exe`) and all necessary data files required to run the program.

4. **Double-click `kisan.exe`** to run the program.

5. Follow the on-screen menu to use the features.

> **Note:** If Windows shows a security warning ("Windows protected your PC"), click **More info** → **Run anyway**. This is normal for `.exe` files downloaded from the internet.


## File Descriptions

| File             | Description                                       |
|------------------|---------------------------------------------------|
| `kisan.exe`      | The main application (executable)                 |
| `soil_data.csv`  | Contains state/city-wise soil and crop data       |
| `crop_costs.csv` | Contains crop cultivation and seed cost details   |
| `schemes.txt`    | Contains information about government schemes     |

---

## Troubleshooting

- **Program closes immediately?** — Run it from Command Prompt instead of double-clicking. Open CMD, navigate to the folder, and type `kisan.exe`.
- **Data not loading?** — Make sure all CSV/TXT files are in the **same folder** as `kisan.exe`.
