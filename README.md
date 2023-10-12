# 🖱 42Paris Project - Security | snow-crash

## Objectives

This project is a **modest introduction** to the wide world of cyber security.  A world where you'll gave no margin for errors.  
It aims to discover, through several little challenges, cyber security in various fields.  

In the repository, you'll find as many **folders** as there are **levels**. In this folders, you'll find a **resources folder** with a text file named **"explain.txt"** that brings all the explanation to pass each levels.  
The file **flag** in the level folder refers to the return of getflag for each levels (password to the next one).

## Usage

To make this project, we have to use a VM (64bits) and starts it with the ISO provided with the subject. Once the machine is started, an IP is provided to connect with ssh.  

`ssh levelX@IP -p 4242`  

The username and password is level00 - level00, the username will increase as we go along in the project (level01, 02... until level14) and bonus part starts at level10.  

In every level we have to find a token (or directly the flag to connect to next level) to connect to user flag(level) as flag00, flag01... 

Once we are connected on flag(level), we can execute getflag command and get the flag of the level, it is the password of the next level.  

## Collaborator

This project was made with:
[Romane Leseur](https://github.com/GAsNA "Romane Leseur")  
