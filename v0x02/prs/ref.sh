#!/bin/bash

reference(){
    echo "enter problem No. :"
    read no
    python -mwebbrowser https://www.acmicpc.net/problem/$no
}

reference