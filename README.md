<div align="center">
  <h1>⚙️ push_swap (a <a href="https://42perpignan.fr/">42</a> project) ⚙️</h1>
  <img src="preview.png" alt="Preview">
  <p><b>Subject (in french):</b> <a href="en.subject.pdf">en.subject.pdf</a></p>
</div>
<div align="center">
  <h2>✅ Grade</h2>
  <img src="grade.png" alt="Grade">
</div><br>

## <div align="center">📄 Introduction</div>
This project consists in sorting a list of numbers in ascending order. But, for that, we can only use some given moves.<br>
To get the best grade, the number of moves has to be optimized to be the less possible.<br>
As a parameter, the program take a list of random numbers, each one between INT_MIN and INT_MAX. This list is called the **stack a**. Then, it uses another list, called the **stack b**, which is empty at start, to sort the **stack a**.

The bonus consists in making another program, called **checker**, to check that the list returned by the push_swap program is well-sorted.
<br><br>

## <div align="center">♟️ Allowed moves</div>
### <div align="center">Swap</div>
Swaps the first and the second element of a list.<br>
- **sa** to perform it in the stack a.
- **sb** to perform it in the stack b.

### <div align="center">Push</div>
Pushes the first element of a stack on the other stack.<br>
- **pa** to push from stack b to stack a.
- **pb** to push from stack a to stack b.

### <div align="center">Rotate</div>
Puts the first element of a stack at the end of the stack.<br>
- **ra** to rotate the stack a.
- **rb** to rotate the stack b.
- **rr** to rotate both of the stacks.

### <div align="center">Reverse Rotate</div>
Puts the last element of a stack at the top of the stack.<br>
- **rra** to reverse rotate the stack a.
- **rrb** to reverse rotate the stack b.
- **rrr** to reverse rotate both of the stack.
<br><br>

## <div align="center">💾 Installation</div>
Type the following commands on a bash terminal to install the program:
```bash
git clone https://github.com/Arawyn42/42_push_swap
```
```bash
cd 42_push_swap && make && make bonus && make clean
```
<br>

## <div align="center">💻 Usage</div>
```bash
ARG="list_of_numbers"; ./push_swap $ARG
```
Replace *list_of_numbers* with something like *15 99 -62 54 23 8 -155963*, numbers separated by spaces.

This will give you all the moves you need to perform on the stack to sort it in ascending order.

If you want to check that the list is well sorted, use the following command:
```bash
ARG="list_of_numbers"; ./push_swap $ARG | ./checker $ARG
```
