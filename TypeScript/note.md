# TypeScript 學習筆記

## 簡述

- TypeScript 就是有型別的 JavaScript
    - 硬型別 (eg: Pyhton)
    - 靜態型別 (eg: C, Java)
- TypeScript 可完全向下兼容 JavaScript (TypeScript is superset of JavaScript)
- 瀏覽器不能直接吃 TypeScript，必須先編譯成 JavaScript

## 環境安裝

> 這篇筆記將以 Windows WSL (Ubuntu) 作為開發作業系統

> Reference: [在 Windows 子系統 Linux 版 (WSL2) 上安裝Node.js](https://learn.microsoft.com/zh-tw/windows/dev-environment/javascript/nodejs-on-wsl)

### 安裝 Node.js

> 直接使用 `sudo apt install nodejs npm` 安裝的話，`npm` 似乎會與 host 的衝突，且 Node.js 的版本變更快速，Microsoft 建議可以使用 `nvm` 版本管理套件。

1. 安裝 `curl`：
   ```bash
   sudo apt install curl
   ```
2. 透過 `curl` 安裝 `nvm`
   ```bash
   curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/master/install.sh | bash
   ```
3. 重新打開 WSL bash，輸入 `command -v nvm` 確認安裝成功
4. 安裝 LTS 版本 Node.js
   ```bash
   nvm install --lts
   ```
5. 確認安裝的 Node.js 版本
   ```bash
   nvm ls
   ```

### 安裝 TypeScript

1. 使用 `npm` 安裝 TypeScript
   ```bash
   npm install -g typescript
   ```
2. 確認是否安裝成功
   ```bash
   tsc --version
   ```
   
### VSCode 套件

- [Live Server](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer)
  > 可在 Html 編輯區按右鍵選擇 **Open in live server** 預覽結果
- [JavaScript and TypeScript Nightly](https://marketplace.visualstudio.com/items?itemName=ms-vscode.vscode-typescript-next)
- [TypeScript Hero](https://marketplace.visualstudio.com/items?itemName=rbbit.typescript-hero)


## 使用與編譯 TypeScript

### Html Templete

```html
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>TypeScript</title>
    </head>

    <script src="script.js"></script>
</html>
```

> *script.js* 為稍後 TypeScript 編譯成 JavaScript 的檔案

### 編譯 TypeScript

- 編譯 ts 檔，輸出與原檔名相同，且相同路徑的 js 檔
  ```bash
  tsc [typescript.ts]
  ```
- 編譯 ts 檔，指定輸出位置與檔名
  ```bash
  tsc [typescript.ts] -outFile [javascript.js]
  ```
- 自動偵測檔案變更並編譯
  ```bash
  tsc [typescript.ts] -w
  tsc [typescript.ts] -outFile [javascript.js] -w
  ```
  
## 語法

### 基本型別

TypeScript 有三種基本型別：

- `number` 數字：int, float, double 這些都算
- `string` 字串：可用 `""` 或 `''` 包住字串
- `boolean` 布林：小寫的 `true` 或 `false`

### 基本宣告

分為 `let` 與 `const` 兩種狀態（我不太清楚這專有名詞，反正看底下就知道那概念了）。

- `let` 變數：值可變更
- `const` 常數：值不可變更，只能賦初值

```typescript
let age = 10
let isMale = false
const TITLE = "TypeScript"
```

TypeScript 中，變數一旦賦予初值，型別就沒辦法更改。

```typescript
age = "old" // error
age = 20 // available
```

變數在宣告時也可以先不賦初值，但指定型別。型別可以是單一一個，也可以是多個，或甚至是任意型別。當然，也可以同時賦初值，同時指定型別。

```typescript
let length: number
let message: (number|string) = "Hello"
let input: any
```

### Array

> 官方給的名詞是 Array，但我覺得這也很難說是 Array 或 List 哪個，但應該比較偏向 List 吧（？

TypeScript 的 Array 在不給其他型別條件的情況下，是只能存特定型別，這個特定型別視初值含有哪些型別而定。

```typescript
let nums = [1, 1, 2, 3, 5]

nums.push("text") // error
nums.push(8) // available

nums[0] = true // error
nums[0] = -1 // available
```

與基本型別的宣告一樣，也可以在不賦初值的情況下（空串列），指定串列中的元素型別。

```typescript
let shopList: string[] = []
let myList: (number|boolean)[] = []
let anyList: any[] = []
```

